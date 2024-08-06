#include"animation.h"
#include <Windows.h>
#pragma comment(lib, "MSIMG32.LIB")
inline void putimageAlpha(int x,int y,IMAGE* img) {
	int width = img->getwidth();
	int height = img->getheight();
	AlphaBlend(GetImageHDC(NULL), x, y, width, height,
		GetImageHDC(img), 0, 0, width, height, { AC_SRC_OVER,0,255,AC_SRC_ALPHA });
}
animation::animation(Atlas* atlas, int interval) :interval_ms(interval), anim_atlas(atlas) {}
	
animation::~animation() {
	
}
void animation::play(int x, int y, int delta) {
	timer += delta;
	if (timer >= interval_ms)
	{
		timer = 0;
		indexFrame = (indexFrame + 1) %anim_atlas->frameList.size();
	}
	putimageAlpha(x, y, anim_atlas->frameList.at(indexFrame));
}


