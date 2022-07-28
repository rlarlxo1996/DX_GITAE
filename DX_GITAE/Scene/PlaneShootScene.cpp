#include "framework.h"
#include "PlaneShootScene.h"

PlaneShootScene::PlaneShootScene()
{
	_worldMap = make_shared<Quad>(L"Resource/Carina_Nebula.png");
	//_worldMap->GetTransform()->GetPos().x += _worldMap->GetHalfSize().x;
	//_worldMap->GetTransform()->GetPos().y += _worldMap->GetHalfSize().y;

	_planeShoot = make_shared<PlaneShoot>();

	_planeFollow = make_shared<Transform>();
	_planeFollow->GetPos() = _planeShoot->GetTransform()->GetPos();

	_aim = make_shared<Aim>();

	Camera::GetInstance()->SetTarget(_planeFollow);
	Camera::GetInstance()->SetLeftBottom({ -_worldMap->GetHalfSize().x, -_worldMap->GetHalfSize().y});
	Camera::GetInstance()->SetRightTop({ _worldMap->GetHalfSize().x, _worldMap->GetHalfSize().y });
}

PlaneShootScene::~PlaneShootScene()
{
}

void PlaneShootScene::Update()
{
	_worldMap->Update();
	_planeShoot->Update();

	_aim->Update();

	float distance = _planeShoot->GetTransform()->GetPos().Distance(_planeFollow->GetPos());

	if (distance >= 10.0f)
		_planeFollow->GetPos() = LERP(_planeFollow->GetPos(), _planeShoot->GetTransform()->GetPos(), DELTA_TIME * 5);
}

void PlaneShootScene::Render()
{
	_worldMap->Render();
	_planeShoot->Render();
	_aim->Render();
}

void PlaneShootScene::PostRender()
{
}
