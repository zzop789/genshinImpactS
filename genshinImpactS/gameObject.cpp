#include "gameObject.h"
#include"transform.h"
#include<iostream>
void limit_obj_in_area(vector2d &pos) {
	if (pos.x < 0) pos.x = 0;
	if (pos.x > 1200) pos.x = 1200;
	if (pos.y > 640) pos.y = 640;
	if (pos.y < 0) pos.y = 0;
}
gameObject::gameObject(int speed, const transform& obj_transform, std::vector<Atlas>& anim_paimeng) :speed(speed), obj_transform(obj_transform){
	anim_left = new animation(&(anim_paimeng.at(0)), 45);
	anim_right = new animation(&(anim_paimeng.at(1)), 45);
}



// ¹¹Ôìº¯Êý

//void gameObject::loadAnimation()
//{
//	for (auto it : animNames) {
//		if (it == nullptr) {
//			std::cout << "Invalid animation name pointer found in animNames." << std::endl;
//			continue;
//		}
//	}
//	for (auto it : animNames) {
//		animation anim = animation(it, 6, 45);
//		animationList.push_back(anim);
//	}
//};

void gameObject::msgSolut(ExMessage& msg)
{
	if (msg.message == WM_KEYDOWN)
	{
		switch (msg.vkcode) {
		case VK_UP:
			obj_transform.frontVector.y = -1;
			break;
		case VK_DOWN:
			obj_transform.frontVector.y = 1;
			break;
		case VK_RIGHT:
			obj_transform.frontVector.x = 1;
			break;
		case VK_LEFT:
			obj_transform.frontVector.x = -1;
			break;
		}
	}
	else if (msg.message == WM_KEYUP) {
		switch (msg.vkcode) {
		case VK_UP:
			obj_transform.frontVector.y = 0;
			break;
		case VK_DOWN:
			obj_transform.frontVector.y = 0;
			break;
		case VK_RIGHT:
			obj_transform.frontVector.x = 0;
			break;
		case VK_LEFT:
			obj_transform.frontVector.x = 0;
			break;
		}
	}
}

void gameObject::obj_move()
{
	vector2d normalized_vector{0,0};
	normalized_vector = obj_transform.frontVector.normalized(obj_transform.frontVector);
	limit_obj_in_area(this->obj_transform.postion);
	obj_transform.postion = obj_transform.postion + normalized_vector * (float)speed;
}

void gameObject::drawPlay(int delta, int dir_x, gameObject* obj)
{
	static bool facing_left = false;
	if (dir_x < 0)
		facing_left = true;
	else if (dir_x > 0)
		facing_left = false;

	if (facing_left )
	{
		anim_left->play(obj->obj_transform.postion.x, obj->obj_transform.postion.y, delta);
	}
	else {
		anim_right->play(obj->obj_transform.postion.x, obj->obj_transform.postion.y, delta);
	}
}

