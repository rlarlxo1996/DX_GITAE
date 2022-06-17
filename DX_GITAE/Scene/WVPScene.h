#pragma once
class WVPScene : public Scene
{
public:
	WVPScene();
	virtual ~WVPScene();

	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;

private:
	shared_ptr<MatrixBuffer> _worldBuffer;
	shared_ptr<MatrixBuffer> _viewBuffer;
	shared_ptr<MatrixBuffer> _projectionBuffer;

	XMFLOAT2 _worldPos = { 0,0 }; // World��ü�� �����̰�
	XMFLOAT2 _cameraPos = { 0,0 }; // view�� �����̰�

	float _cameraAngle = { 0 }; // World ȸ��

	shared_ptr<Texture> _texture;
	shared_ptr<Texture> _texture2;
};

