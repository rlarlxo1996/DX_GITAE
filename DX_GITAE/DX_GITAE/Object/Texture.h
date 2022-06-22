#pragma once
class Texture
{
public:
	Texture(wstring file);
	~Texture();

	void Update();
	void Render();

	void CreateVertices();

	shared_ptr<Transform> GetTransform() { return _transform; }

private:
	shared_ptr<Transform> _transform;

	vector<VertexUV> _vertices;
	vector<UINT> _indices;

	shared_ptr<VertexBuffer>	_vertexBuffer;
	shared_ptr<IndexBuffer>		_indexBuffer;

	shared_ptr<VertexShader>	_vertexShader;
	shared_ptr<PixelShader>		_pixelShader;

	shared_ptr<SRV>				_srv;
};