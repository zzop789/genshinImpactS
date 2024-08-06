#include"menuScene.h"
#include"animation.h"
#include"gameObject.h"
#include"enemy.h"
#include"weapon.h"


std::vector<LPCTSTR>anim_names = { _T("img/player_left_%d.png") ,_T("img/player_right_%d.png") };
//animation anim_left_player(_T("img/player_left_%d.png"), 6, 45);
//animation anim_right_player(_T("img/player_right_%d.png"), 6, 45);
//void drawPlay(int delta, int dir_x, gameObject* obj);
void spwan_enemys(std::vector<enemy*>& enemy_list, int num_limit, int interval) {
	static int tick{ 0 };
	if (++tick % interval == 0&&enemy_list.size()< num_limit)
	{
		enemy_list.push_back(new enemy());
	}
};

int main() {
	vector2d init_pos(500, 500); vector2d init_front(0, 0);
	transform init_trans(init_pos, init_front, 1);
	bool runing=1;
	ExMessage msg;
	IMAGE imgBackground;
	std::vector<enemy*> enemy_list;
	std::vector<weapon*> weapon_list;
	loadimage(&imgBackground, _T("img/background.png"));

	initgraph(1280, 720);
	gameObject *paimeng = new gameObject(10, init_trans,anim_names);
	menuScene *menu = new menuScene;
	paimeng->loadAnimation();
	BeginBatchDraw();

	// game init
	
	while (runing)
	{
		DWORD startTime = GetTickCount();
		spwan_enemys(enemy_list,100,100);
		while (peekmessage(&msg)) {
			paimeng->msgSolut(msg);
			if (msg.message==WM_KEYDOWN)
			{
				if (msg.vkcode == 0x1B) runing = false;
				
			}
			if (msg.message == WM_LBUTTONDOWN)
			{
				weapon* bullets = new weapon(*paimeng, msg);
				weapon_list.push_back(bullets);
			}
		}

		paimeng->obj_move();
		
		for (auto it : enemy_list) {
			it->track_player(*paimeng);
		}
		
		
		for (auto bullets:weapon_list )
		{
			bullets->move();
			if (bullets->postion.x > 1280 || bullets->postion.x < 0 || bullets->postion.y>720 || bullets->postion.y < 0)
				weapon_list.erase(weapon_list.begin());
		}
		
		
		
		cleardevice();
		putimage(0, 0, &imgBackground);
		paimeng->drawPlay(1000 / 144, paimeng->obj_transform.frontVector.x,paimeng);
		for (auto bullets : weapon_list)
		{
			bullets->draw(bullets->postion);
		}
		for (enemy* it : enemy_list) { 
			int dix = it->trans.frontVector.x;
			it->drawPlay(1000 / 144);
		}
		FlushBatchDraw();
	


		DWORD endTime = GetTickCount();
		DWORD deltaTime = endTime - startTime;
		if (deltaTime < 1000 / 144)
		{
			Sleep(1000 / 144 - deltaTime);
		}
	}
	// data solut and draw 
	delete menu,paimeng;
	EndBatchDraw();
	
}
