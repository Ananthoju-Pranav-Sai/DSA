#include <iostream>
using namespace std;

class Node
{
    public:
        pair<string,string>User;
        Node* next;
        
        Node()
        {
            User = make_pair("Username","Password");
            next = NULL;
        }
        Node(pair<string,string> u)
        {
            this->User = u;
            this->next = NULL;
        }
};

class LinkedList
{
    public:
        Node *head;
        LinkedList()
        {
            head = NULL;
        }
        int size() const;
        void InsertNode(pair<string,string>user);
        void DeleteNode(string username);
        void print_list();
};
int LinkedList::size() const
{
    Node *temp = head;
    int size=0;
    while(temp!=NULL)
    {
        size++;
        temp=temp->next;
    }
    return size;
}
void LinkedList::InsertNode(pair<string,string>user)
{
    Node *newuser = new Node(user);
    if(head==NULL)
    {
        head = newuser;
        return;
    }
    Node *temp = head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next = newuser;
}
void LinkedList::DeleteNode(string username)
{
    Node *temp = head;
    if(head->User.first==username)
    {
        head=head->next;
        return;
    }
    while(temp!=NULL)
    {
        if((temp->next)->User.first==username)
        {
            temp->next = (temp->next)->next;
            delete(temp->next);
            return;
        }
    }
    cout<<"List is Empty!\n";
}
void LinkedList::print_list()
{
    Node *temp = head;
    if(head==NULL)
    {
        cout<<"List empty!\n";
    }
    while(temp!=NULL)
    {
        cout<<temp->User.first<<" "<<temp->User.second<<"\n";
        temp = temp->next;
    }
}