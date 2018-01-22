#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
void pprint(T t){
    cout << __PRETTY_FUNCTION__ << " : "; 
    for( auto it=t.begin(); it!=t.end(); ++it)
        cout << *it << " ";
    cout << endl;
}
template <typename I>
void pprint(I b, I e){
    cout << __PRETTY_FUNCTION__ << " : "; 
    for(; b != e; ++b) cout << *b << " ";
    cout << endl;
}
#include <limits.h>

using namespace std;

long candies(int n, vector <int> rank) {
    vector<int> lds(n); // longest decreasing sequence starting at i
    vector<long> candies(n);
    lds[n-1] = 1;
    
    for(int i=n-2; i>=0; --i){
        if(rank[i] > rank[i+1]) lds[i] = lds[i+1] + 1;
        else lds[i] = 1;
    }
    
    candies[0] = lds[0];
    for(int i=1; i<n; i++){
        if(rank[i] > rank[i-1]){
            candies[i] = max(candies[i-1] + 1, static_cast<long>(lds[i]));
        } else {
            candies[i] = max(lds[i], 1);
        }
    }
    return accumulate(candies.begin(), candies.end(), 0);
}

/*
 * https://www.hackerrank.com/challenges/candies/problem
 * Alice is a kindergarten teacher. She wants to give some candies to the children in her class.  
 * All the children sit in a line (their positions are fixed), and each of them has a rating score 
 * according to his or her performance in the class.  
 * Alice wants to give at least 1 candy to each child. 
 * If two children sit next to each other, then the one with the higher rating must get more candies. 
 * Alice wants to save money, so she needs to minimize the total number of candies given to the children.
 */
int main() {
    int n;
    cin >> n;
    vector<int> rank(n);
    for(int i = 0; i < n; i++){
       cin >> rank[i];
    }
    long result = candies(n, rank);
    cout << result << endl;
    return 0;
}

//    vector<int> c(n); // candies allocated to each child
//    long total=c[n-1];
//    
//    c[0]=1;
//    for (int i=1;i<n;i++) {
//        if (rank[i] > rank[i-1]) c[i] = c[i-1] + 1 ;
//        else c[i] = 1;
//    }
//    for (int i=n-2;i>=0;i--) {
//        if (rank[i] > rank[i+1]) c[i] = max(c[i+1] + 1, c[i]);
//        else c[i] = max(1, c[i]);
//        total+=c[i];
//    }    
//
//    return total;
