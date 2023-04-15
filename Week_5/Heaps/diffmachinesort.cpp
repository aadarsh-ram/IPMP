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
    struct node *next;
};

struct heapNode {
    node *head;
};

struct minHeap {
    int capacity, count;
    heapNode *arr;
};

minHeap* createHeap(int c) {
    minHeap *minh = new minHeap;
    minh->capacity = c;
    minh->count = 0;
    minh->arr = new heapNode[c];
    return minh;
}

void push(node **ref, int data) {
    node *newnode = new node;
    newnode->data = data;
    newnode->next = (*ref);
    (*ref) = newnode;
}

void swap(heapNode *a, heapNode *b) {
    heapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(minHeap *minh, int k) {
    int left = 2*k + 1;
    int right = 2*k + 2;
    int smallest = k;
    if (left < minh->count && minh->arr[left].head->data < minh->arr[smallest].head->data) {
        smallest = left;
    }
    if (right < minh->count && minh->arr[right].head->data < minh->arr[smallest].head->data) {
        smallest = right;
    }
    if (smallest != k) {
        swap(&minh->arr[smallest], &minh->arr[k]);
        heapify(minh, smallest);
    }
}

void buildHeap(minHeap *minh) {
    int n = minh->count - 1;
    for (int i=(n-1)/2; i>=0; i--) {
        heapify(minh, i);
    }
}

node* extractMin(minHeap *minh) {
    if (minh->count == 0) return NULL;
    heapNode temp = minh->arr[0];
    if (temp.head->next) {
        minh->arr[0].head = temp.head->next;
    } else {
        minh->arr[0] = minh->arr[minh->count - 1];
        --minh->count;
    }
    heapify(minh, 0);
    return temp.head;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; t=1;
    while (t--) {
        
        node *nums[3];
        
        nums[0] = NULL;
        push (&nums[0], 50);
        push (&nums[0], 40);
        push (&nums[0], 30);
        
        nums[1] = NULL;
        push (&nums[1], 45);
        push (&nums[1], 35);
        
        nums[2] = NULL;
        push (&nums[2], 100);
        push (&nums[2], 80);
        push (&nums[2], 70);
        push (&nums[2], 60);
        push (&nums[2], 10);

        minHeap *minh = createHeap(3);
        for (int i=0; i<3; i++) {
            minh->arr[minh->count++].head = nums[i];
        }
        buildHeap(minh);
        while (minh->count != 0) {
            node *temp = extractMin(minh);
            cout << temp->data << " ";
        }
    }
    return 0;
}