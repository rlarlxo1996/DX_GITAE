#pragma once
class Bullet
{
public:
	Bullet();
	~Bullet();

	void Update();
	void Render();

	shared_ptr<Transform> GetTransform() { return _quad->GetTransform(); }
	shared_ptr<Collider>& GetCollider() { return _col; }

	void SetDirection(const Vector2& direction);

	bool _isActive = false;
private:
	shared_ptr<Quad> _quad;
	shared_ptr<Collider> _col;

	Vector2 _direction = { 0,0 };
	float _speed = 500.0f;
	float _runTime = 0.0f;
	float _delayTime = 3.0f;
};

