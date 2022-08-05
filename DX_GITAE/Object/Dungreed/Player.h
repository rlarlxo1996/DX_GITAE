#pragma once
class Player
{
public:
	enum State
	{
		GROUND,
		JUMPING,
		ATTACK,
		JUMPING_CHARGE
	};

	Player();
	~Player();

	void Update();
	void Render();

	void Move();
	void SetGun();
	void Fire();
	void Jump();

	shared_ptr<Transform> GetTransform() { return _quad->GetTransform(); }
	vector<shared_ptr<class Bullet>>& GetBullet() { return _bullets; }
	shared_ptr<Collider> GetCollider() { return _col; }

private:
	shared_ptr<Quad> _quad;
	shared_ptr<Collider> _col;
	
	shared_ptr<Transform> _gunParent;
	shared_ptr<class Gun> _gun;

	vector<shared_ptr<class Bullet>> _bullets;
	UINT _poolCount = 30;

	float _speed = 150.0f;

	float _jumpPower = 300.0f;
	float _gravity = 150.0f;
	State _state = GROUND;
};

