/*
 * Given an array A, you are asked to perform a number of queries and divide the array into what are called, beautiful subsequences.
 *
 * The array A has length n. A function f(A) is defined to be a minimal possible x, such that it's possible to divide array A into 
 * x beautiful subsequences. 
 * Note that each element of an array should belong to exactly one subsequence, and subsequence does not necessarily need to be consecutive.
 *
 * A subsequence S with length len is called beautiful if and only if:
 * 1. len = 1 or
 * 2. Let SS be a sorted version of S. It must hold that SS[i] = SS[i+1] - 1 for every i in [1, len -1]
 *  For instance, if A = [1,2,3,4,3,5], f(A) would be 2, because you can divide A into 2 beautiful subsequences either like [1,2,3] and [4,3,5] 
 *  or like [1,2,3,4,5] and [3].
 *
 *  You have to answer q queries. Each query is of the type:
 *  id val : you need to change the value of A[id] to val. . Here id is 1-indexed.
 *  
 *  After each query, for the value of f(A), lets denote that value as ans-i, where i indicates the i-th query.
 *
 *   You need to find sum(i* ans-i) modulo 1000000007, i ranges from 1 to q.
 *
 *   Input Format
 *   The first line contains a single integer n, representing the length of array A. 
 *   The next line contains the array A given as space-separated integers. 
 *   The next line contains a single integer q, representing the number of queries. 
 *   Each of the next q lines contain two integers id and val, which is described above.
 */
#include <iostream>
#include <algorithm>
#include <utility>
#include <limits.h>
#include <vector>
#include <set>

using namespace std;

using lli = long long int;
const int MOD = 1000000007;

struct bSequences{
    lli count;              // total beautiful sequences
    multiset<lli> starts;   // starting elements of beautiful sequences
    multiset<lli> ends;     // ending elements of beautiful sequences
    
    bSequences(): count(0){}
    
    void deleteElement(lli val){
        auto startswith = starts.find(val); // a sequence starting with val
        auto endswith = ends.find(val);     // a sequence ending with val
        
        if(startswith!=starts.end() && endswith!=ends.end()){ // must be a single element sequence [val]
            starts.erase(startswith);
            ends.erase(endswith);
            --count; // a sequence [val] got deleted
        } else if (startswith!=starts.end()){   // sequence [val,x] now becomes [val+1, x]
            starts.erase(startswith);           // val is not a starting element anymore
            starts.insert(val+1);               // val+1 is a new starting element
        } else if (endswith!=ends.end()){   // sequence [x, val] now becomes [x, val-1]
            ends.erase(endswith);           // val is not an ending element anymore    
            ends.insert(val-1);             // val-1 is a new ending element
        } else { // there must be a sequence [x, ... ,val, ..., y], deleting val breaks this sequence
            starts.insert(val+1);   // [val+1, ..., y] is a new sequence
            ends.insert(val-1);		// [x, ..., val-1] is a new sequence
            ++count;
        }
    }

    void addElement(lli val){
        auto endsbefore = ends.find(val-1);     // a sequence ending with val-1
        auto startsafter = starts.find(val+1);  // a sequence beginning with val+1
        
        if(startsafter != starts.end() && endsbefore!=ends.end()){ // two sequences get joined
            starts.erase(startsafter);  // the new sequence doesn't start with val+1 anymore
            ends.erase(endsbefore);     // the new sequence doesn't end with val-1 anymore
            --count;                    // two sequences got joined into one
        } else if (startsafter!=starts.end()){  // a sequence starting with val+1, stick val to it
            starts.erase(startsafter);          // val becomes the new starting element
            starts.insert(val);                 
        } else if (endsbefore!=ends.end()){ // val becomes the new ending element
            ends.erase(endsbefore);
            ends.insert(val);
        } else {    // add a new sequence [val]
            starts.insert(val);
            ends.insert(val);
            ++count;
        }
    }
};

lli arrayAndQueries(vector <int> &arr, vector < vector<int> > queries) {
	
	bSequences bs;

    for(auto it=arr.begin(); it!=arr.end(); ++it){
        bs.addElement(*it);
    }
    
    lli result = 0;
    for(int i=0; i<queries.size(); ++i){
        int deleteidx = queries[i][0] - 1;
        int deleteval = arr[deleteidx];
        int addval = queries[i][1];

        arr[deleteidx] = addval;

        bs.deleteElement(deleteval);
        bs.addElement(addval);
        result = ( result + (i+1)*bs.count  )%MOD; 
    }
    
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++){
       cin >> A[i];
    }
    int q;
    cin >> q;
    vector< vector<int> > queries(q,vector<int>(2));
    for(int i = 0;i < q;i++){
       for(int j = 0;j < 2;j++){
          cin >> queries[i][j];
       }
    }
    int result = arrayAndQueries(A, queries);
    cout << result << endl;
    return 0;
}
