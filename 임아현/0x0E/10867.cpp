#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> V;
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        V.push_back(num);
    }
    sort(V.begin(), V.end());
    
    int temp = V[0];
    cout << V[0];
    
    for(int i = 1; i < N; i++){
        if(temp != V[i]){
            cout <<" " << V[i];
            temp = V[i];
        }
        
    }
}