#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

// kadane's algorithm
int maxSumSubarray(vector<int> &v){
    int max_so_far = v[0], max_ending_here = v[0];

    for_each(v.begin() + 1, v.end(), 
            [&](int x){
                max_ending_here = max(max_ending_here + x, x);
                max_so_far = max(max_so_far, max_ending_here);
        });
    return max_so_far;
}

int maxSumSubsequence(vector<int> &v){
    int maxSum = 0;
    
    for_each(v.begin(), v.end(), [&maxSum](int x){if(x>0) maxSum += x;});
 
    if(maxSum)
        return maxSum;
    else return *max_element(v.begin(), v.end());
}

pair<int, int> maxSubarray(vector <int>& v) {
    return make_pair(maxSumSubarray(v), maxSumSubsequence(v));
}

/* Given an array of N elements, find the maximum possible sum among
 * 1. all nonempty subarrays.
 * all nonempty subsequences.
 */
int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
        auto result = maxSubarray(arr);
        cout << result.first << " " << result.second << endl;
    }
    return 0;
}
