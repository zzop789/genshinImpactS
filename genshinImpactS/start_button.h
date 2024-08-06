#pragma once
#include"button.h"

class start_button:public button
{
public:
	start_button(RECT rect, std::vector<LPCTSTR>& path_img_button_list,bool *check) :button(rect, path_img_button_list,check) {};
	~start_button() = default;

protected:
	void onclick(bool* is_game_started) override;
};

class quit_buttion:public button
{
public:
	quit_buttion(RECT rect, std::vector<LPCTSTR>& path_img_button_list, bool *check) :button(rect, path_img_button_list,check) {};
	~quit_buttion() = default;
	void onclick(bool* check) override;
private:

};
