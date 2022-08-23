#pragma once
class InstancingScene : public Scene
{
public:
	struct InstanceData
	{
		XMMATRIX matrix;
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

	shared_ptr<Transform> _transform;
};

