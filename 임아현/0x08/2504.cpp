#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL);
    
    string str;
    cin >> str;
    
    stack<int> S;
    
    int sum = 0; //총합 계산...
    int temp[31] = {0} ; //괄호 안의 값 계산
    int idx = 0;
    int flag = 0; //잘못된 괄호
    
    for(int i = 0; i < str.length(); i++){
        if(str.length() % 2 != 0) { //홀수 괄호 (올바르지 않음)
            flag = 1;
            break;
        }
        //1. 여는 괄호 
        if(str[i] == '[' || str[i] == '(') {
            S.push(str[i]);
            idx++;
        }
        //2. 닫는 괄호일 때
        else{
            if(S.empty()){
                flag = 1;
                break;
            }
            if(str[i] == ')' && S.top() == '(' ||str[i] == ']' && S.top() == '['){
               S.pop();
               //2-1. [] () 이런 괄호일 때
               if(str[i - 1] == '('){ 
                  // S.pop();
                   idx--;
                   if(S.empty()) sum += 2; //단독으로 () 있을 때
                   else temp[idx] += 2;
                }
                else if(str[i - 1] == '['){
                  // S.pop();
                   idx--;
                   if(S.empty()) sum += 3; //단독으로 [] 있을 때
                   else temp[idx] += 3;
                }
              //2-2. 바로 만나는 괄호가 아닐 때
                else{ 
                    if(!S.empty()){ //밖에 괄호가 더 있는 경우
                       if(str[i]==']'){
                           temp[idx] *= 3;
                           temp[idx - 1] += temp[idx];
                           temp[idx] = 0;
                           idx--;
                       }
                       else{
                           temp[idx] *= 2;
                           temp[idx - 1] += temp[idx];
                           temp[idx] = 0;
                           idx--;
                       }
                    }
                    else{ //입력으로 들어온모든 괄호가 짝을 찾음 계산 ㄱ
                       int asum = 0;
                       while(idx >= 0){
                           asum += temp[idx];
                           temp[idx] = 0;
                           idx--;
                       }
                       if(str[i]==']') sum += asum * 3;
                       else sum += asum * 2;
                       idx = 0; //idx 초기화 처음부터
                    }
                }
            }
            else{
                flag = 1;
                break;
            }
        }
    }
    if(S.empty() && flag == 0) cout<< sum;
    else cout << 0;
}