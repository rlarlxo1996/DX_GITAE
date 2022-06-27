#pragma once
class Gun
{
public:
	Gun();
	~Gun();

	void Update();
	void Render();

	shared_ptr<Transform> GetTransform() { return _texture->GetTransform(); }
	void SetPlayer(shared_ptr<Transform> transform) { _texture->GetTransform()->SetParent(transform); }

private:
	shared_ptr<Texture> _texture;
	shared_ptr<class Bullet> _bullet;
};

