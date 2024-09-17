//BOJ 1158 요세푸스 문제
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin >> n >> k;

    list<int> peopleInCircle;
    
    for(int i = 0; i<n; i++)
        peopleInCircle.push_back(i+1); // {1, 2, 3, ... , n-1, n}

    list<int>::iterator iter = peopleInCircle.begin();

    cout << "<";

    while(!peopleInCircle.empty())
    {
        int target = k;
        if(k%peopleInCircle.size() != 0)
            target = k%peopleInCircle.size();

        for(int i = 0; i<target-1; i++)
        {
            iter++;
            if(iter == peopleInCircle.end()) iter = peopleInCircle.begin();
        }
        
        if(peopleInCircle.size() == 1)
            cout << *iter << ">";
        else cout << *iter << ", ";

        iter = peopleInCircle.erase(iter);
        if(iter == peopleInCircle.end()) iter = peopleInCircle.begin();
    }

    
}