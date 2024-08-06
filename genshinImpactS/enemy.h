#pragma once
#include"gameObject.h"
#include"animation.h"
#include"Collider.h"
 


class enemy {
public:
    enemy();  // ���캯��
    ~enemy()=default; // ��������

    transform trans{ position, front_vector, 1 };

    void track_player(gameObject obj);
    void drawPlay(int delta);
protected:
    int speed;
    vector2d position{ 0,0 };
    vector2d front_vector{ 0,0 };
private:
    animation* anim_left;
    animation* anim_right;
};