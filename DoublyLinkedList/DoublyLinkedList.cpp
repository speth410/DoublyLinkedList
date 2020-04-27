#include <stddef.h>
#include <iostream>

struct node {
    void* putData;
    int data;
    node* next;
    node* prev;
};

class List {
private:
    node* front;
    node* rear;

public:
    List();
    void insertfront(int d);
    void insertfront(void* d);
    void insertrear(int d);
    void insertrear(void* d);
    int removefront();
    void* removefront_p();
    int removerear();
    void* removerear_p();
    void print();
};

// Remove node from the rear of the linked list and return the data that was stored. 
int List::removerear() {
    int hold;

    // The list is empty
    if (front == NULL) {

    }

    // The list contains 1 item
    else if (front = rear) {
        hold = rear->data;
        delete rear;
        rear = front = NULL;
    }

    // The list contains more than 1 item
    else {
        hold = rear->data;

        rear = rear->prev;

        delete rear->next;
        rear->next = NULL;
    }
    return hold;
}

// Remove node from the rear of the linked list and return a pointer to the data that was stored.
void* List::removerear_p() {
    void* hold = NULL;


    // The list is empty
    if (front == NULL) {

    }

    // the list contains 1 item
    else if (front == rear) {
        hold = &(rear->data);
        delete rear;
        rear = front = NULL;
    }

    // The list contains more than 1 item
    else {
        hold = ((int*)(rear->data));

        rear = rear->prev;
        delete rear->next;
        rear->next = NULL;
    }
    return hold;
}

// Remove node from the front of the list
int List::removefront() {

    node* p;
    int hold;

    // If list it empty
    if (front == NULL) {

    }

    // If the list contains one item
    else if (front == rear) {
        hold = front->data;
        delete front;
        front = rear = NULL;
    }

    // If the list contains more than one item
    else {
        hold = front->data;   // Save the data stored in linked list item

        p = front->next;
        delete front;           // Delete item
        front = p;
        front->prev = NULL;
    }
    return hold;
}

// Remove node from the front of the list and return a pointer to the data held in that node.
void* List::removefront_p() {
    node* p;
    void* hold = NULL;

    // If list it empty
    if (front == NULL) {

    }

    // If the list contains one item
    else if (front == rear) {
        hold = &(front->data);
        delete front;
        front = rear = NULL;
    }

    // If the list contains more than one item
    else {
        hold = (void*)(front->data);

        p = front->next;
        delete front;           // Delete item
        front = p;
        front->prev = NULL;
    }
    return hold;
}

// Insert a new node to the front of the list and store the integer passed.
void List::insertfront(int data) {
    node* p;
    p = new node;

    p->data = data;

    // If the list is empty
    if (front == NULL) {
        p->next = NULL;
        front = rear = p;
    }

    // If the list contains one or more items
    else {
        p->next = front;  // Link new node to front
        front->prev = p;  // Link front to new node
        front = p;          // Assign new node as front
    }
}

// Insert a node to the front of the list and store the value of the pointer passed in.
void List::insertfront(void* data) {
    node* p;
    p = new node;

    p->data = (intptr_t)data;

    // If the list is empty
    if (front == NULL) {
        p->next = NULL;
        front = rear = p;
    }

    // If the list contains one or more items
    else {
        p->next = front;
        front->prev = p;
        front = p;
    }

}

// Insert a node to the rear of the list and store the integer passed.
void List::insertrear(int data) {
    node* p;
    p = new node;
    p->data = data;
    p->next = NULL;

    if (rear == NULL) {     // If the list is empty
        front = rear = p;
    }
    else {
        rear->next = p;
        p->prev = rear;
        rear = p;
    }
}

// Insert a node to the rear of the list and store the value of the pointer passed in.
void List::insertrear(void* data) {
    node* p;
    p = new node;

    p->data = (intptr_t)data;

    p->next = NULL;

    if (rear == NULL) {     // If the list is empty
        front = rear = p;
    }
    else {
        rear->next = p;
        p->prev = rear;
        rear = p;
    }
}

// Print the contents of the linked list
void List::print() {
    int i = 0;
    node* current;
    current = front;

    while (current != NULL) {
        std::cout << "Item " << i << ": " << current->data << std::endl;
        if (current->next != NULL)
            current = current->next;
        else
            break;
        i++;
    }
}

// Contructor for a new list
List::List() {

    front = NULL;
    rear = NULL;
}

int main() {
    List myList;
    void* data;

    myList.insertfront(5);
    myList.insertfront(1);
    myList.insertrear(10);

    myList.print();

    std::cout << "_______________________" << std::endl;

    data = myList.removefront_p();

    myList.insertrear(data);

    myList.print();

    std::cout << "________________________" << std::endl;

    data = myList.removerear_p();

    myList.insertfront(data);

    myList.print();

}


