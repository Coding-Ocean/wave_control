#pragma once
#include"ENEMY.h"
class ENEMIES
{
    //Appear data
    struct APPEAR_DATA {
        int type;
        float px;
        float py;
        float dx;
        float dy;
    };
    struct APPEAR_DATA AppearData[11] = {
        0,100,-200,0,8,//0
        0,250,-200,0,8,//1
        0,400,-200,0,8,//2

        1,-200,100,8,0,//3
        1,600,250,-8,0,//4
        1,-200,400,8,0,//5

        2,190,-200,0,8,//6
        2,310,-200,0,8,//7

        0,100,-200,0,16,//8
        1,-200,250,8,0,//9
        2,400,-200,0,8,//10
    };

    //Wave data
    struct WAVE {
        int appearFrame;
        int numAppearEnemies;//�ő哯���o�����R��
        int appearDataIdxs[3];//�Q�̈ȉ��̏ꍇ�A�]�����Ƃ����-1��ݒ�(���ł��悢�̂���)
    };
    struct WAVE Waves[6] = {
        120,1,1,-1,-1,
        240,2,0,2,-1,
        360,3,0,1,2,
        480,3,3,4,5,
        600,2,6,7,-1,
        720,3,8,9,10,
    };
    int WaveIdx = 0;
    int FrameCnt = 0;

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

