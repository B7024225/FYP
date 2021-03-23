#include "levels.h"
#include "GameControler.h"
#include <d2d1.h>
#include "Graphics.h"
#include <string>


void Level1::load() {

	y = 0.0f;
	x = 0.0f;


	sprites = new SpriteSheet(L"test.png",graphics);
}
void Level1::Unload() {
	delete sprites;
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
		x -= 5.0f;
	}
	if (GetKeyState(VK_RIGHT) & 0x8000) {
		x += 5.0f;
	}
	/*
	if (GetKeyState(VK_F2) & 0x8000) {
		GameControler::SwithLevel(new Level2);
	}
	*/
}

void Level1::Render() {

	graphics->ClearScreen(0.0f, 0.0f, 1.0f);
	graphics->DrawCircle(375.0f + x, 375.0f + y, 50.0f, 0.5f, 0.5f, 0.5f, 1.0f);
	sprites->Draw(0.0f,0.0f);
}


