#include <iostream>
#include "list.h"
using namespace std;

class HashTable
{
    private:
        static const int m=100;
        LinkedList table[m];
    public:
        bool isEmpty() const;
        int HashFunction(string username);
        void InsertUser(string username,string password);
        void RemoveUser(string username);
        string SearchUser(string username);
        void print_table();
};
//Function to check whether the hash table is empty or not.
bool HashTable::isEmpty() const
{
    int sum=0;
    for (int i=0;i<m;i++)
    {
        sum += table[i].size();
    }
    if(sum)
        return true;
    return false;
}
//Function which returns index where username and password are to be stored based on username.
int HashTable::HashFunction(string username)
{
    int l = username.length();
    int index=0;
    for(int i=0;i<l;i++)
    {
        index += int(username[i]);
    }
    index = index%m;
    return index;
}
//Function to insert username and password of a user.
void HashTable::InsertUser(string username,string password)
{
    int ind = HashFunction(username);
    bool insertion=false;
    Node *temp = table[ind].head;
    while(temp!=NULL)
    {
        pair<string,string> i = temp->User;
        if(i.first==username)
        {
            i.second=password;
            insertion = true;
        }
        temp=temp->next;
    }
    if(!insertion)
    {
        table[ind].InsertNode(make_pair(username,password));
    }
}
//Function to remove details of user using the username.
void HashTable::RemoveUser(string username)
{
    int ind = HashFunction(username);
    bool deletion=false;
    Node *temp = table[ind].head;
    table[ind].DeleteNode(username);    
    if(!deletion)
    {
        cout<<"Username not found\n";
    }
}
//Function which returns the password of the user if user exits or else returns -1.
string HashTable::SearchUser(string username)
{
    int ind = HashFunction(username);
    Node *temp = table[ind].head;
    while(temp!=NULL)
    {
        pair<string,string> i = temp->User;
        if(i.first==username)
        {
            
            return(i.second);
        }
        temp = temp->next;
    }
    return "-1";
}
//Function to print the hash table.
void HashTable::print_table()
{
    for(int i=0;i<m;i++)
    {
        cout<<i<<"\n";
        table[i].print_list();
    }
}