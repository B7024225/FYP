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
	
	// Movment
	if (GetKeyState(VK_DOWN) & 0x8000) {
		y += 5.0f;
	}
	if (GetKeyState(VK_UP) & 0x8000) {
		y -= 5.0f;
	}
	if (GetKeyState(VK_LEFT) & 0x8000) {
		x -= 15.0f;
	}
	if (GetKeyState(VK_RIGHT) & 0x8000) {
		x += 15.0f;
	}
	player->pos.x = x;


}

void Level1::Render() {

	graphics->ClearScreen(0.0f, 0.0f, 1.0f);
	background->draw();
	player->draw();
}


