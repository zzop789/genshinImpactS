#pragma once

#include<iostream>
#include<graphics.h>

class Scene
{
public:
	Scene()=default;
	~Scene() = default;

	virtual void switchIn() {};
	virtual void update() {};
	virtual void draw() {};
	virtual void msgInput(const ExMessage& msg ) {};
	virtual void exit() {};

private:

};
