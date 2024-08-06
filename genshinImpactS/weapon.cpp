#include"weapon.h"
#include<iostream>

weapon::weapon(gameObject obj, ExMessage msg) :speed(3), front_vector(0, 0)
{
	vector2d vec{ float(msg.x),float(msg.y) };
	this->postion = obj.obj_transform.postion;
	front_vector = vec - this->postion;
	front_vector = front_vector.normalized(front_vector);
	this->postion = this->postion + front_vector * 0.001;
}

weapon::~weapon()
{
}

void weapon::draw(vector2d pos) {
	setlinecolor(RGB(255, 155, 50));
	setfillcolor(RGB(200, 75, 10));
	fillcircle(pos.x, pos.y, 10);
}



void weapon::move() {
	this->postion = this->postion + front_vector * speed;
}

void weapon::crossCheck(std::vector<weapon*> weapon_list)
{
	if (weapon_list.at(0)->postion.x> 1280 || weapon_list.at(0)->postion.x < 0 || weapon_list.at(0)->postion.y>720 || weapon_list.at(0)->postion.y < 0)
		weapon_list.erase(weapon_list.begin());
}

