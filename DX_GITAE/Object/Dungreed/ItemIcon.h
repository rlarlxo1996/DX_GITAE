#pragma once
class ItemIcon
{
public:
	struct InstanceData
	{
		XMMATRIX matrix;
		Vector2 maxFrame;
		Vector2 curFrame;
	};

	struct IconData
	{
		bool isActive;
		string name;
		InstanceData* data;
		shared_ptr<Transform> transform;
	};

	ItemIcon();
	~ItemIcon();

	void Update();
	void Render();
	void SetIcon(string name, Vector2 pos);

private:
	void CreateIcons();

	shared_ptr<Quad> _quad;
	vector<InstanceData> _instanceDataes;
	unordered_map<string, vector<IconData>> _iconTable;

	shared_ptr<VertexBuffer> _instancingBuffer;

	int _poolCount = 30;
};

