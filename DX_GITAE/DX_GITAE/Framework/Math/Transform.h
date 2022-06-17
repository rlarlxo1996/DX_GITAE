#pragma once
class MatrixBuffer;

class Transform
{
public:
	Transform();
	~Transform();

	void UpdateWorld();
	void SetWorldBuffer(UINT slot);

	XMMATRIX* GetMatrix() { return &_srtMatrix; }
	XMMATRIX* GetSMatrix() { return &_scaleM; }
	XMMATRIX* GetRMatrix() { return &_rotationM; }
	XMMATRIX* GetTMatrix() { return &_translateM; }

	XMFLOAT2& GetScale() { return _scale; }
	float& GetAngle() { return _angle; }
	XMFLOAT2& GetPos() { return _pos; }

	void SetParent(XMMATRIX* matrix) { _parentMatrix = matrix; }
	void SeparateParent() { _parentMatrix = nullptr; }

private:
	XMFLOAT2 _scale = { 1.0f,1.0f };
	float _angle = { 0.0f };
	XMFLOAT2 _pos = { 0.0f, 0.0f };

	XMMATRIX _scaleM = XMMatrixIdentity();
	XMMATRIX _rotationM = XMMatrixIdentity();
	XMMATRIX _translateM = XMMatrixIdentity();

	XMMATRIX _srtMatrix = XMMatrixIdentity();
	shared_ptr<MatrixBuffer> _worldBuffer;

	XMMATRIX* _parentMatrix = nullptr;
};

