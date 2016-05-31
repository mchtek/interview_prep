#include "util.h"

using namespace std;

struct Node {
    Node *next;
    int data;
};

class List {
public:
    List () {
        head = NULL;
        tail = NULL;
    }
    void insert (int ele) {
        Node *node = new Node;
        if (head == NULL) {
            head = tail = node;
        }
        tail->next = node;
        node->data = ele;
        node->next = NULL;
        tail = node;
    }
    void print () {
        Node *n_ptr = head;
        while (n_ptr) {
            cout << n_ptr->data << " ";
            n_ptr = n_ptr->next;
        }
    }

    void partition(int val) {
        Node *partition = head;
        Node *tmp = head;
        int swap_tmp;
        // Find an element greater than val
        while (tmp) {
            if (tmp->data > val) {
                break;
            }
            tmp = tmp->next;
        }

        // Found an element that is greater than val 
        // tmp is now pointing to this element.
        partition = tmp;
        while (tmp) {
            if (tmp->data < val) {
                // swap with partition
                swap_tmp = partition->data;
                partition->data = tmp->data;
                tmp->data = swap_tmp; 
                partition = partition->next;
            }
            tmp = tmp->next;
        }
    }

private:
    Node *head;
    Node *tail;
};

int main() 
{
    // Implement Linked List
    List list;
    list.insert(4);
    list.insert(7);
    list.insert(1);
    list.insert(9);
    list.print();

    // 2.1 Remove duplicates from unsorted linked list
    // Isn't merge sort enough to solve this problem in nlogn ?
    
    // 2.4 Partition linked list around a value x
    cout << "\nPartitioning around 2\n";
    list.partition(2);
    list.print();
}
