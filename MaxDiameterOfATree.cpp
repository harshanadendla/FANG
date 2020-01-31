// codingclub prob setter intern lo adigaru....n^2 sol ki vcha...but asalu alochinchalekapoya next....and sol choosinappudu
//height asa parameter artham kala....time pattindi...but arthamaindi

int solve(TreeNode* a,int& height)
{
  int lh=0,rh=0;
  int ld=0,rd=0;
  if(!a)
  {
    height=0;
    return 0;
  }
  ld=solve(a->left,lh);
  rd=solve(a->right,rh);
  height=max(lh,rh)+1;
  return max({lh+rh+1,ld,rd});
}

int maxDiameter(TreeNode* root)
{
  int height=0;
  return solve(root,height);
  return 0;
}
