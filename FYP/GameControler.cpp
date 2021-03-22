#include "GameControler.h"

GameLevel* GameControler::currentLevel;

bool GameControler::loading;

void GameControler::Init() {
	loading = true;
	currentLevel = 0;
}

void GameControler::LoadInitLevel(GameLevel* level) {
	loading = true;
	currentLevel = level;
	currentLevel->load();
	loading = false;
}
void GameControler::SwithLevel(GameLevel* level) {
	loading = true;
	currentLevel->Unload();
	level->load();
	delete currentLevel;
	currentLevel = level;
	loading = false;
}

void GameControler::Render() {
	if (loading) { return; }
	currentLevel->Render();
}
void GameControler::Update() {
	currentLevel->Update();
}
