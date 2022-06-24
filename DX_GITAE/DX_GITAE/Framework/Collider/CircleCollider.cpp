#include "framework.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider(const float& radius)
: _radius(radius)
{
	_vertices.reserve(5);

	CreateVertices();

	_colorBuffer = make_shared<ColorBuffer>();
	_colorBuffer->SetColor(XMFLOAT4(0, 1, 0, 1));

	_pixelShader = make_shared<PixelShader>(L"Shader/ColliderShader/ColliderPixelShader.hlsl");
	_vertexShader = make_shared<VertexShader>(L"Shader/ColliderShader/ColliderVertexShader.hlsl");

	_transform = make_shared<Transform>();
	_parent = nullptr;
}

CircleCollider::~CircleCollider()
{
}

void CircleCollider::CreateVertices()
{
	VertexPos v;

	float theta = 2 * PI / 36;

	for (int i = 0; i < 37; i++)
	{
		v.pos.x = cosf(theta * i) * _radius;
		v.pos.y = sinf(theta * i) * _radius;
		v.pos.z = 0;
		_vertices.push_back(v);
	}
	_vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(VertexPos), _vertices.size());
}

void CircleCollider::Update()
{
	_transform->UpdateWorld();
}

void CircleCollider::Render()
{
	_transform->SetWorldBuffer(0);

	_vertexBuffer->IASetVertexBuffer(0);

	_colorBuffer->Update();
	_colorBuffer->SetPSBuffer(0);

	DEVICE_CONTEXT->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);

	_vertexShader->SetIAInputLayOut();
	_vertexShader->SetVertexShader();

	_pixelShader->SetPixelShader();

	DEVICE_CONTEXT->Draw(_vertices.size(), 0);
}

bool CircleCollider::IsCollision(Vector2 pos)
{
	return (pos - GetWorldPos()).Length() < GetRadius();
}

bool CircleCollider::IsCollision(shared_ptr<CircleCollider> other)
{
	Vector2 otherPos = other->GetWorldPos();
	Vector2 mine = GetWorldPos();

	Vector2 thisToOther = otherPos - mine;
	float radius = GetRadius();
	float radiusOther = other->GetRadius();

	return thisToOther.Length() < (radius + radiusOther);
}

bool CircleCollider::IsCollision(shared_ptr<RectCollider> rect, bool isObb)
{
	return rect->IsCollision(make_shared<CircleCollider>(*this), isObb);
}
