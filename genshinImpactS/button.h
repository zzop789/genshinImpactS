#pragma once
#include"graphics.h"
#include<vector>
class button
{
public:
	button(RECT rect, std::vector<LPCTSTR>& path_img_button_list,bool *check);
	~button()=default;
	void button_draw();
	void msg_solut(const ExMessage& msg);
	bool* btn_check;
protected:
	virtual void onclick(bool *check) = 0;

private:
	enum class status
	{
		idle = 0,
		hovered,
		on_push,
	};
private:
	RECT region;
	std::vector<IMAGE> img_list;
	status status = status::idle;
private:
	bool check_cursor_hit(int x, int y);
};
