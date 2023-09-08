#include <bits/stdc++.h>

int arr[200002];


using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    
    if(N > K) cout << N - K;
    else if(N == K) cout << 0;
    else{
        queue<int> Q;
        Q.push(N);
        arr[N] = 1;
        
        while(!Q.empty()){
            int start = Q.front(); Q.pop();
            for(int i = 0; i < 3; i++){
               int plus = 0; //시간 1초 또는 0초 
               int move = 0; //이동한 좌표, -1, +1, *2
               switch(i){
                   case 0: { move = start + 1; plus++; break;}
                   case 1: { move = start - 1; plus++; break;}
                   case 2: { move = start * 2; break;}
               } 
               if(move < 0 || move > K * 2) continue;
               if(arr[move] > 0){
                   arr[move] = min(arr[move], arr[start] + plus);
               }
               else{
                   arr[move] = arr[start] + plus;
                   //cout << "push: " << move <<" \n";
                   Q.push(move);
               }
            } 
        }
        
        cout << arr[K] - 1;
    }
    
}