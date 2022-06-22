#pragma once
class Bullet
{
public:
	Bullet();
	~Bullet();

	void Update();
	void Render();

	shared_ptr<Transform> GetTransform() { return _texture->GetTransform(); }

	void SetDirection(const Vector2& direction);

	bool _isActive = false;
private:
	shared_ptr<Texture> _texture;

	Vector2 _direction = { 0,0 };
	float _speed = 3000.0f;
	float _runTime = 0.0f;
	float _delayTime = 3.0f;
};

