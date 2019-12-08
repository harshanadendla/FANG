string temp="";

unordered_map<char,string> keypad=
{
    {'0',"0"},
    {'1',"1"},
    {'2',"abc"},
    {'3',"def"},
    {'4',"ghi"},
    {'5',"jkl"},
    {'6',"mno"},
    {'7',"pqrs"},
    {'8',"tuv"},
    {'9',"wxyz"}
}

void generate(string a,int i,vector<string> &res)
{
    string s=keypad[a[i]];
    for(int j=0;j<s.length();j++)
    {
        temp+=s[j];
        if(i==a.length()-1)
        {
            res.push_back(temp);
        }
        else
        {
            generate(a,i+1,res);
        }
        temp.pop_back();
    }
}

vector<string> letter-phone(string a)
{
    vector<string> res;
    generate(a,0,res);
    return res;
}