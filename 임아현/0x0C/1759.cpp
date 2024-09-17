#include <bits/stdc++.h>

using namespace std;

char alp[17];
char str[17];
bool check[17];

int L, C;

void func(int cnt, int idx){
    if(cnt == L){
        int vow = 0;
        for(int i = 0; i < L; i++){
            char a = str[i];
            if(a == 'a' || a == 'e'|| a == 'i' || a == 'o' || a == 'u'){
                vow++;
            }
        }
        if(vow > 0 && L - vow > 1){
          for(int i = 0; i < L; i++)
             cout << str[i];
          cout << '\n';
        }
        return;
    }
    
    for(int i = idx; i < C; i++){
        if(!check[i]){
            str[cnt] = alp[i];
            check[i] = 1;
            func(cnt + 1, i);
            check[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> L >> C;
    
    for(int i = 0; i < C; i++){
        cin >> alp[i];
    }
    
    sort(alp, alp + C);
    
    func(0, 0);
}