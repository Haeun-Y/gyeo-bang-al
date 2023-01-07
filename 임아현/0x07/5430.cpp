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
    int err, flag; //flag 0 앞, 1 뒤
    
    while(T--){
        err = 0;
        flag = 0;
        cin >> cmd >> n >> arr; //ex RDD, 4
        deque<string> D; 
        arr = arr.substr(1, arr.length() - 2);
        istringstream ss(arr);
        
        string temp;
        
        while(getline(ss, temp, ',')){
            D.push_back(temp);
        }

        for(auto f: cmd){
          if(f == 'R'){
              if(!D.empty()){
                  flag = (!flag);
              }
          }
          else if(f == 'D'){
              if(D.empty()){
                  cout << "error\n";
                  err = 1;
                  break;
              }
              else{
                  if(flag == 0) D.pop_front();
                  else D.pop_back();
              }
          }
          
        }
        
        if(!err){
            if(D.empty()) cout << "[]\n";
            else{
               if(flag == 0){
                 cout << '[';
                 for(int i = 0 ; i < D.size() - 1; i++){
                     cout << D[i] << ',';
                 }
                 cout << D.back() << "]\n";
               }
               else{
                 cout << '[';
                 for(int i = D.size() - 1 ; i > 0 ; i--){
                     cout << D[i] << ',';
                 }  
                 cout << D.front() << "]\n";
               }
            }
        }

    }
}