#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

struct Node* makeUnion(struct Node* head1, struct Node* head2);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        printList(makeUnion(first,second));
    }
    return 0;
}

struct Node* makeUnion(struct Node* head1, struct Node* head2)
{
    // code here
    map<int, int> mp;
    Node *temp1 = head1;
    Node *temp2 = head2;
    while (temp1 != NULL){
        mp[temp1->data]++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL){
        mp[temp2->data]++;
        temp2 = temp2->next;
    }
    Node *head = NULL, *tail = NULL;
    for (auto i: mp) {
        if (i.second > 0) {
            if (head == NULL) {
                head = new Node(i.first);
                tail = head;
            }
            else {
                Node *curr = new Node(i.first);
                tail->next = curr;
                tail = tail->next;
            }
        }
    }
    return head;
}
