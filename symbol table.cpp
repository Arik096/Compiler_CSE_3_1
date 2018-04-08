///      بسم الله الرحمن الرحيم الذي خلقني     By The Name of Allah, Who Created Me.
///      بسميلة الرحمن الرحمن الرحيم        BISMILLAH AR-RAHMAN AR-RAHEEM.

/**
    * Arik Md. Isthiaque
    * 1103096
    * Symbol Table
    * 7-4-2018
**/
#include<bits/stdc++.h>
using namespace std;
struct symbol_table{
public:
    string variable;
    string value;
    struct symbol_table *next;
}*table[11];
long Hash_function(string variable)
{
    long length=0;
    for(long i=0;variable[i];i++)
    {
        length=length+variable[i];
    }
    return (length%11);
}
void insaert(string variable,string value)
{
    long position=Hash_function(variable);
    if(table[position]==NULL)
    {
        table[position]=new symbol_table();
        table[position]->variable=variable;
        table[position]->value=value;
        table[position]->next=NULL;
    }
    else
    {
        symbol_table* newNode=new symbol_table();
        newNode->variable=variable;
        newNode->value=value;
        symbol_table* nextNode=table[position];
        table[position]=newNode;
        newNode->next=nextNode;
    }
}
long Search(string variable,string value)
{
    long position=Hash_function(variable);
    symbol_table* temp_var=table[position];
    while(temp_var!=NULL)
    {
        if( temp_var->variable.compare(variable)==0&&temp_var->value.compare(value)==0)
        {
            return 1;
        }
        temp_var=temp_var->next;
    }
    return 0;
}
void show()
{
    long ID=0;
    for(long i=0;i<11;i++)
    {
        symbol_table* temp_var=table[i];
        cout<<i<<" -> ";
        while(temp_var!=NULL)
        {
            ID++;
            cout<<"{ "<<temp_var->variable<<"="<<temp_var->value<<" , ID-"<<ID<<" }  ";
            temp_var=temp_var->next;
        }
        cout<<endl;
    }
}
int main()
{
    ///freopen("input.txt","r",stdin);
    long option;
    while(1)
    {
    cout<<"Options:"<<endl<<endl;
    cout<<"1 -> Insert new"<<endl;
    cout<<"2 -> Search for a existing"<<endl;
    cout<<"3 -> Show all"<<endl;
    cout<<"4 -> Exit"<<endl<<endl;
    cout<<"Enter your option: ";
    cin>>option;

    if(option==1)
    {
        long entry;
        cout<<"Enter your number of entries: ";
        cin>>entry;
        string variable,value;
        for(long i=0;i<entry;i++)
        {
            cin>>variable;
            cin>>value;
            long temp_var=Search(variable,value);
            if(temp_var==1)
                {
                    continue;
                }
            else
                {
                insaert(variable,value);
                }
        }
    }
    else if(option==2)
    {
        string variable,value;
        cin>>variable>>value;
        long temp_var=Search(variable,value);
        if(temp_var==1)
            cout<<"Found"<<endl<<endl;
        else
            cout<<"Not found"<<endl<<endl;
    }
    else if(option==3)
    {
        show();
    }
    else if(option==4)
    {
        break;
    }
    else
    {
        cout<<"Try again"<<endl;
    }
    }
    return NULL;
}