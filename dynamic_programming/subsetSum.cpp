#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
 * subsetsum(arr, n, sum) =
 * 	subsetsum(arr, n-1, sum) ||
 * 	subsetsum(arr, n-1, sum-arr[n-1])
 *
 * 	Base case:
 * 	subsetsum(arr, n, sum) = false, if sum>0 and n=0
 * 	subsetsum(arr, n, sum) = true, if sum=0
 */
bool subsetsum(vector<int> &arr, int n, int sum) {
    
    if (sum == 0) return true;
    else if (sum > 0 && n == 0) return false;

    if (arr[n-1] > sum)
        return subsetsum(arr, n-1, sum);

    return subsetsum(arr, n-1, sum) || subsetsum(arr, n-1, sum - arr[n-1]);
}

void prettyPrint(vector<vector<bool>> &vv, vector<int> &arr){
    cout << endl << __PRETTY_FUNCTION__ << endl;
    cout << "  0 ";
    for (int j = 1; j < vv[0].size(); j++)
        cout <<  j << " ";
    cout << endl;

    for (int i = 0; i < vv.size(); ++i) {
        if (i > 0) cout << arr[i - 1] << " "; 
        else cout << "_ "; 
        for (int j = 0; j < vv[0].size(); ++j)
            cout << vv[i][j] << " ";
        cout << endl ;
    }
    cout << endl;
}

bool subsetsumDP(vector<int> &arr, int sum) {
    /* ss[i][j] = true, if subsetsumDP(arr, i, j) is true
     * i.e. there is a subset of arr[0] .. arr[i-1] with sum j 
     */
    size_t n = arr.size();
    vector<vector<bool>> ssDP(n+1, vector<bool>(sum+1, false)); 

    // if sum=0, there's always a subset
    for_each(ssDP.begin(), ssDP.end(), [](vector<bool> &row){row[0]=true;});
    
    // if sum!=0, and set is empty, then there's no subset possible
    for_each(next(ssDP[0].begin()), ssDP[0].end(), [](_Bit_reference x){x=false;});

    for (int row = 1; row <= n; ++row){
        for (int col = 1; col <= sum; ++col) {
            if (col < arr[row - 1]) { // sum is less than current number being considered
                ssDP[row][col] = ssDP[row-1][col];  // current number can't be used to make sum
            } else {
                ssDP[row][col] = ssDP[row-1][col - arr[row-1]] || // include current element in the sum 'col'
                        ssDP[row-1][col]; // find sum 'col' without including this element
            }
        }
    }

    prettyPrint(ssDP, arr);

    if (ssDP[n][sum]) { // if subset found then print elements
        cout << "Subset with sum " << sum << ": ";
        bool done = false;
        int remaining = sum;
        for (int col = remaining; col>0;) {
            for (int row = n; row > 0; --row) {
                if (ssDP[row][col] && !ssDP[row-1][col]) { // can't make sum without current element
                    remaining = remaining - arr[row-1];
                    cout << arr[row-1] << ", ";
                    if (!remaining) {
                        done = 1;
                    } else col = remaining;
                    break;
                }
            }
            if (done) break;
        }
        cout << endl;
    } else {
        cout << "No subset with sum " << sum << endl;
    }

    return true;
}

int main() {
    int sum, n, i;
    
    cout << "Input set size: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Input " << n << " numbers (space separated): ";
    for (int i=0; i<n; ++i)
        cin >> arr[i];

    cout << "Input required Sum: ";
    cin >> sum;
    subsetsumDP(arr, sum);
}
