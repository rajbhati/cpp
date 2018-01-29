/* 
 * Give a set S of positive integers, partition S into two subsets S1 and S2 such that:
 * 1. S1 and S2 disjoint. (they don't share any element)
 * 2. Sum of all elements in S1 = Sum of all elements in S2
 * 3. The above Sum is the maximum such sum possible.
 * 
 * You need not use all elements in S to create S1 and S2, in other words you can discard elements
 * from S (i.e. S1 U S2 != S)
 * 
 * Output the maximal sum.
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 
 * DP(S(n), X, Y) = Solution to setPartition n element set S(n), partitioned into two sets with sum X and Y.
 *
 * DP[S(n), X, Y] = DP[S(n-1), X, Y] or 			{don't use nth item}
 * 					DP[S(n-1), X - value(n), Y] or	{use nth item in X}
 * 					DP[S(n-1), X, Y - value(n)];	{use nth item in Y}
 * 						
 */
bool partitionSet(vector<int> &arr, int sum) {
    size_t n = arr.size();
    
    bool ss[n+1][sum+1][sum+1];
    for(int i=0; i<=n; ++i)
        for(int j=0; j<=sum; ++j){
            for(int k=0; k<=sum; ++k){
                ss[i][j][k] = false; 
            }
        }

    for(int i=0; i<=n; ++i)
        ss[i][0][0] = true;

    for (int items = 1; items <= n; ++items){
        for (int x = 0; x<=sum; ++x) {
            for(int y=0; y<=sum; ++y){
                if (x < arr[items-1] && y < arr[items-1]) { // x and y are less than the number being considered
                    ss[items][x][y] = ss[items-1][x][y];    // current number can't be used in x or y
                } else if (x < arr[items-1]) { // current item can be used to make y
                    ss[items][x][y] = ss[items-1][x][y] ||              // don't use item  
                                      ss[items-1][x][y-arr[items-1]];   // use item for y
                } else if (y < arr[items - 1]) { // current item can be used to make x
                    ss[items][x][y] = ss[items-1][x][y] ||              // don't use item  
                                      ss[items-1][x-arr[items-1]][y];   // use item for x
                } else { // current item can be used to make either x or y
                    ss[items][x][y] = ss[items-1][x][y] ||              // don't use item
                                      ss[items-1][x-arr[items-1]][y] || // use item for x
                                      ss[items-1][x][y-arr[items-1]];   // use item for y
                }
            }
        }
    }

    for(int i=sum; i>0; --i){
        if(ss[n][i][i]) {
            cout << "Maximum sum=" << i << endl;
            return true;
        }
    }

    return false;
}

int main() {
    int sum, n, i;
    
    cout << "Input set size: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Input " << n << " numbers (space separated): ";
    for (int i=0; i<n; ++i)
        cin >> arr[i];

    sum = accumulate(arr.begin(), arr.end(), 0) / 2;
    partitionSet(arr, sum);
}
