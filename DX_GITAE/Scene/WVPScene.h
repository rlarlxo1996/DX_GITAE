#pragma once
class WVPScene : public Scene
{
public:
	WVPScene();
	virtual ~WVPScene();

	// Scene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;

private:
	shared_ptr<MatrixBuffer> _worldBuffer;
	shared_ptr<MatrixBuffer> _viewBuffer;
	shared_ptr<MatrixBuffer> _projectionBuffer;

	XMFLOAT2 _worldPos = { 0,0 }; // World자체를 움직이게
	XMFLOAT2 _cameraPos = { 0,0 }; // view를 움직이게

	float _cameraAngle = { 0 }; // World 회전

	shared_ptr<Quad> _quad;
	shared_ptr<Quad> _quad2;
};

