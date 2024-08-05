//240805
//softeer 염기서열 커버
//Lv.3
#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<string> seq;
bool coverStr(string target, string str)
{
    char ns[4] = {'a', 'c', 'g', 't'};
    for(int i = 0; i<target.length(); i++)
    {
        if(str[i] == '.') continue;
        else if(ns[str[i]-'0'] != target[i]) return false;
        cout << "cur ch : " << ns[str[i]-'0'] << "\n";
    }
    return true;
}
void coverSeq(int target, vector<bool>& result)
{
    string targetStr = "";
    int num = target;
    while(num/4 > 0)
    {
        targetStr = (char)(num%4 + '0') + targetStr; 
        num /= 4;
    }
    if(targetStr.length() < m) 
        for(int i = 0; i<m; i++) targetStr = '0' + targetStr;
    
    cout << "targetStr : " << targetStr << "\n";

    for(int i = 0; i<n; i++)
    {
        if(result[i]) continue;
        if(coverStr(targetStr, seq[i])) result[i] = true;
    }
}
int solution()
{
    int size = pow(4, m);
    cout << "size : " << size <<"\n";
    const int maxSeqNum = 15;
    vector<int> v(size, 1);

    
    for(int i = 1; i<=15; i++)
    {
        for(int j = 0; j<i; j++) v[j] = 0;

        do
        {
            vector<bool> isCovered(n, false);
            for(int k = 0; k<size; k++)
            {
                if(v[k] == 0) //selected
                    coverSeq(k, isCovered);
            }

            bool answer = true;
            for(int k = 0; k<n; k++)
                if(!isCovered[k]) answer = false;

            if(answer) return i;
             
        }while(next_permutation(v.begin(), v.end()));
    }
    
    
}
int main(int argc, char** argv)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    cin >> n >> m;
    seq = vector<string>(n);

    for(int i = 0; i<n; i++) 
        cin >> seq[i];
    

    cout << solution();

   return 0;
}