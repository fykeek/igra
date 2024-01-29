#include "TXLib.h"

struct GG {

    int x;
    int y;
    int v;
    int w;
    int h;

    void up() {
        txSetColor(RGB(244, 203, 77));
        txSetFillColor(RGB(244, 203, 77));
        txRectangle(x, y, x + w, y + h);
    }

    void left() {
        txSetColor(RGB(244, 203, 77));
        txSetFillColor(RGB(244, 203, 77));
        txRectangle(x, y, x + w, y + h);

        txSetColor(TX_WHITE);
        txSetFillColor(TX_WHITE);
        txRectangle(x + 10, y + 10, x + 20, y + 20);

        txSetColor(TX_BLACK);
        txSetFillColor(TX_BLACK);
        txRectangle(x + 10, y + 15, x + 15, y + 20);
    }

    void down() {
        txSetColor(RGB(244, 203, 77));
        txSetFillColor(RGB(244, 203, 77));
        txRectangle(x, y, x + w, y + h);

        txSetColor(TX_WHITE);
        txSetFillColor(TX_WHITE);
        txRectangle(x + 10, y + 10, x + 20, y + 20);
        txRectangle(x + 30, y + 10, x + 40, y + 20);

        txSetColor(TX_BLACK);
        txSetFillColor(TX_BLACK);
        txRectangle(x + 15, y + 15, x + 20, y + 20);
        txRectangle(x + 30, y + 15, x + 35, y + 20);
    }

    void right() {
        txSetColor(RGB(244, 203, 77));
        txSetFillColor(RGB(244, 203, 77));
        txRectangle(x, y, x + w, y + h);

        txSetColor(TX_WHITE);
        txSetFillColor(TX_WHITE);
        txRectangle(x + 30, y + 10, x + 40, y + 20);

        txSetColor(TX_BLACK);
        txSetFillColor(TX_BLACK);
        txRectangle(x + 35, y  + 15, x + 40, y + 20);
    }


};

struct dom {

    int x;
    int y;
    int w;
    int h;

    int xDoor;
    int yDoor;
    int wDoor;
    int hDoor;

    void draw () {
        txSetColor(RGB(252, 250, 158));
        txSetFillColor(RGB(252, 250, 158));
        txRectangle(x, y, x + w, y + h);

        txSetColor(TX_BROWN);
        txSetFillColor(TX_BROWN);
        txRectangle(xDoor, yDoor, xDoor + wDoor, yDoor + hDoor); //800, 500, 80, 100
    }

};

int main()
    {
    txCreateWindow (1200, 800);

    int i = 0;

    GG kub = {100, 100, 15, 50, 50};
    dom House = {750, 300, 300, 300, 800, 490, 80, 110};

    while (i != 1) {

        if (GetAsyncKeyState (VK_ESCAPE)) {i = 1;}

        txSetFillColor(TX_GREY);
        txClear();
        txBegin();

        House.draw();

        kub.down();

        if (GetAsyncKeyState('W')) {
            kub.up();
            kub.y -= kub.v;
        }

        else if (GetAsyncKeyState('A')) {
            kub.left();
            kub.x -= kub.v;
        }

        else if (GetAsyncKeyState('S')) {
            kub.down();
            kub.y += kub.v;
        }

        else if (GetAsyncKeyState('D')) {
            kub.right();
            kub.x += kub.v;
        }



        if (kub.x + kub.w <= House.xDoor + House.wDoor && kub.y + kub.h <= House.yDoor + House.hDoor &&
        kub.y >= House.yDoor && kub.x >= House.xDoor && GetAsyncKeyState(VK_LBUTTON)) {

            break;

        }


        if (kub.y < 0) {
            kub.y = 0;
        }


        if (kub.y > 800 - kub.h) {
            kub.y = 800 - kub.h;
        }

        if (kub.x < 0) {
            kub.x = 0;
        }

        if (kub.x + kub.w > 1200) {
            kub.x = 1200 - kub.w;
        }

        txEnd();
        txSleep(10);
    }

    while(i != 1) {

        if (GetAsyncKeyState (VK_ESCAPE)) {i = 1;}

        txSetFillColor(TX_GREY);
        txClear();
        txBegin();

        kub.x =

        kub.down();

        if (GetAsyncKeyState('W')) {
            kub.up();
            kub.y -= kub.v;
        }

        else if (GetAsyncKeyState('A')) {
            kub.left();
            kub.x -= kub.v;
        }

        else if (GetAsyncKeyState('S')) {
            kub.down();
            kub.y += kub.v;
        }

        else if (GetAsyncKeyState('D')) {
            kub.right();
            kub.x += kub.v;
        }


        if (kub.y < 0) {
            kub.y = 0;
        }


        if (kub.y > 800 - kub.h) {
            kub.y = 800 - kub.h;
        }

        if (kub.x < 0) {
            kub.x = 0;
        }

        if (kub.x + kub.w > 1200) {
            kub.x = 1200 - kub.w;
        }

        txEnd();
        txSleep(10);
    }

    txDisableAutoPause();
    txTextCursor (false);
    return 0;
}

