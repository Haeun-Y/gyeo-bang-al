//240126
//softeer 성적 평균
//Lv.3
#include<iostream>
#include<vector>
using namespace std;
int n, k;
vector<long long> scores;
void computeSum()
{
    for(int i = 1; i<=n; i++)
        scores[i] += scores[i-1];
}
double computeSectionAvg(int a, int b)
{
    int studentNum = b-a+1;
    double sectionSum = scores[b] - scores[a-1];
    return sectionSum/studentNum;
}
int main(int argc, char** argv)
{
    cin >> n >> k;
    scores = vector<long long>(n+1, 0);
    for(int i = 1; i<=n; i++)
        cin >> scores[i];

    computeSum();

    for(int i = 0; i<k; i++)
    {
        int a, b;
        cin >> a >> b;
        printf("%.2lf\n", computeSectionAvg(a, b));
    }
   return 0;
}
