#include "framework.h"
#include "MiniMap.h"

MiniMap::MiniMap(Vector2 size)
{
	_rtv = make_shared<RenderTarget>(size.x, size.y);

	_rtvQuad = make_shared<Quad>(L"RenderTarget", size);
	shared_ptr<Texture> texture = Texture::Add(L"Target", _rtv->GetSRV());
	_rtvQuad->SetTexture(texture);
	_rtvQuad->GetTransform()->GetPos() = CENTER;

	_miniPlayer = make_shared<Quad>(L"Resource/Player.png");
	_miniPlayer->GetTransform()->GetScale() *= 0.3f;
}

MiniMap::~MiniMap()
{
}

void MiniMap::Update()
{
	_rtvQuad->Update();
	_miniPlayer->Update();

	assert(_playerPos != nullptr);

	float backGroundX = _rightTop.x - _leftBottom.x;
	float backGroundY = _rightTop.y - _leftBottom.y;

	Vector2 ratio;
	ratio.x = _playerPos->x / backGroundX;
	ratio.y = _playerPos->y / backGroundY;

	_miniPlayer->GetTransform()->GetPos().x = _rtvQuad->LeftBottom().x + ratio.x * _rtvQuad->GetSize().x;
	_miniPlayer->GetTransform()->GetPos().y = _rtvQuad->LeftBottom().y + ratio.y * _rtvQuad->GetSize().y;
}

void MiniMap::SetRTV()
{
	_rtv->Set();
}

void MiniMap::PostRender()
{
	_rtvQuad->Render();
	_miniPlayer->Render();
}
