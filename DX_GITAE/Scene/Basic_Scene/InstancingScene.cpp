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
		temp.GetScale() *= MathUtility::RandomFloat(0, 0.1f);
		
		temp.UpdateWorld();

		instanceData.matirx = XMMatrixTranspose(temp.GetMatrix());
		instanceData.maxFrame = { 10,8 };
		instanceData.curFrame = { MathUtility::RandomFloat(0,10), MathUtility::RandomFloat(0,8) };
	}

	_instancingBuffer = make_shared<VertexBuffer>(_instanceDataes.data(), sizeof(InstanceData), 450);
}

InstancingScene::~InstancingScene()
{
}

void InstancingScene::Update()
{

}

void InstancingScene::Render()
{
	_instancingBuffer->IASetVertexBuffer(1);
	IASetPT();

	_quad->SetRender();

	DEVICE_CONTEXT->DrawIndexedInstanced(6, 450, 0, 0, 0);
}
