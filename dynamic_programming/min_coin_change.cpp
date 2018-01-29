#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

long minCoins(long n, vector < long > c){
	vector<long> coins(n+1, LONG_MAX);

    coins[0] = 0;
    for(auto it = c.begin(); it != c.end(); ++it) {
        for(long i= *it; i <= n; ++i) {
            if(coins[i-*it] != LONG_MAX)
               coins[i] = min(coins[i], coins[i-*it] + 1);
        }
    }
    
    return coins[n];
}

// Print the minimum number of coins required to make change for 'n' units using 
// coins having the values given by 'c'
int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<long> c(m);
    for(int c_i = 0; c_i < m; c_i++){
       cin >> c[c_i];
    }
    cout <<  minCoins(n, c) << endl;
    return 0;
}
