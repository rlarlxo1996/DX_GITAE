#include "framework.h"
#include "RectCollider.h"

RectCollider::RectCollider(const Vector2& halfSize)
: _halfSize(halfSize)
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

RectCollider::~RectCollider()
{
	_parent = nullptr;
}

void RectCollider::CreateVertices()
{
	VertexPos v;
	// 왼쪽 위
	v.pos = { -_halfSize._x, _halfSize._y, 0 };
	_vertices.push_back(v);

	// 오른쪽 위
	v.pos = { _halfSize._x, _halfSize._y, 0 };
	_vertices.push_back(v);

	// 오른쪽 아래
	v.pos = { _halfSize._x, -_halfSize._y, 0 };
	_vertices.push_back(v);

	// 왼쪽 아래
	v.pos = { -_halfSize._x, -_halfSize._y, 0 };
	_vertices.push_back(v);

	// 왼쪽 위
	v.pos = { -_halfSize._x, _halfSize._y, 0 };
	_vertices.push_back(v);

	_vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(VertexPos), _vertices.size());
}

void RectCollider::Update()
{
	_center = GetPos();

	_transform->UpdateWorld();
}

void RectCollider::Render()
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

bool RectCollider::IsCollision(shared_ptr<RectCollider> col)
{
	// 사각 사각
	if (Right() < col->Left())
		return false;
	if (Bottom() < col->Top())
		return false;
	if (Left() > col->Right())
		return false;
	if (Top() > col->Bottom())
		return false;
	return true;
}
