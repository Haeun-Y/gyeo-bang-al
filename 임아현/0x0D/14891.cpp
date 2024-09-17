#include <bits/stdc++.h>

using namespace std;

#define NUM 8

string wnum[4];
//top 12시 방향 
int TP[4] = {0}; 
int K;

void rotate(int n, int dir){
    //n번째 톱니 회전 방향
    int rot[4] = {0}; //0 회전 안 1: 시계 -1:반시계
    bool issame[4] = {0}; 
    int start = n - 1; 
    rot[start] = dir;
    
    for(int i = 0; i < 3; i++){
        char L = wnum[i][(TP[i] + 2) % NUM];
        char R = wnum[i + 1][(TP[i + 1] + 6) % NUM];
        if(L == R) issame[i] = 1; 
    }
    
    if(start == 0){
        for(int i = 0; i < 3; i++){
            if(!issame[i] && rot[i] != 0) rot[i + 1] = rot[i] * (-1);
            else rot[i + 1] = 0;
        }
    }
    else if(start == 1){
        if(issame[0]) rot[0] = 0;
        if(issame[1]) rot[2] = 0;
        if(!issame[0]) rot[0] = rot[1] * (-1); 
        if(!issame[1]) rot[2] = rot[1] * (-1);
        if(!issame[2] && rot[2] != 0) rot[3] = rot[2] * (-1);
        else rot[3] = 0;
    }
    
    else if(start == 2){
        if(issame[1]) rot[1] = 0;
        if(issame[2]) rot[3] = 0;
        if(!issame[1]) rot[1] = rot[2] * (-1); 
        if(!issame[2]) rot[3] = rot[2] * (-1);
        if(!issame[0] && rot[1] != 0) rot[0] = rot[1] * (-1);
        else rot[0] = 0;
    }
    
    else{
        for(int i = 3; i > 0; i--){
            if(!issame[i - 1] && rot[i] != 0) rot[i - 1] = rot[i] * (-1);
            else rot[i - 1] = 0;
        }
    }
    
    for(int i = 0; i < 4; i++){
        if(rot[i] == -1) TP[i] = (TP[i] + 1) % NUM;
        else if(rot[i] == 1) TP[i] = (TP[i] + NUM - 1) % NUM;
    }
}

int main()
{
    for(int i = 0; i < 4; i++){
        cin >> wnum[i];
    }
    
    cin >> K; //회전 수
    
    while(K--){
        //번호와 방향
        int n, dir;
        cin >> n >> dir; 
        rotate(n, dir);
    }
    
    int sum = 0;
    if(wnum[0][TP[0]] == '1') sum += 1;
    if(wnum[1][TP[1]] == '1') sum += 2;
    if(wnum[2][TP[2]] == '1') sum += 4; 
    if(wnum[3][TP[3]] == '1') sum += 8;
    
    cout << sum;
    
}