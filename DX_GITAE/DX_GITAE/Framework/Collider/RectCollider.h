#pragma once
class RectCollider
{
public:
	struct ObbDesc
	{
		Vector2 _position;
		Vector2 _direction[2]; // 가로 세로
		float _length[2]; // 가로 세로
	};
	
	RectCollider(const Vector2& halfSize);
	~RectCollider();

	void CreateVertices();

	// 사각형 점
	// 사각형 사각형 (AABB)

	void Update();
	void Render();

	Vector2& GetPos() { return _transform->GetPos(); }
	float& GetAngle() { return _transform->GetAngle(); }
	shared_ptr<Transform> GetTransform() { return _transform; }


	float Left() { return _center._x - _halfSize._x; }
	float Top() { return _center._y - _halfSize._y; }
	float Right() { return _center._x + _halfSize._x; }
	float Bottom() { return _center._y + _halfSize._y; }

	void SetColorRed() { _colorBuffer->SetColor(RED); }
	void SetColorGreen() { _colorBuffer->SetColor(GREEN); }

	bool IsCollision(Vector2 pos);
	bool IsCollision(shared_ptr<RectCollider> rect, bool isObb = false);

	float SeparateAxis(Vector2 separate, Vector2 e1, Vector2 e2);

	bool IsOBB(shared_ptr<RectCollider> rect);
	bool IsAABB(shared_ptr<RectCollider> rect);

	ObbDesc GetOBB();

private:
	vector<VertexPos> _vertices;

	shared_ptr<VertexBuffer> _vertexBuffer;
	// color버퍼는 상수버퍼, world, view projection처럼 상수 정보들을 PS에 세팅할 용도
	shared_ptr<ColorBuffer> _colorBuffer;

	shared_ptr<PixelShader> _pixelShader;
	shared_ptr<VertexShader> _vertexShader;

	shared_ptr<Transform> _transform;
	shared_ptr<Transform> _parent;

	Vector2 _center = { 0,0 };
	Vector2 _halfSize = { 0,0 };
	bool _isCollision = false;
};

