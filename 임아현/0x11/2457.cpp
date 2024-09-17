//다시 풀어보기 

#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    
    vector<pair<int, int>> f;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        f.push_back({a * 100 + b, c * 100 + d}); //1101 301 이런 식으로 날짜 저장하기
    }
    
    int st = 301; //3월 1일부터 시작함
    int cnt = 0; //꽃 개수 세기
    
    while(st < 1201){ //12월 1일 전까지니까까
        int nt = st; 
        for(int i = 0; i < N; i++){
            if(f[i].X <= st && f[i].Y > nt){
                nt = f[i].Y;
            }
        }
        
        //둘이 같다는 건 다 채울 수 없단 의미 (위에서 N까지 다 확인함함)
        if(nt == st){
            cout << 0;
            return 0; //0 출력 후 종려
        }
        cnt++;
        st = nt;
    }
    cout << cnt;
}