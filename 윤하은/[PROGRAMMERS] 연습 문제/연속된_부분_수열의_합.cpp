//240312
//PROGRAMMERS 연속된 부분 수열의 합
//Lv.2
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int p1 = 0;
    int p2 = 0;
    int total = sequence[0];
    pair<int, int> sub;
    int size = sequence.size();
    int length = size+1;
    while(p1 >= 0 && p1<size && p2 >= 0 && p2 < size && p1 <= p2)
    {
        
        if(total < k)
            total += sequence[++p2];
        else if(total > k)
            total -= sequence[p1++];
        else if(total == k)//total == k
        {
            if(length > p2-p1+1)
            {
                length = p2-p1+1;
                sub.first = p1;
                sub.second = p2;
            }
            total -= sequence[p1++];
        }
    }
    answer.push_back(sub.first);
    answer.push_back(sub.second);
    return answer;
}
/*
//시간초과 55.9
vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int size = sequence.size();
    vector<int> sum(size+1, 0);
    
    sum[1] = sequence[0];
    
    for(int i = 1; i<size; i++)
        sum[i+1] = sum[i] + sequence[i];
    
    int length = size+1;
    pair<int, int> sub;
    for(int i = 1; i<=size; i++)
    {
        for(int j = i; j<=size; j++)
        {
            if(sum[j] - sum[i-1] == k && j-i+1 < length)
            {
                sub = {i-1, j-1};
                length = j-i+1;
                break;
            }
        }
    }
    answer.push_back(sub.first);
    answer.push_back(sub.second);
    return answer;
}*/