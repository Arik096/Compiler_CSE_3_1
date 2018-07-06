#include<bits/stdc++.h>
using namespace std;

struct token
{
    string tokenName;
    string lexeme;
} info;

struct node
{
    token data;
    node* next;
};

class LinkedList
{
public:
    node* head;
    node* first;

    LinkedList()
    {
        head=NULL;
        first=NULL;
    }

    node* Insert(token temp)
    {
        node* t=new node;
        t->data=temp;
        t->next=NULL;

        if(Search(temp)==false)
        {
            if(head==NULL)
            {
                head=t;
                first=head;
            }
            else
            {
                head->next=t;
                head=t;
            }
        }
        return head;
    }

    node* Delete(token temp)
    {
        node* t=new node;
        t=first;

        while(t!=NULL)
        {
            if(t->data.tokenName==temp.tokenName&&t->data.lexeme==temp.lexeme)
            {
                free(t);
            }
            t=t->next;
        }
        return head;
    }

    bool Search(token temp)
    {
        node* t=new node;
        t=first;

        while(t!=NULL)
        {
            if(t->data.tokenName==temp.tokenName&&t->data.lexeme==temp.lexeme)
                return true;
            t=t->next;
        }
        return false;
    }
};
int main()
{
    LinkedList l;

    while(1)
    {
        cout<<"Options"<<endl;
        cout<<"1. Insert"<<endl;
        cout<<"2. Search"<<endl;
        cout<<"3. Delete"<<endl;
        cout<<"4. Exit"<<endl;

        cout<<"Enter your choice: ";

        int n;
        cin>>n;

        if(n==1)
        {
            cout<<"Enter toke name: ";
            cin>>info.tokenName;

            cout<<"Enter Lexeme: ";
            cin>>info.lexeme;

            l.head=l.Insert(info);
        }
        else if(n==2)
        {
            cout<<"Enter toke name: ";
            cin>>info.tokenName;

            cout<<"Enter Lexeme: ";
            cin>>info.lexeme;

            bool i=l.Search(info);

            if(i==true)

            {
                cout<<endl<<"Found"<<endl<<endl;
            }
            else
            {
                cout<<endl<<"Not Found"<<endl<<endl;
            }
        }
        else if(n==3)
        {
            cout<<"Enter toke name: ";
            cin>>info.tokenName;

            cout<<"Enter Lexeme: ";
            cin>>info.lexeme;

            l.head=l.Delete(info);
        }
        else if(n==4)
        {
            break;
        }
        else
        {
            cout<<"Wrong input"<<endl<<endl;
        }

    }
    return 0;
}
