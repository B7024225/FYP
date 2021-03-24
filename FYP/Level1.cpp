#include "levels.h"
#include "GameControler.h"
#include <d2d1.h>
#include "Graphics.h"
#include <string>
#include "GameObject.h"

void Level1::load() {

	player = new GameObject(graphics);
	background = new GameObject(graphics);

	player->setImage(L"mario.png");
	player->size = 4;
	player->pos.y = 2100.0f;
	background->setImage(L"background.jpg");

	

}
void Level1::Unload() {

}

void Level1::Update() {
	
	float gravity = 10.0f;

	player->pos.x = x;
	player->pos.y = y;
	// Movment
	if (GetKeyState(VK_DOWN) & 0x8000) {
		y += 25.0f;
	}
	if (GetKeyState(VK_UP)& 0x8000) {
		y -= 25.0f;
	}
	if (GetKeyState(VK_LEFT) & 0x8000) {
		x -= 15.0f;
	}
	if (GetKeyState(VK_RIGHT) & 0x8000) {
		x += 15.0f;
	}
	if (GetKeyState(VK_F1) & 0x8000) {
		GameControler::SwithLevel(new Level2);
	}

	if (y > 2100.0f) {
		y = 2100.0f;

	}	
	/*
	if (y < 1500.0f) {
		y +=  5;
	}
	*/
	y += gravity;
}

void Level1::Render() {

	graphics->ClearScreen(0.0f, 0.0f, 1.0f); // dont tuch
	background->draw();
	player->draw();
}


