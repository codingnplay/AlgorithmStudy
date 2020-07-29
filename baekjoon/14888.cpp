#include <iostream>

using namespace std;

int T;
int num[11];
int oper[4]; // + - * %

int Amax = -1000000000;
int Amin = 1000000000;

void solve(int idx, int currentNum, int oper0, int oper1, int oper2, int oper3){
    
    if(idx == T){
        if(currentNum > Amax) Amax = currentNum;
        if(currentNum < Amin) Amin = currentNum;
        return;
    }
    
    if(oper0 < oper[0]){
        solve(idx+1, currentNum+num[idx], oper0+1, oper1, oper2, oper3);
    }
    if(oper1 < oper[1]){
        solve(idx+1, currentNum-num[idx], oper0, oper1+1, oper2, oper3);
    }
    if(oper2 < oper[2]){
        solve(idx+1, currentNum*num[idx], oper0, oper1, oper2+1, oper3);
    }
    if(oper3 < oper[3]){
        solve(idx+1, currentNum/num[idx], oper0, oper1, oper2, oper3+1);
    }
}

int main()
{    
    cin >> T;
    int t;
    
    for(t=0; t<T; t++){
        cin >> num[t];
    }
    
    for(t=0; t<4; t++){
        cin >> oper[t];
    }
    
    solve(1, num[0], 0, 0, 0, 0);
    
    cout << Amax << "\n" << Amin;

    return 0;
}
