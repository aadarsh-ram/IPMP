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

node* revLL;

node* reverse(node *head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) {
        revLL = head;
        return head;
    }
    node* revNode = reverse(head->next);
    revNode->next = head;
    head->next = NULL;
    return head;
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
        reverse(HEAD);
        displayLL(revLL);
    }
}