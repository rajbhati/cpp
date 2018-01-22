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

/* recursive solution. */
string abbreviation(string a, string b) {
    size_t n1, n2;
    n1 = a.length(); n2 = b.length();
    if(!n2){
        auto it = find_if(a.begin(), a.end(), [](char x){return isupper(x);});
        if(it == a.end()) return "YES";
        else return "NO";
    } else if(!n1) return "NO";

    if(a[n1-1] == b[n2-1]){
        return abbreviation(a.substr(0, n1-1), b.substr(0, n2-1));
    } else if (toupper(a[n1-1]) == b[n2-1]){
        string capa = a;
        capa[n1-1] = toupper(capa[n1-1]); // capitalize the last letter
        if(abbreviation(capa, b) == "YES") return "YES";
        if(abbreviation(a.substr(0, n1-1), b) == "YES") return "YES";
        return "NO";
    } else {
        if(islower(a[n1-1])){
            return abbreviation(a.substr(0, n1-1), b);
        } else return "NO";
    }
}

string abbreviationDP(string a, string b) {
    size_t n1, n2;
    n1 = a.length(); n2 = b.length();
    bool abbDP[n1+1][n2+1];
    
    abbDP[0][0] = true;
    
    for(int i=1; i<=n1; ++i){
        abbDP[i][0] = abbDP[i-1][0] && islower(a[i-1]);
    }
    for(int j=1; j<=n2; ++j){
        abbDP[0][j] = false;
    }

    for(int i=1; i<=n1; ++i){
        for(int j=1; j<=n2; ++j){
            if(a[i-1] == b[j-1]){
                abbDP[i][j] = abbDP[i-1][j-1];
            } else if(toupper(a[i-1]) == b[j-1]){
                abbDP[i][j] = abbDP[i-1][j] || abbDP[i-1][j-1];
            } else {
                if( islower(a[i-1])) abbDP[i][j] = abbDP[i-1][j];
                else abbDP[i][j] = false;
            }
        }
    }
    
    return abbDP[n1][n2] ? "YES" : "NO";
}

/* 
 * You can perform the following operation on some string, a :
 *
 * Capitalize zero or more of a's lowercase letters at some index i (i.e., make them uppercase).
 * Delete all of the remaining lowercase letters in a.
 * Given q queries in the form of two strings, a and b, determine if it's possible to make a equal to b by performing the above operation on a. 
 * If a can be transformed into b, print YES on a new line; otherwise, print NO.
 *
 * https://www.hackerrank.com/challenges/abbr/problem
 */

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string a;
        cin >> a;
        string b;
        cin >> b;
        auto result = abbreviationDP(a, b);
        cout << result << endl;
    }
    return 0;
}
