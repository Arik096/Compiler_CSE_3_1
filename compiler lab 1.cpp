/// compiler lab 1
/// creating simple link list

#include<bits/stdc++.h>
using namespace std;
class node{
public:
int n;
class node *next;
};
node *head=NULL;
void inserT(int x)
{
    node *temp=new node();
    temp->n=x;
    temp->next=head;
    head=temp;
}
void print()
{
    node *temp=head;
    while(temp)
    {
        cout<<temp->n<<endl;
        temp=temp->next;
    }
}
int main()
{
    inserT(5);
    inserT(10);
    print();
    return 0;
}
