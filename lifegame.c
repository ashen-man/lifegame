#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define WIDTH 10
#define HEIGHT 10

// todo: copy
int FIELD[HEIGHT][WIDTH];

void display(void);
void initialize(void);
void evolve(void);
int is_alive(int, int);

int main(void) {
    initialize();
    display();
    while(1) {
        evolve();
        Sleep(1000);
        display();
    }
    return 0;
}

void display(void) {
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            printf("%d", FIELD[y][x]);
        }
        printf("\n");
    }
    printf("\n");
}

void initialize(void) {
    for (int row = 0; row < HEIGHT; row++) {
        for (int column = 0; column < WIDTH; column++) {
            FIELD[row][column] = rand() % 2;
        }
    }
}

void evolve(void) {
    for (int row = 0; row < HEIGHT; row++) {
        for (int column = 0; column < WIDTH; column++) {
            FIELD[row][column] = is_alive(row, column);
        }
    }
}

int is_alive(int row, int column) {
    int count = 0;

    int lower = row == HEIGHT-1 ? 0 : row+1;
    int upper = row == 0 ? HEIGHT-1 : row-1;
    int right = column == WIDTH-1 ? 0 : column+1;
    int left = column == 0 ? WIDTH-1 : column-1;

    int neighbors[8][2] = {
        {upper, left},
        {upper, column},
        {upper, right},
        {row, left},
        {row, right},
        {lower, left},
        {lower, column},
        {lower, right}
    };
    for (int i = 0; i < 8; i++) {
        if (FIELD[neighbors[i][0]][neighbors[i][1]] == 1) {
            count++;
        }
    }
    switch (count) {
        case 2: return FIELD[row][column] == 1 ? 1 : 0;
        case 3: return 1;
        default: return 0;
    }
}
