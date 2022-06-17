#include <bits/stdc++.h>            
//header file that includes every standard library, so dont need to include the libaries separately 
using namespace std;               
// standard namespace, the C++ input output library 

struct Data   
{
    string symbol;
    string symbol_type;
};
// it is the structure of the symbol table data item, the structure name is "Data". it holds the representation of the symbol table data, as we need only two data so take symbol and symbol_type. We can add more if we need.

struct node
{
    Data data;
    node *next;
};
// as we are working with linkedlist we need a node structure, to hold node information, in the linkedlist each node consists of a data item(here we save the symbol table data) and a  address of next noded


class LinkedList // creating a linklist class
{
public:
    node *head;
    node *first;  
    // every linklist have two address, frist holds the address of the starting of the linklist, head holds the address of where we can inseat new value, if head=first that means the linklist is empty,and if head!=first the linklist is not empty 

    LinkedList()
    {
        head = NULL;
        first = NULL;
    }
    // so we called a consturctor, to initialize the linkedlist and making both head and first is null, that means the linklist is empty

    bool Insert(Data temp) // it is receiving the new value that will be inserted into the linkedlist as temp variable
    {
        node *t = new node;  
        t->data = temp;
        t->next = NULL;
        // we need to create a new node to inseart data, so we create a temp node variable t in 1st line, then inseart the value of the new data into the t node in 2nd line, in 3rd line we make the next node address is null as t is the temp variable

        if (Search(temp) == false) // we are searching if the data is already in the linkedlist
        {
            if (head == NULL)
            {
                head = t;
                first = head;
            }// checking if head is null , if null that means the linklist is empty so save the value in both head and first
            else
            {
                head->next = t;
                head = t;
            }// else the creating a new next head in the address of t and inseart the t in the new head
            cout << "Data Insearted" << endl;
        }
        else
        {
            cout<<"Duplicate Value"<<endl; 
            // if search value is true that means the data is already in the linkedlist, so no need to inseart the data
        }
    }

    bool Search(Data temp) // it is receiving the new value that will be inserted into the linkedlist as temp variable and search if it is already in the linkedlist
    {
        node *t = new node; //making a new temp node variable for searching
        t = first; // geting the exsiting linklist 1st value into the temp node so that we can make a search
        while (t != NULL) // run the loop untill the t is empty
        {
            if (t->data.symbol == temp.symbol){ 
                return true;
            } // checking if the new value is already in the linkedlist, is exists return true
            t = t->next;
            // saving the next node into t, for checking in the next step of loop
        }
        return false;
        // return false if no data found
    }

    void show(){
        node *t = new node; // making a new temp node variable for display
        t = first;          // geting the exsiting linklist 1st value into the temp node so that we can display 

        while (t != NULL)
        {
            cout <<t<<"->"<< t->data.symbol << " " << t->data.symbol_type << endl;
            //t shows the actual address where the is saved, t->data.symbol shows the symbol, t->data.symbol_type shows the symbol type
            t = t->next;
            // saving the next node into t, for checking in the next step of loop
        }
        }
};


int main()
{
    LinkedList linklist;
    // this will initialize the LinkedList class variable

    while (1) // this will run the loop infinitely until we choose the exit
    {
        cout << "Options-> 1.Insert 2.Display 3.Exit" << endl;
        cout << "Enter your choice: ";
        int n;
        cin >> n; // taking option input

        if (n == 1) // if n is 1 we are insearting new data into the LinkedList
        {
            Data data1; //// this will initialize a symbol table structure variable to take symbol table data input
            cout << "Enter symbol name: ";
            cin >> data1.symbol;

            cout << "Enter symbol_type: ";
            cin >> data1.symbol_type;

            linklist.Insert(data1); // insearting the symbol table value in the head of the LinkedList by using the LinkedList variable we declared before
        }
        else if (n == 2) // if n is 2, it will display all the linklist data
        {
            linklist.show();
        }
        else if (n == 3) // if n is 3, it will exit the program
        {
            break;
        }
        else
        {
            cout << "Wrong input" << endl; // if you choose the value of n worng it will show
        }
    }
    return 0;
}
