#include <iostream>
#include <cmath>
#include <queue>
#include <list>

using namespace std;

struct node{
    int x, y, value;
};

int board[501][1001];
int tileNum[501][1001];
int route[5000001];
bool visited[501][1001];
int N;
queue<node> bfsQueue;
int endTileNum;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;

    int i, j, x, y;
    int k=1;
    for(i=1;i<=N;i++){
        if(i%2==1){
            for(j=0;j<N;j++){
                cin >> x >> y;
                board[i][j*2]=x;
                board[i][j*2+1]=y;
                tileNum[i][j*2]=k;
                tileNum[i][j*2+1]=k++;
            }
        }
        else{
            for(j=0;j<N-1;j++){
                cin >> x >> y;
                board[i][j*2+1]=x;
                board[i][j*2+2]=y;
                tileNum[i][j*2+1]=k;
                tileNum[i][j*2+2]=k++;
            }
        }
    }

    visited[1][0] = true;
    visited[1][1] = true;
    bfsQueue.push({1,0,board[1][0]});
    bfsQueue.push({1,1,board[1][1]});

    int tx[4] = {0,1,-1,0};
    int ty[4] = {1,0,0,-1};

    while(!bfsQueue.empty()){
        x = bfsQueue.front().x;
        y = bfsQueue.front().y;
        int v = bfsQueue.front().value;
        bfsQueue.pop();

        if(tileNum[x][y] > endTileNum) endTileNum = tileNum[x][y];

        if(tileNum[x][y] == k-1){
            break;
        }

        for(i=0;i<4;i++){
            int dx = x + tx[i];
            int dy = y + ty[i];

            if(dx >= 1 && dx <= N){
                if(dx%2==1 && dy >= 0 && dy < 2*N){
                    if(!visited[dx][dy] && board[dx][dy] == v){
                        route[tileNum[dx][dy]] = tileNum[x][y];
                        visited[dx][dy] = true;
                        bfsQueue.push({dx, dy, board[dx][dy]});
                        if(dy%2==0 && !visited[dx][dy+1]){
                            visited[dx][dy+1] = true;
                            bfsQueue.push({dx, dy+1, board[dx][dy+1]});
                        }
                        if(dy%2==1 && !visited[dx][dy-1]){
                            visited[dx][dy-1] = true;
                            bfsQueue.push({dx, dy-1, board[dx][dy-1]});
                        }
                    }
                }
                else if(dx%2 == 0 && dy > 0 && dy < 2*N-1){
                    if(!visited[dx][dy] && board[dx][dy] == v){
                        route[tileNum[dx][dy]] = tileNum[x][y];
                        visited[dx][dy] = true;
                        bfsQueue.push({dx, dy, board[dx][dy]});
                        if(dy%2==1 && !visited[dx][dy+1]){
                            visited[dx][dy+1] = true;
                            bfsQueue.push({dx, dy+1, board[dx][dy+1]});
                        }
                        if(dy%2==0 && !visited[dx][dy-1]){
                            visited[dx][dy-1] = true;
                            bfsQueue.push({dx, dy-1, board[dx][dy-1]});
                        }
                    }
                }
            }
        }

    }

    list<int> ans;
    while(endTileNum != 1){
        ans.push_front(endTileNum);
        endTileNum = route[endTileNum];
    }
    ans.push_front(endTileNum);

    cout << ans.size() << "\n";
    for(int a : ans){
        cout << a << " " ;
    }

    return 0;
}
