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

	if (_isCollision)
		SetColorRed();
	else
		SetColorGreen();
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

bool RectCollider::IsCollision(shared_ptr<RectCollider> rect, bool isObb)
{
	if (isObb)
		return IsOBB(rect);
	else
		return IsAABB(rect);
}

float RectCollider::SeparateAxis(Vector2 separate, Vector2 e1, Vector2 e2)
{
	float r1 = abs(separate.Dot(e1));
	float r2 = abs(separate.Dot(e2));

	return r1 + r2;
}

bool RectCollider::IsOBB(shared_ptr<RectCollider> rect)
{
	ObbDesc obbA = GetOBB();
	ObbDesc obbB = rect->GetOBB();

	Vector2 distance = obbA._position - obbB._position;

	// n = Normal의 약자
	// e = Edge의 약자
	Vector2 nea1 = obbA._direction[0];
	Vector2 ea1 = nea1 * obbA._length[0];
	Vector2 nea2 = obbA._direction[1];
	Vector2 ea2 = nea2 * obbA._length[1];

	Vector2 neb1 = obbB._direction[0];
	Vector2 eb1 = neb1 * obbB._length[0];
	Vector2 neb2 = obbB._direction[1];
	Vector2 eb2 = neb2 * obbB._length[1];

	float lengthA = ea1.Length();
	float lengthB = SeparateAxis(nea1, eb1, eb2);
	float length = abs(nea1.Dot(distance));
	if (length > lengthA + lengthB)
		return _isCollision = false;

	lengthA = ea2.Length();
	lengthB = SeparateAxis(nea2, eb1, eb2);
	length = abs(nea2.Dot(distance));
	if (length > lengthA + lengthB)
		return _isCollision = false;

	lengthA = SeparateAxis(neb1, ea1, ea2);
	lengthB = eb1.Length();
	length = abs(neb1.Dot(distance));
	if (length > lengthA + lengthB)
		return _isCollision = false;

	lengthA = SeparateAxis(neb2, ea1, ea2);
	lengthB = eb2.Length();
	length = abs(neb2.Dot(distance));
	if (length > lengthA + lengthB)
		return _isCollision = false;

	return _isCollision = true;
}

bool RectCollider::IsAABB(shared_ptr<RectCollider> rect)
{
	// 사각 사각
	if (Right() < rect->Left())
		return _isCollision = false;
	if (Bottom() < rect->Top())
		return _isCollision = false;
	if (Left() > rect->Right())
		return _isCollision = false;
	if (Top() > rect->Bottom())
		return _isCollision = false;

	return _isCollision = true;
}

RectCollider::ObbDesc RectCollider::GetOBB()
{
	ObbDesc obbDesc;

	obbDesc._position = GetPos();

	obbDesc._length[0] = _halfSize._x;
	obbDesc._length[1] = _halfSize._y;

	XMFLOAT4X4 world;
	XMStoreFloat4x4(&world, *(_transform->GetMatrix()));

	obbDesc._direction[0] = { world._11, world._12 };
	obbDesc._direction[1] = { world._21, world._22 };

	obbDesc._direction[0].Normalize();
	obbDesc._direction[1].Normalize();

	return obbDesc;
}

bool RectCollider::IsCollision(Vector2 pos)
{
	if (pos._x < Left() || pos._x > Right())
		return _isCollision = false;
	if (pos._y > Top() || pos._y < Bottom())
		return _isCollision = false;
	return _isCollision = true;
}
