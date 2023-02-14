#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

vector<long long> V;
int N;

//원소 거꾸로 뒤집기
long long change(string str){
    long long cnum = 0; //바뀐 숫자
    int digit = 0; //자리수 
    for(auto i: str){
       cnum += (i - 48) * pow(10, digit);
       digit++;
    }
    return cnum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        string tmp;
        cin >> tmp;
        V.push_back(change(tmp));
    }
    //정렬
    sort(V.begin(), V.end());
    
    for(int i = 0; i < N; i++){
        cout << V[i] << '\n';
    }
}