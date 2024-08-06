#include"collider.h"

bool collider::is_overlaping(const collider& box) {
	vector2d distance = this->center - box.center;
	if (80>distance.getLength())
		return true;
	return false;
}

bool collider::being_hitted(weapon *bullet)
{
	vector2d distance = this->center - bullet->postion;
	if (40 > distance.getLength()) {
		return true;
	}
	return false;
}
