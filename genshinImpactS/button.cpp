#include"button.h"

button::button(RECT rect,std::vector<LPCTSTR> &path_img_button_list,bool *check):img_list(3)
{
	btn_check = check;
	region = rect;
	loadimage(&img_list[0], path_img_button_list[0]);
	loadimage(&img_list[1], path_img_button_list[1]);
	loadimage(&img_list[2], path_img_button_list[2]);
}

void button::button_draw() {
	switch (status)
	{
	case button::status::idle:
		putimage(region.left, region.top, &img_list[0]);
		break;
	case button::status::hovered:
		putimage(region.left, region.top, &img_list[1]);
		break;
	case button::status::on_push:
		putimage(region.left, region.top, &img_list[2]);
		break;
	default:
		break;
	}
}

void button::msg_solut(const ExMessage& msg)
{
	switch (msg.message)
	{
	case WM_MOUSEMOVE:
		if (status ==status::idle && check_cursor_hit(msg.x,msg.y)){
			status = status::hovered;
		}
		else if (status == status::hovered && !check_cursor_hit(msg.x, msg.y)) {
			status = status::idle;
		}break;

	case WM_LBUTTONDOWN:
		if (check_cursor_hit(msg.x, msg.y)) {
			status = status::on_push;
		}break;
	case WM_LBUTTONUP:
		if (status == status::on_push) {
			onclick(btn_check);
			status = status::idle;
		}break;
	default:
		break;
	}
}

bool button::check_cursor_hit(int x, int y)
{
	return x>= region.left&&x<=region.right&&y>=region.top&&y<=region.bottom;
}
