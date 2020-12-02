#pragma once
class ENEMY
{
    float Px=0, Py=0, Dx=0, Dy=0;
    float W = 0, H = 0;
    float R=255, G=255, B=255, A=255;
    int Type=-1;
    int Hp=0;
public:
    int hp() { return Hp; }
    int type() { return Type; }
    void create(int type);
    void appear(float px, float py, float dx, float dy);
    void move();
    void draw();
};

