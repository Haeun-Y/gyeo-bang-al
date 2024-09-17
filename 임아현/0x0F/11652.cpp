#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

vector<long long> V; //정수 저장
int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        long long tmp;
        cin >> tmp;
        V.push_back(tmp);
    }
    //정렬
    sort(V.begin(), V.end());
    
    long long ans = V[0]; int mcnt = 0; int cnt = 1;
    for(int i = 0; i < N - 1; i++){
        if(V[i] == V[i + 1]){ 
            cnt++;
            if(i == N - 2){
                if(mcnt < cnt){
                mcnt = cnt;
                ans = V[i];
                cnt = 1;
               }
            }
        }
        else{
            if(mcnt < cnt){
                mcnt = cnt;
                ans = V[i];
                cnt = 1;
            }
            else cnt = 1;
        }
    }
    cout << ans;
}