#include"start_button.h"
void start_button::onclick(bool *is_game_started) {
	*btn_check = true;
}

void quit_buttion::onclick(bool *running)
{
	*btn_check = false;
}
