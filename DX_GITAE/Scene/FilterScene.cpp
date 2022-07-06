#include "framework.h"
#include "FilterScene.h"

FilterScene::FilterScene()
{
	_quad = make_shared<Quad>(L"Resource/IU.png", L"Shader/TextureVertexShader.hlsl", L"Shader/FilterShader/FilterShader.hlsl");
	_quad->GetTransform()->GetPos() = { WIN_WIDTH * 0.5f, WIN_HEIGHT * 0.5f };

	_filterBuffer = make_shared<FilterBuffer>();
	_filterBuffer->_data.selected = 1;
	_filterBuffer->_data.value1 = 3;
}

FilterScene::~FilterScene()
{
}

void FilterScene::Update()
{
	_quad->Update();
}

void FilterScene::Render()
{
	_filterBuffer->SetPSBuffer(0);

	_quad->Render();
}

void FilterScene::PostRender()
{
	ImGui::SliderInt("Mosaic Value", &_filterBuffer->_data.value1, 1, 416);
}
