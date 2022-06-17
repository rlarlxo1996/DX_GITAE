#pragma once
class TextureScene : public Scene
{
public:
	TextureScene();
	virtual ~TextureScene();

	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;

private:
	shared_ptr<Texture> _texture;
};

