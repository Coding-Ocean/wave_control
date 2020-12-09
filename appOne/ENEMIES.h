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
        int numAppearEnemies;//�ő哯���o�����R��
        int appearDataIdxs[3];//�Q�̈ȉ��̏ꍇ�A�]�����Ƃ����-1��ݒ�(���ł��悢�̂���)
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
    int NumTypes = 3;//�^�C�v��
    int NumByType = 4;//�^�C�v���Ƃ̐�
    int NumEnemies = 0;
    class ENEMY* Enemies = 0;

    //�P��APPEAR_DATA�ɏ]���AEnemy�P�̂��o��������
    void Appear(int idx);
public:
    ~ENEMIES();
    //�^�C�v�ʂ�Enemy�����
    void create();
    //WAVE�f�[�^�ɏ]��Enemy�𕡐��̓����ɏo��������
    void wave();
    void move();
    void draw();
};

