//240311
//PROGRAMMERS 두 원 사이의 정수 쌍
//Lv.2
//60
#include <bits/stdc++.h>
using namespace std;
bool isIncluded(int x, int y, int r1, int r2)
{
    double dist = sqrt(x*x + y*y);
    if(dist >= r1 && dist <= r2)
        return true;
    else return false;
}
long long solution(int r1, int r2) {
    long long answer = 0;
    for(int x = -r2; x< 0; x++)
    {
        for(int y = -r2; y< 0; y++)
        {
            if(isIncluded(x, y, r1, r2))
                answer++;
        }
    }
    return answer * 4 + (r2-r1+1) * 4;
}