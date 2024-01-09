//240106
//BOJ 9466 텀 프로젝트
//GOLD 3
#include <iostream>
#include <queue>
using namespace std;
void printQueue(queue<int> q)
{
    cout << "front : ";
    while(!q.empty())
    {
        cout << q.front() << ", ";
        q.pop();
    }
    cout << "\n";
}
//return the number of students in group.
int findTeam(int &n, vector<int>& students)
{
    int result = 0;
    vector<bool> isVisited(n, false);

    for(int i = 1; i<= n; i++)
    {
        if(isVisited[i]) continue;

        queue<int> q;
        
        int j = i;
        while(!isVisited[j])
        {
            q.push(j);
            isVisited[j] = true;
            //cout << "push " << j << " in q\n";
            j = students[j];
        }
        //printQueue(q);
        while(!q.empty() && q.front() != j)
            q.pop();
        //printQueue(q);
        result += q.size();
    }

    return result;
}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--)
    {
        int n;
        cin >> n;
        vector<int> students(n+1, 0);
        
        for(int i = 1; i<=n; i++)
            cin >> students[i];
        
        cout << n - findTeam(n, students) << "\n";
    }

}