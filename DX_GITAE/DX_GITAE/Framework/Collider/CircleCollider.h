#pragma once
class CircleCollider
{
public:
	CircleCollider(const float& radius);
	~CircleCollider();

	void CreateVertices();

	void Update();
	void Render();

	Vector2& GetPos() { return _transform->GetPos(); }
	const Vector2& GetWorldPos() { return _transform->GetWorldPos(); }
	float& GetAngle() { return _transform->GetAngle(); }
	shared_ptr<Transform> GetTransform() { return _transform; }

	float GetRadius() { return _radius * _transform->GetScale()._x; }

	void SetColorRed() { _colorBuffer->SetColor(RED); }
	void SetColorGreen() { _colorBuffer->SetColor(GREEN); }

	bool IsCollision(Vector2 pos);
	bool IsCollision(shared_ptr <CircleCollider> other);
	bool IsCollision(shared_ptr<class RectCollider> rect, bool isObb = false);

private:
	vector<VertexPos> _vertices;

	shared_ptr<VertexBuffer> _vertexBuffer;
	shared_ptr<ColorBuffer> _colorBuffer;

	shared_ptr<PixelShader> _pixelShader;
	shared_ptr<VertexShader> _vertexShader;

	shared_ptr<Transform> _transform;
	shared_ptr<Transform> _parent;

	float _radius = 0;
};

