#include <bits/stdc++.h>

using namespace std;

int main()
{
    int cntz = 0; //연속되는 0 count
    int cnto = 0;  //연속되는 1 count
    
    string str;
    cin >> str;
    
    char start = str[0];
    if(start == '0') cntz++;
    else cnto++;
    
    for(int i = 1 ; i < str.length(); i++){
        if(start != str[i]){
            if(str[i] == '0') cntz++;
            else cnto++;
            start = str[i];
        }
    }
    cout << min(cntz, cnto);
}