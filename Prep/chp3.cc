#include "util.h"

using namespace std;

struct Node {
    Node *next;
    int data;
};

class Queue {
public:
    Queue() : front(NULL), end(NULL), size(0) {
    }
    void enqueue (int ele) {
        // Insert elements at the end
        Node *node = new Node;
        if (end == NULL) {
            node->data = ele;
            node->next = NULL;
            front = end = node;
            return;
        }
        node->data = ele;
        end->next = node;
        end = node;
    }
    void dequeue () {
        if (front == NULL) {
            return;
        }
        Node *node = front;
        front = node->next;
        // If last element reset end
        if (front == NULL) {
            end = NULL;
        }
        delete node;
    }
    void print () {
        Node *n_ptr = front;
        while (n_ptr) {
            cout << n_ptr->data << " ";
            n_ptr = n_ptr->next;
        }
    }

private:
    Node *front;
    Node *end;
    int size;
};
class Stack {
public:
    Stack() : top(NULL), size(0) {
    }
    // Insert at front
    void push (int ele) {
        Node *node = new Node;
        node->data = ele;
        node->next = top;
        top = node;
    }
    //Delete front element
    void pop () {
        if (top == NULL) {
            return;
        }
        Node *node = top;
        if (node->next) {
            top = node->next;
        } else {
            // last element
            top = NULL;
        }
        delete node;
    }
    void print () {
        Node *n_ptr = top;
        while (n_ptr) {
            cout << n_ptr->data << " ";
            n_ptr = n_ptr->next;
        }
    }

private:
    Node *top;
    int size;
};

int main() 
{
    // Implement Linked Stack
    Stack mystack;
    mystack.push(4);
    mystack.push(7);
    mystack.push(1);
    mystack.push(9);
    mystack.print();
    Queue myqueue;
    myqueue.enqueue(4);
    myqueue.enqueue(7);
    myqueue.enqueue(1);
    myqueue.enqueue(9);
    myqueue.print();
}
