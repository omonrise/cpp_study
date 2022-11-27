// https://www.learn-cpp.org/en/Linked_lists - using classes.
// https://www.softwaretestinghelp.com/linked-list/ -- using struct nodes, but shitty explanation.
// https://www.geeksforgeeks.org/data-structures/linked-list/?ref=gcse
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
void add_node(struct Node **head_ref, int node_data)
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
    newNode->next = (*head_ref);

    /*
        Now move the head pointer to look at new node.
        For this, we deallocate head and then assign NewNode as value.
    */

    (*head_ref) = newNode;
}

/* Add a node after a node */
void add_after(struct Node **head_ref, int node_data, int key)
{
    /*
        Does previous node exist?
    */
    if (head_ref == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    /*
        - Allocate new node
        - assign data to it
        - new node gets the next of previous node
        - previous node gets the new node address as next
    */
    struct Node * new_node = new Node;
    new_node -> data = node_data;
    new_node -> next = nullptr;

    /* Find the node with key */
    struct Node * cur_node = *head_ref;
    struct Node * next_node = nullptr;

    /**/
    while (cur_node -> data != key)
    {
        // if not found
        if (cur_node -> next == nullptr)
        {
            cout<< "Node with " << key << " not found" << endl;
            return;
        }
        
        // otherwise, continue looking 
        else 
        {
            cur_node = cur_node -> next;
        }

    }
    // if found 
    // if there's a next node, new_node will point to it.
    if (cur_node -> next != nullptr)
    {
        new_node -> next = cur_node -> next;
    }
    // and the current node will point to new node
    cur_node -> next = new_node;
    return;

}

/* Add a node at end of list */
void add_to_end(struct Node **head_ref, int node_data)
{
    /* Allocate new node */
    Node * new_node = new Node;
    new_node -> data = node_data;
    new_node -> next = nullptr; // new node is the new last node.

    /* Make a pointer that saves last node. */
    Node * last_node = *head_ref;

    /* If passed list is empty, just attach new_node. */
    if (*head_ref == nullptr)
    {
        *head_ref = new_node ;
        return;
    }

    /* Look for last node, traversing list. */
    while (last_node->next != nullptr)
    {
        last_node = last_node -> next;
    }

    /* change the next of the last node thus found*/
    last_node -> next = new_node;
    return;

}

void remove_node (struct Node ** head_ref, int key)
{
    if (head_ref == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    /* Find the node with key */
    struct Node * cur_node = *head_ref;
    struct Node * prev_node = nullptr;  // We'll need previous node to repair the list.

    /* If the head itself needs to be replaced */
    if (cur_node -> data == key)
    {
        *head_ref = cur_node -> next;
        delete cur_node;
        return;
    }

    while (cur_node -> data != key)
    {
        // if not found
        if (cur_node -> next == nullptr)
        {
            cout<< "Node with " << key << " not found" << endl;
            return;
        }

        // otherwise, continue looking 
        else 
        {
            prev_node = cur_node; // save previous node
            cur_node = cur_node -> next;
        }

    }
    // if found , delete cur_node.
    prev_node -> next = cur_node -> next; // rebuild linkage
    delete cur_node;

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
        cout << "Reached end of list." << endl;
    }
}

/* User can add or delete nodes.*/

/* Main program */
int main()
{
    // make empty list
    struct Node *mylist = nullptr;
    // variable for new data.
    int newItem, key;
    // user input command
    char command;
    bool continue_flag{true};

    do
    {
        cout << "Commands:" << endl 
        << "f - add node in the beginning" << endl 
        << "e - add node at the end" << endl 
        << "a - add node after key" << endl
        << "d - display list"<< endl 
        << "r - remove node" << endl
        << "q - exit." << endl;
        cin >> command;

        switch (command)
        {
        case 'f':
            cout << "Input new value for node." << endl;
            cin >> newItem;
            // add an item
            cout << "Adding node" << endl;
            add_node(&mylist, newItem);
            break;
        case 'e':
            cout << "Input new value for node" << endl;
            cin >> newItem;
            cout << "Appending node at the end" <<endl;
            add_to_end(&mylist, newItem);
            break; 
        case 'a':
            cout << "Input new value for node" << endl;
            cin >> newItem;
            cout << "Input key to look for" << endl;
            cin >> key;
            add_after(&mylist, newItem, key);
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
        case 'r':
            // remove node 
            cout << "Input key to look for" << endl;
            cin >> key;
            remove_node(&mylist, key);
            break;
        default:
            cout << "Unsupported command: " << command << endl;
            cout << "Please try again." << endl;
            break;
        }

    } while (continue_flag == true);

    return 0;
}
