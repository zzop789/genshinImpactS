#pragma once
#include"vector2d.h"

class transform
{
public:
	transform(vector2d postion,vector2d frontVector,float scale);
	~transform()=default;


	vector2d postion;
	vector2d frontVector;
	float scale;
};

