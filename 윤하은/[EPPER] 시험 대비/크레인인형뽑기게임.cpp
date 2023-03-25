#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    
    stack<int> bucket;
    vector<queue<int>> qBoard(board.size(), queue<int>());
    
    for(int i = 0; i<board.size(); i++)
    {
        for(int j = 0; j<board[0].size(); j++)
        {
            if(board[i][j] != 0)
                qBoard[j].push(board[i][j]);
        }
        
    }
    
    int answer = 0;
    
    for(int i = 0; i<moves.size(); i++)
    {
        int curTarget = moves[i] -1;
        if(qBoard[curTarget].empty()) continue;
        else
        {
            if(!bucket.empty() && bucket.top() == qBoard[curTarget].front())
            {
                bucket.pop();
                answer += 2;
            }
            else
                bucket.push(qBoard[curTarget].front());
            
            qBoard[curTarget].pop();
        }
    }
    
    return answer;
}
/*
//주어진 이차원 배열에서 바로 해결하는 방법 -> 틀림.. .수정하기

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    
    stack<int> bucket;
    int answer = 0;
    
    
    for(int i = 0; i<moves.size(); i++)
    {
        int curTarget = moves[i]-1;
        int pos = 0;
        
        while(pos < board[curTarget].size() && board[curTarget][pos] == 0)
            pos++;
        
        //해당 칸이 인형이 없을 경우
        if(pos == board[curTarget].size())
            continue;
        
        else
        {
            if(!bucket.empty() && (bucket.top() == board[curTarget][pos]))
            {
                bucket.pop();
                answer += 2;
            }
            else bucket.push(board[curTarget][pos]);
            
            board[curTarget][pos] = 0;
            
        }
        
        
    }
    
    return answer;
}



*/