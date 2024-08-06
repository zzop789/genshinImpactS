#pragma once
#include <vector>
#include <graphics.h>
#include"atlas.h"



class animation
{
public:
	animation(Atlas* atlas, int interval);
		
	~animation();
	
	void play(int x, int y, int delta);
protected:
	int timer = 0;
	int indexFrame = 0;
	int interval_ms = 0;
	
private:
	Atlas* anim_atlas;
};

