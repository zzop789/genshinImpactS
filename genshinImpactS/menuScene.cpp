#include"menuScene.h"

void menuScene::switchIn() {
	std::cout << "now is menu" << std::endl;
}
void menuScene::update()
{
	std::cout << " is updating" << std::endl;
}
void menuScene::draw() {
	
	outtextxy(10, 10,_T("meun interface"));
}

void menuScene::msgInput(const ExMessage& msg)
{

}

void menuScene::exit()
{

}
