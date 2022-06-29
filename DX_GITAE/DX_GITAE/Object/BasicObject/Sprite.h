#pragma once
class Sprite : public Quad
{
public:
	Sprite(wstring file, Vector2 maxFrame = { 1, 1 });
	~Sprite();

	virtual void Render() override;
	virtual void CreateVertices() override;

private:
	shared_ptr<FrameBuffer> _frameBuffer;
};

