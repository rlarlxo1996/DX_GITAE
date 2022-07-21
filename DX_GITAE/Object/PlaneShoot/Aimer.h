#pragma once
class Aimer
{
public:
	Aimer();
	~Aimer();

	void Update();
	void Render();

	shared_ptr<Transform> GetTransform() { return _quad->GetTransform(); }
	void SetPlayer(shared_ptr<Transform> transform) { _quad->GetTransform()->SetParent(transform); }

private:
	shared_ptr<Quad> _quad;
	shared_ptr<class Bullet> _bullet;
};

