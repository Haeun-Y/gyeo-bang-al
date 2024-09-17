//BOJ 1406 에디터
#include <bits/stdc++.h>
using namespace std;
void commandL(list<char>& l, list<char>::iterator& iter)
{
    if(l.begin() == iter) return;
    iter--; 
}
void commandD(list<char>& l, list<char>::iterator& iter)
{
    if(l.end() == iter) return;
    iter++;
}
void commandB(list<char>& l, list<char>::iterator& iter)
{
    if(l.begin() == iter) return;
    iter = l.erase(--iter);
}
void commandP(list<char>& l, list<char>::iterator& iter)
{
    char ch;
    cin >> ch;
    l.insert(iter, ch);
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str;
    cin >> str;

    list<char> editor;
    for(char ch : str)
        editor.push_back(ch);

    list<char>::iterator cursor = editor.end();

    int commandNum;
    cin >> commandNum;

    for(int i = 0; i<commandNum; i++)
    {
        char command;
        cin >> command;
        
        switch(command)
        {
            case 'L':
                commandL(editor, cursor);
                break;
            
            case 'D':
                commandD(editor, cursor);
                break;
            
            case 'B':
                commandB(editor, cursor);
                break;
            
            case 'P':
                commandP(editor, cursor);
                break;

        }
    }

    for(char ch : editor)
        cout << ch;
        
}