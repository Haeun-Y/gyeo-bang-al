/*
세준이는 양수와 +, -, 그리고 괄호를 가지고 식을 만들었다. 그리고 나서 세준이는 괄호를 모두 지웠다.
그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.
괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.

입력
첫째 줄에 식이 주어진다. 식은 ‘0’~‘9’, ‘+’, 그리고 ‘-’만으로 이루어져 있고, 가장 처음과 마지막 문자는 숫자이다. 
그리고 연속해서 두 개 이상의 연산자가 나타나지 않고, 5자리보다 많이 연속되는 숫자는 없다. 수는 0으로 시작할 수 있다. 입력으로 주어지는 식의 길이는 50보다 작거나 같다.

출력
첫째 줄에 정답을 출력한다.
*/

string s; int num[55]; char op[55];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 입력 처리
    cin >> s;
    int idx = 1; // 자릿수
    int num_idx = 0, op_idx = 0;
    for (char i : s) {
        int ch = i - '0';
        if (ch >= 0 && ch < 10) { // 숫자 
            if (idx > 1) // 십의 자리수 이상
                num[num_idx] = num[num_idx] * 10 + ch;
            else         // 일의 자리수 
                num[num_idx] = ch;
            idx += 1;
        }
        else {                 // 연산자
            op[op_idx++] = i;
            num_idx++; idx = 1;
        }
    }

    // 계산
    bool minus = false;
    int i, ans = 0;
    for (i = 0; i <= op_idx; i++) {
        if (op[i] == '-') {
            minus = true;
            break;
        }
    }
    for (int j = 0; j <= i; j++) ans += num[j];
    for (int j = i + 1; j <= num_idx; j++) ans -= num[j];

    // 결과 출력
    cout << ans;
}