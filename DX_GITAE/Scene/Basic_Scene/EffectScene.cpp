#include "framework.h"
#include "EffectScene.h"

EffectScene::EffectScene()
{
	_effect = make_shared<Effect>(L"Resource/Effects/GreenExplosion.png", Vector2(4, 4));
	_effect->Play(CENTER);

	EffectManager::GetInstance()->Add(L"Resource/Effects/GreenExplosion.png", Vector2(4, 4));
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

	if (KEY_DOWN('W'))
	{
		EffectManager::GetInstance()->Play("GreenExplosion", CENTER);
	}
}

void EffectScene::PostRender()
{
}
