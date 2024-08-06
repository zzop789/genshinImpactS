#pragma once
#include "vector2d.h"
#include "transform.h"
#include "animation.h"
#include <graphics.h>
#include <vector>
class gameObject
{
public:
	gameObject(int speed,const transform& obj_transform, std::vector<Atlas>& anim_paimeng);
	~gameObject()=default;
//	void loadAnimation();
	//virtual int getSpeed() = 0;
	//virtual void setSpeed(int newSpeed) = 0;
	//virtual void setTransform(const transform& newTransform) = 0;
	//virtual bool isOverlap() = 0;
	virtual void msgSolut(ExMessage& msg);
	virtual void obj_move(); 
	void drawPlay(int delta, int dir_x, gameObject* obj);
	int speed;
	transform obj_transform;
//	std::vector<LPCTSTR> animNames;
 //   std::vector<animation> animationList;
	
protected:
	animation* anim_left;
	animation* anim_right;
};
