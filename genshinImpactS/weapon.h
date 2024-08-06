#pragma once
#include"transform.h"
#include"vector2d.h"
#include"graphics.h"
#include"gameObject.h"
#include"enemy.h"

class weapon
{
public:
	vector2d postion{ 0,0 };
	vector2d front_vector;
	weapon(gameObject obj, ExMessage msg);
	~weapon();
	void draw(vector2d pos);
	void move();
	void crossCheck(std::vector<weapon*> weapon_list);
protected:
	
	float speed;
};
