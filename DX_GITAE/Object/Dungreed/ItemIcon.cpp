#include "framework.h"
#include "ItemIcon.h"

ItemIcon::ItemIcon()
{
	_quad = make_shared<Quad>(L"Resource/Item_11x5.png", L"Shader/InstancingVertexShader.hlsl", L"Shader/InstancingPixelShader.hlsl");

	// µµ¿Â¬Ô±‚
	CreateIcons();

	_instancingBuffer = make_shared<VertexBuffer>(_instanceDataes.data(), sizeof(InstanceData), _poolCount * _itemCount);
}

ItemIcon::~ItemIcon()
{
}

void ItemIcon::Update()
{
}

void ItemIcon::Render()
{
	_instancingBuffer->IASetVertexBuffer(1);

	_quad->SetRender();

	DEVICE_CONTEXT->DrawIndexedInstanced(6, _poolCount * 5, 0, 0, 0);
}

void ItemIcon::SetIcon(string name, Vector2 pos)
{
	if (_iconTable.count(name) == 0)
		return;

	for (auto& icon : _iconTable[name])
	{
		if (icon.isActive == false)
		{
			icon.isActive = true;
			icon.transform->GetPos() = pos;
			icon.transform->UpdateWorld();
			icon.data->matrix = XMMatrixTranspose(icon.transform->GetMatrix());

			break;
		}
	}
}

void ItemIcon::CreateIcons()
{
	_instanceDataes.reserve(_poolCount * 5);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < _poolCount; j++)
		{
			IconData data;
			InstanceData ins_data;
			ins_data.maxFrame = { 11,5 };
			data.isActive = false;

			data.transform = make_shared<Transform>();
			data.transform->GetPos().x = -3000.0f;
			data.transform->GetScale().x /= 11.0f;
			data.transform->GetScale().y /= 5.0f;
			data.transform->UpdateWorld();

			ins_data.matrix = XMMatrixTranspose(data.transform->GetMatrix());

			string itemName;

			switch (i)
			{
			case 0:
			{
				ins_data.curFrame = { 0,0 };
				itemName = "Sword";
			}
			break;
			case 1:
			{
				ins_data.curFrame = { 1,0 };
				itemName = "Armor";
			}
			break;
			case 2:
			{
				ins_data.curFrame = { 2,0 };
				itemName = "Shoes";
			}
			break;
			case 3:
			{
				ins_data.curFrame = { 3,0 };
				itemName = "Lamp";
			}
			break;
			case 4:
			{
				ins_data.curFrame = { 4,0 };
				itemName = "Potion";
			}
			break;
			case 5:
			{
				ins_data.curFrame = { 10,4 };
				itemName = "NONE";
			}
			break;
			default:
				break;
			}

			_instanceDataes.push_back(ins_data);
			data.data = &_instanceDataes.back();
			data.name = itemName;
			_iconTable[itemName].push_back(data);
		}
	}
}
