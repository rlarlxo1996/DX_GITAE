#include "framework.h"
#include "PlaneShoot.h"

PlaneShoot::PlaneShoot()
{
	_sprite = make_shared<Sprite>(L"Resource/RPlane.png", Vector2(5, 5));
}

PlaneShoot::~PlaneShoot()
{
}

void PlaneShoot::Update()
{
}

void PlaneShoot::Render()
{
}

void PlaneShoot::PostRender()
{
}

void PlaneShoot::CreateActions()
{
	vector<Action::Clip> clips;
	clips.reserve(10);
	float w = 920.0f / 5.0f;
	float h = 920.0f / 5.0f;

	// F_IDLE
	{
		clips.emplace_back(920 * 0 + w * 2, 0, w, h, Texture::Add(L"Resource/RPlane.png"));
		clips.emplace_back(920 * 0 + w * 2, 1, w, h, Texture::Add(L"Resource/RPlane.png"));
		clips.emplace_back(920 * 0 + w * 2, 2, w, h, Texture::Add(L"Resource/RPlane.png"));
		shared_ptr<Action> action = make_shared<Action>(clips, "F_IDLE", Action::PINGPONG, 0.3f);
		action->Pause();
		_actions.push_back(action);
		clips.clear();
	}
	// L_MOVE
	{
	
	}
}

void PlaneShoot::SetAnimation(PlaneShoot::State state)
{
}

void PlaneShoot::KeyBoardMove()
{
}
