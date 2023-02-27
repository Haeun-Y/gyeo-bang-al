#include <bits/stdc++.h>

using namespace std;

bool compare(tuple<string, int, int, int> &v1, tuple<string, int, int, int> &v2){
    //1. 국어 점수가 다름 -> 국어 내림차순
    if(get<1>(v1) != get<1>(v2)) return get<1>(v1) > get<1>(v2);
    //2. 국어 점수 같음 -> 영어 오름차순
    else{
        //3. 국어, 영어 점수 같음 -> 수학 내림차순
        if(get<2>(v1) != get<2>(v2)) return get<2>(v1) < get<2>(v2);
        else{
             if(get<3>(v1) != get<3>(v2)) return get<3>(v1) > get<3>(v2);
             //4. 네 과목이 다같 사전순
             else{
                 return get<0>(v1) < get<0>(v2);
             }
        }
    }
}

int main()
{
    int N;
    vector<tuple<string, int, int, int>> V ;

    cin >> N;
    while(N--){
        string name;
        int a, b, c;
        
        cin >> name >> a >> b >> c;
        V.push_back(make_tuple(name, a, b, c));
    }
    
    sort(V.begin(), V.end(), compare);
    
    for(int i = 0; i < V.size(); i++){
        cout << get<0>(V[i]) <<'\n';
    }
}