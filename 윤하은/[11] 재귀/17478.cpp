//BOJ 17478 재귀함수가 뭔가요?
//indentation과 챗봇 내용 for문으로 수정
//오타확인하기 <- 챗봇 내용 복붙해서 다시 시도
#include <bits/stdc++.h>
using namespace std;
void printIndentation(int cnt)
{
  for(int i = 0; i<cnt*4; i++)
      cout << "_";
  
}
void whatIsRecursion(int n, int cur)
{
  printIndentation(cur);
  cout << "\"재귀함수가 뭔가요?\"\n";
  
  if(n==cur)
  {
    printIndentation(cur);
    cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
    printIndentation(cur);
    cout << "라고 답변하였지.\n";
    return;
  }
  else
  {
    printIndentation(cur);
    cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
    printIndentation(cur);
    cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
    printIndentation(cur);
    cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
    whatIsRecursion(n, cur+1);
    printIndentation(cur);
    cout << "라고 답변하였지.\n";
  }
  
}
int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;

  cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다. \n";

  whatIsRecursion(n, 0);
}
