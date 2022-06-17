#include "framework.h"
#include "TextureScene.h"

TextureScene::TextureScene()
{
	_texture = make_shared<Texture>(L"Resource/Dia.png");
}

TextureScene::~TextureScene()
{
}

void TextureScene::Update()
{
}

void TextureScene::Render()
{
	_texture->Render();
}
