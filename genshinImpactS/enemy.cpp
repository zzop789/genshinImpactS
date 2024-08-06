#include"enemy.h"
#include<iostream>

enemy::enemy():speed(3),anim_left(nullptr), anim_right(nullptr) {

	anim_left = new animation(_T("img/enemy_left_%d.png"), 6, 45);
	anim_right = new animation(_T("img/enemy_right_%d.png"), 6, 45);
	enum edge
	{
		up = 0,
		down,
		left,
		right
	};
	edge spawn_edge = (edge)(rand() % 4);
	switch (spawn_edge)
	{
	case up:
		this->trans.postion={ float(rand() % 1280),float( - 80)};
		break;
	case down:
		this->trans.postion = { float(rand() % 1280),720.0 };
		break;
	case left:
		this->trans.postion = { float(-80),float(rand() % 720 )};
		break;
	case right:
		this->trans.postion = { 1280.0,float(rand() % 720) };
		break;
	default:
		break;
	}
}



void enemy::track_player(gameObject obj)
{
	vector2d track_vector{0,0};
	track_vector = obj.obj_transform.postion - this->trans.postion;
	track_vector = track_vector.normalized(track_vector);
	this->trans.postion = this->trans.postion + track_vector * speed;
	this->trans.frontVector = track_vector;
}

void enemy::drawPlay(int delta)
{
	static bool facing_left = false;
	if (this->trans.frontVector.x< 0)
		facing_left = true;
	else if (this->trans.frontVector.x > 0)
		facing_left = false;
	if (facing_left)
	{
		anim_left->play(trans.postion.x, trans.postion.y, delta);

	}
	else {
		anim_right->play(trans.postion.x, trans.postion.y, delta);
	}
}
