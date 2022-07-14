#include "framework.h"
#include "PlaneShoot.h"

PlaneShoot::PlaneShoot()
{
	_sprite = make_shared<Sprite>(L"Resource/RPlane.png", Vector2(5, 5));
	_pos = { WIN_WIDTH * 0.5f, WIN_HEIGHT * 0.5f };

	_collider = make_shared<RectCollider>(_sprite->GetFrameHalfSize());
	_collider->SetParent(_sprite->GetTransform());

	CreateActions();

	SetAnimation(_state);
}

PlaneShoot::~PlaneShoot()
{
}

void PlaneShoot::Update()
{
	KeyBoardMove();

	_sprite->Update();
	_collider->Update();

	for (auto& action : _actions)
	{
		action->Update();
		if (action->IsPlay())
			_sprite->SetActionToActionBuffer(action->GetCurClip());
	}
}

void PlaneShoot::Render()
{
	_sprite->Render();
}

void PlaneShoot::PostRender()
{
	_collider->Render();
}

void PlaneShoot::CreateActions()
{
	vector<Action::Clip> clips;
	clips.reserve(10);
	float w = 1000.0f / 5.0f;
	float h = 1000.0f / 5.0f;

	// F_IDLE
	{
		clips.emplace_back(1000 * 0 + w * 2, 0, w, h, Texture::Add(L"Resource/RPlane.png"));
		clips.emplace_back(1000 * 0 + w * 2, 1, w, h, Texture::Add(L"Resource/RPlane.png"));
		clips.emplace_back(1000 * 0 + w * 2, 2, w, h, Texture::Add(L"Resource/RPlane.png"));
		shared_ptr<Action> action = make_shared<Action>(clips, "F_IDLE", Action::PINGPONG, 0.3f);
		action->Pause();
		_actions.push_back(action);
		clips.clear();
	}
	// L_MOVE
	{
		clips.emplace_back(1000 * 0 + w, 0, w, h, Texture::Add(L"Resource/RPlane.png"));
		clips.emplace_back(1000 * 0, 0, w, h, Texture::Add(L"Resource/RPlane.png"));
		shared_ptr<Action> action = make_shared<Action>(clips, "L_MOVE", Action::END, 0.3f);
		action->Pause();
		_actions.push_back(action);
		clips.clear();
	}
	// R_MOVE
	{
		clips.emplace_back(1000 * 0 + w * 3, 0, w, h, Texture::Add(L"Resource/RPlane.png"));
		clips.emplace_back(1000 * 0 + w * 4, 0, w, h, Texture::Add(L"Resource/RPlane.png"));
		shared_ptr<Action> action = make_shared<Action>(clips, "R_MOVE", Action::END, 0.3f);
		action->Pause();
		_actions.push_back(action);
		clips.clear();
	}
}

void PlaneShoot::SetAnimation(PlaneShoot::State state)
{
	if (_actions[state]->IsPlay() &&
		(_actions[state]->GetReapeatTyoe() == Action::LOOP || _actions[state]->GetReapeatTyoe() == Action::PINGPONG))
		return;

	for (auto& action : _actions)
	{
		if (action->IsPlay() && _state == state)
		{
			continue;
		}

		action->Reset();
	}

	_state = state;
	_actions[static_cast<UINT>(state)]->Play();
}

void PlaneShoot::KeyBoardMove()
{
	SetPosition(_pos);

	if (KEY_PRESS('W'))
	{
		_pos.y += 400.0f * DELTA_TIME;
		SetAnimation(PlaneShoot::State::F_IDLE);
		return;
	}

	if (KEY_PRESS('S'))
	{
		_pos.y -= 400.0f * DELTA_TIME;
		SetAnimation(PlaneShoot::State::F_IDLE);
		return;
	}

	if (KEY_PRESS('A'))
	{
		_pos.x -= 400.0f * DELTA_TIME;
		SetAnimation(PlaneShoot::State::L_MOVE);
		return;
	}

	if (KEY_PRESS('D'))
	{
		_pos.x += 400.0f * DELTA_TIME;
		SetAnimation(PlaneShoot::State::R_MOVE);
		return;
	}

	SetIDLE();
}

void PlaneShoot::SetIDLE()
{
	switch (_state)
	{
	case PlaneShoot::F_IDLE:
		SetAnimation(F_IDLE);
		break;
	case PlaneShoot::L_MOVE:
		SetAnimation(F_IDLE);
		break;
	case PlaneShoot::R_MOVE:
		SetAnimation(F_IDLE);
		break;
	default:
		break;
	}
}