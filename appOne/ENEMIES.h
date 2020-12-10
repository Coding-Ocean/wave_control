#pragma once
#include"ENEMY.h"
class ENEMIES{
public:
    ~ENEMIES();
    //タイプ別のEnemyを作る
    void create();
    //WAVEデータに従いEnemyを複数体出現させる
    void wave();
    void move();
    void draw();
    //公開データ型
    struct NUM_DATA {
        int numAppearData = 0;
        int numWaveData = 0;
    };
    struct APPEAR_DATA {
        int type;
        float px;
        float py;
        float dx;
        float dy;
    };
    struct WAVE_DATA {
        int appearFrame;
        int appearDataIdx;
    };
private:
    //Wave制御データ
    struct NUM_DATA NumData;
    struct APPEAR_DATA* AppearData=0;
    struct WAVE_DATA* WaveData=0;
    int WaveIdx = 0;
    int FrameCnt = 0;
    //data functions
    void LoadData();
    void FreeData();

    //Enemies
    int NumTypes = 3;//タイプ数
    int NumByType = 4;//タイプごとの数
    int NumEnemies = 0;
    class ENEMY* Enemies = 0;
    //１個のAPPEAR_DATAに従い、Enemy１体を出現させる
    void Appear(int idx);
};

