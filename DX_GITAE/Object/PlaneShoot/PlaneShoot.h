#pragma once
class PlaneShoot
{
public:
	enum State
	{
		F_IDLE,

		L_MOVE,
		R_MOVE
	};

	PlaneShoot();
	~PlaneShoot();

	void Update();
	void Render();
	void PostRender();

	void CreateActions();

	shared_ptr<Transform> GetTransform() { return _sprite->GetTransform(); }

	void SetPosition(Vector2 pos) { _sprite->GetTransform()->GetPos() = pos; }
	void SetAnimation(PlaneShoot::State state);

	void KeyBoardMove();

private:
	shared_ptr<Sprite> _sprite;
	vector<shared_ptr<Action>> _actions;
	shared_ptr<Collider> _collider;
};

