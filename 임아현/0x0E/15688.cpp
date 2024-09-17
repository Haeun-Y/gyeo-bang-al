#include <bits/stdc++.h>

using namespace std;

vector<int> vec;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end());
    
    for(int i = 0; i < N; i++){
        cout << vec[i] << '\n';
    }
    
}