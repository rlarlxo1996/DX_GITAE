#pragma once
class Monster
{
public:
	Monster();
	~Monster();

	void Update();
	void Render();

	shared_ptr<Transform> GetTransform() { return _quad->GetTransform(); }
	shared_ptr<Collider> GetCollider() { return _col; }

private:
	shared_ptr<Quad> _quad;
	shared_ptr<Collider> _col;
};

