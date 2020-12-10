#pragma once
#include"ENEMY.h"
class ENEMIES{
public:
    ~ENEMIES();
    //�^�C�v�ʂ�Enemy�����
    void create();
    //WAVE�f�[�^�ɏ]��Enemy�𕡐��̏o��������
    void wave();
    void move();
    void draw();
    //���J�f�[�^�^
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
    //Wave����f�[�^
    struct NUM_DATA NumData;
    struct APPEAR_DATA* AppearData=0;
    struct WAVE_DATA* WaveData=0;
    int WaveIdx = 0;
    int FrameCnt = 0;
    //data functions
    void LoadData();
    void FreeData();

    //Enemies
    int NumTypes = 3;//�^�C�v��
    int NumByType = 4;//�^�C�v���Ƃ̐�
    int NumEnemies = 0;
    class ENEMY* Enemies = 0;
    //�P��APPEAR_DATA�ɏ]���AEnemy�P�̂��o��������
    void Appear(int idx);
};

