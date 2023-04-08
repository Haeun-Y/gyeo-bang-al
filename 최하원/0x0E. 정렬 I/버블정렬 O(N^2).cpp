int arr[10] = { 0,45,31,461,-3,-78,19,9184,3499,-142198 };

for (int i = 0; i < 9; i++) {
	for (int j = 0; j < 9 - i; j++)
		if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
}