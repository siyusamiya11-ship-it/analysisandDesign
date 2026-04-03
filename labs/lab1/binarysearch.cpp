#include<iostream>
using namespace std;
int searchtwothird(int arr[],int low, int high, int key){
    while(low<=high){
        int mid1=low+(high-low)/3
        int mid2=high-(high-low)/3
        if(arr[mid1]==key)
        return mid1;
    if(arr[mid2]==key)
    return mid2;
 if (key < arr[mid1])
            high = mid1 - 1;

        else if (key > arr[mid2])
            low = mid2 + 1;
        else {
            low = mid1 + 1;
            high = mid2 - 1;
        }
    }

    return -1; 
}
int main() {
    int arr[] = {10,20,30,40,50,60,70,80,90};
    int n = 9;
    int key = 60;

    int result = searchtwothird(arr, n, key);

    if (result != -1)
        cout << "Element found at index: " << result;
    else
        cout << "Element not found";

    return 0;
}
    


