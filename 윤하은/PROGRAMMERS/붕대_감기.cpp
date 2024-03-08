//240308
//programmers [PCCP 기출문제] 1번 붕대감기
//Lv.1
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int curHealth = health;
    int combo = 0;
    int attackIdx = 0;
    for(int i = 0; i<=attacks[attacks.size()-1][0]; i++)
    {
        if(i == attacks[attackIdx][0])//attack
        {
            curHealth -= attacks[attackIdx][1];
            combo = 0;
            if(curHealth <= 0) return -1;
            attackIdx++;
        }
        else//no attack
        {
            curHealth = min(health, curHealth + bandage[1]);
            combo++;
            if(combo == bandage[0])
            {
                combo = 0;
                curHealth = min(health, curHealth + bandage[2]);
            }
            
        }
        
    }
    return curHealth;
}