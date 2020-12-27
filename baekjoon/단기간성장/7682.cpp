#include <iostream>

using namespace std;

string input = "";
char lastTurn = 'A';
int Xs = 0, Os = 0;

bool checkNumbers(){
    int i;
    for(i=0;i<9;i++){
        if(input[i] == 'X') Xs++;
        else if(input[i] == 'O') Os++;
    }

    if(Xs == Os){
        lastTurn = 'O';
        return true;
    }else if(Xs == Os + 1){
        lastTurn = 'X';
        return true;
    }
    else return false;
}

bool checkAlreadyWin(){
    int Xwins = 0;
    int Owins = 0;
    int i, j;
    //가로로 검사
    for(i=0; i<3; i++){
        bool Xflag = true;
        bool Oflag = true;
        for(j=0;j<3;j++){
            if(input[i*3+j] != 'X') Xflag = false;
            if(input[i*3+j] != 'O') Oflag = false;
        }
        if(Xflag) Xwins++;
        if(Oflag) Owins++;
    }
    //세로로 검사
    for(i=0; i<3; i++){
        bool Xflag = true;
        bool Oflag = true;
        for(j=0;j<3;j++){
            if(input[i+j*3] != 'X') Xflag = false;
            if(input[i+j*3] != 'O') Oflag = false;
        }
        if(Xflag) Xwins++;
        if(Oflag) Owins++;
    }
    //대각선 검사
    if(input[4] == 'O'){
        if(input[0] == 'O' && input[8] == 'O') Owins++;
        if(input[2] == 'O' && input[6] == 'O') Owins++;
    }
    else if (input[4] == 'X'){
        if(input[0] == 'X' && input[8] == 'X') Xwins++;
        if(input[2] == 'X' && input[6] == 'X') Xwins++;
    }

    if(Xwins == 0 && Owins == 0 && Xs + Os != 9) return false;
    if(Xwins > 0 && Owins > 0) return false;
    if(lastTurn == 'X' && Owins > 0) return false;
    if(lastTurn == 'O' && Xwins > 0) return false;
    return true;
}

int main(void){

    while(true){
        cin >> input;

        if(input == "end") break;

        Xs = 0; Os = 0;

        if(!checkNumbers()){
            printf("invalid\n");
            continue;
        }
        if(!checkAlreadyWin()){
            printf("invalid\n");
            continue;
        }
        
        printf("valid\n");
    }

    return 0;
}
