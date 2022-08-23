#include "framework.h"
#include "PlaneShoot.h"

PlaneShoot::PlaneShoot()
{
	_sprite = make_shared<Sprite>(L"Resource/RPlane.png", Vector2(5, 5));
	_sprite->GetTransform()->GetScale() = { 0.5f,0.5f };

	// Gun Setting
	_gunParent = make_shared<Transform>();
	_gunParent->SetParent(_sprite->GetTransform());
	_gunParent->GetPos().x = 80.0f;

	_gun = make_shared<Gun>();
	_gun->SetPlayer(_gunParent);

	_collider = make_shared<RectCollider>(_sprite->GetFrameHalfSize());
	_collider->SetParent(_sprite->GetTransform());

	// Bullets
	for (int i = 0; i < _poolCount; i++)
	{
		shared_ptr<MainBullet> bullet = make_shared<MainBullet>();
		bullet->_isActive = false;

		_bullets.emplace_back(bullet);
	}

	CreateActions();
	SetAnimation(_state);
}

PlaneShoot::~PlaneShoot()
{
}

void PlaneShoot::Update()
{
	KeyBoardMove();
	SetGun();
	Fire();

	_sprite->Update();
	_collider->Update();
	_gunParent->UpdateWorld();
	_gun->Update();

	for (auto& action : _actions)
	{
		action->Update();
		if (action->IsPlay())
			_sprite->SetActionToActionBuffer(action->GetCurClip());
	}

	for (auto& bullet : _bullets)
		bullet->Update();
}

void PlaneShoot::Render()
{
	_sprite->Render();
	_gun->Render();

	for (auto& bullet : _bullets)
		bullet->Render();
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
		(_actions[state]->GetRepeatType() == Action::LOOP || _actions[state]->GetRepeatType() == Action::PINGPONG))
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
		_pos.y += _speed * DELTA_TIME;
		SetAnimation(PlaneShoot::State::F_IDLE);
		return;
	}

	if (KEY_PRESS('S'))
	{
		_pos.y -= _speed * DELTA_TIME;
		SetAnimation(PlaneShoot::State::F_IDLE);
		return;
	}

	if (KEY_PRESS('A'))
	{
		_pos.x -= _speed * DELTA_TIME;
		SetAnimation(PlaneShoot::State::L_MOVE);
		return;
	}

	if (KEY_PRESS('D'))
	{
		_pos.x += _speed * DELTA_TIME;
		SetAnimation(PlaneShoot::State::R_MOVE);
		return;
	}

	SetIDLE();
}

void PlaneShoot::Fire()
{
	if (KEY_DOWN(VK_LBUTTON))
	{
		vector<shared_ptr<MainBullet>>::iterator iter = _bullets.begin();

		iter = std::find_if(_bullets.begin(), _bullets.end(), [](const shared_ptr<MainBullet> bullet) -> bool
			{
				if (bullet->_isActive == false)
					return true;

				return false;
			});

		if (iter == _bullets.end())
			return;

		shared_ptr<MainBullet> bullet = *iter;
		bullet->_isActive = true;
		bullet->GetTransform()->GetPos() = _gunParent->GetWorldPos();
		Vector2 dir = MOUSE_POS - _gunParent->GetWorldPos();
		dir.Normalize();
		bullet->SetDirection(dir);
	}
}

void PlaneShoot::SetGun()
{
	// Gun Angle
	Vector2 dir = MOUSE_POS - _gunParent->GetWorldPos();
	dir.Normalize();
	_gun->GetTransform()->GetAngle() = dir.Angle();
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