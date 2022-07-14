#include "framework.h"
#include "CameraScene.h"

CameraScene::CameraScene()
{
	_backGround = make_shared<Quad>(L"Resource/Carina_Nebula.png");

	_zelda = make_shared<Zelda>();
	Load();

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

void CameraScene::PostRender()
{
	if (ImGui::Button("Save", { 100, 100 }))
	{
		Save();
	}
}

void CameraScene::Save()
{
	BinaryWriter writer(L"Save/ZeldaPos.zelda");

	vector<float> posDataes;

	posDataes.push_back(_zelda->GetTransform()->GetPos().x);
	posDataes.push_back(_zelda->GetTransform()->GetPos().y);

	writer.Uint(posDataes.size());
	writer.Byte(posDataes.data(), posDataes.size() * sizeof(float));
}

void CameraScene::Load()
{
	BinaryReader reader(L"Save/ZeldaPos.zelda");

	UINT size = reader.Uint();

	vector<float> posDataes;
	posDataes.resize(2);
	void* ptr = posDataes.data();
	reader.Byte(&ptr, size * sizeof(float));

	_zelda->GetTransform()->GetPos().x = posDataes[0];
	_zelda->GetTransform()->GetPos().y = posDataes[1];

	_zelda->_pos = { posDataes[0], posDataes[1] };
}
