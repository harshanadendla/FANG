#include <vector>
using namespace std;

class TrieNode {
	public:
		unordered_map<char,TrieNode *> children;
		string word; 
};

class Trie {
	public:
		TrieNode *root;
		char endSymbol;
	
		Trie() {
			this->root=new TrieNode();
			this->endSymbol='*';
		}
	
		void insert(string str) {
			TrieNode *cur=this->root;
			for (int i=0;i<str.size();i++) {
				char letter=str[i];
				if (cur->children.find(letter)==cur->children.end()) {
					TrieNode *newNode=new TrieNode();
					cur->children.insert({letter,newNode});
				}
				cur=cur->children[letter];
			}
			cur->children.insert({this->endSymbol,NULL});
			cur->word=str;
		}
};

void findSmallStringsIn(string str,int startIdx,Trie *trie,
											 unordered_map<string,bool> *containedString);

vector<bool> multiStringSearch(string bigString, vector<string> smallStrings) {
	Trie *trie=new Trie();
	for (string smallString : smallStrings) {
		trie->insert(smallString);
	}
	unordered_map<string,bool> containedStrings;
	for (int i=0;i<bigString.size();i++) {
		findSmallStringsIn(bigString,i,trie,&containedStrings);
	}
	vector<bool> solution;
	for (string smallString : smallStrings) {
		solution.push_back(containedStrings.find(smallString) != 
											containedStrings.end());
	}
	return solution;
}

void findSmallStringsIn(string str,int startIdx,Trie *trie,
											 unordered_map<string,bool> *containedStrings) {
	TrieNode *cur=trie->root;
	for (int i=startIdx;i<str.size();i++) {
		if (cur->children.find(str[i])==cur->children.end()) {
			break;
		}
		cur=cur->children[str[i]];
		if (cur->children.find(trie->endSymbol) !=
			 cur->children.end()) {
			containedStrings->insert({cur->word,true});
		}
	}
}
