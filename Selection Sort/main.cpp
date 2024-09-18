#include <iostream>
using namespace std;

void selectionSort(int arr[] , int n)
{
    for (int i=0;i<n-1;i++)
    {
        int minIndex = i;

        for (int j=i+1;j<n;j++)
        {
            if (arr[j] < arr[minIndex]) // (arr[j] > arr[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i) // swap
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout << "Original array: ";
    print(arr,size);

    selectionSort(arr,size);

    cout << "Sorted array: ";
    print(arr,size);

    return 0;
}
