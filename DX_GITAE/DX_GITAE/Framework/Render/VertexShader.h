#pragma once
class VertexShader
{
public:
	VertexShader(std::wstring file);
	~VertexShader();

	void CreateBlob(std::wstring file);
	void CreateInputLayout();
	void CreateVertexShader();

	void SetIAInputLayOut();
	void SetVertexShader();

private:
	Microsoft::WRL::ComPtr<ID3D11InputLayout>	_inputLayout; // � �������� �˷��ִ� ����
	Microsoft::WRL::ComPtr<ID3D11VertexShader>	_vertexShader; // ���� �������� WVP -> 3D�� �ִ� ���� 2D �ű�� �۾�
	Microsoft::WRL::ComPtr<ID3DBlob>			_vertexBlob;
};

