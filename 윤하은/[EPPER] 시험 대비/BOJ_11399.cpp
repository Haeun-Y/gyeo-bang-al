#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    vector<int> atmTimes(n);

    for(int i = 0; i<n; i++)
        cin >> atmTimes[i];

    sort(atmTimes.begin(), atmTimes.end());

    int total = 0;
    
    for(int i = 0; i<n; i++)
        total += (atmTimes[i] * (n-i));

   
   /*
    total = atmTimes[0];

    for(int i = 1; i<n; i++)
    {
        atmTimes[i] += atmTimes[i-1]; 
        total += atmTimes[i];
    }
    */
    

    cout << total;

    

    

}