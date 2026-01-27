#include <iostream>
using namespace std;

void findDuplicate(int arr[], int n, int i, int j)
{

    if (i >= n - 1)
        return;

 
    if (j >= n)
    {
        findDuplicate(arr, n, i + 1, i + 2);
        return;
    }

    if (arr[i] == arr[j])
    {
        cout << "Duplicate element: " << arr[i] << endl;
        return;   
    }

  
    findDuplicate(arr, n, i, j + 1);
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    findDuplicate(arr, n, 0, 1);

    return 0;
}