#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;
#ifndef HASH_H
#define HASH_H

class symbol_table{
private:
    static const int tablesize=5;
public:
    struct symbol_info{
    string key;
    symbol_info* next;

    };
    symbol_info* HashTable[tablesize];
public:
    symbol_table();
    int Hash(string key);
    void Insert(string key);
    void Lookup(string key);
    void dump();
};
 symbol_table::symbol_table()
{
    for(int i=0;i<tablesize;i++)
    {
        HashTable[i]=new symbol_info;
        HashTable[i]->key="empty";
        HashTable[i]->next=NULL;
    }
}
int symbol_table::Hash(string key){
    int hash=0;
    int index;
    for(int i=0;i<key.length();i++)
    {
        hash=hash+(int)key[i];
    }
    index=hash%tablesize;
    return index;

}
void symbol_table::Insert(string key)
{
    int index=Hash(key);
    if(HashTable[index]->key=="empty")
    {
        HashTable[index]->key=key;
    }
    else{
       symbol_info *ptr=HashTable[index];
        symbol_info *n=new symbol_info;
        n->key=key;
        n->next=NULL;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;

        }
        ptr->next=n;
    }
}
void symbol_table::dump()
{
    for(int i=0;i<tablesize;i++)
    {
        cout<<"---------------------------"<<endl;
        cout<<"[index]:"<<i<<" || ";

        symbol_info* temp=HashTable[i];
        while(temp!=NULL){

            cout<<temp->key;

            cout<<"->";
            temp=temp->next;
        }

        cout<<"\n"<<endl;
    }
}
void symbol_table::Lookup(string key)
{
    int index=Hash(key);
    bool foundName=false;
    string type;
    symbol_info *ptr=HashTable[index];
    while(ptr!=NULL)
    {
        if(ptr->key==key)
        {
            foundName=true;
        }
        ptr=ptr->next;
    }
    if(foundName==true)
    {
        cout<<endl;
        cout<<"Your desired Key  Type "<<key<<" :=  is Found!!"<<endl;
        cout<<endl;
    }
    else{
        cout<<" Not Found on Your desired KEY  List!!!"<<endl;
    }
}

int main()
{
    symbol_table st;

    string key,type;
    int choice;
     while (1)
    {
        cout<<"\n\t\t\t\t------------------------------------------------------"<<endl;
        cout<<"\t\t\t\t\tAssignment on Hash Table With Linked List"<<endl;
        cout<<"\t\t\t\t------------------------------------------------------"<<endl;
        cout<<"\n"<<endl;
        cout<<"\t\t\t\t\t1.Insert element into the table"<<endl;
        cout<<"\t\t\t\t\t2.Lookup element from the key"<<endl;
        cout<<"\t\t\t\t\t3.Dump element"<<endl;
        cout<<"\t\t\t\t\t4.Exit"<<endl;
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter The KEY: ";
            cin>>key;
            st.Insert(key);
            break;

        case 2:

                cout<<"Search your Favorite key:";
                cin>>key;
                if(key!="exit")
                {
                    st.Lookup(key);
                }


            break;
        case 3:
            st.dump();
            break;
        case 4:
            exit(1);
        default:
           cout<<"\nEnter correct option\n";
        }
    }
}


#endif // HASH_H

