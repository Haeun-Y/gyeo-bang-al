//240426
//BOJ 20055 컨베이어 벨트 위의 로봇
//GOLD 5
#include <iostream>
#include <vector>
using namespace std;
int n, k;
vector<pair<int, bool>> conveyor;
int compute0Block()
{
    int result = 0;
    for(int i = 0; i<2*n; i++)
    {
        if(conveyor[i].first == 0) result++;
    }
    return result;

}
void rotate()
{
    pair<int, bool> first = conveyor[2*n-1];
    for(int i = 2*n-2; i>= 0; i--)
        conveyor[i+1] = conveyor[i];
    
    conveyor[0] = first;

    if(conveyor[n-1].second)
        conveyor[n-1].second = false;

}
void robotMove()
{
    for(int i = n-2; i>= 0; i--)
    {
        if(conveyor[i].second && !conveyor[i+1].second && conveyor[i+1].first > 0)
        {
            conveyor[i].second = false;
            conveyor[i+1].second = true;
            conveyor[i+1].first--;
        }

    }

    if(conveyor[n-1].second)
        conveyor[n-1].second = false;


}
void putRobot()
{
    if(conveyor[0].first > 0 && !conveyor[0].first)
    {
        conveyor[0].first--;
        conveyor[0].first = true;
    }

}
int solution()
{
    int step = 0;

    while(compute0Block() < k)
    {
        step++;
        rotate();
        robotMove();
        putRobot();
    }
    return step;
    
}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    cin >> n >> k;
    conveyor = vector<pair<int, bool>>(2, {0, false});

    for(int i = 0; i<2*n; i++)
        cin >> conveyor[i].first;

    cout << solution();

}