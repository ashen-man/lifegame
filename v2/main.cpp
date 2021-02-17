#include <windows.h>
#include "lifegame.h"


int main(void) {
    bool field[HEIGHT][WIDTH];
    initialize(field);
    display(field);
    while(true) {
        evolve(field);
        Sleep(2000);
        display(field);
    }
    return 0;
}

