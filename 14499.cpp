#include <iostream>
using namespace std;

int dice[6] = { 0, 0, 0, 0, 0, 0 };
int diceX, diceY;
int N, M, K;
int** board;
int* command;

void dice_w() {
    int tmp[6];
    for (int i = 0; i < 6; i++) tmp[i] = dice[i];
    dice[1] = tmp[0];
    dice[5] = tmp[1];
    dice[3] = tmp[5];
    dice[0] = tmp[3];
}

void dice_e() {
    int tmp[6];
    for (int i = 0; i < 6; i++) tmp[i] = dice[i];
    dice[5] = tmp[3];
    dice[3] = tmp[0];
    dice[0] = tmp[1];
    dice[1] = tmp[5];
}

void dice_n() {
    int tmp[6];
    for (int i = 0; i < 6; i++) tmp[i] = dice[i];
    dice[4] = tmp[0];
    dice[0] = tmp[2];
    dice[2] = tmp[5];
    dice[5] = tmp[4];
}

void dice_s() {
    int tmp[6];
    for (int i = 0; i < 6; i++) tmp[i] = dice[i];
    dice[0] = tmp[4];
    dice[2] = tmp[0];
    dice[4] = tmp[5];
    dice[5] = tmp[2];
}

int main()
{
    cin >> N >> M >> diceX >> diceY >> K;

    board = new int* [N];
    for (int i = 0; i < N; i++) {
        board[i] = new int[M];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    command = new int[K];
    for (int i = 0; i < K; i++) {
        cin >> command[i];
    }

    for (int i = 0; i < K; i++) {
        switch (command[i]) {
        case 1: 
            //east
            diceY++;  
            break;
        case 2: 
            //west
            diceY--;
            break;
        case 3: 
            //north
            diceX--;
            break;
        case 4: 
            //south
            diceX++;
            break;
        }

        if (diceX < 0 || diceX >= N || diceY < 0 || diceY >= M) {
        
            switch (command[i]) {
            case 1:
                diceY--;
                break;
            case 2:
                diceY++;
                break;
            case 3:
                diceX++;
                break;
            case 4:
                diceX--;
                break;
            }

            continue;
        } 
        
        switch (command[i]) {
        case 1:
            dice_e();
            break;
        case 2:
            dice_w();
            break;
        case 3:
            dice_n();
            break;
        case 4:
            dice_s();
            break;
        }
        
        if (board[diceX][diceY] == 0) {
            board[diceX][diceY] = dice[5];
        }
        else {
            dice[5] = board[diceX][diceY];
            board[diceX][diceY] = 0;
        }

        cout << dice[0] << "\n";
    }
}