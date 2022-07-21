#include "framework.h"
#include "MainBullet.h"

MainBullet::MainBullet()
{
	_quad = make_shared<Quad>(L"Resource/Bullet.png");
	_quad->GetTransform()->GetScale() = { 0.1f,0.1f };

	_col = make_shared<CircleCollider>(_quad->GetSize().x);
	_col->SetParent(_quad->GetTransform());
}

MainBullet::~MainBullet()
{
}

void MainBullet::Update()
{
	if (_isActive == false)
		return;

	_runTime += DELTA_TIME;

	if (_runTime > _delayTime)
	{
		_runTime = 0.0f;
		_isActive = false;
	}

	_direction.Normalize();
	_quad->GetTransform()->GetPos() += _direction * _speed * DELTA_TIME;

	_quad->Update();
	_col->Update();
}

void MainBullet::Render()
{
	if (_isActive == false)
		return;

	_quad->Render();
	_col->Render();
}

void MainBullet::SetDirection(const Vector2& direction)
{
	_direction = direction;
	_quad->GetTransform()->GetAngle() = _direction.Angle();
}
