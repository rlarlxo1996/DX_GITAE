#pragma once
class RectCollider : public Collider
{
public:
	struct ObbDesc
	{
		Vector2 _position;
		Vector2 _direction[2]; // 가로 세로
		float _length[2]; // 가로 세로
	};
	
	RectCollider(const Vector2& halfSize);
	virtual ~RectCollider();

	void CreateVertices();

	virtual void Update() override;
	virtual void Render() override;

	float Top() { return GetWorldPos()._y + _halfSize._y * _transform->GetScale()._y; }
	float Bottom() { return GetWorldPos()._y - _halfSize._y * _transform->GetScale()._y; }
	float Right() { return GetWorldPos()._x + _halfSize._x * _transform->GetScale()._x; }
	float Left() { return GetWorldPos()._x - _halfSize._x * _transform->GetScale()._x; }


	virtual bool IsCollision(const Vector2& pos) override;
	virtual bool IsCollision(shared_ptr<class RectCollider> rect, bool isObb = false) override;
	virtual bool IsCollision(shared_ptr <class CircleCollider> circle, bool isObb = false) override;

	float SeparateAxis(Vector2 separate, Vector2 e1, Vector2 e2);

	bool IsOBB(shared_ptr<RectCollider> rect);
	bool IsAABB(shared_ptr<RectCollider> rect);

	bool IsOBB(shared_ptr<class CircleCollider> circle);
	bool IsAABB(shared_ptr<class CircleCollider> circle);

	ObbDesc GetOBB();

private:
	Vector2 _halfSize = { 0,0 };
};

