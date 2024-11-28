#include <iostream>
using namespace std;

class InputRestrictedDeque {
private:
    int* arr;
    int front, rear, capacity;

public:
    InputRestrictedDeque(int size) {
        arr = new int[size];
        capacity = size;
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void insertRear(int value) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert " << value << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = value;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from front" << endl;
            return;
        }
        if (front == rear) {
            front = rear = -1; // Deque becomes empty
        } else {
            front = (front + 1) % capacity;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }
        cout << "Deque elements: ";
        for (int i = front; i != rear; i = (i + 1) % capacity) {
            cout << arr[i] << " ";
        }
        cout << arr[rear] << endl; // Print the last element
    }

    ~InputRestrictedDeque() {
        delete[] arr;
    }
};

class OutputRestrictedDeque {
private:
    int* arr;
    int front, rear, capacity;

public:
    OutputRestrictedDeque(int size) {
        arr = new int[size];
        capacity = size;
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void insertFront(int value) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert " << value << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            front = (front - 1 + capacity) % capacity;
        }
        arr[front] = value;
    }

    void insertRear(int value) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert " << value << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = value;
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from rear" << endl;
            return;
        }
        if (front == rear) {
            front = rear = -1; // Deque becomes empty
        } else {
            rear = (rear - 1 + capacity) % capacity;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }
        cout << "Deque elements: ";
        for (int i = front; i != rear; i = (i + 1) % capacity) {
            cout << arr[i] << " ";
        }
        cout << arr[rear] << endl; // Print the last element
    }

    ~OutputRestrictedDeque() {
        delete[] arr;
    }
};

int main() {
    int choice, size;
    cout << "Enter the size of the deques: ";
    cin >> size;

    InputRestrictedDeque inputDeque(size);
    OutputRestrictedDeque outputDeque(size);

    do {
        cout << "\nMenu:\n";
        cout << "1. Input Restricted Deque Operations\n";
        cout << "2. Output Restricted Deque Operations\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int subChoice, value;
                do {
                    cout << "\nInput Restricted Deque Menu:\n";
                    cout << "1. Insert at Rear\n";
                    cout << "2. Delete from Front\n";
                    cout << "3. Display\n";
                    cout << "4. Back\n";
                    cout << "Choose an option: ";
                    cin >> subChoice;

                    switch (subChoice) {
                        case 1:
                            cout << "Enter value to insert: ";
                            cin >> value;
                            inputDeque.insertRear(value);
                            break;
                        case 2:
                            inputDeque.deleteFront();
                            break;
                        case 3:
                            inputDeque.display();
                            break;
                        case 4:
                            break;
                        default:
                            cout << "Invalid option!" << endl;
                    }
                } while (subChoice != 4);
                break;
            }
            case 2: {
                int subChoice, value;
                do {
                    cout << "\nOutput Restricted Deque Menu:\n";
                    cout << "1. Insert at Front\n";
                    cout << "2. Insert at Rear\n";
                    cout << "3. Delete from Rear\n";
                    cout << "4. Display\n";
                    cout << "5. Back\n";
                    cout << "Choose an option: ";
                    cin >> subChoice;

                    switch (subChoice) {
                        case 1:
                            cout << "Enter value to insert at front: ";
                            cin >> value;
                            outputDeque.insertFront(value);
                            break;
                        case 2:
                            cout << "Enter value to insert at rear: ";
                            cin >> value;
                            outputDeque.insertRear(value);
                            break;
                        case 3:
                            outputDeque.deleteRear();
                            break;
                        case 4:
                            outputDeque.display();
                            break;
                        case 5:
                            break;
                        default:
                            cout << "Invalid option!" << endl;
                    }
                } while (subChoice != 5);
                break;
            }
            case 3:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid option!" << endl;
        }
    } while (choice != 3);

    return 0;
}
