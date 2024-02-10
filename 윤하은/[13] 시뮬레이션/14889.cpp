//240210
//BOJ 14889 스타트와 링크
//SILVER 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<vector<int>> stat;
int computeStat(int memberIdx, vector<bool>& isStartTeamMember, bool isStartTeam)
{
    int result = 0;
    for(int i = 0; i<n; i++)
        if(isStartTeamMember[i] == isStartTeam)
            result += stat[memberIdx][i];
    
    return result;

}
int buildTeam()
{
    vector<bool> isStartTeamMember(n, false);
    for(int i = n/2; i < n; i++)
        isStartTeamMember[i] = true;

    int minDifference = 100 * n * n;
    do
    {
        int startTeamStat = 0;
        int linkTeamStat = 0;

        for(int i = 0; i<n; i++)
        {
            if(isStartTeamMember[i])
                startTeamStat += computeStat(i, isStartTeamMember, true);
            else 
                linkTeamStat += computeStat(i, isStartTeamMember, false);
        }
        minDifference = min(minDifference, abs(startTeamStat-linkTeamStat));

    }while(next_permutation(isStartTeamMember.begin(), isStartTeamMember.end()));
    return minDifference;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    stat = vector<vector<int>>(n, vector<int>(n, 0));

    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            cin >> stat[i][j];

    cout << buildTeam();
}