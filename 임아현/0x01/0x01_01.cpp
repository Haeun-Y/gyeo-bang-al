//비효율적인 풀이 O(N)짜리 풀이 존재
int func2(int arr[], int N){
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if(arr[i] + arr[j] == 100){
                return 1;
            }
        }
    }
    return 0;
}