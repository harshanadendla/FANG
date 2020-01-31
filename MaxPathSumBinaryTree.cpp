//prathi node...we check how it contributes to its parent....whether as a branch or....having been included int the global max path.
//max branch check cheyyali ante....max of left mas branch and right as branch kanukkuni...add tree val to it...check if tree val alone is greater..
//...this suffices max_b....for maxP....it is max of l_p...r_p...or l_b + tree->val + r_b......anthe...pass max_b and max_p in array

vector<int> solve(BinaryTree *tree)
{
  // no l and r...return 0;
	if(!tree) return vector<int>{0,0};
	
  //know what l contributes
	vector<int> left=solve(tree->left);
	int l_b=left[0];
	int l_p=left[1];
	
  //know what right contributes
	vector<int> right=solve(tree->right);
	int r_b=right[0];
	int r_p=right[1];
	
  //calculate what this node contributes as branch
	int max_b=max(tree->value,max(l_b,r_b)+tree->value);
  
  //calculate what this node contributes as path
	int max_p=max(max_b,l_b+r_b+tree->value);
	max_p=max({l_p,r_p,max_p});
	
	return vector<int>{max_b,max_p};
}

int maxPathSum(BinaryTree tree) 
{
	vector<int> arr=solve(&tree);
  return arr[1];
}
