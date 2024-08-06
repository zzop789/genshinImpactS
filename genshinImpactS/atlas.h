#pragma once
#include"graphics.h"
#include<vector>

class Atlas
{
public:
	Atlas(LPCTSTR path,int num);
	~Atlas();
	std::vector<IMAGE*> frameList;

private:

};


