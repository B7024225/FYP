#pragma once

#include "GameLevel.h"

class Level2 : public GameLevel {


public:
	void load()	override;
	void Unload()  override;
	void Render()  override;
	void Update()  override;

};