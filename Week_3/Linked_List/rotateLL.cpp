#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution
{
    public:
    Node* rotate(Node* head, int k) {
        Node *check = head;
        int len = 0;
        while (check != NULL) {
            len++;
            check = check->next;
        }
        if (k == len || k == 0) return head;
        
        Node *temp = head;
        int l = 0;
        while (l < k) {
            temp = temp->next;
            l++;
        }
        Node *last = head;
        k--;
        while (k) {
            last = last->next;
            k--;
        }
        last->next = NULL;
        Node *newH = temp;
        while (newH->next != NULL) {
            newH = newH->next;
        }
        newH->next = head;
        return temp;
    }
};

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}
