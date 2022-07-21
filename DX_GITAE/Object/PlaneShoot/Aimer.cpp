#include "framework.h"
#include "Aimer.h"

Aimer::Aimer()
{
	_quad = make_shared<Quad>(L"Resource/Gun.png");
	_quad->GetTransform()->GetScale() = { 0.3f, 0.3f };
}

Aimer::~Aimer()
{
}

void Aimer::Update()
{
	_quad->GetTransform()->GetPos() = MOUSE_POS;

	_quad->Update();
}

void Aimer::Render()
{
	_quad->Render();
}
