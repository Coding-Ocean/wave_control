#include"graphic.h"
#include "ENEMY.h"
void ENEMY::create(int type) {
    Type = type;
    switch (type) {
    case 0: R = 255; G = 200; B = 200; W = 100; H = 100; break;
    case 1: R = 255; G = 255; B = 160; W = 200; H = 100; break;
    case 2: R = 160; G = 160; B = 255; W = 100; H = 200; break;
    }
}
void ENEMY::appear(float px, float py, float dx, float dy) {
    Px = px;
    Py = py;
    Dx = dx;
    Dy = dy;
    Hp = 60*2;//Ç∆ÇËÇ†Ç¶Ç∏ÇQïbä‘ï\é¶
}
void ENEMY::move() {
    if (Hp) {
        Px += Dx;
        Py += Dy;
        Hp--;
    }
}
void ENEMY::draw() {
    if (Hp) {
        fill(R, G, B, A);
        rect(Px, Py, W, H);
    }
}