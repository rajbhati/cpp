/* 
 * Given a set S of positive integers, partition S into two subsets S1 and S2 such that:
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
#include <set>

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
multiset<int> subsetsumDP(vector<int> &arr, int sum) {
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

    multiset<int> sumSet;
    
    if (ssDP[n][sum]) { // subset found

        int remaining = sum;
        int row = n;
        while(remaining){
            for (; row > 0; --row) {
                if (ssDP[row][remaining] && !ssDP[row-1][remaining]) { // can't make sum without current element
                    sumSet.insert(arr[row-1]);
                    remaining = remaining - arr[row-1];
                    if (!remaining)
                        return sumSet;
                    break;
                }
            }
        }
    }

    return sumSet;
}

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

	for(int i=0; i<=n; ++i) // subsets of size '0' are always possible
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
        if(ss[n][i][i]) { // maximum sum subset
            cout << endl << "Maximum sum=" << i << endl;
    		multiset<int> setX; // first set, X
            int remaining = i;
            int row = n;
            while(remaining){
                int xx = remaining;
                for(; row>0; --row){
                    if(ss[row][xx][0] && !ss[row-1][xx][0]){
                        setX.insert(arr[row-1]);
                        remaining -= arr[row-1];
                        break;
                    }
                }
            }
            
            cout << "First set: ";
            for_each(setX.begin(), setX.end(), [](int x){cout << x << ",";});
            cout << endl;
            vector<int> yarr; // use subsetSumDP to find a subset of 'i' sum in remaining elements of arr
            set_difference(arr.begin(), arr.end(), setX.begin(), setX.end(), inserter(yarr, yarr.begin()));
            multiset<int> setY = subsetsumDP(yarr, i);
            cout << "Second set: ";
            for_each(setY.begin(), setY.end(), [](int x){cout << x << ",";});
            cout << endl;

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
