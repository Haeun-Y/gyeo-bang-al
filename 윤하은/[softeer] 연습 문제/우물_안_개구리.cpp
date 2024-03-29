//240329
//softeer 우물 안 개구리
//Lv.3
#include<bits/stdc++.h>
using namespace std;
vector<int> bestW;
vector<int> w;
int n, m;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    bestW = vector<int>(n, 0);
    w = vector<int>(n, 0);
    for(int i = 0; i<n; i++)
        cin >> w[i];
    
    for(int i = 0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        bestW[a] = max(bestW[a], w[b]);
        bestW[b] = max(bestW[b], w[a]);
    }

    int result = 0;
    for(int i = 0; i<n; i++) {
        if(bestW[i] < w[i]) {
            //cout << i+1 << " is Best\n";
            result++;
        }
    }

    cout << result;
    
   return 0;
}