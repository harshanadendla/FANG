#include <vector>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>

vector<vector<int>> getKnapsackItems(vvi knapsackValues,
																		vvi items,int weight);

vector<vector<int>> knapsackProblem(vector<vector<int>> items, int capacity) {
	vvi knapsackValues(items.size()+1,
										vi(capacity+1,0));
	for (int i=1;i<items.size()+1;i++) {
		int currentWeight=items[i-1][1];
		int currentValue=items[i-1][0];
		for (int c=0;c<capacity+1;c++) {
			if (currentWeight>c) {
				knapsackValues[i][c]=knapsackValues[i-1][c];
			} else {
				knapsackValues[i][c]=
					max(knapsackValues[i-1][c],
						 knapsackValues[i-1][c-currentWeight]+currentValue);
			}
		}
	}
  return getKnapsackItems(knapsackValues,items,
												 knapsackValues[items.size()][capacity]);
		
	}

vvi getKnapsackItems(vvi knapsackValues,
										vvi items,int weight) {
	vvi solution ={{},{}};
	int i=knapsackValues.size()-1;
	int c=knapsackValues[0].size()-1;
	while (i>0) {
		if (knapsackValues[i][c] == knapsackValues[i-1][c]) {
			i--;
		} else {
			solution[1].insert(solution[1].begin(),i-1);
			c-=items[i-1][1];
			i--;
		}
		if (c==0) {
			break;
		}
	}
	solution[0].push_back(weight);
	return solution;
}