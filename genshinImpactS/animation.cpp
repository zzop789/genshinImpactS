#include"animation.h"
#include <Windows.h>
#pragma comment(lib, "MSIMG32.LIB")
inline void putimageAlpha(int x,int y,IMAGE* img) {
	int width = img->getwidth();
	int height = img->getheight();
	AlphaBlend(GetImageHDC(NULL), x, y, width, height,
		GetImageHDC(img), 0, 0, width, height, { AC_SRC_OVER,0,255,AC_SRC_ALPHA });
}
animation::animation(LPCTSTR path, int num, int interval) : interval_ms(interval) {
	interval_ms = interval;

	TCHAR path_flie[256];
	for (size_t i = 0; i < num; i++) {
		_stprintf_s(path_flie, path, i);

		IMAGE* frame = new IMAGE();
		loadimage(frame, path_flie);
		frameList.push_back(frame);
	}
}
animation::~animation() {
	
}
void animation::play(int x, int y, int delta) {
	timer += delta;
	if (timer >= interval_ms)
	{
		timer = 0;
		indexFrame = (indexFrame + 1) % frameList.size();
	}
	putimageAlpha(x, y, frameList.at(indexFrame));
}


