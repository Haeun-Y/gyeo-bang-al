#include <bits/stdc++.h>

using namespace std;

vector<string> vec;

bool compare(string a, string b){
    if(a.length() == b.length()){
        return a < b;
    }
    return a.length()< b.length();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        vec.push_back(str);
    }
    sort(vec.begin(), vec.end(), compare);
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << '\n';
    }
}