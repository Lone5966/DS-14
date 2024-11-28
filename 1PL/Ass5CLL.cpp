//Assignment 5: Circular Linked list
//Name:Pranav Walunj  RollNo:02  Batch:A1  PRN:202301040002

#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
};

Node* End_node(Node *head, int datax) {
    Node *temp = new Node;
    Node *a = head;

    temp->data = datax;
    if (head == NULL) {
        temp->next = temp; 
        head = temp;
    } else {
        while (a->next != head) {
            a = a->next;
        }
        temp->next = head;
        a->next = temp;
    }
    return head;
}

Node* First(Node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return NULL;
    }
    if (head->next == head) { 
        delete head;
        return NULL;
    }

    Node *temp = head;
    Node *prev = head;
    while (prev->next != head) {
        prev = prev->next;
    }

    prev->next = head->next;
    head = head->next;
    delete temp;
    
    return head;
}

void Display(Node *head) {
    if (head == NULL) {
        cout << "Linked list is empty" << endl;
        return;
    }

    Node *t = head;
    do {
        cout << t->data << " -> ";
        t = t->next;
    } while (t != head);
    cout << head->data << " " << endl; 
}

int main() {
    Node* head = NULL;
    int n = 0;
    char ch;

    while (true) {
        cout << "1. Add at the end\n2. Display list\n3. Remove from the start\n4. Quit" << endl;
        cin >> ch;
        switch (ch) {
            case '1':
                cout << "Enter data" << endl;
                cin >> n;
                head = End_node(head, n);
                break;
            case '2':
                Display(head);
                break;
            case '3':
                head = First(head);
                break;
            case '4':
                exit(0);
            default:
                cout << "Wrong choice!" << endl;
        }
    }
    return 0;
}
