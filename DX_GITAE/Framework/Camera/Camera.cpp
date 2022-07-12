#include "framework.h"
#include "Camera.h"

Camera* Camera::_instance = nullptr;

Camera::Camera()
{
	_transform = make_shared<Transform>();
	_projectionBuffer = make_shared<MatrixBuffer>();

	SetProjectionBuffer(2);


}

Camera::~Camera()
{
}

void Camera::Update()
{
	if (_target == nullptr)
		FreeMode();
	else
		FollowMode();

	Shake();

	_transform->UpdateWorld();
	_transform->SetBuffer(1);
}

void Camera::PostRender()
{
	ImGui::Text("Camera Info");
	ImGui::Text("CamX : %0.1f, CamY : %0.1f", _transform->GetPos().x, _transform->GetPos().y);
}

void Camera::ShakeStart(float magnitude, float duration, float reduceDamping)
{
	_magnitude = magnitude;
	_duration = duration;
	_reduceDamping = reduceDamping;

	_originPos = _transform->GetPos();
}

void Camera::SetViewPort(UINT width, UINT height)
{
	D3D11_VIEWPORT vp;
	vp.Width = width;
	vp.Height = height;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;
	DEVICE_CONTEXT->RSSetViewports(1, &vp);
}

void Camera::SetProjectionBuffer(UINT width, UINT height)
{
	XMMATRIX projectionM = XMMatrixOrthographicOffCenterLH(0, WIN_WIDTH, 0, WIN_HEIGHT, -1.0f, 1.0f);

	_projectionBuffer->Set(projectionM);

	_projectionBuffer->SetVSBuffer(2);
}

void Camera::Shake()
{
	if (_duration <= 0.0f)
		return;

	_duration -= DELTA_TIME;
	_magnitude -= DELTA_TIME * _reduceDamping;

	if (_magnitude <= 0.0f)
	{
		_magnitude = 0.0f;
		_duration = 0.0f;
	}

	Vector2 temp;

	// ������ ���� -magnitude ~ magnitude (�Ǽ�)
	// 0 ~ 1.0f
	// -1.0f ~ 1.0f
	// -magnitude ~ magnitude
	float zeroToOne = rand() / (float)RAND_MAX;
	float temp2 = zeroToOne * 2 - 1.0f;

	float zeroToOne2 = rand() / (float)RAND_MAX;
	float temp3 = zeroToOne2 * 2 - 1.0f;

	_transform->GetPos().x = _originPos.x + temp2 * _magnitude;
	_transform->GetPos().y = _originPos.y + temp3 * _magnitude;

	if (_duration <= 0.0f)
		_transform->GetPos() = _originPos;
}

void Camera::FreeMode()
{
	if (KEY_PRESS(VK_RBUTTON))
	{
		if (KEY_PRESS('W'))
			_transform->GetPos().y -= _speed * DELTA_TIME;

		if (KEY_PRESS('S'))
			_transform->GetPos().y += _speed * DELTA_TIME;

		if (KEY_PRESS('A'))
			_transform->GetPos().x += _speed * DELTA_TIME;

		if (KEY_PRESS('D'))
			_transform->GetPos().x -= _speed * DELTA_TIME;
	}
}

void Camera::FollowMode()
{
	Vector2 targetPos = _target->GetPos() - _offset;

	if (targetPos.x < _leftBottom.x)
		targetPos.x = _leftBottom.x;

	if (targetPos.x < _rightTop.x - WIN_WIDTH)
		targetPos.x = _rightTop.x - WIN_WIDTH;

	if (targetPos.y < _leftBottom.y)
		targetPos.y = _leftBottom.y;

	if (targetPos.y < _rightTop.y - WIN_HEIGHT)
		targetPos.y = _rightTop.y - WIN_HEIGHT;

	_transform->GetPos() = LERP(_transform->GetPos(), targetPos * -1, DELTA_TIME * _speed);
}

