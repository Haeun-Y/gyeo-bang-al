/*
����
LCS(Longest Common Subsequence, ���� ���� �κ� ����) ������ �� ������ �־����� ��, ����� �κ� ������ �Ǵ� ���� �� ���� �� ���� ã�� �����̴�.
���� ���, ACAYKP�� CAPCAK�� LCS�� ACAK�� �ȴ�.

�Է�
ù° �ٰ� ��° �ٿ� �� ���ڿ��� �־�����.���ڿ��� ���ĺ� �빮�ڷθ� �̷���� ������, �ִ� 1000���ڷ� �̷���� �ִ�.

���
ù° �ٿ� �Է����� �־��� �� ���ڿ��� LCS�� ���̸� ����Ѵ�.
*/
int dp[1003][1003]; //dp[i][j] A�� i��°, B�� j��° ���� ������ ���� ���� ����

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