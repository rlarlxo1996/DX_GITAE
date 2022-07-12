#include "framework.h"
#include "TextureScene.h"

TextureScene::TextureScene()
{
	_quad = make_shared<Quad>(L"Resource/Moon.png", L"Shader/TextureVertexShader.hlsl", L"Shader/ReversePixelShader.hlsl");
	_isRightBuffer = make_shared<FilterBuffer>();

	_quad->GetTransform()->GetPos() = CENTER;

	_isRightBuffer->_data.selected = 1;

	EffectManager::GetInstance()->Add(L"Resource/Effects/GreenExplosion.png", Vector2(4, 4));
}

TextureScene::~TextureScene()
{
}

void TextureScene::Update()
{
	_quad->Update();

	if (KEY_DOWN('W'))
	{
		EffectManager::GetInstance()->Play("GreenExplosion", CENTER);
		Camera::GetInstance()->ShakeStart(5.0f, 1.0f, 2.0f);
	}
}

void TextureScene::Render()
{
	_isRightBuffer->SetPSBuffer(0);
	_quad->Render();
}

void TextureScene::PostRender()
{
	ImGui::SliderInt("isRight", &_isRightBuffer->_data.selected, 0, 1);
}
