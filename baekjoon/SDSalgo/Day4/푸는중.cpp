#include <iostream>
#include <vector>
#include <string>
using namespace std;

int W, B;
string board[30][4];
bool visited[30][4][4];

class TrieNode{
    public:
    
    TrieNode* next[26] = { NULL, };
    bool isEnd;
    bool isHit;
    
    bool hasChild(int n){
        return next[n] != NULL;
    }
    
    TrieNode* getChild(int n){
        return next[n];
    }
};

class Trie{
  public:
    TrieNode* root = new TrieNode();

    void insert(string word){
        TrieNode* current = root;
        for(int i=0; i<word.length(); i++){
            int index = word[i] - 'A';
            if(current->hasChild(index) == false){
                current->next[index] = new TrieNode();
            }
            current = current->getChild(index);
        }
        current->isEnd = true;
    }
    
    bool checkWord(string word){
        TrieNode* current = root;
        for(int i=0; i<word.length(); i++){
            int index = word[i] - 'A';
            if(!current->hasChild(index)){
                cout << "here";
                return false;
            }
            current = current->getChild(index);
        }
        
        if(current->isEnd && !current->isHit){
            current->isHit = true;
            return true;
        }
        return false;
    }
};

int maxScore;
string maxStr;
int foundCount;
Trie TrieTree;

int getSocre(int length){
    if(length < 3) return 0;
    if(length < 5) return 1;
    if(length == 5) return 2;
    if(length == 6) return 3;
    if(length == 7) return 5;
    if(length == 8) return 11;
}

void dfs(int b, int i, int j, int length, string str){
    if(length == 1) visited[b][i][j] = true;
    
    int mx[] = {0,0,-1,1};
    int my[] = {-1,1,0,0};
    
    if(TrieTree.checkWord(str + board[b][i][j])){
        foundCount++;
        if(maxScore < getSocre(length)) {
            maxScore = getSocre(length);
            if(strcmp(maxStr, str) > 0){
                maxStr = str;
            }
        }
    }
    
    for(int x=0;i<4;i++){
        int tx = i+mx[x];
        int ty = j+my[x];
        
        if(tx>=0 && ty<=0 && tx<4 && ty<4 && !visited[b][tx][ty]){
            dfs(b, tx, ty, )
        }
    }
    
}

int main()
{
	
    cin >> W;
    int i, j, k;
    for(i=0;i<W;i++){
        string tmp;
        cin >> tmp;
        TrieTree.insert(tmp);
    }
    
    cin >> B;
    for(i=0; i<B; i++){
        for(j=0; j<4; j++){
            cin >> board[i][j];
        }
    }
    
    for(i=0; i<B; i++){
        maxScore = 0;
        maxStr = "";
        foundCount = 0;
        for(j=0; j<4; j++){
            for(k=0;k<4;k++){
                if(!visited[i][j][k] && TrieTree.root->hasChild(board[i][j][k] - 'A')){
                    dfs(i, j, k, 1, string(1, board[i][j][k]));
                }
            }
        }
    }
	return 0;
}
