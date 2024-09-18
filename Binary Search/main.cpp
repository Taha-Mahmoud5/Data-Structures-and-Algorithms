#include <iostream>
using namespace std;

int BinarySearch(int arr[],int size,int key)
{
    int left = 0;
    int right = size-1;

    while (left <= right)
    {
        int mid = left+(right-left) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }

        if (arr[mid] < key)
        {
            left = mid + 1;
        }

        else
            right = mid - 1;

    }


    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};  // must be sorted
    int size = sizeof(arr) / sizeof(arr[0]);
    int key ;
    cout << "Enter the target :  " ;
    cin >> key ;

    int result = BinarySearch(arr,size,key);

    if (result != -1)
    {
        cout << "The number " << arr[result] << " found at index: " << result << endl;
    }
    else
        cout << "Element not found" << endl;



    return 0;
}
