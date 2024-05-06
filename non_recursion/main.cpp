#include <iostream>
using namespace std;

int countDistinct(int A[], int n) {
    int distinctCount = 0;

    for (int i = 0; i < n; ++i) {
        bool isDistinct = true;
        // Check if the current element is distinct from previous elements
        for (int j = 0; j < i; ++j) {
            if (A[i] == A[j]) {
                isDistinct = false;
                break;
            }
        }
        // If the current element is distinct, increment the distinct count
        if (isDistinct)
            distinctCount++;
    }

    return distinctCount;
}

int main() {
    int n;
    printf("Enter size of array:");
    cin>>n;
    printf("Enter the items you want to know the distinct between them:");
    int arr [n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }


    cout << "Number of distinct values: " << countDistinct(arr, n) << endl;
return 0;
}
