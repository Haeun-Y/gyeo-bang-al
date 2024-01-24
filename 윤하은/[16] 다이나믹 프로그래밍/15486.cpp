//240124
//BOJ 15486 퇴사2
//SILVER 3
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct
{
    int startDay;
    int finishDay;
    int pay;
}reservation;
int n;
vector<reservation> consulting;
bool cmp(reservation a, reservation b)
{
    return a.finishDay < b.finishDay;
}
long long func1()
{
    int result = 0;
    for(int i = 0; i<n; i++)
    {
        if(i > 0 && consulting[i-1].finishDay == consulting[i].finishDay)
        {
            int beforePay = consulting[i-1].pay;
            int curPay = consulting[i].pay;
            if(beforePay < curPay)
                result = result - beforePay + curPay;
        }

        else
            result += consulting[i].pay;
    }

}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    cin >> n;

    for(int i = 1; i<=n; i++)
    {
        int t, p;
        cin >> t >> p;
        consulting.push_back({i, i+t-1, p});
    }

    sort(consulting.begin(), consulting.end(), cmp);
    cout << func1();
}