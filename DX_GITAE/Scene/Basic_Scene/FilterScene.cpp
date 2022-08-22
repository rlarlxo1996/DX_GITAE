#include "framework.h"
#include "FilterScene.h"

FilterScene::FilterScene()
{
	_quad = make_shared<Quad>(L"Resource/IU.png", L"Shader/TextureVertexShader.hlsl", L"Shader/FilterShader/FilterShader.hlsl");
	_quad->GetTransform()->GetPos() = { WIN_WIDTH * 0.5f, WIN_HEIGHT * 0.5f };

	_filterBuffer = make_shared<FilterBuffer>();
	_filterBuffer->_data.selected = 1;
	_filterBuffer->_data.value1 = 3;
	_filterBuffer->_data.value2 = 4;

	_imageSizeBuffer = make_shared<ImageSizeBuffer>();
	_imageSizeBuffer->_data._size = _quad->GetSize();

	_sun = make_shared<Quad>(L"Resource/Sun.png", L"Shader/TextureVertexShader.hlsl", L"Shader/FilterShader/FilterShader.hlsl");
	_sun->GetTransform()->GetPos() = { WIN_WIDTH * 0.1f, WIN_HEIGHT * 0.5f };
	_sun->GetTransform()->GetScale() *= 0.3f;
	_sunFilterBuffer = make_shared<FilterBuffer>();
	_sunFilterBuffer->_data.selected = 6;
}

FilterScene::~FilterScene()
{
}

void FilterScene::Update()
{
	_quad->Update();
	_sun->Update();
}

void FilterScene::Render()
{
	_filterBuffer->SetPSBuffer(0);
	_imageSizeBuffer->SetPSBuffer(1);
	_quad->Render();

	_sunFilterBuffer->SetPSBuffer(0);
	_sun->Render();
}

void FilterScene::PostRender()
{
	ImGui::SliderInt("FilterSelect", &_filterBuffer->_data.selected, 0, 6);
	ImGui::SliderInt("Mosaic Value", &_filterBuffer->_data.value1, 1, 416);
	ImGui::SliderInt("Blur Value", &_filterBuffer->_data.value2, 1, 30);
	ImGui::SliderInt("Radial Value", &_filterBuffer->_data.value3, 1, 800);
}
