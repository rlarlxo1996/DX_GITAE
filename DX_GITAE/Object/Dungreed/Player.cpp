#include "framework.h"
#include "Player.h"

Player::Player()
{
	_quad = make_shared<Quad>(L"Resource/Player.png");
	_quad->GetTransform()->GetScale() = { 0.7f, 0.7f };
	_quad->GetTransform()->GetPos() = { 100,100 };

	// Gun Setting
	_gunParent = make_shared<Transform>();
	_gunParent->SetParent(_quad->GetTransform());
	_gunParent->GetPos().x = 80.0f;

	_gun = make_shared<Gun>();
	_gun->SetPlayer(_gunParent);

	// Bullets
	for (int i = 0; i < _poolCount; i++)
	{
		shared_ptr<Bullet> bullet = make_shared<Bullet>();
		bullet->_isActive = false;

		_bullets.emplace_back(bullet);
	}

	_col = make_shared<RectCollider>(_quad->GetHalfSize());
	_col->SetParent(_quad->GetTransform());
}

Player::~Player()
{
}

void Player::Update()
{
	Move();
	SetGun();
	Fire();
	Jump();

	_quad->Update();
	_gunParent->UpdateWorld();
	_gun->Update();
	_col->Update();

	for(auto& bullet : _bullets)
		bullet->Update();
}

void Player::Render()
{
	_quad->Render();
	_gun->Render();
	_col->Render();

	for(auto& bullet : _bullets)
		bullet->Render();
}

void Player::Move()
{
	if (KEY_PRESS('W'))
	{
		_quad->GetTransform()->GetPos().y += _speed * DELTA_TIME;
	}
	if (KEY_PRESS('A'))
	{
		_quad->GetTransform()->GetPos().x -= _speed * DELTA_TIME;
	}
	if (KEY_PRESS('S'))
	{
		_quad->GetTransform()->GetPos().y -= _speed * DELTA_TIME;
	}
	if (KEY_PRESS('D'))
	{
		_quad->GetTransform()->GetPos().x += _speed * DELTA_TIME;
	}
	if (KEY_PRESS(VK_SPACE) && (_state == GROUND || _state == JUMPING_CHARGE))
	{
		_jumpPower += 1000.0f * DELTA_TIME;
		_state = JUMPING_CHARGE;
	}
	if (KEY_UP(VK_SPACE) && _state == JUMPING_CHARGE)
	{
		_state = JUMPING;
	}
}

void Player::SetGun()
{
	// Gun Angle
	Vector2 dir = MOUSE_POS - _gunParent->GetWorldPos();
	dir.Normalize();
	_gun->GetTransform()->GetAngle() = dir.Angle();
}

void Player::Fire()
{
	if (KEY_DOWN(VK_LBUTTON))
	{
		//for (auto& bullet : _bullets)
		//{
		//	if (bullet->_isActive == false)
		//	{
		//		bullet->_isActive = true;
		//		bullet->GetTransform()->GetPos() = _gunParent->GetWorldPos();
		//		Vector2 dir = MOUSE_POS - _gunParent->GetWorldPos();
		//		dir.Normalize();
		//		bullet->SetDirection(dir);
		//		break;
		//	}
		//}

		// 람다
		vector<shared_ptr<Bullet>>::iterator iter = _bullets.begin();

		iter = std::find_if(_bullets.begin(), _bullets.end(), [](const shared_ptr<Bullet> bullet) -> bool
			{
				if (bullet->_isActive == false)
					return true;

				return false;
			});

		if (iter == _bullets.end())
			return;

		shared_ptr<Bullet> bullet = *iter;
		bullet->_isActive = true;
		bullet->GetTransform()->GetPos() = _gunParent->GetWorldPos();
		Vector2 dir = MOUSE_POS - _gunParent->GetWorldPos();
		dir.Normalize();
		bullet->SetDirection(dir);
	}
}

void Player::Jump()
{
	if (_state != JUMPING)
		return;

	Vector2 temp;
	temp.y += _jumpPower * DELTA_TIME;

	_quad->GetTransform()->GetPos() += temp;
	_jumpPower -= _gravity * DELTA_TIME;

	// Ground 조건
	if (_quad->GetTransform()->GetPos().y < 0)
	{
		_state = GROUND;
		_jumpPower = 150.0f;
	}
}
