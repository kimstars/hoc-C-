#include <iostream>
using namespace std;
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    // Di chuyển ranh giới của mảng đã sắp xếp và chưa sắp xếp
    for (i = 0; i < n - 1; i++)
    {
        // Tìm phần tử nhỏ nhất trong mảng chưa sắp xếp
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Đổi chỗ phần tử nhỏ nhất với phần tử đầu tiên
        swap(arr[min_idx], arr[i]);
        cout << "\nBuoc " << i + 1 << ": ";
        for (int j = 0; j < n; j++)
            cout << arr[j] << " ";
    }
}

int main()
{
    int n, idx;
    cin >> n;
    int a[n + 1];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    selectionSort(a,n);
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}