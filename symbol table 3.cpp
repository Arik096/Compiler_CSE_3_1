#include<bits/stdc++.h>
using namespace std;

struct symbol_table{
public:
    string variable;
    struct symbol_table *next;
};

int Hash_function(string variable)
{
    int length=0;
    for(int i=0;variable[i];i++)
    {
        length=(length*(i+1))+variable[i];
    }
    return (length%13);
}

symbol_table *table[13];

void insaert(string variable)
{
    int position=Hash_function(variable);
    if(table[position]==NULL)
    {
        table[position]=new symbol_table();

        table[position]->variable=variable;

        table[position]->next=NULL;
    }
    else
    {
        symbol_table* newNode=new symbol_table();

        newNode->variable=variable;

        symbol_table* nextNode=table[position];
        table[position]=newNode;
        newNode->next=nextNode;
    }
}
int Search(string variable)
{
    int position=Hash_function(variable);

    symbol_table* temp_var=table[position];

    while(temp_var!=NULL)
    {
        if(temp_var->variable.compare(variable)==0)
        {
            return 1;
        }
        temp_var=temp_var->next;
    }
    return 0;
}
void show()
{
    for(int i=0;i<13;i++)
    {
        symbol_table* temp_var=table[i];
        cout<<i<<"-";
        while(temp_var!=NULL)
        {
            cout<<" -> "<<temp_var->variable;
            temp_var=temp_var->next;
        }
        cout<<endl;
    }
}
int main()
{
    int option;
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
        string variable;
        cout<<"enter variable : ";
        cin>>variable;
        int temp_var=Search(variable);
        if(temp_var==1)
            {
                continue;
            }
        else
            {
                insaert(variable);
            }
    }
    else if(option==2)
    {
        string variable;
        cout<<"enter variable : ";
        cin>>variable;
        long temp_var=Search(variable);
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

