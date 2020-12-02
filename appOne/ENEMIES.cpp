#include "ENEMIES.h"
ENEMIES::~ENEMIES() {
    if (Enemies) { delete[] Enemies; Enemies = 0; }
}
void ENEMIES::create() {
    //敵の総数＝タイプ数×タイプごとの数
    NumEnemies = NumTypes * NumByType;
    Enemies = new ENEMY[NumEnemies];
    for (int i = 0; i < NumEnemies; i++) {
        //普通しない感じのタイプ決め。
        int type = i / NumByType; //今のデータなら000011112222になる
        Enemies[i].create(type);
    }
}
void ENEMIES::Appear(int idx){
    struct APPEAR_DATA& a = AppearData[idx];
    //タイプ番号からstartとendを求める
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
        //次のWaveの準備
        ++WaveIdx;
        if (WaveIdx == 6) {
            //最初に戻る
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
