#include "framework.h"
#include "CameraScene.h"

CameraScene::CameraScene()
{
	_backGround = make_shared<Quad>(L"Resource/Carina_Nebula.png");

	_zelda = make_shared<Zelda>();

	_zeldaFollow = make_shared<Transform>();
	_zeldaFollow->GetPos() = _zelda->GetTransform()->GetPos();

	Camera::GetInstance()->SetTarget(_zeldaFollow);
	Camera::GetInstance()->SetLeftBottom({ -_backGround->GetHalfSize().x, -_backGround->GetHalfSize().y });
	Camera::GetInstance()->SetRightTop({ _backGround->GetHalfSize().x, _backGround->GetHalfSize().y });
}

CameraScene::~CameraScene()
{
}

void CameraScene::Update()
{
	_backGround->Update();

	_zelda->Update();

	float distance = _zelda->GetTransform()->GetPos().Distance(_zeldaFollow->GetPos());

	if (distance >= 10.0f)
		_zeldaFollow->GetPos() = LERP(_zeldaFollow->GetPos(), _zelda->GetTransform()->GetPos(), DELTA_TIME * 5);
}

void CameraScene::Render()
{
	_backGround->Render();

	_zelda->Render();
}
