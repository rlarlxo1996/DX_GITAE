#pragma once
class Quad
{
public:
	Quad(wstring file, wstring vs = L"Shader/TextureVertexShader.hlsl", wstring ps = L"Shader/TexturePixelShader.hlsl");
	Quad(wstring file, Vector2 size, wstring vs = L"Shader/TextureVertexShader.hlsl", wstring ps = L"Shader/TexturePixelShader.hlsl");
	~Quad();

	virtual void Update();
	virtual void Render();
	void SetRender();

	virtual void CreateVertices();

	shared_ptr<Transform> GetTransform() { return _transform; }
	Vector2 GetSize();
	Vector2 GetHalfSize();

	void SetTexture(shared_ptr<Texture> texture) { _texture = texture; }

	Vector2 LeftBottom();
	Vector2 RightTop();

protected:
	Quad();

	shared_ptr<Transform> _transform;

	// Mesh
	vector<VertexUV> _vertices;
	vector<UINT> _indices;
	shared_ptr<VertexBuffer>	_vertexBuffer;
	shared_ptr<IndexBuffer>		_indexBuffer;

	// Material
	// Texture
	shared_ptr<Texture> _texture;
	shared_ptr<VertexShader>	_vertexShader;
	shared_ptr<PixelShader>		_pixelShader;

	Vector2 _size;
};

