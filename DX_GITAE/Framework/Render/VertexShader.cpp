#include "framework.h"
#include "VertexShader.h"

VertexShader::VertexShader(wstring file)
{
    CreateBlob(file);
    CreateInputLayout();
    CreateVertexShader();
}

VertexShader::~VertexShader()
{
}

void VertexShader::CreateBlob(wstring file)
{
    DWORD flags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;

    D3DCompileFromFile(file.data(), nullptr, nullptr, "VS", "vs_5_0", flags, 0,
        _vertexBlob.GetAddressOf(), nullptr);
}

void VertexShader::CreateInputLayout()
{
    D3D11_INPUT_ELEMENT_DESC layout[] =
    {
        {
            "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0,0,
            D3D11_INPUT_PER_VERTEX_DATA, 0
        },
        {
            "UV", 0, DXGI_FORMAT_R32G32_FLOAT, 0,12,
            D3D11_INPUT_PER_VERTEX_DATA, 0
        }
    };

    UINT layoutSize = ARRAYSIZE(layout);

    // Shader ���� ����
    DEVICE->CreateInputLayout(layout, layoutSize, _vertexBlob->GetBufferPointer(), _vertexBlob->GetBufferSize(),
        _inputLayout.GetAddressOf());
}

void VertexShader::CreateVertexShader()
{
    DEVICE->CreateVertexShader(_vertexBlob->GetBufferPointer(), _vertexBlob->GetBufferSize(), nullptr,
        _vertexShader.GetAddressOf());
}

void VertexShader::SetIAInputLayOut()
{
    DEVICE_CONTEXT->IASetInputLayout(_inputLayout.Get());
}

void VertexShader::SetVertexShader()
{
    DEVICE_CONTEXT->VSSetShader(_vertexShader.Get(), nullptr, 0);
}
