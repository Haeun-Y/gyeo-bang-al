#include <iostream>
using namespace std;
string solution(string bitstr)
{
	string zipStr = (bitstr[0] == '1')? "1" : "";
	
	for(int i = 0; i<bitstr.length();)
	{
		int sum = 0;
		for(int j = i; j<bitstr.length(); j++)
		{
			if(bitstr[i] == bitstr[j])
				sum++;
			else break;
		}
		
		zipStr += (char)('A'+sum-1);
		i += sum;
		
	}
	return zipStr;
	
}
int main() {
	
	string str;
	cin >> str;
	
	cout << solution(str);
	
}
