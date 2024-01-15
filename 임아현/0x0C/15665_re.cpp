#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> num;
int save[8];


void func(int k){
    if(k == M){
        for(int i = 0; i < M; i++){
            cout << num[save[i]] <<' ';
        }
        cout << "\n";
        return;
    }
    
    for(int i = 0; i < num.size(); i++){
        save[k] = i;
        func(k + 1);
    }
}

int main()
{
    cin >> N >> M;
    
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        num.push_back(temp);
    }
    
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
    
    func(0);
}