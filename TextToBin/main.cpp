#include<stdio.h>
#include"../appOne/ENEMIES.h"

//AppearData,WaveDataそれぞれのデータ数
struct ENEMIES::NUM_DATA NumData;

void CreateAppearData() {
    //AppearData行数を数える
    FILE* fp;
    fopen_s(&fp, "appear_data.txt", "r");
    char str[128];
    int numData = 0;
    while (fgets(str, 128, fp) != 0) {
        numData++;
    }
    //appear_data.txt読み込み
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
    //appear_data.bin書き込み
    fopen_s(&fp, "data/appear_data.bin", "w");
    fwrite(AppearData, sizeof(ENEMIES::APPEAR_DATA), numData, fp);
    fclose(fp);
    delete[] AppearData;
    //データ数の保存
    NumData.numAppearData = numData;
}
void CreateWaveData() {
    //WaveData行数を数える
    FILE* fp;
    fopen_s(&fp, "wave_data.txt", "r");
    char str[128];
    int numData = 0;
    while (fgets(str, 128, fp) != 0) {
        numData++;
    }
    //wave_data.txt読み込み
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
    //wave_data.bin書き込み
    fopen_s(&fp, "data/wave_data.bin", "w");
    fwrite(WaveData, sizeof(ENEMIES::WAVE_DATA), numData, fp);
    fclose(fp);
    delete[] WaveData;
    //データ数の保存
    NumData.numWaveData = numData;
}
//各データ数
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