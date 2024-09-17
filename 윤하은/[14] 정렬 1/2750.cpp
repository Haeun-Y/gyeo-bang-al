#include <iostream>
#define NUM_OF_ELEMENT 6
using namespace std;
void swap_e(int * a, int * b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
int partition(int *list, int p, int r)
{
    int x = list[r];
    int i = p-1;
    for(int j = p; j<r; j++)
    {
        if(list[j] <= x)
        {
            i++;
            swap_e(&list[i], &list[j]);
        }
    }
    swap_e(&list[i+1], &list[r]);
    
    /*for(int k = 0; k<i+1; k++)
        cout << list[k] << " ";
    cout << "\npivot : " << list[i+1] << "\n";
    for(int k = i+1; k<= r; k++)
        cout << list[k] << " ";
    cout << "\n";*/

    
    return i+1;
}
void quick_sort(int * list, int left, int right)
{
  if(left < right)
  {
    int q = partition(list, left, right);
    quick_sort(list, left, q-1);
    quick_sort(list, q+1, right);
  }
}
void print_arr(int* arr, int n)
{
    for(int i = 0; i<n; i++)
        cout << arr[i] << "\n";
    
}
int main(void) {
  
  
  int arr[1005]= {0,};
  int num;
  cin >> num;
  
  for(int i = 0; i<num; i++)
    cin >> arr[i];
  
  //cout << "input data\n";
  //print_arr(arr, num);
  
  quick_sort(arr, 0, num-1);
  
  //cout << "sorted data\n";
  print_arr(arr, num);
  
  

  
    
}