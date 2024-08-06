#include"vector2d.h"

float Q_rsqrt(float number) {
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;
    i = *(long*)&y;                       // ����������λģʽ���Ƶ�������
    i = 0x5f3759df - (i >> 1);               // ����ĳ�����λ����
    y = *(float*)&i;                      // ��λģʽ���ƻظ�������
    y = y * (threehalfs - (x2 * y * y));   // ţ�ٵ�������һ�ε���
    // y  = y * ( threehalfs - ( x2 * y * y ) ); // �����Ҫ���ߵľ��ȣ������ٽ���һ�ε���

    return y;
}
vector2d::vector2d(float inX, float inY) : x(inX), y(inY) {};

void vector2d::setVector(float inX, float inY)
{
	x = inX;
	y = inY;
}

vector2d vector2d::operator +(const vector2d& vector) const {
	return vector2d(x + vector.x, y + vector.y);
}

vector2d vector2d::operator-(const vector2d& vector) const
{
	return vector2d(x-vector.x, y - vector.y);
}

vector2d vector2d::operator*(float scalar) const
{
	return vector2d(x* scalar,y* scalar);
}

vector2d vector2d::normalized(vector2d& vec)
{
    float rlength= Q_rsqrt(static_cast<float>(vec.x * vec.x + vec.y * vec.y));
    return vector2d(vec.x * rlength, vec.y * rlength);

}

float vector2d::getLength()
{
	return sqrt(x * x + y * y);
}
