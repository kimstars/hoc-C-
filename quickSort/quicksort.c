#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high){
	int pirot = arr[high];
	int left = low;
	int right = high - 1;
	while(1){
		while(left <= right && arr[left] < pirot) left++;
		while(right >= left && arr[right] > pirot) right--;
		if(left >= right) break;
		swap(&arr[left], &arr[right]);
		left++;
		right--;
	}
	swap(&arr[left], &arr[high]);
	return left;
}


void qs(int arr[], int low, int high){
	if(low < high){
		int pi = partition(arr,low,high);
		qs(arr,low, pi-1);
		qs(arr,pi+1, high);
	}
}

void print(int arr[], int size){
	int i;
	for(i = 0; i < size; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void genArr(int arr[], int size){
	int i;
	for (i = 0; i < size; i++){
		arr[i] = rand()%100 + 1;
	}
}

int main(){
	srand(time(0));
	int n ; 
	scanf("%d", &n);
	int arr[n];
	genArr(arr,n);
	qs(arr,0,n-1);
	print(arr,n);
	return 0;
}















