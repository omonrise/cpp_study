// https://www.learn-cpp.org/en/Linked_lists - using classes.
// https://www.softwaretestinghelp.com/linked-list/ -- using struct nodes.
#include <iostream>
using namespace std;

// data structure for a node in the list.
struct Node
{
    int data;
    struct Node *next; // this is a pointer to the next node's location.
};

// our "list" is really the first Node.
// We access items in the list through walking from head node.

/*Add new node in front of list.*/
void add_node(struct Node **head, int node_data)
{
    /*
        Create a pointer newNode of type Node.
        Allocate memory to it using keyword new.
    */
    struct Node *newNode = new Node;

    /*
        Assign data to the node.
        The data is easy - just int.
        The next is a pointer itself.
        Deallocate head - i.e. save the address of head in next.
    */
   
    // a -> b means structure dereference ("member b of object pointed to by a")
    newNode->data = node_data;
    newNode->next = (*head);

    /*
        Now move the head pointer to look at new node.
        For this, we deallocate head and then assign NewNode as value.
    */

    (*head) = newNode;
}


/*  Display list items. */

void displayList(struct Node *node) // takes a pointer to a node
{
    // display nodes until it reaches the end
    while (node != nullptr)
    {
        cout << node->data << "-->";
        node = node->next;
    }
    if (node == nullptr)
    {
        cout << "Reached end of list."<< endl;
    }
}

/* User can add or delete nodes.*/

/* Main program */
int main()
{
    // make empty list
    struct Node *mylist = nullptr;
    // variable for new data.
    int newItem;
    // user input command
    char command;
    bool continue_flag {true};

    do
    {
        cout << "Commands: n - add node, d - display list, q - exit." << endl;
        cin >> command;

        switch (command)
        {
        case 'n':
            cout << "Input new value for node." << endl;
            cin >> newItem;
            // add an item
            cout << "Adding node" << endl;
            add_node(&mylist, newItem);
            break;
        case 'd':
            // Display items
            cout << "Displaying list.." << endl;
            displayList(mylist);
            break;
        case 'q':
            // quit
            cout << "Exiting.." << endl;
            continue_flag = false;
            break;
        default:
            cout << "Unsupported command: " << command << endl;
            cout<< "Please try again." << endl;
            break;
        }


    } while (continue_flag == true);

    return 0;
}
