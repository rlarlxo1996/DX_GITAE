#pragma once
class PixelShader
{
public:
	PixelShader(std::wstring file);
	~PixelShader();

	void CreatePixelblob(std::wstring file);
	void CreatePixelShader();

	void SetPixelShader();

private:
	Microsoft::WRL::ComPtr<ID3D11PixelShader> _pixelShader;
	Microsoft::WRL::ComPtr<ID3DBlob> _pixelblob;
};

