#include<bits/stdc++.h>
using namespace std;

vector<int> findMinimaElements(int n, int arr[]) {
    vector<int> result;
    int smallest = arr[0];
    int secondSmallest = arr[0];
    
    for (int i = 1; i < n; i++) {
        if (smallest >= arr[i]) {
            secondSmallest = smallest;
            smallest = arr[i];
        }
    }
    
    result.push_back(smallest);
    result.push_back(secondSmallest);
    return result;
}

int main() {
    int n;
    cout << "Enter the size of array" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter elements of the array" << endl;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<int> result = findMinimaElements(n, arr); // function call
    cout << "First minima of the array is : " << result[0] << endl;
    cout << "Second minima of the array is : " << result[1] << endl;
    cout << endl;
    
    return 0;
}
