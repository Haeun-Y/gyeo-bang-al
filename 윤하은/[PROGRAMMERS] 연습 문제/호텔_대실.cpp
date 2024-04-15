//230321
//PROGRAMMERS 호텔 대실
//Lv.2
#include <bits/stdc++.h>
using namespace std;
int strToTime(string str)
{
    return stoi(str.substr(0, 2)) * 60 + stoi(str.substr(3, 2));
}
bool cmp(vector<string> v1, vector<string> v2)
{
    return strToTime(v1[0]) < strToTime(v2[0]);
}
void assignRoom(vector<string>& book, vector<int>& rooms)
{
    //무조건 빈방을 찾으면 빈방에 넣는 것이 최소객실의 수를 보장해줄 수 있는가?
    for(int i = 0; i<rooms.size(); i++)
    {
        if(rooms[i]+10 <= strToTime(book[0]))
        {
            rooms[i] = strToTime(book[1]);
            return;
        }
    }
    rooms.push_back(strToTime(book[1]));
}
int solution(vector<vector<string>> book_time) {
    sort(book_time.begin(), book_time.end(), cmp);
    
    vector<int> rooms;
    
    for(int i = 0; i<book_time.size(); i++)
        assignRoom(book_time[i], rooms);
    
    return rooms.size();
}