//230324
//PROGRAMMERS 뒤에 있는 큰 수 찾기
//Lv.2
//82.6 -> 시간초과
#include <bits/stdc++.h>
using namespace std;
vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    for(int i = 0; i<numbers.size()-1; i++)
    {
        for(int j = i+1; j<numbers.size(); j++)
        {
            if(numbers[i] < numbers[j])
            {
                answer[i] = numbers[j];
                break;
            }
        }
    }
    return answer;
}