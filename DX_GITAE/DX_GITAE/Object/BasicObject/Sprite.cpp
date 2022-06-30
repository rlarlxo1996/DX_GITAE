#include "framework.h"
#include "Sprite.h"

Sprite::Sprite(wstring file, Vector2 maxFrame)
: _maxFrame(maxFrame)
{
    // Texture Setting
    _texture = Texture::Add(file);
    _size = _texture->GetSize();

    _frameBuffer = make_shared<FrameBuffer>();
    _frameBuffer->_data._maxFrame.x = maxFrame.x;
    _frameBuffer->_data._maxFrame.y = maxFrame.y;

    CreateVertices();
    _vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(VertexUV), _vertices.size());
    _indexBuffer = make_shared<IndexBuffer>(_indices.data(), _indices.size());

    _vertexShader = ADD_VS(L"Shader/TextureVertexShader.hlsl");
    _pixelShader = ADD_PS(L"Shader/SpriteShader.hlsl");

    _transform = make_shared<Transform>();
}

Sprite::~Sprite()
{
}

void Sprite::Update()
{
    Quad::Update();
}

void Sprite::Render()
{
    _frameBuffer->SetPSBuffer(0);

    Quad::Render();
}

void Sprite::CreateVertices()
{
    Vector2 halfSize = _texture->GetSize() * 0.5f;
    halfSize.x /= _frameBuffer->_data._maxFrame.x;
    halfSize.y /= _frameBuffer->_data._maxFrame.y;

    _vertices.reserve(4);

    _vertices.emplace_back(-halfSize.x, halfSize.y, 0, 0);
    _vertices.emplace_back(halfSize.x, halfSize.y, 1, 0);
    _vertices.emplace_back(halfSize.x, -halfSize.y, 1, 1);
    _vertices.emplace_back(-halfSize.x, -halfSize.y, 0, 1);

    _indices.push_back(0);
    _indices.push_back(1);
    _indices.push_back(2);

    _indices.push_back(0);
    _indices.push_back(2);
    _indices.push_back(3);
}
