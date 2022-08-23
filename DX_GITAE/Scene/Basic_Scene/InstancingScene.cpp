#include "framework.h"
#include "InstancingScene.h"

InstancingScene::InstancingScene()
{
	_quad = make_shared<Quad>(L"Resource/zelda.png", L"Shader/InstancingVertexShader.hlsl", L"Shader/InstancingPixelShader.hlsl");

	_instanceDataes.resize(450);

	for (auto& instanceData : _instanceDataes)
	{
		Transform temp;
		temp.GetPos() = { MathUtility::RandomFloat(0,WIN_WIDTH), MathUtility::RandomFloat(0,WIN_HEIGHT) };
		temp.GetScale() *= MathUtility::RandomFloat(0, 0.01f);

		temp.UpdateWorld();

		instanceData.matrix = XMMatrixTranspose(temp.GetMatrix());
		instanceData.maxFrame = { 10,8 };
		instanceData.curFrame = { MathUtility::RandomInt(0,10), MathUtility::RandomInt(0,8) };
	}

	_transform = make_shared<Transform>();
	_transform->GetPos() = CENTER;
	_transform->GetScale() *= 0.01f;
	//_instanceDataes[0].matrix = XMMatrixTranspose(_transform->GetMatrix());

	_instancingBuffer = make_shared<VertexBuffer>(_instanceDataes.data(), sizeof(InstanceData), 450);
}

InstancingScene::~InstancingScene()
{
}

void InstancingScene::Update()
{
	_instanceDataes[0].matrix = XMMatrixTranspose(_transform->GetMatrix());
	if (KEY_PRESS(VK_SPACE))
	{
		_transform->GetScale().x += DELTA_TIME;
		_transform->GetScale().y += DELTA_TIME;
	}

	_transform->UpdateWorld();
}

void InstancingScene::Render()
{
	_instancingBuffer->IASetVertexBuffer(1);

	_quad->SetRender();

	DEVICE_CONTEXT->DrawIndexedInstanced(6, 450, 0, 0, 0);
}
