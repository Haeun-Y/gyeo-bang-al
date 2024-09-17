//BOJ 2504 괄호의 값
#include <bits/stdc++.h>
using namespace std;
//()이거나 []인 경우를 확인해주는 함수
int func1(string& str, int i)
{
    if(str.length()-1 == i) return -1;
    else if(str[i] == '(' && str[i+1] == ')') return 2;
    else if(str[i] == '[' && str[i+1] == ']') return 3;
    else return -1;
}
void printStack(stack<int>& s1)
{
    stack<int> s2 = s1;
    
    while(!s2.empty())
    {
        int num = s2.top();
        s2.pop();
        
        switch(num)
        {
            case -2:
                cout << "(";
                break;
            case -3:
                cout << "[";
                break;
            default:
                cout << num;
        }
    }
    cout << "\n";
    
}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    
    string str;
    cin >> str;

    stack<int> s;
    int result = 0;

    for(int i = 0; i<str.length(); i++)
    {
        //cout << "str[i] : " << str[i] << "\n";
        //cout << "...before...\n";
        //printStack(s);
        int tmp = func1(str, i);
        if(tmp != -1) 
        {
            s.push(tmp);
            i++;
            continue;
        }

        else if(str[i] == '(')
            s.push(-2);

        else if(str[i] == '[')
            s.push(-3);

        else//닫는 괄호인 경우
        {
            if(s.empty())//올바르지 못한 괄호열
            {
                result = 0;
                //cout << "error\n";
                break;
            }
            
            bool isSmallParen = (str[i] == ')')? true : false;
                
            if(s.top() == ((isSmallParen)?-3:-2))//올바르지 않은 괄호열
            {
                result = 0;
                //cout << "error\n";
                break;
            }
            
            //위 if문을 통해 올바르지 않은 괄호열인 경우를 처리했기 때문에 num은 숫자임이 보장됨.
            int num = s.top();
            s.pop();

            while(!s.empty() && s.top() >= 0)//s.top 이 숫자일 경우
            {
                num += s.top();
                s.pop();                 
            }
            if(s.empty() || (!s.empty() && s.top() == ((isSmallParen)?-3:-2)))//올바르지 않은 괄호열
            {
                result = 0;
                //cout << "error\n";
                break;
            }
            else//올바른 괄호열
            {
                s.pop();
                s.push(num * ((isSmallParen)?2:3));
            }

            
        }
        
        //cout << "..after..\n";
        //printStack(s);

    }

    while(!s.empty())
    {
        if(s.top() < 0) //parenthesis is remained.
        {
            result = 0;
            break;
        }
        else
        {
            result += s.top();
            s.pop();
        }
    }

    cout << result;
    
}
