#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node *next;

    public:
    Node(int data1,Node* next1)
    {
        data = data1;
        next = next1;
    } 

    // ye constructor by default next ki value NULL dal dega
    Node (int data1)
    {
        data = data1;
        next = NULL;
    }

};
// THIS FUNCTION CONVERTS ARRAY TO LINKED LIST 
Node* convertArr2LL(vector <int> &v)
{
    // [1,2,3,4]
    Node* head = new Node (v[0]);
    Node* temp = head;

    for(int i=1 ; i <v.size() ; i++)
    {
        Node *mover = new Node(v[i]);
        temp-> next = mover;
        temp = mover;
    }
    return head;
} 


// FUNCTION FINDS THE LENGTH OF THE LINKED LIST
int lengthOfLL(Node* head)

//******* Why passed Node* head as parameter?? ****** 
// REASON : Node* head ko function mein pass karke, tu specify kar raha hai ki linked list ka shuruaati point kahan se hai. Isse function kisi bhi linked list ke length ko nikalne mein help karega.

{
    int count=0;
    Node*temp = head;
     while(temp !=NULL)
    {
        temp=temp->next;
        count ++;
    }
    return count;
}


// FUNCTION TO FIND IF AN ELEMENT IS PRESENT IN THE LL
int findElement(Node *head,int key)
{
    Node* temp = head;
     while(temp !=NULL)
    {
        if(temp->data == key)
        return 1;
        temp= temp->next;
    }
    return 0;
}

//-----------TRAVERSING LINKEDLIST------------

   void printLL(Node*head)
   {
    Node* temp = head;
    while(temp !=NULL)
    {
        
        cout << temp->data<<" ";
        temp= temp->next;
    }
   }


//-----------LECTURE-2 ----------------

//########## DELETION TYPE-1 : DELETING HEAD OF LL ##########

Node* deleteHead(Node* head)
{
    if(head == NULL)
    return head;

    //Create a temporary pointer to the head node
    Node* temp = head;

    // Move the head to the next node
    head=head->next;

    // Delete the original head node
    delete temp;

    // Return the updated head of the linked list        
    return head ; 
}

Node* deleteTail(Node* head)
{
    // 1->2->3->4->NULL

    Node* temp =head;
    while(temp->next->next !=NULL)
    {
        temp=temp->next;
    }
    // after this loop ends temp will be second last element 

    // delete the last element
    delete temp->next;

    temp->next = NULL;
    return head;            
}


int main()
{
    vector <int> v={1,2,3,4};

    // Node *y=new Node(10,nullptr);  // node with data 10 , Null ptr is created
    // cout << y->data; // printing the data part of node

    Node* head = convertArr2LL(v);

    //cout << lengthOfLL(head) << endl;
    //cout << findElement(head, 3);

    head = deleteHead(head); //****** YE KU LIKHA ???? *****
    // Bhai, yeh line of code "head = removeHead(head);"  ka matlab hai ki hum linked list ka head hata rahe hain aur uski jagah new head ko assign kar rahe hain.  


    //head = deleteTail(head);
    printLL(head);



}
