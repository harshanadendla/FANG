



// compiler waste...unordered map ledu.





#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

bool balancedPar(string s)
{
    vector<char> stack;
    unordered_map<char,char> jodi { {')','('} , {']','['} , {'}','{'} };
    string opening="([{";
    string closing=")]}";
    for(char c : s)
    {
        if(opening.find(c) != string::npos)
        {
            stack.push_back(c);
        }
        else if(closing.find(c) != string::npos)
        {
            if(stack.empty())
            {
                return false;
            }
            if(stack.back() == jodi[c])
            {
                stack.pop_back();
            }
            else
            {
                return false;
            }
        }
    }
    return stack.empty();
}

int main()
{
    cout<<balancedPar("{[]}((([])))");
    return 0;
}