#include<unordered_map>
using namespace std;
#define tn TrieNode
#define suffTrie SuffixTrie

class tn
{
	public:
	 unordered_map<char,tn*> children;
};

class suffTrie
{
	public:
	  tn* root;
	  char endsymbol;
	
	suffTrie(string str)
	{
		this->root=new tn();
		this->endsymbol='*';
		this->fill(str);
	}
	
	void fill(string str)
	{
		for(int i=0;i<str.length();i++)
		{
			this->fillDown(i,str);
		}
	}
	
	void fillDown(int i,string str)
	{
		tn* node=this->root;
		for(int j=i;j<str.length();j++)
		{
			char letter=str[j];
			if(node->children.find(letter)==node->children.end())
			{
				tn* temp=new tn();
				node->children[letter]=temp;
			}
			node=node->children[letter];
		}
		node->children['*']=NULL;
	}
	
	bool contains(string str)
	{
		tn* node=this->root;
		for(char letter : str)
		{
			if(node->children.find(letter)==node->children.end())
			{
				return false;
			}
			node=node->children[letter];
		}
		return node->children.find(this->endsymbol)==node->children.end() ? false : true ;
	}
};