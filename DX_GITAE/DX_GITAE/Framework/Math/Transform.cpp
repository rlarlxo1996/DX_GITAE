#include "framework.h"
#include "Transform.h"

Transform::Transform()
{
	_worldBuffer = make_shared<MatrixBuffer>();
}

Transform::~Transform()
{
}

void Transform::UpdateWorld()
{
    // SRT Matrix ¼³Á¤
    _scaleM = XMMatrixScaling(_scale._x, _scale._y, 0);
    _rotationM = XMMatrixRotationZ(_angle);
    _translateM = XMMatrixTranslation(_pos._x, _pos._y, 0);

    _srtMatrix = _scaleM * _rotationM * _translateM;

    if (_parentMatrix != nullptr)
    {
        _srtMatrix *= (*_parentMatrix);
    }

    _worldBuffer->Set(_srtMatrix);
    _worldBuffer->Update();
}

void Transform::SetWorldBuffer(UINT slot)
{
    _worldBuffer->SetVSBuffer(slot);
}

const Vector2& Transform::GetWorldPos()
{
    XMFLOAT4X4 matrix;
    XMStoreFloat4x4(&matrix, _srtMatrix);

    return Vector2(matrix._41, matrix._42);
}
