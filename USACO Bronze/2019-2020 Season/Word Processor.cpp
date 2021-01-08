#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<string> words;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> K;
    int i; string s;
    for(i=0;i<N;i++){
        cin >> s;
        words.push_back(s);
    }
    int count = 0;
    for(i=0;i<N;i++){
        if(count + words[i].length() <= K){
            if(count > 0) cout << " ";
            cout << words[i];
            count += words[i].length();
        }
        else{
            cout << "\n" << words[i];
            count = words[i].length();
        }
    }
    cout << "\n";

    return 0;
}
