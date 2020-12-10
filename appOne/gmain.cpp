#include"libOne.h"
#include"ENEMIES.h"
void gmain() {
#ifdef _DEBUG
    system("TextToBin");
#endif
    window(600, 600);
    class ENEMIES enemies;
    enemies.create();
    while(notQuit) {
        enemies.wave();
        enemies.move();
        clear(128);
        enemies.draw();
    }
}