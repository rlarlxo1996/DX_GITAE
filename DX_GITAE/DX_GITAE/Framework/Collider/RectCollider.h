#pragma once
class RectCollider
{
public:
	RectCollider(const Vector2& halfSize);
	~RectCollider();

	void CreateVertices();

	// �簢�� ��
	// �簢�� �簢�� (AABB)

	void Update();
	void Render();

	Vector2& GetPos() { return _transform->GetPos(); }
	Vector2& GetHalfSize() { return _halfSize; }

	float Left() { return _center._x - _halfSize._x; }
	float Top() { return _center._y - _halfSize._y; }
	float Right() { return _center._x + _halfSize._x; }
	float Bottom() { return _center._y + _halfSize._y; }

	bool IsCollision(shared_ptr<RectCollider> col);

	void SetColorRed() { _colorBuffer->SetColor(RED); }
	void SetColorGreen() { _colorBuffer->SetColor(GREEN); }

private:
	vector<VertexPos> _vertices;

	shared_ptr<VertexBuffer> _vertexBuffer;
	// color���۴� �������, world, view projectionó�� ��� �������� PS�� ������ �뵵
	shared_ptr<ColorBuffer> _colorBuffer;

	shared_ptr<PixelShader> _pixelShader;
	shared_ptr<VertexShader> _vertexShader;

	shared_ptr<Transform> _transform;
	shared_ptr<Transform> _parent;

	Vector2 _center = { 0,0 };
	Vector2 _halfSize = { 0,0 };
};

