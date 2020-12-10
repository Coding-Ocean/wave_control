#include<stdio.h>
#include"../appOne/ENEMIES.h"

//AppearData,WaveData���ꂼ��̃f�[�^��
struct ENEMIES::NUM_DATA NumData;

void CreateAppearData() {
    //AppearData�s���𐔂���
    FILE* fp;
    fopen_s(&fp, "appear_data.txt", "r");
    char str[128];
    int numData = 0;
    while (fgets(str, 128, fp) != 0) {
        numData++;
    }
    //appear_data.txt�ǂݍ���
    ENEMIES::APPEAR_DATA* AppearData;
    AppearData = new ENEMIES::APPEAR_DATA[numData];
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
    fwrite(AppearData, sizeof(ENEMIES::APPEAR_DATA), numData, fp);
    fclose(fp);
    delete[] AppearData;
    //�f�[�^���̕ۑ�
    NumData.numAppearData = numData;
}
void CreateWaveData() {
    //WaveData�s���𐔂���
    FILE* fp;
    fopen_s(&fp, "wave_data.txt", "r");
    char str[128];
    int numData = 0;
    while (fgets(str, 128, fp) != 0) {
        numData++;
    }
    //wave_data.txt�ǂݍ���
    ENEMIES::WAVE_DATA* WaveData;
    WaveData = new ENEMIES::WAVE_DATA[numData];
    rewind(fp);
    for (int i = 0; i < numData; ++i) {
        fscanf_s(fp, "%d,%d,",
            &WaveData[i].appearFrame,
            &WaveData[i].appearDataIdx
        );
    }
    fclose(fp);
    //wave_data.bin��������
    fopen_s(&fp, "data/wave_data.bin", "w");
    fwrite(WaveData, sizeof(ENEMIES::WAVE_DATA), numData, fp);
    fclose(fp);
    delete[] WaveData;
    //�f�[�^���̕ۑ�
    NumData.numWaveData = numData;
}
//�e�f�[�^��
void CreateNumData() {
    FILE* fp;
    fopen_s(&fp, "data/num_data.bin", "w");
    fwrite(&NumData, sizeof(NumData), 1, fp);
    fclose(fp);
}

int main() {
    CreateAppearData();
    CreateWaveData();
    CreateNumData();
    return 0;
}