// C++ Code for count of AP
// Subsequences using Recursion
#include <bits/stdc++.h>
using namespace std;

// Recursive function to count all 
// arithmetic subsequences
int numberOfAP(vector<int>& arr, int n, int idx, 
               int pre, int count, int diff) {
  
    int ans = 0;

    // Base case: if we've processed all elements
    if (idx == n) {
        return 1;
    }

    // If we have picked one element but 
    // no difference set yet
    if (pre != -1 && diff == INT_MIN) {
      
        // Pick the current element and 
       // set the difference
        ans += numberOfAP(arr, n, idx + 1, idx, 
                          count + 1, arr[idx] - arr[pre]);
    } 

    // First element or continuation of 
    // an AP with the same difference
    if (pre == -1 || diff == arr[idx] - arr[pre]) {
      
        // Pick the current element to extend the AP
        ans += numberOfAP(arr, n, idx + 1, 
                          idx, count + 1, diff);
    }

    // Skip the current element
    ans += numberOfAP(arr, n, idx + 1, pre, count, diff);

    return ans;
}

// Wrapper function to start the recursion
int count(vector<int>& arr) {
    int n = arr.size();
    return numberOfAP(arr, n, 0, -1, 0, INT_MIN);
}

int main() {

    vector<int> arr = {1, 2, 3}; 

    cout << count(arr);
    return 0;
}
