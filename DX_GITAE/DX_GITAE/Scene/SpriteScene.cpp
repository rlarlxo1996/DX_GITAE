#include "framework.h"
#include "SpriteScene.h"

SpriteScene::SpriteScene()
{
	_sprite = make_shared<Sprite>(L"Resource/zelda.png", Vector2(10, 8));
	_sprite->GetTransform()->GetPos() = { WIN_WIDTH * 0.5f, WIN_HEIGHT * 0.5f };

	// 1200 1040, maxFrameX 10, Y 8
	vector<Action::Clip> clips;
	clips.reserve(10);
	float w = 1200.0f / 10.0f;
	float h = 1040.0f / 8.0f;
	{
		clips.emplace_back(1200 * 0, 1040 * 0.5f, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w, 1040 * 0.5f, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 2, 1040 * 0.5f, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 3, 1040 * 0.5f, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 4, 1040 * 0.5f, w, h, Texture::Add(L"Resource/zelda.png"));

		clips.emplace_back(1200 * 0 + w * 5, 1040 * 0.5f, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 6, 1040 * 0.5f, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 7, 1040 * 0.5f, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 8, 1040 * 0.5f, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 9, 1040 * 0.5f, w, h, Texture::Add(L"Resource/zelda.png"));
	}

	_action = make_shared<Action>(clips, Action::Type::END);
	_action->SetEndEvent(std::bind(&SpriteScene::Test, this));
}

SpriteScene::~SpriteScene()
{
}

void SpriteScene::Update()
{
	_sprite->Update();
	_action->Update();

	_sprite->SetAction(_action->GetCurClip());
}

void SpriteScene::Render()
{
	_sprite->Render();
}

void SpriteScene::PostRender()
{
	ImGui::Text(_hello.data());
}
