
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
 * DP(S(n), X, Y) = Solution to setPartition n element set S(n), partitioned into two sets with sum X and Y.
 *
 * DP[S(n), X, Y] = DP[S(n-1), X, Y] or                         {don't use nth item}
 *                                      DP[S(n-1), X - value(n), Y] or  {use nth item in X}
 *                                      DP[S(n-1), X, Y - value(n)];    {use nth item in Y}
 * 
 */
bool partitionSet(vector<int> &arr, int sum) {

    size_t n = arr.size();

    bool ss[n+1][sum+1][sum+1];
    for(int i=0; i<=n; ++i){
        for(int j=0; j<=sum; ++j){
            for(int k=0; k<=sum; ++k){
                ss[i][j][k] = false; 
            }
        }
	}

	for(int i=0; i<=n; ++i) ss[i][0][0] = true; // subsets of size '0' are always possible

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
            cout << endl << "Maximum sum: " << i << endl;
            multiset<int> setx;
            multiset<int> sety;
            int rx, ry; // remaining values of sum X, sum Y which backtracking for set X and Y
            rx = ry = i;
            for(; n>0 && (rx || ry); --n ){ // consider items one by one
                if(ss[n][rx][ry] && !ss[n-1][rx][ry]){ // arr[n-1] is essential for either x or y
                    if(rx && (arr[n-1] <= rx) && !ss[n-1][rx][ ry-arr[n-1] ]){ 
					// without the nth element, sumSets {rx} and {ry - arr[n-1]} would be impossible. 
					// i.e. it's not possible to put arr[n-1] in set Y, hence it goes in X
                        rx -= arr[n-1];
                        setx.insert(arr[n-1]);
                    } else {
                        ry -= arr[n-1];
                        sety.insert(arr[n-1]);
                    }
                }
            }

            cout << "First set : ";
            for_each(setx.begin(), setx.end(), [](int x){cout << x << ",";}); cout << endl;
            cout << "Second set: ";
            for_each(sety.begin(), sety.end(), [](int x){cout << x << ",";}); cout << endl;

            return true;
        }
    }
	
	cout << "No equal sum sets possible!" << endl;

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
