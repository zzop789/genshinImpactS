#include"weapon.h"
#include<iostream>
#pragma comment(lib,"Winmm.lib")

weapon::weapon(gameObject obj, ExMessage msg) :speed(8), front_vector(0, 0)
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

bool weapon::hit_check(std::vector<enemy*> enemy_list)
{
	for (size_t i = 0; i< enemy_list.size();i++) {
		vector2d distance = enemy_list[i]->trans.postion - this->postion;
		if (this->postion.x< enemy_list[i]->trans.postion.x+80&& this->postion.x > enemy_list[i]->trans.postion.x
			&& this->postion.y < enemy_list[i]->trans.postion.y + 80 && this->postion.y > enemy_list[i]->trans.postion.y)
		{
			mciSendString(_T("play hit from 0"), NULL, 0, NULL);
			enemy_list[i]->alive = false;
		}
	}
	return false;
}

