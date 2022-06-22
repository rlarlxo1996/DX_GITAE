#include "framework.h"
#include "Aim.h"

Aim::Aim()
{
	_texture = make_shared<Texture>(L"Resource/Aim.png");
}

Aim::~Aim()
{
}

void Aim::Update()
{
	_texture->GetTransform()->GetPos() = MOUSE_POS;

	_texture->Update();
}

void Aim::Render()
{
	_texture->Render();
}
