//BOJ 5397 키로거
//맞았지만 cursor = result.begin() 으로 초기화 코드 다시 확인
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    //중간 삽입 삭제 빈번 -> 연결리스트 사용
    
    /*
    논리적 커서 위치가 원소 뒤이면 다음원소를 가리키는걸로
    즉 논리적 커서 위치가 원소 왼쪽일경우 실제 iterator가 해당 원소를 가리킴
    B
    BP
    <<BP<A>>Cd-
    ThIsIsS3Cr3t
    */
    
    int tc;
    cin >> tc;
    
    for(int i = 0; i<tc; i++)
    {
        string password;
        cin >> password;
        
        list<char> result;
        list<char>::iterator cursor;
        
        
        for(char ch : password)
        {
            switch(ch)
            {
                case '<':
                    if(result.size() != 0 && cursor != result.begin())
                        cursor--;
                    break;
                case '>':
                    if(result.size() != 0 && cursor != result.end())
                        cursor++;
                    break;
                case '-':
                    if(result.size() != 0 && cursor != result.begin())
                        cursor = result.erase(--cursor);
                    break;
                
                //소문자, 대문자, 숫자인 경우  
                default:
                    if(result.size() == 0)
                    {
                        result.push_back(ch);
                        cursor = result.end();
                    }
                    else
                        result.insert(cursor, ch);
                    
                    break;
                
            }
        }
        
        for(char ch : result)
            cout << ch;
        
        cout << "\n";
        
    }
}
