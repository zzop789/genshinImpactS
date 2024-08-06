#pragma once
#include "scene.h"

class menuScene:public Scene
{
public:
	menuScene() = default;
	~menuScene()=default;
	void switchIn() override;
	void update() override;
	void draw() override;
	void msgInput(const ExMessage& msg) override;
	void exit()override;
private:

};
