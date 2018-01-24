/* 
 * Given a string and a dictionary of words, find out if the input string can be 
 * broken into a space-separated sequence of one or more dictionary words. If yes,
 * output the space-separated words, else output "NO". 
 * Store the dictionary in a trie.
 *
 * Input Format:
 * 1. First line has an integer 'N' denoting number of words in the dictionary.
 * 2. Following 'N' lines have one word each making the dictionary.
 * 3. Next line has an integer 'T' denoting number of sentences to pretty-print.
 * 4. Following 'T' lines have one sentence each.
 */

#include <iostream>
#include <algorithm>

using namespace std;

const int ALPHABETS = 26;

struct trieNode {
	struct trieNode *children[ALPHABETS];
	bool isEOW;
	trieNode():isEOW(false) {
		for (int i = 0; i < ALPHABETS; ++i)
			children[i] = nullptr;
	}
};

using tnode = trieNode;

struct trie {
	tnode *root_;

	trie() { root_ = new(tnode);} 
	void insert(string word) { if(!word.empty()) insertUtil(root_, word);}
	bool search(string word) { return searchUtil(root_, word);}

 private:
	void insertUtil(tnode * root, string word) {
		if(!word.length()){	// last character
			root->isEOW = true;
			return;
		}
		size_t i = word[0] - 'a';
		if(!root->children[i]){	// node doesn't exist
			root->children[i] = new(tnode);
		}
		insertUtil(root->children[i], word.substr(1));
	}
	bool searchUtil(tnode * root, string word) {
		if(!word.length())
			return root->isEOW;

		size_t i = word[0] - 'a';
		if(!root->children[i])
			return false;	// word is longer than TRIE path
		return searchUtil(root->children[i], word.substr(1));
	}
};

using pbi = pair < bool, size_t >;
void pretty_print(string sentence, trie & dictionary){
	size_t sentenceLen = sentence.length();
	pbi dp[sentenceLen][sentenceLen];
	dp[0][0] = make_pair(false, -1);

	for (int wordlen = 1; wordlen <= sentenceLen; ++wordlen) 
		for (int start = 0; start <= (sentenceLen - wordlen); ++start) {
			int end = start + wordlen - 1;
			string tryword = sentence.substr(start, end - start + 1);
			if (dictionary.search(tryword)) // tryword found in dictionary, store word's end-index
				dp[start][end] = make_pair(true, end);
			else {
				pbi found = make_pair(false, -1);
				for (int k = start; k < end; ++k) { // try all ways to split tryword in two
					if (dp[start][k].first // first split can be pretty-printed
					    && dp[k + 1][end].first) { // second split can be pretty-printed
						found = make_pair(true, k); // store the split-index
						break;
					}
				}
				dp[start][end] = found;
			}
		}

	int i = 0;
	int j = sentenceLen - 1;
	if (dp[i][j].first) { // whole sentence can be pretty printed
		while (i < j) {
			if (dp[i][j].first) {
				int split = dp[i][j].second; // read split-index from dp table
				cout << sentence.substr(i, split - i + 1) << " ";
				i = split + 1;
			} else
				break;
		}
		cout << endl;
	} else
		cout << "NO" << endl;
}

int main(int argc, char **argv)
{
	int n, T;

	cin >> n;
	// input the dictionary and store in a Trie
	trie dictionary;
	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		dictionary.insert(word);
	}

	cin >> T;
	for (int t = 0; t < T; t++) {
		string sentence;
		cin >> sentence;
		pretty_print(sentence, dictionary);
	}
}
