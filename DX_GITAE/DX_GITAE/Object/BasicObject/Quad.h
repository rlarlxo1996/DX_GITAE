#pragma once
class Quad
{
public:
	Quad(wstring file);
	~Quad();

	void Update();
	virtual void Render();

	virtual void CreateVertices();

	shared_ptr<Transform> GetTransform() { return _transform; }
	const Vector2& GetSize() { return _size; }

protected:
	shared_ptr<Transform> _transform;

	// Texture
	shared_ptr<Texture> _texture;

	// Mesh
	vector<VertexUV>			_vertices;
	vector<UINT>				_indices;
	shared_ptr<VertexBuffer>	_vertexBuffer;
	shared_ptr<IndexBuffer>		_indexBuffer;

	// Material
	shared_ptr<VertexShader>	_vertexShader;
	shared_ptr<PixelShader>		_pixelShader;

	Vector2 _size;
};

