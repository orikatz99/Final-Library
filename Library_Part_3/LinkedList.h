#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template <typename T>

class LinkedList 
{
private:
    struct Node 
    {
        T data;
        Node* next;

        Node(const T& data, Node* next = nullptr): data(data), next(next) {}
    };
    Node* head;
    Node* tail;
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}
    ~LinkedList() {clear();}

    void addToEnd(const T& data) 
    {
        Node* newNode = new Node(data);
        if (tail) 
        {
            tail->next = newNode;
            tail = newNode;
        }
        else 
            head = tail = newNode;
        size++;
    }

    void deleteMember(const T& data) 
    {
        Node* current = head;
        Node* previous = nullptr;
        while (current) 
        {
            if (current->data == data) 
            {
                if (previous) 
                    previous->next = current->next;
                
                else 
                    head = current->next;
                
                if (current == tail) 
                    tail = previous;
                
                delete current;
                size--;
                return;
            }
            previous = current;
            current = current->next;
        }
    }

    void printList() const
    {
        Node* current = head;
        while (current) 
        {
            std::cout << current->data << std::endl;
            current = current->next;
        }
    }

    int getSize() const 
    {
        return size;
    }

    void clear() 
    {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        head = tail = nullptr;
        size = 0;
    }
};

#endif // LINKEDLIST_H

