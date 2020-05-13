#include<bits/stdc++.h>
using namespace std;

#define ds LinkedList
#define val value

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    next = NULL;
  }
};

LinkedList *rearrangeLinkedList(LinkedList *head, int k) {
	ds* lhead=NULL;
	ds* ltail=NULL;
	ds* eqhead=NULL;
	ds* eqtail=NULL;
	ds* ghead=NULL;
	ds* gtail=NULL;
	
	ds* temp=head;
	while (temp) {
		if (temp->val < k) {
			if (lhead) {
				ltail->next=temp;
				ltail=temp;
			} else {
				lhead=temp;
				ltail=temp;
			}
		} else if (temp->val == k) {
			if (eqhead) {
				eqtail->next=temp;
				eqtail=temp;
			} else {
				eqhead=temp;
				eqtail=temp;
			}
		} else {
			if (ghead) {
				gtail->next=temp;
				gtail=temp;
			} else {
				ghead=temp;
				gtail=temp;
			}
		}
		temp=temp->next;
	}
	
	if (lhead) {
		if (eqhead) {
			ltail->next=eqhead;
			if (ghead) {
				eqtail->next=ghead;
				gtail->next=NULL;
			} else {
				eqtail->next=NULL;
			}
		} else {
			if (ghead) {
				ltail->next=ghead;
				gtail->next=NULL;
			} else {
				ltail->next=NULL;
			}
		}
		return lhead;
	}
	
	if (eqhead) {
		if (ghead) {
			eqtail->next=ghead;
			gtail->next=NULL;
		} else {
			eqtail->next=NULL;
		}
		return eqhead;
	}
	
	if (ghead) {
		gtail->next=NULL;
		return ghead;
	} else {
		return NULL;
	}
}
