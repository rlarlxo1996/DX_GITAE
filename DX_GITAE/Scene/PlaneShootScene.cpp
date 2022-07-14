#include "framework.h"
#include "PlaneShootScene.h"

PlaneShootScene::PlaneShootScene()
{
	_planeShoot = make_shared<PlaneShoot>();
}

PlaneShootScene::~PlaneShootScene()
{
}

void PlaneShootScene::Update()
{
	_planeShoot->Update();
}

void PlaneShootScene::Render()
{
	_planeShoot->Render();
}

void PlaneShootScene::PostRender()
{
	_planeShoot->PostRender();
}
