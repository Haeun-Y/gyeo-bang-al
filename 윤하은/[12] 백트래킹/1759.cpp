//240822 BOJ 1759 암호 만들기
//GOLD 5
//틀렸습니다
#include <bits/stdc++.h>
using namespace std;
int l, c;
vector<char> alphabets;
vector<char> pw;
bool isVowel(char& ch)
{
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
    else return false;
}
void solution(int preIdx, int idx, int vNum, int cNum)
{
    if(idx == l)
    {
        if(vNum < 1 || cNum < 2) return;
        else 
        {
            for(int i = 0; i<l; i++)
                cout << pw[i];
            cout << "\n";
            return;
        }
    }
    else 
    {
        for(int i = preIdx+1; i<c; i++)
        {
            char ch = alphabets[i];
            pw[idx] = ch;
            if(isVowel(ch)) solution(i, idx+1, vNum+1, cNum);
            else solution(i, idx+1, vNum, cNum+1);
        }
    }
    
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> l >> c;
    
    pw = vector<char>(l);
    alphabets = vector<char>(c);
    
    for(int i = 0; i<c; i++)
        cin >> alphabets[i];
        
    sort(alphabets.begin(), alphabets.end());
    for(int i = 0; i<c; i++) cout << alphabets[i] << " ";
    
    solution(-1, 0, 0, 0);
    
    
}
