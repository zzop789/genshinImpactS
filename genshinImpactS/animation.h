#pragma once
#include <vector>
#include <graphics.h>



class animation
{
public:
	animation(LPCTSTR path, int num, int interval);
		
	~animation();
	
	void play(int x, int y, int delta);
	std::vector<IMAGE*> frameList;
protected:
	int timer = 0;
	int indexFrame = 0;
	int interval_ms = 0;

};

