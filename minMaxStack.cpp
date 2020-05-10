#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second
#define mp make_pair

class MinMaxStack {
public:
	
	stack<pair<int,pii>> st;
	
  int peek() {
    return st.top().f;
  }

  int pop() {
		int x=this->peek();
		st.pop();
		return x;
  }

  void push(int number) {
		int minV=min(this->getMin(),number);
		int maxV=max(this->getMax(),number);
		st.push(mp(number,mp(minV,maxV)));
  }

  int getMin() {
		if (st.empty()) {
			return INT_MAX;
		}
    return st.top().s.f;
  }

  int getMax() {
		if (st.empty()) {
			return INT_MIN;
		}
    return st.top().s.s;
  }
};
