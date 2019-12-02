#include<vector>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<bool>
#define vvb vector<vector<bool>>

using namespace std;

vvi getNeighbours(int i,int j,vvb visited)
{
    vvi neighbours{};
    if(i-1>=0 && !visited[i-1][j])
    {
        neighbours.push_back({i-1,j});
    }
    if(i+1<=visited.size()-1 && !visited[i+1][j])
    {
        neighbours.push_back({i+1,j});
    }
    if(j-1>=0 && !visited[i][j-1])
    {
        neighbours.push_back({i,j-1});
    }
    if(j+1<=visited[0].size()-1 && !visited[i][j+1])
    {
        neighbours.push_back({i,j+1});
    }
    return neighbours;
}

void traverseNodes(int i,int j,vvi matrix,vvb& visited,vi& sizes)
{
    int riverSize=0;
    vi stacks{{i,j}};
    while(!stacks.empty())
    {
        vi curr=stacks.back();
        stacks.pop_back();

        int i=curr[0];
        int j=curr[1];

        if(visited[i][j])
        {
            continue;
        }
        visited[i][j]=true;
        if(matrix[i][j]==0)
        {
            continue;
        }
        riverSize++;
        vvi neighbours=getNeighbours(i,j,visited);
        for(vi neighbour : neighbours)
        {
            stacks.push_back(neighbour);
        }
    }
    if(riverSize>0)
    {
        sizes.push_back(riverSize);
    }
}

vi riverSizes(vvi matrix)
{
  vi sizes{};
  vvb visited(matrix.size(),vb(matrix[0].size(),false));
  for(int i=0;i<matrix.size();i++)
  {
      for(int j=0;j<matrix[0].size();j++)
      {
          if(visited[i][j])
          {
              continue;
          }
          traverseNodes(i,j,matrix,visited,sizes);
      }
  }
  return sizes;  
}