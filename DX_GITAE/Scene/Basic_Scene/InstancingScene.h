#pragma once
class InstancingScene : public Scene
{
public:
	struct InstanceData
	{
		XMMATRIX matirx;
		Vector2 maxFrame;
		Vector2 curFrame;
	};
	
	InstancingScene();
	virtual ~InstancingScene();

	virtual void Update() override;
	virtual void Render() override;


private:
	shared_ptr<Quad> _quad;
	vector<InstanceData> _instanceDataes;
	shared_ptr<VertexBuffer> _instancingBuffer;
};

