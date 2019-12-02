#include<vector>
#include<iostream>
#include<map>
#include<queue>
#define v vector<int>
#define vv vector<vector<int> >

vv vot(tree* a)
{
    vv res;
    map<int,v> vects;
    queue<pair<tree*,int>> q;
    q.push(make_pair(a,0));

    while(!q.empty())
    {
        pair<tree*,int> p=queue.front();
        q.pop();
        tree* temp=p.first;
        int count=p.second;
        
        if(temp->left != NULL)
        {
            q.push(make_pair(temp->left,count-1));
            vects[count].push_back(temp->val);
        }
        if(temp->right != NULL)
        {
            q.push(make_pair(temp->right,count+1));
            vects[count].push_back(temp->val);
        }
        free(temp);
    }
    map<int,v>::iterator it;
    for(it=vects.begin();it!=vects.end();it++)
    {
        res.push_back(it->second);
    }
    return res;
}

vv vot(tree* a)
{
    map<int,v> vects;
    queue<pair<tree*,int>> q;
    q.push_back(make_pair(a,0));
    while(!q.empty())
    {
        pair<tree*,int> p=q.front();
        q.pop();
        
        tree* temp=p.first;
        int count=p.second;

        vects[count].push_back(temp->val);

        if(temp->left)
        {
            q.push(make_pair(temp->left,count-1));
        }
        if(tree->right)
        {
            q.push(make_pair(temp->right,count+1));
        }
    }
    vector<vector<int>> res;
    map<int,v>::iterator it;
    for(it=vects.begin();it!=vects.end();it++)
    {
        res.push_back(it->second);
    }
    return res;
}