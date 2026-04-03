#include <iostream>
#include <algorithm>
using namespace std;


struct Activity {
    int start, finish;
};


bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

void activitySelection(Activity arr[], int n) {
   
    sort(arr, arr + n, compare);

    cout << "Selected activities:\n";

    // First activity always selected
    int i = 0;
    cout << "(" << arr[i].start << ", " << arr[i].finish << ")\n";

    // Select remaining activities
    for (int j = 1; j < n; j++) {
        if (arr[j].start >= arr[i].finish) {
            cout << "(" << arr[j].start << ", " << arr[j].finish << ")\n";
            i = j;
        }
    }
}

int main() {
    Activity arr[] = {{1, 3}, {2, 4}, {3, 5}, {0, 6}, {5, 7}, {8, 9}};
    int n = sizeof(arr) / sizeof(arr[0]);

    activitySelection(arr, n);

    return 0;
}