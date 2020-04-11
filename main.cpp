//
//  main.cpp
//  Temp_C++
//
//  Created by Mikołaj Semeniuk on 04/04/2020.
//  Copyright © 2020 Mikołaj Semeniuk. All rights reserved.
//

#include <iostream>

template <class T>
class Linked_List
{
    private:
        struct Node
        {
            T data;
            struct Node *next;
        } *head, *tail, *temp;
        int length;
    public:
        Linked_List()
        {
            length = 0;
            head = NULL;
            tail = NULL;
            temp = NULL;
        }
        Linked_List(T A[], int n)
        {
            head = new struct Node;
            head->data = A[0];
            head->next = NULL;
            tail = head;
            length = 1;
            for (int i = 1; i < n; i++)
            {
                temp = new struct Node;
                temp->data = A[i];
                temp->next = NULL;
                tail->next = temp;
                tail = temp;
                length++;
            }
            return;
        }
        ~Linked_List()
        {
            deleteList();
            length = NULL;
        }
        
        void push (T n); // add element at the end of linked list
        void unshift (T n); // add element at the beginning of linked list
        void insert (int i, T n); // add element at certain index
        
        void edit (int i, T n); // edit element at certain index
        
        void pop (); // remove element at the end of linked list
        void shift (); // remove element at the beginning of linked list
        void remove (int i); // remove element at certain index
        
        void deleteList(); // delete whole linked list
        
        void swap(struct Node *p, struct Node *q); // swap elements of linked list
        void sortB(); // bubble sort
        
        void sort(); // the main wrapper for merge sort
        void MergeSort(Node** headRef);
        void FrontBackSplit(Node* source, Node** frontRef, Node** backRef);
        struct Node* SortedMerge(Node* a, Node* b);
        
        void reverse (); // reverse a linked list
        void display (); // show all elements of list
        int len (); // return length of list
        
};

template <class T>
void Linked_List<T>::push (T n)
{
    temp = new struct Node;
    temp->data = n;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        tail = new struct Node;
        tail = head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = temp;
    }
    length++;
    return;
}
template <class T>
void Linked_List<T>::unshift (T n)
{
    temp = new struct Node;
    temp->data = n;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
    length++;
    return;
}
template <class T>
void Linked_List<T>::insert (int i, T n)
{
    if (i < 0 && i > length)
        return;
    temp = new struct Node;
    temp->data = n;
    temp->next = NULL;
    if (i == 0)
    {
        tail = head;
        head = temp;
        head->next = tail;
    }
    else
    {
        tail = head;
        for (int j = 0; j < i - 1; j++)
        {
            tail = tail->next;
        }
        temp->next = tail->next;
        tail->next = temp;
    }
    length++;
    return;
}
template <class T>
void Linked_List<T>::edit (int i, T n)
{
    if (head == NULL || (i < 0 && i > length))
        return;
    tail = head;
    for (int j = 0; j < i; j++) {
        tail = tail->next;
    }
    tail->data = n;
    return;
}
template <class T>
void Linked_List<T>::pop ()
{
    if (head == NULL)
        return;
    else if (head->next == NULL )
    {
        delete head;
        head = NULL;
    }
    else
    {
        tail = head;
        while (tail->next && tail->next->next != NULL) {
            tail = tail->next;
        }
        delete tail->next;
        tail->next = NULL;
    }
    length--;
    return;
    
}
template <class T>
void Linked_List<T>::shift ()
{
    if (head == NULL)
        return;
    else
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    length--;
    return;
}
template <class T>
void Linked_List<T>::remove (int i)
{
    if (head == NULL || (i < 0 && i > length))
        return;
    if (i == 0)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        tail = head;
        for (int j = 0; j < i - 1; j++) {
            tail = tail->next;
        }
        temp = tail->next;
        tail->next = temp->next;
        delete temp;
        temp = NULL;
    }
    length--;
    return;
}
template <class T>
void Linked_List<T>::deleteList()
{
    tail = head;
    while (tail != NULL)
    {
        temp = tail->next;
        delete tail;
        tail = temp;
        length--;
    }
    head = NULL;
    tail = NULL;
    temp = NULL;
}
template <class T>
void Linked_List<T>::swap (struct Node *p, struct Node *q)
{
    T temp = p->data;
    p->data = q -> data;
    q -> data = temp;
}
template <class T>
void Linked_List<T>::sortB ()
{
    bool swapped;
    tail = NULL;
    
    do {
        swapped = false;
        tail = head;
        while(tail->next != NULL)
        {
            if (tail->data > tail->next->data)
            {
                swap(tail, tail->next);
                swapped = true;
            }
            tail = tail->next;
        }
    } while(swapped);
}
template <class T>
void Linked_List<T>::sort ()
{
    MergeSort(&head);
}
template <class T>
void Linked_List<T>::MergeSort (Node** headRef)
{
    Node* head = *headRef;
    Node* a;
    Node* b;

    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    FrontBackSplit(head, &a, &b);

    MergeSort(&a);
    MergeSort(&b);

    *headRef = SortedMerge(a, b);
}
template <class T>
void Linked_List<T>::FrontBackSplit (Node* source, Node** frontRef, Node** backRef)
{
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;
  
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
  
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}
template <class T>
typename Linked_List<T>::Node* Linked_List<T>::SortedMerge (Node* a, Node* b)
{
    Node* result = NULL;
    
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    if (a->data <= b->data) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}
template <class T>
void Linked_List<T>::reverse ()
{
    T *A,i=0;
    tail = head;
    
    A = (T *)malloc(sizeof(T)* len());
    while(tail != NULL)
    {
        A[i] = tail->data;
        tail = tail->next;
        i++;
    }
    tail = head;
    i--;
    
    while(tail != NULL)
    {
        tail->data = A[i];
        tail = tail->next;
        i--;
    }
    return;
}
template <class T>
void Linked_List<T>::display ()
{
    if (head != NULL)
    {
        tail = head;
        while (tail != NULL) {
            std::cout << tail->data << std::endl;
            tail = tail->next;
        }
    }
    else
    {
        printf("the linked list is empty\n");
    }
    return;
}
template <class T>
int Linked_List<T>::len ()
{
    return length;
}

/*
    Example of using our object in function
*/

template <class T>
void next (Linked_List<T> &object) {
    object.push("string from next");
}
template <class T>
void init (Linked_List<T> &object) {
    object.push("string from init");
    next(object);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Linked_List<int> a; // Integers
    a.push(10);
    a.push(40);
    a.push(30);
    a.unshift(11);
    a.insert(3, 15);
    a.edit(1, 99);
    a.remove(2);
    a.push(47);
    a.shift();
    a.sort();
    a.display();
    printf("len: %d\n", a.len());
    a.deleteList();
    a.display();
    printf("len: %d\n\n", a.len());
    
    double E[] = { 3.6, 5.4, 7.2, 10.10, 15.2, 12.19 };
    Linked_List<double> b(E, 6); // Doubles
    b.push(14);
    b.push(18);
    b.sortB();
    b.display();
    printf("\n");
    printf("len: %d\n\n", b.len());
    
    char F[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    Linked_List<char> c(F, 6); // Chars
    c.pop();
    c.reverse();
    c.display();
    printf("len: %d\n\n", c.len());
    std::string G[] = { "hello", "there", "from", "linked", "list", "of", "strings" };
    
    Linked_List<std::string> d(G, 7); // Strings
    d.push("new string");
    init(d);
    d.display();
    return 0;
}
