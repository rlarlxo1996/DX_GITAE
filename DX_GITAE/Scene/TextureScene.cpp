#include "framework.h"
#include "TextureScene.h"

TextureScene::TextureScene()
{
	_quad = make_shared<Quad>(L"Resource/Dia.png");
}

TextureScene::~TextureScene()
{
}

void TextureScene::Update()
{
}

void TextureScene::Render()
{
	_quad->Render();
}
