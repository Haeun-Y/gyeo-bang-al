//1111 E 111 A 11 B 1 C X D
#include <bits/stdc++.h>
using namespace std; 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num, sum; 
    
    for(int i = 0; i < 3; i++){
        sum = 0;
        for(int j = 0 ; j < 4; j++){
            cin >> num; //하나씩 입력
            sum += num;
        }
        if(sum == 4) cout << 'E' << '\n';
        else if(sum == 3) cout << 'A' << '\n';
        else if(sum == 2) cout << 'B' << '\n';
        else if(sum == 1) cout << 'C'<< '\n';
        else cout << 'D' << '\n';
    }
}