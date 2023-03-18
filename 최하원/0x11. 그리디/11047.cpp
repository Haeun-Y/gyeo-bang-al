/*
문제
준규가 가지고 있는 동전은 총 N종류이고, 각각의 동전을 매우 많이 가지고 있다.
동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 한다. 이때 필요한 동전 개수의 최솟값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 10, 1 ≤ K ≤ 100,000,000)
둘째 줄부터 N개의 줄에 동전의 가치 Ai가 오름차순으로 주어진다. (1 ≤ Ai ≤ 1,000,000, A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수)

출력
첫째 줄에 K원을 만드는데 필요한 동전 개수의 최솟값을 출력한다.
*/

int N, K. A[12], ans=0;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> A[i];

    for (int i = N; i > 0; i--) {
        int tmp = K / A[N];
        ans += tmp;         
        K -= tmp * A[N]; // K %= A[i];
    }
    cout << ans;
}

/*
<반례>
1원, 9원, 10원 동전이 있을 때 18원을 만드는 상황을 생각해보면 9원짜리 동전 2개를 쓰는게 가장 좋은 방법이지만,
그리디 알고리즘은 10원을 먼저 쓰고 남은 돈이 8원이니 남은건 1원으로 처리를 해서 동전 9개를 사용합니다. 
이렇게 사소한 조건의 변화만으로도 풀이가 확 달라질 수 있어서 조심을 해야하고, 
비슷해보이는 문제를 풀어봤다는 이유만으로 풀이의 방향을 한정짓는건 굉장히 위험할 수 있습니다.
*/