//Assignment 3: Operations on Singly Linked List
//Name:Pranav Walunj  RollNo:02  Batch:A1  PRN:202301040002
//Operations performed are: Create, Display, insert, search, update, sort, delete.

#include<iostream>
using namespace std;

class Node{
	public:
		int ticketno;             
		string name;
		int seatno;
		int train;
		Node *next; 
};

class sll{
	Node *head; 
	public:
		sll(){
			head = NULL;
		}
		void create();          //Declaration of Functions
		void display();
		void insert();
		void search();
		void update();
		void sort();
		void del();
};

void sll::create(){            //Function for creating Items in SLL
	int c=1;
	Node *temp = NULL; 
	Node *p = NULL; 
	temp = new(Node); 
	while(c!=0){
		if(head == NULL){ 
			cout << "Enter Ticket no: ";
			cin >> temp->ticketno;
			cout << "Enter name of passenger: ";
			cin >> temp->name;
			cout << "Enter seatno: ";
			cin >> temp->seatno;
			cout << "Enter train: " ;
			cin >> temp->train;
			cout << "Added Successfully!\n\n";
			
			head = temp;
			p = temp;
			temp->next = NULL;
		}
		else{ 
			temp = new(Node);
			cout << "Enter ticket no: ";
			cin >> temp->ticketno;
			cout << "Enter name of passenger: ";
			cin >> temp->name;
			cout << "Enter seatno: ";
			cin >> temp->seatno;
			cout << "Enter train: " ;
			cin >> temp->train;
			cout << "Added Successfully!\n\n";
			
			p->next = temp; 
			p = temp;
			temp->next = NULL;
		}
		cout << "Enter 0 to exit and else any number to add another: ";
		cin >> c;
	}
}

void sll::display(){               //Function for displaying item in SLL
	Node *p;
	p = head;
	if(head == NULL){
		cout << "Linked list is empty!\n\n";
	}
	else{
		while(p!=NULL){
			cout << "ticket no: " << p->ticketno << endl;
			cout << "Name: " << p->name << endl;
			cout << "seatno: " << p->seatno << endl;
			cout << "train: " << p->train << endl;
			p = p->next;
		}
	}
}

void sll::insert(){                    //Function for multiple inserting options in SLL
	Node *temp = NULL; 
	Node *p = NULL; 
	int ch = 0;
	while(ch!=5){
		cout << "Enter:\n1 - Insert at Begining\n2 - Insert at end\n3 - Insert at Specific Position\n4 - Insert in between\n5 - Exit\nEnter: ";
		cin >> ch;
		if(ch == 5){
			break;
		}
		switch (ch){
			case 1:
				temp = NULL;
				temp = new(Node);
				cout << "Enter ticket no: ";
				cin >> temp->ticketno;
				cout << "Enter name of passenger: ";
				cin >> temp->name;
				cout << "Enter seatno: ";
				cin >> temp->seatno;
				cout << "Enter train: " ;
				cin >> temp->train;
				
				temp->next = NULL;
				temp->next = head;
				head = temp;
				cout << "Node Added at Begining Successfully!\n\n"; 
				display();
				break;
			case 2:
				temp = NULL;
				temp = new(Node);
				cout << "Enter ticket no: ";
				cin >> temp->ticketno;
				cout << "Enter name of passenger: ";
				cin >> temp->name;
				cout << "Enter seatno: ";
				cin >> temp->seatno;
				cout << "Enter train: " ;
				cin >> temp->train;
				
				temp->next = NULL;
				p = head;
				while(p->next!=NULL){
					p = p->next;
				}
				p->next = temp;
				cout << "Node Added at Last Successfully!\n\n";
				display();
				break;
			case 3:
				int x;
				cout << "Enter at what position you want to enter: ";
				cin >> x;
				temp = NULL;
				p = head;
				for(int i=0; i<x-1;i++){
					if(p->next == NULL){
						p = NULL;
						cout << "Please enter a valid position!\n\n";
						break;
					}
					p=p->next;
				}
				temp = new(Node);
				cout << "Enter ticket no: ";
				cin >> temp->ticketno;
				cout << "Enter name of passenger: ";
				cin >> temp->name;
				cout << "Enter seatno: ";
				cin >> temp->seatno;
				cout << "Enter train: " ;
				cin >> temp->train;
				
				temp->next = p->next;
				p->next = temp;
				cout << "Node Added at " << x << " position Successfully!\n\n";
				display();
				break;
			case 4:
				int n,f;
				temp = NULL;
				p = head;
				cout << "Enter value after which the ticket no to be inserted: ";
				cin >> n;
				while(p->next != NULL){
					if(p->ticketno == n){
						f = 1;
						break;
					}
					p = p->next;
				}
				temp = new(Node);
				cout << "Enter ticket no to inserted: ";
				cin >> temp->ticketno;
				cout << "Enter name of passenger: ";
				cin >> temp->name;
				cout << "Enter seatno: ";
				cin >> temp->seatno;
				cout << "Enter train: " ;
				cin >> temp->train;
				
				temp->next = NULL;
				if(f==1){
					if(p->next!=NULL){
						temp->next = p->next;
						p->next = temp;
					}else{
						p->next=temp;
					}
				}else{
					cout << "Element Not Found\n\n";
				}
				cout << "Linked List: \n";
				display();
				break;
				
			default:
				cout << "Enter valid choice!\n\n";
				break;
		}
	}
}

void sll::search(){               //Function for Searching a specific Item in SLL
	Node *p = NULL;
	int no,flag;
	p = head;
	cout<<"Enter The ticket no to Search"<<endl;
	cin>>no;
	while (p !=NULL)
	{
		if(p-> ticketno == no){
			flag = 1;
			break;
		}
		p = p->next;
	}
	
	if(flag==1){
		cout<<"ticket not Present"<<endl;
	}else{
		cout<<"Element not found"<<endl;
	}
}

void sll::update() {          //Funtion for Updating the SLL
    Node *p = head;  
    int no, c, flag = 0;  
    cout << "Enter ticket no to be updated: " << endl;
    cin >> no;

    
    while (p != NULL) {
        if (p->ticketno == no) {
            flag = 1;  
            break;  // Exit the loop if element is found
        }
        p = p->next;  
    }

    if (flag == 1) {  
        cout << "Element found." << endl;
        do {
            cout << "Enter what you want to update" << endl;
            cout << "1. Ticket no\n2. Name\n3. Seat no.\n4. Train\n5. Exit\n";
            cin >> c;

            switch (c) {
                case 1:
                    cout << "Enter new Ticket no: " << endl;
                    cin >> p->ticketno;
                    break;
                case 2:
                    cout << "Enter new passenger name: " << endl;
                    cin >> p->name;
                    break;
                case 3:
                    cout << "Enter new seatno: " << endl;
                    cin >> p->seatno;
                    break;
                case 4:
                    cout << "Enter new train: " << endl;
                    cin >> p->train;
                    break;
            }
        } while (c != 5);  
    } else {
        cout << "Element not found." << endl;
    }
}


void sll::sort() {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node *p, *s;
    int z, w;
    string x;
    float y;

    // Outer loop for the first pointer (p)
    for (p = head; p->next != NULL; p = p->next) {
        // Inner loop for the second pointer (s)
        for (s = p->next; s != NULL; s = s->next) {
            // Compare roll numbers and swap if needed
            if (p->ticketno > s->ticketno) {
                // Swap roll numbers
                z = p->ticketno;
                p->ticketno = s->ticketno;
                s->ticketno = z;

                // Swap names
                x = p->name;
                p->name = s->name;
                s->name = x;

                // Swap train
                y = p->train;
                p->train = s->train;
                s->train = y;

                // Swap seatno
                w = p->seatno;
                p->seatno = s->seatno;
                s->seatno = w;
            }
        }
    }

    // After sorting, display the sorted list
    cout << "Linked list after sorting: \n";
    display();
}


void sll::del() {
    int ch;
    do {
        cout << "\nEnter option to delete\n";
        cout << "1. First\n2. Last\n3. At Specific Position\n4. Specific value\n5. Exit\n";
        cin >> ch;

        switch(ch) {
            case 1: {  // Delete first node
                if (head == NULL) {
                    cout << "List is empty.\n";
                    break;
                }
                Node *p = head;
                head = head->next;
                delete p;

                cout << "\nLinked list after deletion: \n";
                display();
                break;
            }

            case 2: {  // Delete last node
                if (head == NULL) {
                    cout << "List is empty.\n";
                    break;
                }

                if (head->next == NULL) {  // Only one node
                    delete head;
                    head = NULL;
                } else {
                    Node *p = head;
                    Node *temp = NULL;

                    while (p->next != NULL) {
                        temp = p;
                        p = p->next;
                    }
                    temp->next = NULL;
                    delete p;
                }

                cout << "Linked list after deletion: \n";
                display();
                break;
            }

            case 3: {  // Delete node at specific position
                if (head == NULL) {
                    cout << "List is empty.\n";
                    break;
                }

                int pos;
                cout << "\nEnter position: \n";
                cin >> pos;

                if (pos == 1) {  // Special case for deleting the first node
                    Node *p = head;
                    head = head->next;
                    delete p;
                } else {
                    Node *p = head;
                    Node *temp = NULL;

                    for (int i = 1; i < pos - 1 && p != NULL; i++) {
                        p = p->next;
                    }

                    if (p == NULL || p->next == NULL) {
                        cout << "Invalid position.\n";
                    } else {
                        temp = p->next;
                        p->next = temp->next;
                        delete temp;
                    }
                }

                cout << "Linked list after deletion: \n";
                display();
                break;
            }

            case 4: {  // Delete node by specific value
                if (head == NULL) {
                    cout << "List is empty.\n";
                    break;
                }

                int no, flag = 0;
                cout << "\nEnter the value to delete: ";
                cin >> no;

                Node *p = head;
                Node *temp = NULL;

                if (p->ticketno == no) {  // Special case for deleting the first node
                    head = head->next;
                    delete p;
                    flag = 1;
                } else {
                    temp = head;
                    while (p != NULL && p->ticketno != no) {
                        temp = p;
                        p = p->next;
                    }

                    if (p != NULL) {  // Node found
                        temp->next = p->next;
                        delete p;
                        flag = 1;
                    }
                }

                if (flag == 0) {
                    cout << "Element not found\n";
                } else {
                    cout << "Linked list after deletion: \n";
                    display();
                }
                break;
            }

            case 5:
                cout << "Exiting deletion menu.\n";
                break;

            default:
                cout << "Invalid option.\n";
        }
    } while (ch != 5);
}

int main(){
	sll l;
	int choice;
	cout << "Welcome to Train Passenger Management system using Linked List!\n\n";
	cout << "Enter Passenger Details: \n";
	l.create();
	do{
		cout << "\n\nEnter:\n1 - Display\n2 - Insert\n3.Search \n4. Update \n5. Sort \n6 - Exit\n: ";
		cin >> choice;
		if(choice == 7){
			break;
		}
		switch (choice){
			case 1:
				l.display();
				break;
			case 2:
				l.insert();
				break;
			case 3:
				l.search();
				break;
			case 4:
				l.update();
				break;
			case 5:
				l.sort();
				break;
			case 6:
				l.del();
				break;
				
			default:
				cout << "Enter valid choice!\n\n";
		}
	}while(choice!=3);
	
return 0;
}


