#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define vi vector<int>
#define pb push_back

using namespace std;

struct minHeapNode {
    char data;
    int freq;
    minHeapNode *left, *right;
};

struct compareFunc {
    bool operator() (minHeapNode *l, minHeapNode *r) {
        return l->freq > r->freq;
    }
};

void printCodes(minHeapNode* root, string str) {
    if (!root) return;
    if (root->data != '$')
        cout << root->data << ": " << str << "\n";

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; t=1;
    while (t--) {
        int n; cin >> n;
        vector<char> arr(n);
        for (int i=0; i<n; i++) {
            cin >> arr[i];
        }
        vi freq(n);
        for (int i=0; i<n; i++) {
            cin >> freq[i];
        }
        struct minHeapNode *left, *right, *top;
        priority_queue<minHeapNode*, vector<minHeapNode*>, compareFunc> pq;
        for (int i=0; i<n; i++) {
            minHeapNode *minn = new minHeapNode;
            minn->data = arr[i]; minn->freq = freq[i];
            minn->left = NULL; minn->right = NULL;
            pq.push(minn);
        }
        while (pq.size() != 1) {
            left = pq.top(); pq.pop();
            right = pq.top(); pq.pop();
            top = new minHeapNode;
            top->data = '$'; top->freq = left->freq + right->freq;
            top->left = left; top->right = right;
            pq.push(top);
        }
        printCodes(pq.top(), "");
    }
}