#include <bits/stdc++.h>

using namespace std;

tuple<int, int, int, char> slicing(string str){
    tuple<int, int, int, char> result;
    //1. year
    get<0>(result) = stoi(str.substr(0, 4));
    //2.month
    if(str[5] == '0') get<1>(result) = stoi(str.substr(5, 5));
    else  get<1>(result) = stoi(str.substr(5, 6));
    //3. day
    if(str[8] == '0')  get<2>(result) = stoi(str.substr(8, 8));
    else  get<2>(result) = stoi(str.substr(8, 9));
    //4. type 
    get<3>(result) = str[11];
    
    return result;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int tday[3] = {0}; //오늘 년, 월, 일
    vector <pair<char, int>> V; //약관 종류, 기한
    
    tday[0] = stoi(today.substr(0, 4));
    if(today[5] == '0') tday[1] = stoi(today.substr(5, 5));
    else tday[1] = stoi(today.substr(5, 6));
    if(today[8] == '0') tday[2] = stoi(today.substr(8, 8));
    else tday[2] = stoi(today.substr(8, 9));

    for(int i = 0; i < terms.size(); i++){
        string str = terms[i];
        char type = str[0];
        int month = stoi(str.substr(2));
        V.push_back({type, month});
    }
    
    for(int i = 0; i < privacies.size(); i++){
        auto privac = slicing(privacies[i]);
        int year = get<0>(privac);
        int month = get<1>(privac);
        int dday = get<2>(privac);
        char type = get<3>(privac);

        for(int j = 0; j < V.size(); j++){
            if(type == V[j].first){
                year += (V[j].second / 12);
                month += (V[j].second % 12);
                if(month > 12) { month -= 12; year++;}
                dday--;
                if(!dday) {month--; dday = 28;}
                if(year < tday[0]) answer.push_back(i + 1);
                else if(tday[0] == year){
                    if(month < tday[1]) answer.push_back(i + 1);
                    else if(tday[1] == month){
                        if(dday < tday[2]) answer.push_back(i + 1);
                    }
                }
                break;
            }
        }
   }
    return answer;
}