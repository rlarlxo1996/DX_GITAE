#pragma once
class Boss
{
public:
	Boss();
	~Boss();

	void Update();
	void Render();

	shared_ptr<Transform> GetTransform() { return _texture->GetTransform(); }
	shared_ptr<Collider> GetCollider() { return _col; }

	bool _isActive = true;
	int hp = 5;
private:
	shared_ptr<Texture> _texture;
	shared_ptr<Collider> _col;

};

