#pragma once

#include "GameLevel.h"


class Level1 : public GameLevel {

public:
	void load()	override;
	void Unload()  override;
	void Render()  override;
	void Update()  override;

};