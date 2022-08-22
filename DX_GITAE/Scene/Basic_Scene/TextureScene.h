#pragma once
class TextureScene : public Scene
{
public:
	TextureScene();
	virtual ~TextureScene();

	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;

private:
	shared_ptr<Quad> _quad;
	shared_ptr<FilterBuffer> _isRightBuffer;
};

