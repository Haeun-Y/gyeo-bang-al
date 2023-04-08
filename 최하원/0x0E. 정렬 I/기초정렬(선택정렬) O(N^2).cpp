
int arr[10] = { 0,145,231,4631,-3,-178,19,239184,32149999,-1429889198 };
int n = 10 // arr size

// 1.
for (int i = n-1; i > 0; i--) {
	int max_idx = 0;
	for (int j = 1; j <= i ; j++) {
		if (arr[max_idx] < arr[j]) max_idx = j;
	}
	swap(arr[max_idx], arr[i]);
}

for (int i = n - 1; i > 0; i--) 
	swap(*max_element(arr, arr+i+1), arr[i]); 
	// max_element 는 arr 중 가장 큰거 찾음