#pragma once
class RectCollider
{
public:
	struct ObbDesc
	{
		Vector2 _position;
		Vector2 _direction[2]; // ���� ����
		float _length[2]; // ���� ����
	};
	
	RectCollider(const Vector2& halfSize);
	~RectCollider();

	void CreateVertices();

	void Update();
	void Render();

	Vector2& GetPos() { return _transform->GetPos(); }
	const Vector2& GetWorldPos() { return _transform->GetWorldPos(); }
	float& GetAngle() { return _transform->GetAngle(); }
	shared_ptr<Transform> GetTransform() { return _transform; }

	void SetColorRed() { _colorBuffer->SetColor(RED); }
	void SetColorGreen() { _colorBuffer->SetColor(GREEN); }

	float Top() { return GetWorldPos()._y + _halfSize._y * _transform->GetScale()._y; }
	float Bottom() { return GetWorldPos()._y - _halfSize._y * _transform->GetScale()._y; }
	float Right() { return GetWorldPos()._x + _halfSize._x * _transform->GetScale()._x; }
	float Left() { return GetWorldPos()._x - _halfSize._x * _transform->GetScale()._x; }


	bool IsCollision(Vector2 pos);
	bool IsCollision(shared_ptr<RectCollider> rect, bool isObb = false);
	bool IsCollision(shared_ptr<class CircleCollider> circle, bool isObb = false);

	float SeparateAxis(Vector2 separate, Vector2 e1, Vector2 e2);

	bool IsOBB(shared_ptr<RectCollider> rect);
	bool IsAABB(shared_ptr<RectCollider> rect);

	bool IsOBB(shared_ptr<class CircleCollider> circle);
	bool IsAABB(shared_ptr<class CircleCollider> circle);

	ObbDesc GetOBB();

private:
	vector<VertexPos> _vertices;

	shared_ptr<VertexBuffer> _vertexBuffer;
	// color���۴� �������, world, view projectionó�� ��� �������� PS�� ������ �뵵
	shared_ptr<ColorBuffer> _colorBuffer;

	shared_ptr<PixelShader> _pixelShader;
	shared_ptr<VertexShader> _vertexShader;

	shared_ptr<Transform> _transform;
	shared_ptr<Transform> _parent;

	Vector2 _halfSize = { 0,0 };
};

