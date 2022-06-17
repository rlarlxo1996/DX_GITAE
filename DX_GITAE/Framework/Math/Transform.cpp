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
    _scaleM = XMMatrixScaling(_scale.x, _scale.y, 0);
    _rotationM = XMMatrixRotationZ(_angle);
    _translateM = XMMatrixTranslation(_pos.x, _pos.y, 0);

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
