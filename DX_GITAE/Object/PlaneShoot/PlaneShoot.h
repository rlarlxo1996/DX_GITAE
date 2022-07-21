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

	void SetIDLE();
	void KeyBoardMove();
	void Fire();
	void SetGun();

	vector<shared_ptr<class MainBullet>>& GetMainBullet() { return _bullets; }
	shared_ptr<Collider> GetCollider() { return _collider; }

	Vector2 _pos = Vector2();
private:
	shared_ptr<Sprite> _sprite;
	vector<shared_ptr<Action>> _actions;
	shared_ptr<Collider> _collider;

	State _state = State::F_IDLE;

	vector<shared_ptr<class MainBullet>> _bullets;
	shared_ptr<Transform> _gunParent;
	shared_ptr<class Gun> _gun;
	UINT _poolCount = 30;

	float _speed = 350.0f;
};

