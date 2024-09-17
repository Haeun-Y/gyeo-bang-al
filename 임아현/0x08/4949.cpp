#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    int flag;
    
    while(true){
        flag = 0;
        stack<char> S;
        getline(cin, str);
        if(str == ".") break;
        for(auto c: str){
            if(c == '[' || c == '(') S.push(c);
            else if(c == ']' ||  c == ')'){
                if(S.empty()){ //닫힌 괄호가 나왔는데 스택이 빔
                    flag = 1;
                    cout << "no\n";
                    break;
                }
                else if(c == ')' && S.top() == '('|| c == ']' && S.top() == '['){
                    S.pop();
                }
                else{ //괄호 종류가 안 맞음 
                    flag = 1;
                    cout << "no\n";
                    break;
                }
            } 
        }
        if(!flag) {
            if(S.empty())
              cout << "yes\n";
            else cout << "no\n";
        }
    }
}