#include "ENEMIES.h"
ENEMIES::~ENEMIES() {
    if (Enemies) { delete[] Enemies; Enemies = 0; }
}
void ENEMIES::create() {
    //�G�̑������^�C�v���~�^�C�v���Ƃ̐�
    NumEnemies = NumTypes * NumByType;
    Enemies = new ENEMY[NumEnemies];
    for (int i = 0; i < NumEnemies; i++) {
        //���ʂ��Ȃ������̃^�C�v���߁B
        int type = i / NumByType; //���̃f�[�^�Ȃ�000011112222�ɂȂ�
        Enemies[i].create(type);
    }
}
void ENEMIES::Appear(int idx){
    struct APPEAR_DATA& a = AppearData[idx];
    //�^�C�v�ԍ�����start��end�����߂�
    int start = a.type * NumByType;
    int end = start + NumByType;
    for (int i = start; i < end; i++) {
        if (Enemies[i].hp() == 0) {
            Enemies[i].appear(a.px, a.py, a.dx, a.dy);
            break;
        }
    }
}
void ENEMIES::wave() {
    ++FrameCnt;
    struct WAVE& wave = Waves[WaveIdx];
    if (FrameCnt >= wave.appearFrame) {
        for (int i = 0; i < wave.numAppearEnemies; i++) {
            Appear(wave.appearDataIdxs[i]);
        }
        //����Wave�̏���
        ++WaveIdx;
        if (WaveIdx == 6) {
            //�ŏ��ɖ߂�
            WaveIdx = 0;
            FrameCnt = 0;
        }
    }
}
void ENEMIES::move() {
    for (int i = 0; i < NumEnemies; i++) {
        Enemies[i].move();
    }
}
void ENEMIES::draw() {
    for (int i = 0; i < NumEnemies; i++) {
        Enemies[i].draw();
    }
}
