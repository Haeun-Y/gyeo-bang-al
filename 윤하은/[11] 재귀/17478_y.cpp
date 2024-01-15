//230708 �����
//BOJ 17478 ��� �Լ��� ������? 
//SILVER 5


#include <iostream>
using namespace std;
void printIndentation(int n)
{
  for(int i = 0; i< n; i++)
    cout << "____";
}
void printQnA(int n, int total)
{
  if(n==0)
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";

  printIndentation(n);
  cout << "\"����Լ��� ������?\"\n";
  if(n == total)
  {
    printIndentation(n);
    cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
  }
  else
  {
    printIndentation(n);
    cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
    printIndentation(n);
    cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
    printIndentation(n);
    cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
    
  }
}
void printAnswered(int n)
{
  printIndentation(n);
  cout << "��� �亯�Ͽ���.\n";
}
void printRecursiveMsg(int n, int total) 
{
  if(n == total)
  {
    printQnA(n, total);
    printAnswered(n);
    return;
  }
  else
  {
    printQnA(n, total);
    printRecursiveMsg(n+1, total);
    printAnswered(n);
  }
  
  
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    cin >> num;

    printRecursiveMsg(0, num);

    
}