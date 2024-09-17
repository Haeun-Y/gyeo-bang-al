//240307
//programmers 가장 많이 받은 선물
//Lv.1
#include <bits/stdc++.h>
using namespace std;
vector<string> split(string str)
{
    vector<string> v;
    stringstream ss;
    string tmp;
    ss << str;
    
    while(ss >> tmp)
        v.push_back(tmp);
    return v;
}
int computeGiftPoint(int idx, vector<vector<int>>& v)
{
    int gNum = 0;
    int rNum = 0;
    for(int i = 0; i<v.size(); i++)
    {
        gNum += v[idx][i];
        rNum += v[i][idx];
    }
    return gNum - rNum;
}
int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    map<string, int> m;
    vector<vector<int>> v(friends.size(), vector<int>(friends.size(), 0));
    
    for(int i = 0; i<friends.size(); i++)
        m.insert(make_pair(friends[i], i));
    for(int i = 0; i<gifts.size(); i++)
    {
        vector<string> cur = split(gifts[i]);
        int giver = m[cur[0]];
        int receiver = m[cur[1]];
        
        v[giver][receiver]++;        
    }
    
    vector<int> giftPoint(friends.size(), 0);
    for(int i= 0; i<friends.size(); i++)
        giftPoint[i] = computeGiftPoint(i, v);
    
    //i번째 친구의 다음달 받을 선물수
    for(int i = 0; i<friends.size(); i++)
    {
        int nGift = 0;
        for(int j = 0; j<friends.size(); j++)
        {
            //여기에서 중복돼서 계산되는데 해결해보기
            if(i == j) continue;
            int gNum = v[i][j];
            int rNum = v[j][i];
            
            if(gNum > rNum) nGift++;
            else if(gNum == rNum && giftPoint[i] > giftPoint[j]) nGift++;
        }
        answer = max(answer, nGift);
    }
    
    return answer;
}