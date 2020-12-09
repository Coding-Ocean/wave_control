#pragma once
#include"ENEMY.h"
class ENEMIES
{
    //
    struct NUM_DATA {
        int numAppearData = 0;
        int numWaveData = 0;
    };
    struct NUM_DATA NumData;
    //Appear data
    struct APPEAR_DATA {
        int type;
        float px;
        float py;
        float dx;
        float dy;
    };
    struct APPEAR_DATA* AppearData=0;
    //Wave data
    struct WAVE_DATA {
        int appearFrame;
        int numAppearEnemies;//最大同時出現数３体
        int appearDataIdxs[3];//２体以下の場合、余ったところに-1を設定(何でもよいのだが)
    };
    struct WAVE_DATA* WaveData=0;
    int WaveIdx = 0;
    int FrameCnt = 0;
    //data functions
    void CreateAppearData();
    void CreateWaveData();
    void CreateNumData();
    void CreateData();
    void LoadData();
    void FreeData();


    //Enemies
    int NumTypes = 3;//タイプ数
    int NumByType = 4;//タイプごとの数
    int NumEnemies = 0;
    class ENEMY* Enemies = 0;

    //１個のAPPEAR_DATAに従い、Enemy１体を出現させる
    void Appear(int idx);
public:
    ~ENEMIES();
    //タイプ別のEnemyを作る
    void create();
    //WAVEデータに従いEnemyを複数体同時に出現させる
    void wave();
    void move();
    void draw();
};

