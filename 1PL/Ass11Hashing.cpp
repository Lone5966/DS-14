/* Name:Pranav Walunj
   PRN: 202301040002
   Roll No: 02
   Batch: A1
   
   Problem: Marks out of 100 of 20 students needs to be stored in a table using hash function 
   hash (key) = key mod 20 where key is the data to be inserted into the Hash table. Write a 
   C++ program to implement hash table for collision handling using separate chaining without
    replacement using linked list
*/

#include <iostream>
using namespace std;

const int TABLE_SIZE = 20;

// Node for linked list used in separate chaining
struct Node {
    int marks;
    Node* next;
    
    Node(int val) {
        marks = val;
        next = nullptr;
    }
};

// Hash table class for student marks
class HashTable {
    Node* table[TABLE_SIZE];

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;  // Initialize the table with null pointers
        }
    }

    // Hash function
    int hash(int key) {
        return key % TABLE_SIZE;
    }

    // Insert marks into the hash table using separate chaining
    void insert(int marks) {
        int index = hash(marks);

        Node* newNode = new Node(marks);

        if (table[index] == nullptr) {
            table[index] = newNode;  // If no collision, directly insert
        } else {
            // Collision occurred, use chaining (linked list)
            Node* temp = table[index];
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;  // Insert at the end of the chain
        }

        cout << "Inserted " << marks << " at index " << index << endl;
    }

    // Display the hash table
    void display() {
        cout << "Hash Table (Student Marks):\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != nullptr) {
                cout << "Index " << i << ": ";
                Node* temp = table[i];
                while (temp != nullptr) {
                    cout << temp->marks << " -> ";
                    temp = temp->next;
                }
                cout << "nullptr\n";
            } else {
                cout << "Index " << i << ": Empty\n";
            }
        }
    }
};

int main() {
    HashTable hashTable;

    // Insert student marks (key represents the marks)
    hashTable.insert(55);  // Student 1
    hashTable.insert(60);  // Student 2
    hashTable.insert(75);  // Student 3
    hashTable.insert(85);  // Student 4
    hashTable.insert(45);  // Student 5
    hashTable.insert(95);  // Student 6
    hashTable.insert(70);  // Student 7
    hashTable.insert(80);  // Student 8
    hashTable.insert(85);  // Student 9
    hashTable.insert(56);  // Student 10
    hashTable.insert(68);  // Student 11
    hashTable.insert(40);  // Student 12
    hashTable.insert(90);  // Student 13
    hashTable.insert(53);  // Student 14
    hashTable.insert(99);  // Student 15
    hashTable.insert(67);  // Student 16
    hashTable.insert(72);  // Student 17
    hashTable.insert(91);  // Student 18
    hashTable.insert(74);  // Student 19
    hashTable.insert(63);  // Student 20

    // Display the hash table
    hashTable.display();

    return 0;
}
