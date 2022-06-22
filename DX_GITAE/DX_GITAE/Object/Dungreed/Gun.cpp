#include "framework.h"
#include "Gun.h"

Gun::Gun()
{
	_texture = make_shared<Texture>(L"Resource/Gun.png");
	_texture->GetTransform()->GetScale() = { 0.3f, 0.3f };


}

Gun::~Gun()
{
}

void Gun::Update()
{
	_texture->Update();
}

void Gun::Render()
{
	_texture->Render();
}
