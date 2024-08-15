//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        // 15.08.24 (POTD)
        if(!head)   return head;
        
        stack<int> s, t;
        Node* h=head;
        Node* p=head;
        while(h){
            s.push(h->data);
            p=h;
            h=h->next;
        }
        
        if(s.top()<9){
            p->data=p->data+1;
            return head;
        }
        else{
            int x=s.top()+1;
            s.pop();
            int car=1;
            x%=10;
            t.push(x);
            
            while(car==1 && s.size()){
                x=s.top()+car;
                s.pop();
                if(x<10){
                    t.push(x);
                    car=0;
                    break;
                }
                else{
                    car=1;
                    x%=10;
                    t.push(x);
                }
            }
            
            while(s.size()){
                t.push(s.top());
                s.pop();
            }
            
            Node* ans=new Node(1);
            Node* a=ans;
            while(t.size()){
                Node* n=new Node(t.top());
                a->next=n;
                a=a->next;
                t.pop();
            }
            
            if(car==0)
                ans=ans->next;
                
            return ans;
        }
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends