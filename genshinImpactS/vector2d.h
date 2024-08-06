#pragma once
#include <xkeycheck.h>
#include <cmath>
class vector2d
{
public:
	vector2d(float inX, float inY);
	~vector2d()=default;
	float x, y;
	void setVector(float inX, float inY);
	vector2d operator +(const vector2d& vector) const;
	vector2d operator -(const vector2d& vector) const;
	vector2d operator *(float scalar) const;
	vector2d normalized(vector2d& vec);
	float getLength();
	void print_vector(int count);
private:

};


