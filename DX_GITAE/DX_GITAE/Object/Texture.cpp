#include "framework.h"
#include "Texture.h"

Texture::Texture(wstring file)
{
    CreateVertices();
    _vertexBuffer = make_shared<VertexBuffer>(_vertices.data(),sizeof(VertexUV),_vertices.size());
    _indexBuffer = make_shared<IndexBuffer>(_indices.data(), _indices.size());

    _vertexShader = make_shared<VertexShader>(L"Shader/TextureVertexShader.hlsl");
    _pixelShader = make_shared<PixelShader>(L"Shader/TexturePixelShader.hlsl");

    _srv = make_shared<SRV>(file);

    _transform = make_shared<Transform>();
}

Texture::~Texture()
{
}

void Texture::Update()
{
    _transform->UpdateWorld();
}

void Texture::Render()
{
    _transform->SetWorldBuffer(0);

    _vertexBuffer->IASetVertexBuffer(0);
    _indexBuffer->IASetIndexBuffer();

    DEVICE_CONTEXT->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    _srv->SetSRV(0);

    _vertexShader->SetIAInputLayOut();
    _vertexShader->SetVertexShader();
    _pixelShader->SetPixelShader();

    DEVICE_CONTEXT->DrawIndexed(_indices.size(), 0, 0);
}

void Texture::CreateVertices()
{
    _vertices.reserve(4);

    VertexUV v;
    // 왼쪽 위
    v.pos = { -100, 100, 0.0f };
    v.uv = { 0.0f, 0.0f };
    _vertices.push_back(v);
    // 오른쪽 위
    v.pos = { 100, 100, 0.0f };
    v.uv = { 1, 0.0f };
    _vertices.push_back(v);
    // 오른쪽 아래
    v.pos = { 100, -100, 0.0f };
    v.uv = { 1, 1 };
    _vertices.push_back(v);
    // 왼쪽 아래
    v.pos = { -100, -100, 0.0f };
    v.uv = { 0.0f, 1 };
    _vertices.push_back(v);

    _indices.push_back(0);
    _indices.push_back(1);
    _indices.push_back(2);

    _indices.push_back(0);
    _indices.push_back(2);
    _indices.push_back(3);
}

