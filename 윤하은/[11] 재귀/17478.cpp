//BOJ 17478 ����Լ��� ������?
//indentation�� ê�� ���� for������ ����
//��ŸȮ���ϱ� <- ê�� ���� �����ؼ� �ٽ� �õ�
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
  cout << "\"����Լ��� ������?\"\n";
  
  if(n==cur)
  {
    printIndentation(cur);
    cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
    printIndentation(cur);
    cout << "��� �亯�Ͽ���.\n";
    return;
  }
  else
  {
    printIndentation(cur);
    cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
    printIndentation(cur);
    cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
    printIndentation(cur);
    cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
    whatIsRecursion(n, cur+1);
    printIndentation(cur);
    cout << "��� �亯�Ͽ���.\n";
  }
  
}
int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;

  cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������. \n";

  whatIsRecursion(n, 0);
}
