#pragma once
#include"vector2d.h"
#include"weapon.h"

class collider
{
public:
	collider();
	~collider();
	vector2d center{ 0,0 };
	bool is_overlaping(const collider& box);
	bool being_hitted(weapon* bullet);
private:
	int hight_size = 60;
	int widght_size = 60;
};

collider::collider()
{
}

collider::~collider()
{
}