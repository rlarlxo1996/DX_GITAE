#include "framework.h"
#include "SpriteScene.h"

SpriteScene::SpriteScene()
{
	_zelda = make_shared<Zelda>();
	_zelda->SetAnimation(Zelda::State::F_IDLE);
}

SpriteScene::~SpriteScene()
{
}

void SpriteScene::Update()
{
	_zelda->Update();
	Move();
}

void SpriteScene::Render()
{
	_zelda->Render();
}

void SpriteScene::PostRender()
{
	_zelda->PostRender();
}

void SpriteScene::Move()
{
	if (KEY_DOWN('W'))
	{
		_zelda->SetAnimation(Zelda::State::B_RUN);
	}
	if (KEY_UP('W'))
	{
		_zelda->SetAnimation(Zelda::State::B_IDLE);
	}
	if (KEY_DOWN('A'))
	{
		_zelda->SetAnimation(Zelda::State::L_RUN);
	}
	if (KEY_UP('A'))
	{
		_zelda->SetAnimation(Zelda::State::L_IDLE);
	}
	if (KEY_DOWN('S'))
	{
		_zelda->SetAnimation(Zelda::State::F_RUN);
	}
	if (KEY_UP('S'))
	{
		_zelda->SetAnimation(Zelda::State::F_IDLE);
	}
	if (KEY_DOWN('D'))
	{
		_zelda->SetAnimation(Zelda::State::R_RUN);
	}
	if (KEY_UP('D'))
	{
		_zelda->SetAnimation(Zelda::State::R_IDLE);
	}
}
