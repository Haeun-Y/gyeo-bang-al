#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    string cmd, arr; //RDD [1,2,3,4] 이런 것
    int n;
    int err, flag = 0; //flag 0 앞, 1 뒤
    
    while(T--){
        cin >> cmd >> n >> arr; //ex RDD, 4
        deque<string> D; //배열 저장할 곳
        cout <<"연산 시작 \n";
        //덱에 삽입하기
        D = 
        for(auto c: arr){
            if(c != '[' && c!= ']' && c!= ','){
                D.push_back(c - '0');
                cout << D.front() << " \n";
            }
        }
        
        for(auto f: cmd){
          if(f == 'R'){
              cout << "R 시작 \n";
              if(D.empty()){
                  cout << "error \n";
                  err = 1;
                  break;
              }
              else{
                  flag = (!flag);
              }
          }
          else if(f == 'D'){
              cout << "D 시작 \n";
              if(D.empty()){
                  cout << "error \n";
                  err = 1;
                  break;
              }
              else{
                  if(flag == 0) D.pop_front();
                  else D.pop_back();
              }
          }
          
        }
        
        if(err){
            if(flag == 0){
              cout << '[';
              for(int i = 0 ; i < D.size() - 1; i++){
                  cout << D[i] << ',';
              }
              cout << D.back() << ']';
            }
            else{
              cout << '[';
              for(int i = D.size() - 1 ; i > 0 ; i--){
                  cout << D[i] << ',';
              }
              cout << D.front() << ']';
                
            }
        }

    }
}