#include"menuScene.h"
#include"animation.h"
#include"gameObject.h"
#include"enemy.h"
#include"weapon.h"
#include<iostream>
#include"start_button.h"


bool is_game_started = 0;
bool runing = 1;
bool* p_is_game_started = &is_game_started;
bool* p_runing = &runing;
std::vector<Atlas> anim_paimeng{ Atlas(_T("img/player_left_%d.png"),6),Atlas(_T("img/player_right_%d.png"),6) };
std::vector<Atlas> anim_enemy{ Atlas(_T("img/enemy_left_%d.png"),6),Atlas(_T("img/enemy_right_%d.png"),6) };
//animation anim_left_player(_T("img/player_left_%d.png"), 6, 45);
//animation anim_right_player(_T("img/player_right_%d.png"), 6, 45);
//void drawPlay(int delta, int dir_x, gameObject* obj);
void spwan_enemys(std::vector<enemy*>& enemy_list, int num_limit, int interval) {
	static int tick{ 0 };
	if (++tick % interval == 0&&enemy_list.size()< num_limit)
	{
		enemy_list.push_back(new enemy(anim_enemy));
	}
};
void increase_bullets(int& num,int interval) {
	static int counter{ 0 };
	if(++counter % interval == 0 && num < 5)
	{
		num++;
	}
}
void draw_number_of_bullets_left(int num) {
	setlinecolor(RGB(255, 155, 50));
	setfillcolor(RGB(200, 75, 10));
	for (size_t i = 0; i < num; i++)
	{
		fillcircle(1250-i*40, 30, 12);
	}
}
void draw_score(int num) {
	static TCHAR text[64];
	_stprintf_s(text, _T("Current score:%d"), num);
	setbkmode(TRANSPARENT);
	settextcolor(RGB(255, 85, 185));
	outtextxy(10, 10, text);

}

int main() {
	vector2d init_pos(500, 500); vector2d init_front(0, 0);
	transform init_trans(init_pos, init_front, 1);
	const int button_width = 192, button_hight = 75;
	ExMessage msg;
	IMAGE imgBackground,menu;
	int number_of_bullets_left = 0;
	std::vector<LPCTSTR> path_start_button_list{ _T("img/ui_start_idle.png"),
	_T("img/ui_start_hovered.png"),_T("img/ui_start_pushed.png") };
	std::vector<LPCTSTR> path_quit_button_list{ _T("img/ui_quit_idle.png"),
	_T("img/ui_quit_hovered.png"),_T("img/ui_quit_pushed.png") };
	RECT region_start_button, region_quit_button;
	region_start_button.left = (1280 - button_width) / 2;
	region_start_button.right = region_start_button.left+button_width;
	region_start_button.top = 430;
	region_start_button.bottom = region_start_button.top + button_hight;
	region_quit_button.left= (1280 - button_width) / 2;
	region_quit_button.right = region_quit_button.left + button_width;
	region_quit_button.top = 550;
	region_quit_button.bottom = region_quit_button.top + button_hight;
	start_button btn_start =start_button(region_start_button,path_start_button_list,p_is_game_started);
	quit_buttion btn_quit = quit_buttion(region_quit_button, path_quit_button_list,p_runing);

	int score = 0;
	std::vector<enemy*> enemy_list;
	std::vector<weapon*> weapon_list;
	loadimage(&menu, _T("img/menu.png"));
	loadimage(&imgBackground, _T("img/background.png"));

	initgraph(1280, 720);
	mciSendString(_T("open mus/bgm.mp3 alias bgm"), NULL, 0, NULL);
	mciSendString(_T("open mus/hit.wav alias hit"), NULL, 0, NULL);
	mciSendString(_T("play bgm repeat from 0"), NULL, 0, NULL);
	gameObject *paimeng = new gameObject(5, init_trans, anim_paimeng);
	menuScene *menu_sence = new menuScene;
	BeginBatchDraw();

	// game init
	
	while (runing)
	{
		DWORD startTime = GetTickCount();
		if (is_game_started) {
			spwan_enemys(enemy_list, 100, 30);
			increase_bullets(number_of_bullets_left, 100);
		}
		while (peekmessage(&msg)) {
			if (is_game_started)
			{
				paimeng->msgSolut(msg);
				if (msg.message == WM_LBUTTONDOWN)
				{
					weapon* bullets = new weapon(*paimeng, msg);
					if (number_of_bullets_left > 0)
					{
						weapon_list.push_back(bullets);
						number_of_bullets_left--;
					}
				}
			}
			else {
				btn_start.msg_solut(msg);
				btn_quit.msg_solut(msg);
			}
			if (msg.message==WM_KEYDOWN)
			{
				if (msg.vkcode == 0x1B) runing = false;
			}
		}

		if (is_game_started)
		{
			paimeng->obj_move();
			for (size_t i = 0; i < enemy_list.size(); i++) {
				if (enemy_list[i]->alive)
				{
					enemy_list[i]->track_player(*paimeng);
					if (enemy_list[i]->check_paimeng(*paimeng))
					{
						static TCHAR text[128];
						_stprintf_s(text, _T("final score:%d !"), score);
						MessageBox(GetHWnd(),text,_T("¿Û1¹Û¿´Õ½°ÜCG"), MB_OK);
						runing = false;
						//reset();
					}
					//std::cout << enemy_list[i]->check_paimeng(*paimeng) << std::endl;
				}
				else {
					enemy* enemis = enemy_list[i];
					std::swap(enemy_list[i], enemy_list.back());
					enemy_list.pop_back();
					delete enemis;
					score++;
				}

			}

			for (auto bullets : weapon_list)
			{
				bullets->move();
				bullets->hit_check(enemy_list);
				if (bullets->postion.x > 1280 || bullets->postion.x < 0 || bullets->postion.y>720 || bullets->postion.y < 0)
					weapon_list.erase(weapon_list.begin());
			}
		}
		
		
		
		cleardevice();
		if (is_game_started)
		{
			putimage(0, 0, &imgBackground);
			draw_number_of_bullets_left(number_of_bullets_left);
			paimeng->drawPlay(1000 / 60, paimeng->obj_transform.frontVector.x, paimeng);
			for (auto bullets : weapon_list)
			{
				bullets->draw(bullets->postion);
			}
			for (enemy* it : enemy_list) {
				int dix = it->trans.frontVector.x;
				it->drawPlay(1000 / 60);
			}
			draw_score(score);
		}
		else {
			putimage(0, 0, &menu);
			btn_start.button_draw();
			btn_quit.button_draw();
		}
		FlushBatchDraw();
	


		DWORD endTime = GetTickCount();
		DWORD deltaTime = endTime - startTime;
		if (deltaTime < 1000 / 60)
		{
			Sleep(1000 / 60 - deltaTime);
		}
	}
	// data solut and draw 
	delete menu_sence,paimeng;
	EndBatchDraw();
	
}
