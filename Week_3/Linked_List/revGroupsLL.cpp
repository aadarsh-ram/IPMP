#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        if (head == NULL || k == 1) return head;
        node *curr = head;
        node *nHead = NULL;
        node *tail = NULL;
        while (curr) {
            int cnt = k;
            node *prev=NULL, *now = curr;
            while (now && cnt>0) {
                struct node *next = now->next;
                now->next = prev;
                prev = now;
                now = next;
                cnt--;
            } 
            if (nHead == NULL) {
                nHead = prev;
            }
            if (tail) {
                tail->next = prev;
            }
            tail = curr;
            curr = now;
        }
        return nHead;
    }
};

int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}