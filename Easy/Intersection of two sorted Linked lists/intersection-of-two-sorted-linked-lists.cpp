//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    if(n)
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    else cout<< " ";
}


// } Driver Code Ends
/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution
{
    public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        // code goes here.
        // 19.11.23 (POTD) 
        
        Node* ans=new Node(-1);
        Node* a;
        Node* h1=head1;
        Node* h2=head2;
    
        while(h1 && h2){
            if(h1->data==h2->data){
                Node* n=new Node(h1->data);
                if(ans->data==-1){
                    ans->data=h1->data;
                    a=ans;
                }
                else{
                    a->next=n;
                    a=n;
                }
                h1=h1->next;
                h2=h2->next;
            }
            else if(h1->data<h2->data)
                h1=h1->next;
            else
                h2=h2->next;
        }
    
        return ans->data == -1 ? NULL : ans;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Solution ob;
	    Node* result = ob.findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends