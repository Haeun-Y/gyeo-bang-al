#include <bits/stdc++.h>

using namespace std;

int N;

void func(int n){
    int q = n / 3;
    if(q == 1){
        cout <<"- -";
        return;
    }
    for(int i = 0; i < 3; i++){
        if(i == 1){
            for(int j = 0; j < q; j++) cout <<" ";
        }
        else{
            func(q);
        }
    }
}

int main(){
    while(true){
        cin >> N;
        if(cin.eof()) break;
        int len = pow(3, N);
        if(len == 1) cout << '-';
        else func(len);
        cout << '\n';
    }
}