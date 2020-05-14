#include<unordered_map>
#include <vector>
using namespace std;

#define umap unordered_map
#define tn TrieNode

class TrieNode {
	public:
		umap<char,TrieNode*> children;
		string word="";
};

class Trie {
	public:
	tn *root;
	char endSymbol;
	
	Trie();
	void add(string str);
};

void explore(int i,int j,vector<vector<char>> board,tn *trieNode,
						vector<vector<bool>> *visited,
						umap<string,bool> *finalWords);
vector<vector<int>> getNeighbours(int i,int j,vector<vector<char>> board);

vector<string> boggleBoard(vector<vector<char>> board, vector<string> words) {
	Trie trie;
	for (string word : words) {
		trie.add(word);
	}
	umap<string,bool> finalWords;
	vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
	for (int i=0;i<board.size();i++) {
		for (int j=0;j<board[0].size();j++) {
			explore(i,j,board,trie.root,&visited,&finalWords);
		}
	}
	vector<string> finalWordsArray;
	for (auto it : finalWords) {
		finalWordsArray.push_back(it.first);
	}
  return finalWordsArray;
}

void explore(int i,int j,vector<vector<char>> board,tn *trieNode,
						vector<vector<bool>> *visited,
						umap<string,bool> *finalWords) {
	if (visited->at(i)[j]) {
		return;
	}
	char letter=board[i][j];
	if (trieNode->children.find(letter) == trieNode->children.end()) {
		return;
	}
	visited->at(i)[j]=true;
	trieNode=trieNode->children[letter];
	if (trieNode->children.find('*') != trieNode->children.end()) {
		finalWords->insert({trieNode->word,true});
	}
	vector<vector<int>> neighbours=getNeighbours(i,j,board);
	for (vector<int> neighbour : neighbours) {
		explore(neighbour[0],neighbour[1],board,trieNode,visited,finalWords);
	}
	visited->at(i)[j]=false;
}

vector<vector<int>> getNeighbours(int i,int j,vector<vector<char>> board) {
	vector<vector<int>> neighbours;
	if (i>0 && j>0) {
		neighbours.push_back({i-1,j-1});
	}
	if (i>0 && j<board[0].size()-1) {
		neighbours.push_back({i-1,j+1});
	}
	if (i<board.size()-1 && j<board[0].size()-1) {
		neighbours.push_back({i+1,j+1});
	}
	if (i<board.size()-1 && j>0) {
		neighbours.push_back({i+1,j-1});
	}
	if (i>0) {
		neighbours.push_back({i-1,j});
	}
	if (i<board.size()-1) {
		neighbours.push_back({i+1,j});
	}
	if (j>0) {
		neighbours.push_back({i,j-1});
	}
	if (j<board[0].size()-1) {
		neighbours.push_back({i,j+1});
	}
	return neighbours;
}

Trie::Trie() {
	this->root=new tn();
	this->endSymbol='*';
}

void Trie::add(string str) {
	tn *node=this->root;
	for (char letter : str) {
		if (node->children.find(letter) == node->children.end()) {
			tn *newNode=new tn();
			node->children.insert({letter,newNode});
		}
		node=node->children[letter];
	}
	node->children.insert({this->endSymbol,NULL});
	node->word=str;
}