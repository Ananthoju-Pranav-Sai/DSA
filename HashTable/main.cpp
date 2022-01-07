#include "HashTable.h"
#include <fstream>
#include <sstream>

// Function which returns Hashtable for usernames and passwords.
HashTable read_userinfo(string filename)
{
    HashTable user_details;
    ifstream fin;
    fin.open(filename);
    string line;
    while(!fin.eof())
    {
        fin>>line;
        stringstream ss(line);
        string username,password;
        getline(ss,username,',');
        getline(ss,password,'\n');
        user_details.InsertUser(username,password);
    }
    return user_details;
}
int main()
{
    HashTable user_details = read_userinfo("userInfo.csv");
    string user,pass,original_pw;       //user stores the entered username, pass stores entered password original_pw stores the actual password of the user.
    cout<<"Enter Username : ";
    cin>>user;
    original_pw = user_details.SearchUser(user);
    if(original_pw=="-1")               //If the original password is not found in hash table then the user doesnot exist in our table.
    {
        cout<<"Login Failed : User not found\n";
    }
    else
    {
        cout<<"Enter Password : ";
        cin>>pass;
        if(pass!=original_pw)
            cout<<"Login Failed : Incorrect Password\n";
        else
            cout<<"Login Succesful!\n";
    }
    
}