#pragma once
class MiniMap
{
public:
	MiniMap(Vector2 size);
	~MiniMap();

	void Update();
	void SetRTV();
	void PostRender();

	void SetPos(Vector2 pos) { _rtvQuad->GetTransform()->GetPos() = pos; }
	void SetBackGround(Vector2 leftBottom, Vector2 rightTop) { _leftBottom = leftBottom; _rightTop = rightTop; }
	void SetPlayerPos(Vector2* playerPos) { _playerPos = playerPos; }

private:
	shared_ptr<RenderTarget> _rtv;
	shared_ptr<Quad> _rtvQuad;
	shared_ptr<Quad> _miniPlayer;

	Vector2 _leftBottom;
	Vector2 _rightTop;
	Vector2* _playerPos;
};

