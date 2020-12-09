#include<iostream>
#include "ENEMIES.h"
ENEMIES::~ENEMIES() {
    FreeData();
    if (Enemies) { delete[] Enemies; Enemies = 0; }
}
void ENEMIES::create() {
    CreateData();
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
    struct WAVE_DATA& wave = WaveData[WaveIdx];
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

void ENEMIES::CreateAppearData() {
    //AppearData�s���𐔂���
    FILE* fp;
    fopen_s(&fp, "data/appear_data.txt", "r");
    char str[128];
    int numData = 0;
    while (fgets(str, 128, fp) != 0) {
        numData++;
    }

    //appear_data.txt�ǂݍ���
    AppearData = new APPEAR_DATA[numData];
    rewind(fp);
    for (int i = 0; i < numData; ++i) {
        fscanf_s(fp, "%d,%f,%f,%f,%f,",
            &AppearData[i].type,
            &AppearData[i].px, &AppearData[i].py,
            &AppearData[i].dx, &AppearData[i].dy
        );
    }
    fclose(fp);

    //appear_data.bin��������
    fopen_s(&fp, "data/appear_data.bin", "w");
    fwrite(AppearData, sizeof(APPEAR_DATA), numData, fp);
    fclose(fp);
    delete[] AppearData;

    NumData.numAppearData = numData;
}
void ENEMIES::CreateWaveData() {
    //WaveData�s���𐔂���
    FILE* fp;
    fopen_s(&fp, "data/wave_data.txt", "r");
    char str[128];
    int numData = 0;
    while (fgets(str, 128, fp) != 0) {
        numData++;
    }

    //wave_data.txt�ǂݍ���
    WaveData = new WAVE_DATA[numData];
    rewind(fp);
    for (int i = 0; i < numData; ++i) {
        fscanf_s(fp, "%d,%d,%d,%d,%d,",
            &WaveData[i].appearFrame,
            &WaveData[i].numAppearEnemies,
            &WaveData[i].appearDataIdxs[0],
            &WaveData[i].appearDataIdxs[1],
            &WaveData[i].appearDataIdxs[2]
        );
    }
    fclose(fp);

    //wave_data.bin��������
    fopen_s(&fp, "data/wave_data.bin", "w");
    fwrite(WaveData, sizeof(WAVE_DATA), numData, fp);
    fclose(fp);
    delete[] WaveData;

    NumData.numWaveData = numData;
}
void ENEMIES::CreateNumData() {
    FILE* fp;
    fopen_s(&fp, "data/num_data.bin", "w");
    fwrite(&NumData, sizeof(NUM_DATA), 1, fp);
    fclose(fp);
}
void ENEMIES::CreateData() {
    CreateAppearData();
    CreateWaveData();
    CreateNumData();
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
