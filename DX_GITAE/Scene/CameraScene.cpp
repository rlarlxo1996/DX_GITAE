#include "framework.h"
#include "CameraScene.h"

CameraScene::CameraScene()
{
	_backGround = make_shared<Quad>(L"Resource/Carina_Nebula.png");
	_backGround->GetTransform()->GetPos().x += _backGround->GetHalfSize().x;
	_backGround->GetTransform()->GetPos().y += _backGround->GetHalfSize().y;

	_zelda = make_shared<Zelda>();
	Load();

	_zeladFollow = make_shared<Transform>();
	_zeladFollow->GetPos() = _zelda->GetTransform()->GetPos();

	Camera::GetInstance()->SetTarget(_zeladFollow);
	Camera::GetInstance()->SetLeftBottom({ 0, 0 });
	Camera::GetInstance()->SetRightTop({ _backGround->GetSize().x, _backGround->GetSize().y });

	_button = make_shared<Button>();
	_button->SetPosition({ CENTER.x, CENTER.y - 200 });
	_button->SetScale(Vector2(0.1f, 0.1f));
	_button->SetText("Save");

	_button->SetEvent(std::bind(&CameraScene::Save, this));

	Vector2 miniMapSize = _backGround->GetSize() * 0.1f;
	_miniMap = make_shared<MiniMap>(miniMapSize);
	_miniMap->SetPos({ WIN_WIDTH - miniMapSize.x * 0.5f - 20.0f, WIN_HEIGHT - miniMapSize.y * 0.5f - 20.0f });
	_miniMap->SetBackGround({ 0,0 }, _backGround->GetSize());
	_miniMap->SetPlayerPos(&_zelda->GetTransform()->GetPos());
}

CameraScene::~CameraScene()
{
}

void CameraScene::Update()
{
	_backGround->Update();

	_zelda->Update();

	float distance = _zelda->GetTransform()->GetPos().Distance(_zeladFollow->GetPos());

	if (distance >= 10.0f)
		_zeladFollow->GetPos() = LERP(_zeladFollow->GetPos(), _zelda->GetTransform()->GetPos(), DELTA_TIME * 5);

	_button->Update();
	_miniMap->Update();
}

void CameraScene::PreRender()
{
	_miniMap->SetRTV();
}

void CameraScene::Render()
{
	_backGround->Render();
	_zelda->Render();
}

void CameraScene::PostRender()
{
	_button->PostRender();
	_miniMap->PostRender();
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

