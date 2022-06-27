#include "framework.h"
#include "SolarSystemScene.h"

SolarSystemScene::SolarSystemScene()
{
	_sun = make_shared<Texture>(L"Resource/Sun.png");
	_earth = make_shared<Texture>(L"Resource/Earth.png");
	_moon = make_shared<Texture>(L"Resource/Moon.png");

	_sunOrbit = make_shared<Transform>();
	_earthOrbit = make_shared<Transform>();

	_earth->GetTransform()->SetParent(_sunOrbit);
	_earthOrbit->SetParent(_sunOrbit);
	_moon->GetTransform()->SetParent(_earthOrbit);

	_earth->GetTransform()->GetPos()._x += 200;
	_earthOrbit->GetPos() = _earth->GetTransform()->GetPos();
	_moon->GetTransform()->GetPos()._x += 160;

	_earth->GetTransform()->GetScale()._x *= 0.4;
	_earth->GetTransform()->GetScale()._y *= 0.4;
	_earthOrbit->GetScale() = _earth->GetTransform()->GetScale();

	_moon->GetTransform()->GetScale()._x *= 0.5;
	_moon->GetTransform()->GetScale()._y *= 0.5;
}

SolarSystemScene::~SolarSystemScene()
{
}

void SolarSystemScene::Update()
{
	// 1초에 업데이트를 1000번하는 컴퓨터
	// 1초에 업데이트를 10번하는 컴퓨터
	// DELTA TIME: 1번 진동하는데 걸리는 시간


	if (KEY_PRESS(VK_SPACE))
	{
		_sun->GetTransform()->GetAngle() += 0.5 * DELTA_TIME;
		_earth->GetTransform()->GetAngle() += 0.5 * DELTA_TIME;
		_moon->GetTransform()->GetAngle() += 0.5 * DELTA_TIME;

		_sunOrbit->GetAngle() += 2 * DELTA_TIME;
		_earthOrbit->GetAngle() += 3 * DELTA_TIME;

		_sun->GetTransform()->GetPos()._x = MOUSE_POS._x;
		_sun->GetTransform()->GetPos()._y = MOUSE_POS._y;

		_sunOrbit->GetPos() = _sun->GetTransform()->GetPos();
	}

	_sun->Update();
	_earth->Update();
	_moon->Update();

	_sunOrbit->UpdateWorld();
	_earthOrbit->UpdateWorld();
}

void SolarSystemScene::Render()
{
	_sun->Render();
	_earth->Render();
	_moon->Render();
}
