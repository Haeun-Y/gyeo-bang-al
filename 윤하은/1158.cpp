

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int peopleNum, target;
    scanf("%d %d", &peopleNum, &target);
    
    list<int> nums;
    int num =0;
    for(int i =1;i<=peopleNum; i++)
        nums.push_back(i);
    
    auto p = nums.begin();
    printf("<");
    while(!nums.empty())
    {
        for(int i = 0; i<target-1; i++)
        {    
            p++;
            if(p == nums.end()) p = nums.begin();
        }
        
        num = *p;
        p = nums.erase(p);
        if(!nums.empty()) printf("%d, ", num);
        if(p==nums.end()) p = nums.begin();
    }
    
    printf("%d>", num);
    
        
}
