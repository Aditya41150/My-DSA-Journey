#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    // ye constructor by default next ki value NULL dal dega
    Node(int data1)
    {
        data = data1;
        next = NULL;
    }
};
// THIS FUNCTION CONVERTS ARRAY TO LINKED LIST
Node *convertArr2LL(vector<int> &v)
{
    // [1,2,3,4]
    Node *head = new Node(v[0]);
    Node *temp = head;

    for (int i = 1; i < v.size(); i++)
    {
        Node *mover = new Node(v[i]);
        temp->next = mover;
        temp = mover;
    }
    return head;
}

// FUNCTION FINDS THE LENGTH OF THE LINKED LIST
int lengthOfLL(Node *head)

//******* Why passed Node* head as parameter?? ******
// REASON : Node* head ko function mein pass karke, tu specify kar raha hai ki linked list ka shuruaati point kahan se hai. Isse function kisi bhi linked list ke length ko nikalne mein help karega.

{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

// FUNCTION TO FIND IF AN ELEMENT IS PRESENT IN THE LL
int findElement(Node *head, int key)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
            return 1;
        temp = temp->next;
    }
    return 0;
}

//-----------TRAVERSING LINKEDLIST------------

void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {

        cout << temp->data << " ";
        temp = temp->next;
    }
}

//-----------LECTURE-2 ----------------

// ########## DELETION TYPE-1 : DELETING HEAD OF LL ##########

Node *deleteHead(Node *head)
{
    if (head == NULL)
        return head;

    // Create a temporary pointer to the head node
    Node *temp = head;

    // Move the head to the next node
    head = head->next;

    // Delete the original head node
    delete temp;

    // Return the updated head of the linked list
    return head;
}

Node *deleteTail(Node *head)
{
    // 1->2->3->4->NULL

    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    // after this loop ends temp will be second last element

    // delete the last element
    delete temp->next;

    temp->next = NULL;
    return head;
}

//------------FUNCTION TO DELETE Kth ELEMENET OF LINKED LIST-----
Node *deletek(Node *head, int k)
{
    if (head == NULL)
        return NULL;

    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int count = 0;
    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL)
    {
        count++;
        if (count == k)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

//-----FUNCTION TO DELETE AN ELEMENT FROM THE LL-----
Node *deleteElement(Node *head, int Element)
{
    if (head == NULL)
        return NULL;

    if (head->data == Element)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL)
    {
        if (temp->data == Element)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
//----THIS FUNCTION INSERTS VALUE AT HEAD----------

Node *insertHead(Node *head, int val)
{
    Node *temp = new Node(val, head);
    return temp;
}

//---- INSERTING VALUE AT THE TAIL -----
Node *insertAtTail(Node *head, int value)
{
    if (head == NULL)
        return new Node(value);

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *y = new Node(value); // creating new node

    temp->next = y;
    return head;
}

//---- INSERTING VALUE AT kth position   -----

Node *insertatKth(Node *head, int k, int value)
{
    if (head == NULL) // condition 1
        return new Node(value);

    if (k == 1) // condition 2
    {
        Node *temp = new Node(value);
        temp = head;
    }
    int count = 0;
    Node *temp = head;
    Node *y = new Node(value); // creating new node to be inserted

    // condition 3
    while (temp != NULL)
    {
        count++;
        if (count == k - 1)
        {
            y->next = temp->next; // connecting new node to next node

            temp->next = y; // now connecting temp to new node.
            break;
        }
        temp = temp->next;
    }

    return head;
}

int main()
{
    vector<int> v = {1, 2, 3, 4};

    // Node *y=new Node(10,nullptr);  // node with data 10 , Null ptr is created
    // cout << y->data; // printing the data part of node

    Node *head = convertArr2LL(v);

    cout << lengthOfLL(head) << endl;
    cout << findElement(head, 3);

    head = deleteHead(head); //****** YE KU LIKHA ???? *****

    // Bhai, yeh line of code "head = removeHead(head);"  ka matlab hai ki hum linked list ka head hata rahe hain aur uski jagah new head ko assign kar rahe hain.

    head = deletek(head,2);  // deletes kth element of LL

    head = deleteElement(head,2); // deletes element passed in the function

    head = deleteTail(head); //deletes Tail element of LL

    head = insertHead(head,6); // insert value at head

    head = insertAtTail(head,12); // inserts value at tail

    head = insertatKth(head,5,20); // inserts value at kth location

    printLL(head); // PRINTS THE LL
}
