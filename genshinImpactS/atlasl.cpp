#include"atlas.h"

Atlas::Atlas(LPCTSTR path, int num){
	TCHAR path_flie[256];
	for (size_t i = 0; i < num; i++) {
		
		_stprintf_s(path_flie, path, i);

		IMAGE* frame = new IMAGE();
		loadimage(frame, path_flie);
		frameList.push_back(frame);
	}
}

Atlas::~Atlas()
{

}
