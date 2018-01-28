/* 
 * The SuperBowl Lottery is about to commence, and there are several lottery tickets being sold, 
 * and each ticket is identified with a ticket ID. In one of the many winning scenarios in the Superbowl lottery, a winning pair of tickets is:
 *
 * 1. Concatenation of the two ticket IDs in the pair, in any order, contains each digit from  to  at least once.
 *
 * For example, if there are 2 distinct tickets with ticket ID 12930045 and 56789, (12930045, 56789) is a winning pair.
 *
 * NOTE: The ticket IDs can be concantenated in any order. Digits in the ticket ID can occur in any order.
 *
 * Your task is to find the number of winning pairs of distinct tickets, such that concatenation of their ticket IDs (in any order) 
 * makes for a winning scenario. Complete the function winningLotteryTicket which takes a string array of ticket IDs as input, 
 * and returns the number of winning pairs.
 *
 * Input Format
 *
 * The first line contains n denoting the total number of lottery tickets in the super bowl. 
 * Each of the next n lines contains a string, denoting a ticket ID.
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace std;

/* concatenate all characters making up a set */
string collapseSet(set<char> &s){
	string str;
	for_each(s.begin(), s.end(), [&](char c){str.push_back(c);});
	return str;
}

/* union all characters of two strings */
string getUnion(const string &str1, const string &str2){
	set<char> u;
	set_union(str1.begin(), str1.end(), str2.begin(), str2.end(), 
			inserter(u, u.begin()));
	return collapseSet(u);
}

long long int winningLotteryTicket(vector <string> &tickets) {
	string all("0123456789"); // the winning combination
	long long int winners = 0;
	long long int non_wildcards = tickets.size();
	unordered_map<string, long long int> hashmap; // a map storing number of tickets with same unique characters

	set<char> unique;
	for (int i = 0; i < tickets.size(); ++i) {
		unique.clear();
		for(int j=0; j<tickets[i].size(); ++j){
			unique.insert(tickets[i][j]);
		}
		string key = collapseSet(unique);
		if(key == all){ // wildcard ticket, it'll match with all other tickets
			winners += 2 * (non_wildcards-1); // count all pairs twice (to match the following comparision logic)
			--non_wildcards;    // exclude this ticket from matching with future wildcards
		} else {
			hashmap[key]++;
		}
	}

	// compare each tickets-bucket with every other to check if the pairs make a winning combination
	for(auto it=hashmap.begin(); it != hashmap.end(); ++it){
		for(auto it1=hashmap.begin();  it1 != hashmap.end(); ++it1){
			if(it->first != it1->first ){
				if(getUnion(it->first, it1->first) == all){
					winners += it->second * it1->second;
				}
			}
		}
	}

	return winners/2; // each winning pair was counted twice
}

int main() {
	int n;
	cin >> n;
	vector<string> tickets(n);
	for(int tickets_i = 0; tickets_i < n; tickets_i++){
		cin >> tickets[tickets_i];
	}
	long long int result = winningLotteryTicket(tickets);
	cout << result << endl;
	return 0;
}
