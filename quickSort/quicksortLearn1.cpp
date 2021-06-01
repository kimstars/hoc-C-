#include <iostream>
#include <ctime>
#include <cstdlib>


using namespace std;

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high){
    int pirot = arr[high];
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && arr[left] < pirot) left++;
        while(right >= left && arr[right] > pirot) right--;
        if(left >= right )break;

        swap(&arr[left], &arr[right]);
        left++;
        right--;
    }
    swap(&arr[left], &arr[right]);
    return left;
    
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pirot = partition(arr,low,high);
        quickSort(arr, low, pirot-1);
        quickSort(arr,pirot+1, high);
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
    int n;
    cin >> n;
    int a[n];
    genArr(a,n);
    quickSort(a,0,n-1);
    print(a,n);

}