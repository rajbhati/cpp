#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

long getWays(long n, vector < long > denominations){
    int noOfdeno = denominations.size();
    long ways[noOfdeno + 1][n+1];

    for(int i=0; i<=noOfdeno; ++i) // one way to make '0' change
        ways[i][0] = 1;
    
    for(int j=1; j<=n; ++j) // no coins, so no change can be made
        ways[0][j] = 0;
            
    // ways[i][j] stores the number of ways to make change of 'j' units
    // using coins of denominations[0...i-1]
    for(int i=1; i<=noOfdeno; ++i) { // consider the denominations[i-1] coins
        for(int j= 1; j <= n; ++j) { // try to make 'j' units change
            if(j < denominations[i-1]){ // denomination is larger than target, can't use this coin
                ways[i][j] = ways[i-1][j]; // # ways same as those without using this coin
            } else { // can use this coin
                ways[i][j] = ways[i][j - denominations[i-1]] + // use this coin, no. of ways to make (j - this-coin)
                    ways[i-1][j]; // no of ways to make 'j' without using this coin
            }
        }
    }
    
    return ways[noOfdeno][n];
}

// https://www.hackerrank.com/challenges/coin-change/problem
// Print the number of ways to make change for 'n' units using 
// coins having the values given by 'c'
int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<long> c(m);
    for(int c_i = 0; c_i < m; c_i++){
       cin >> c[c_i];
    }
    // Print the number of ways of making change for 'n' units using coins having 
    // the values given by 'c'
    cout <<  getWays(n, c) << endl;
    return 0;
}
