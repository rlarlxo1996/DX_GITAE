#pragma once
using namespace Microsoft::WRL;

class RenderTarget
{
public:
	RenderTarget(float width, float height);
	~RenderTarget();

	void Set();

	ComPtr<ID3D11ShaderResourceView> GetSRV() { return _srv; }
	ComPtr<ID3D11RenderTargetView> GetRTV() { return _rtv; }

private:
	ComPtr<ID3D11ShaderResourceView> _srv;
	ComPtr<ID3D11RenderTargetView> _rtv;
	ComPtr<ID3D11Texture2D> _rtvTexture;
};

