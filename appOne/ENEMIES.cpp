#include<stdio.h>
#include "ENEMIES.h"
ENEMIES::~ENEMIES() {
    FreeData();
    if (Enemies) { delete[] Enemies; Enemies = 0; }
}
void ENEMIES::create() {
    LoadData();
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
    while (WaveIdx < NumData.numWaveData &&
        FrameCnt == WaveData[WaveIdx].appearFrame) {
        Appear(WaveData[WaveIdx].appearDataIdx);
        ++WaveIdx;
        if (WaveIdx == NumData.numWaveData) {
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

void ENEMIES::LoadData() {
    FILE* fp;
    fopen_s(&fp, "data/num_data.bin", "r");
    fread(&NumData, sizeof(NUM_DATA), 1, fp);
    fclose(fp);

    AppearData = new APPEAR_DATA[NumData.numAppearData];
    fopen_s(&fp, "data/appear_data.bin", "r");
    fread(AppearData, sizeof(APPEAR_DATA), NumData.numAppearData, fp);
    fclose(fp);

    WaveData = new WAVE_DATA[NumData.numWaveData];
    fopen_s(&fp, "data/wave_data.bin", "r");
    fread(WaveData, sizeof(WAVE_DATA), NumData.numWaveData, fp);
    fclose(fp);
}
void ENEMIES::FreeData() {
    if (WaveData) { delete[] WaveData; WaveData = 0; }
    if (AppearData) { delete[] AppearData; AppearData = 0; }
}
