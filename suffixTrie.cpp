#include<unordered_map>
using namespace std;
#define tn TrieNode

class TrieNode
{
    public:
     unordered_map<char,tn*> children;
};

class SuffixTrie
{
    public:
     tn* root;
     char endsymbol;

    SuffixTrie(string str)
    {
        this->root=new TrieNode();
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
        TrieNode* node=this->root;
        for(int k=i;k<str.length();k++)
        {
            char letter=str[k];
            if(node->children.find(letter)==node->children.end())
            {
                TrieNode* temp=new TrieNode();
                node->children.insert({letter,temp});
            }
            node=node->children[letter];
        }
        node->children.insert({'*',NULL});
    }

    bool contains(string str)
    {
        TrieNode* node=this->root;
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