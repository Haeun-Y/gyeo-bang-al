//BOJ 15663 N과 M(9)
//틀렸습니다. 
#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v;
vector<int> seq;
//vector<string> result;
vector<bool> isUsed;
vector<vector<bool>> isUsedInPosition;
void func1(int cur)
{
    if(cur == m)
    {
        string str = "";
        for(int num : seq)
            str += to_string(num) + " ";
        //result.push_back(str);
        return;
    }
    else
    {
        for(int i = 0; i<n; i++)
        {
            //2 4 4
            //3개 중에 2개 뽑는다면
            //2 4
            //4 2
            //4 4
            //해당 cur 자리에 어떤 수가 들어간적이 잇는지- > x.. 
            if(isUsed[i] || isUsedInPosition[cur][v[i]]) continue;
            seq[cur] = v[i];
            isUsed[i] = true;

            func1(cur+1);
            isUsed[i] = false;
        }
    }

}
/*
void printResult()
{
    sort(result.begin(), result.end());
    for(int i = 0; i< result.size(); i++)
    {
        if(i > 0 && result[i-1] == result[i])
            continue;
        cout << result[i] << "\n";
    }
}*/
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    v = vector<int>(n, 0);
    isUsed = vector<bool>(n, false);
    seq = vector<int>(m, 0);
    isUsedInPosition = vector<vector<bool>>(m, vector<bool>(10005));

    for(int i = 0; i< n; i++)
        cin >> v[i];
    
    sort(v.begin(), v.end());

    func1(0);

    //printResult();
    

}