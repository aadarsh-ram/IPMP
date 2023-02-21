#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define vi vector<int>
#define pb push_back

using namespace std;

struct node {
    int data;
    node* next;
};

node *a, *p, *q;
node* createNodes(int n, vi arr) {
	a = new node;
	a->data=arr[0];
	a->next=NULL;
	p = a;
	
	for (int i=1; i<n; i++) {
		q = new node;
		q->data=arr[i];
		q->next=NULL;
		p->next=q;
		p = q;
	}
	return a;
}

void displayLL(node *head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

bool loopExists(node *head) {
    if (head == NULL) return false;
    node *slow = head, *fast = head;
    int flag = 0;
    while (fast != slow || flag == 0) {
        if (flag == 0) flag = 1;
        if (fast->next == NULL || fast->next->next == NULL) return false; 
        fast = fast->next->next;
        slow = slow->next;
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; t=1;
    while (t--) {
        int n; cin >> n;
        vi arr(n);
        for (int i=0; i<n; i++) {
            cin >> arr[i];
        }
	    node *HEAD = createNodes(n, arr);
        cout << loopExists(HEAD) << endl;
    }
}