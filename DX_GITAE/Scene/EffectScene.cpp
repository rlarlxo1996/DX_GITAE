#include "framework.h"
#include "EffectScene.h"

EffectScene::EffectScene()
{
	_effect = make_shared<Effect>(L"Resource/Effects/GreenExplosion.png", Vector2(4, 4));
	_effect->Play(CENTER);
}

EffectScene::~EffectScene()
{
}

void EffectScene::Update()
{
	_effect->Update();
}

void EffectScene::Render()
{
	_effect->Render();
}

void EffectScene::PostRender()
{
}
