/*
문제
LCS(Longest Common Subsequence, 최장 공통 부분 수열) 문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.
예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

입력
첫째 줄과 둘째 줄에 두 문자열이 주어진다.문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.

출력
첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를 출력한다.
*/
int dp[1003][1003]; //dp[i][j] A의 i번째, B의 j번째 까지 비교했을 때의 최장 길이

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string A, B;
    cin >> A >> B;
    int lenA = A.length(); int lenB = B.length();


    for (int i = 0; i < lenA; i++) {
        int A_cur = i;
        if (A[A_cur] == B[0]) {
            dp[i][0] = 1;
        }
        for (int j = 1; j < lenB; j++) {
            if (A[A_cur] == B[j]) {
                dp[i][j] = dp[i][j - 1] + 1;
                A_cur++;
            }
            else dp[i][j] = dp[i][j - 1];

        }

    }

    int max = dp[0][lenB - 1];
    for (int i = 1; i < lenA; i++)
        max = (max > dp[i][lenB - 1]) ? max : dp[i][lenB - 1];
    cout << max;
}