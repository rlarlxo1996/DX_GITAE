#include "framework.h"
#include "Collider.h"

Collider::Collider()
{
}

Collider::~Collider()
{
	_parent = nullptr;
}

void Collider::CreateData()
{
	_colorBuffer = make_shared<ColorBuffer>();
	_colorBuffer->SetColor(XMFLOAT4(0, 1, 0, 1));

	_pixelShader = make_shared<PixelShader>(L"Shader/ColliderShader/ColliderPixelShader.hlsl");
	_vertexShader = make_shared<VertexShader>(L"Shader/ColliderShader/ColliderVertexShader.hlsl");

	_transform = make_shared<Transform>();
	_parent = nullptr;
}

void Collider::Update()
{
	_transform->UpdateWorld();
}

void Collider::Render()
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

bool Collider::IsCollision(shared_ptr<Collider> col, bool isObb)
{
	switch (col->_type)
	{
	case Collider::Type::DEFAULT:
		break;
	case Collider::Type::CIRCLE:
	{
		shared_ptr<CircleCollider> circle = dynamic_pointer_cast<CircleCollider>(col);
		return IsCollision(circle, isObb);
	}
		break;
	case Collider::Type::RECT:
	{
		shared_ptr<RectCollider> rect = dynamic_pointer_cast<RectCollider>(col);
		return IsCollision(rect, isObb);
	}
		break;
	default:
		break;
	}
    return false;
}
