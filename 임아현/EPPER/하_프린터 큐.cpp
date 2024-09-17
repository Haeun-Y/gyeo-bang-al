#include <bits/stdc++.h>

using namespace std;

int solution(int N, int M, vector<int> V){
    int ans = 0;
    queue<int> Q;
    
    for(int i = 0; i < N; i++){
        Q.push(V[i]);
    }
    
    sort(V.begin(), V.end());
    
    while(true){
        if(Q.front() == V[V.size() - 1]){
            ans++;
            Q.pop();
            V.pop_back();
            if(M == 0) break; //내가 원하는 것 인쇄 
        }
        else{
            Q.push(Q.front()); //맨 앞의 원소 맨 뒤로 보내기 
            Q.pop();
        }
        
        if(M == 0) M = Q.size() - 1; //맨 뒤로 갔으니까 위치 변경
        else M--; //앞에 하나 빠졌으니까 앞으로 한 칸 
    }
    
    return ans;
}



int main()
{
    int TC;
    cin >> TC;
    while(TC--){
        vector<int> V ;
        int N, M;
        cin >> N >> M; //문서 개수, 순서 
        for(int i = 0; i < N; i++){
            int num;
            cin >> num;
            V.push_back(num);
        }
        
       cout << solution(N, M, V);
       cout << '\n';
    }
    
}