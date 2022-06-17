#pragma once

class MatrixBuffer : public ConstantBuffer
{
	struct Data
	{
		XMMATRIX _matrix;
	};
public:
	MatrixBuffer()
	: ConstantBuffer(&_data, sizeof(Data))
	{
		_data._matrix = XMMatrixIdentity();
	}

	void Set(XMMATRIX value)
	{
		_data._matrix = XMMatrixTranspose(value);
	}

private:
	Data _data;
};