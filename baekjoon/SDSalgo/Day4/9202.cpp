#include <iostream>
#include <vector>
#include <string>
using namespace std;

int W, B;
string board[31][4];
bool visited[31][4][4];

class TrieNode
{
public:
    TrieNode *next[26] = {
        NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
        NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    bool isEnd = false;
    bool isHit = false;

    bool hasChild(int n)
    {
        return next[n] != NULL;
    }

    TrieNode *getChild(int n)
    {
        return next[n];
    }
};

class Trie
{
public:
    TrieNode *root = new TrieNode();

    void insert(string word)
    {
        if (word.length() == 0)
            return;
        TrieNode *current = root;
        for (int i = 0; i < word.length(); i++)
        {
            int index = word[i] - 'A';
            if (!current->hasChild(index))
            {
                current->next[index] = new TrieNode();
            }
            current = current->getChild(index);
        }
        current->isEnd = true;
    }

    bool checkWord(string word)
    {
        TrieNode *current = root;
        for (int i = 0; i < word.length(); i++)
        {
            int index = word[i] - 'A';
            if (!current->hasChild(index))
            {
                return false;
            }
            current = current->getChild(index);
        }

        if (current->isEnd && !current->isHit)
        {
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

int getSocre(int length)
{
    if (length < 3)
        return 0;
    if (length < 5)
        return 1;
    if (length == 5)
        return 2;
    if (length == 6)
        return 3;
    if (length == 7)
        return 5;
    if (length == 8)
        return 11;
    return 0;
}

int strcompare(string str, string str2)
{
    int i;
    for (i = 0; i < str2.length(); i++)
    {
        if (str[i] < str2[i])
            return -1;
        if (str[i] > str2[i])
            return 1;
    }
    return 1;
}

int mx[8] = {0, 0, -1, 1, 1, 1, -1, -1};
int my[8] = {-1, 1, 0, 0, 1, -1, 1, -1};

void dfs(int b, int i, int j, int length, string str, TrieNode *parent)
{
    visited[b][i][j] = true;

    if (TrieTree.checkWord(str))
    {
        foundCount++;
        maxScore += getSocre(length);
        if (length > maxStr.length() || (length == maxStr.length() && strcompare(str, maxStr) < 0))
        {
            maxStr = str;
        }
    }

    if (length >= 8)
    {
        visited[b][i][j] = false;
        return;
    }

    for (int x = 0; x < 8; x++)
    {
        int tx = i + mx[x];
        int ty = j + my[x];

        if (tx >= 0 && ty >= 0 && tx < 4 && ty < 4 && !visited[b][tx][ty] && parent->hasChild(board[b][tx][ty] - 'A'))
        {
            dfs(b, tx, ty, length + 1, str + board[b][tx][ty], parent->getChild(board[b][tx][ty] - 'A'));
        }
    }

    visited[b][i][j] = false;
}

void resetHit(TrieNode *parent)
{
    parent->isHit = false;
    for (int i = 0; i < 26; i++)
    {
        if (parent->hasChild(i))
        {
            resetHit(parent->getChild(i));
        }
    }
}

int main()
{

    cin >> W;
    int i, j, k;
    string tmp;
    for (i = 0; i < W; i++)
    {
        cin >> tmp;
        TrieTree.insert(tmp);
    }

    cin >> B;
    for (i = 0; i < B; i++)
    {
        for (j = 0; j < 4; j++)
        {
            cin >> board[i][j];
        }
    }

    for (i = 0; i < B; i++)
    {
        maxScore = 0;
        maxStr = "";
        foundCount = 0;
        resetHit(TrieTree.root);

        for (j = 0; j < 4; j++)
        {
            for (k = 0; k < 4; k++)
            {
                if (TrieTree.root->hasChild(board[i][j][k] - 'A'))
                {
                    dfs(i, j, k, 1, string(1, board[i][j][k]), TrieTree.root->getChild(board[i][j][k] - 'A'));
                }
            }
        }

        cout << maxScore << " " << maxStr << " " << foundCount << "\n";
    }
    return 0;
}
