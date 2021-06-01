#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}


int partition(int arr[], int low, int high){
	int pirot = arr[high];
	int left = low;
	int right = high -1 ;
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

void quicksort(int arr[], int low, int high){
	if(low < high){
		int pi = partition(arr,low,high);
		quicksort(arr,low,pi-1);
		quicksort(arr,pi+1,high);
	}
}

void print(int arr[], int size){
	for(int i = 0; i< size; i++){
		cout << arr[i] <<"  ";
	}
	cout << endl;
}


void genArr(int arr[], int size){
	for (int i = 0 ; i < size; i++){
		arr[i] = rand()%100 + 1;
	}
}





int main(){
	srand(time(0));
	int n;
	cin >> n;
	int arr[n];
	genArr(arr,n);
	print(arr,n);
	quicksort(arr,0,n-1);
	print(arr,n);
	
	
	
	
	
}
