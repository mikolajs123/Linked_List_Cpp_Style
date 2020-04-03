//
//  main.cpp
//  brand_new
//
//  Created by Mikołaj Semeniuk on 03/04/2020.
//  Copyright © 2020 Mikołaj Semeniuk. All rights reserved.
//

#include <iostream>

class Linked_List
{
    private:
        struct Node
        {
            int data;
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
        void create (int A[], int n)
        {
            head = new struct Node;
            head->data = A[0];
            head->next = NULL;
            tail = head;
            length++;
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
        void push (int n) // add element at the end of linked list
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
        void unshift (int n) // add element at the beginning of linked list
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
        void insert (int i, int n) // add element at certain index
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
        void edit (int i, int n) // edit element at certain index
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
        void pop () /// remove element at the end of linked list
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
        void shift () // remove element at the beginning of linked list
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
        void remove (int i) // remove element at certain index
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
        void deleteList() // delete whole linked list
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
        void display ()
        {
            if (head != NULL)
            {
                tail = head;
                while (tail != NULL) {
                    printf("%d\n", tail->data);
                    tail = tail->next;
                }
            }
            else
            {
                printf("the linked list is empty\n");
            }
            return;
        }
        int len ()
        {
            return length;
        }
        ~Linked_List()
        {
            deleteList();
            length = NULL;
        }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Linked_List a;
    a.push(10);
    a.push(20);
    a.push(30);
    a.unshift(11);
    a.insert(3, 15);
    a.edit(1, 99);
    a.remove(2);
    a.shift();
    a.display();
    printf("len: %d\n", a.len());
    a.deleteList();
    a.display();
    printf("len: %d\n\n", a.len());
    Linked_List b;
    int C[] = { 3, 5, 7, 10, 15, 12 };
    b.create(C, 6);
    b.push(14);
    b.push(18);
    b.display();
    printf("\n");
    printf("len: %d\n\n", b.len());
    return 0;
}
