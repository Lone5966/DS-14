//Assignment 1: Class and Objects
//Name:Pranav Walunj RollNo:02 Batch:A1 PRN:202301040002
//Operations performed are; Add, Delete, Display, Delete, Update.

#include <iostream>
#include <string>

using namespace std;

class BookManagementSystem 
{
  private:
    int book_id;
    string book_title;
    string author_name;
    int quantity;

  public:
    void add_book();
    void display_book();
    void update_book();
    void delete_book();
    void issue_book();
    void return_book();
};


void BookManagementSystem::add_book() 
{
    cout << "\n-----------------------------" << endl;
    cout << "Add a New Book" << endl << endl;
    cout << "Enter Book ID: ";
    cin >> book_id;
    cout << "Enter Book Title (single word): ";
    cin >> book_title;
    cout << "Enter Author Name (single word): ";
    cin >> author_name;
    cout << "Enter Quantity: ";
    cin >> quantity;
    cout << "Book added successfully with ID " << book_id << "!" << endl;
}


void BookManagementSystem::display_book()
{
    cout << "\nBook Information:" << endl;
    cout << "Book ID: " << book_id << endl;
    cout << "Book Title: " << book_title << endl;
    cout << "Author Name: " << author_name << endl;
    cout << "Quantity Available: " << quantity << endl;
}


void BookManagementSystem::update_book() 
{
    int choice{0};
    bool is_continue = true;
    do {
        cout << "\nUpdate Book Information. Choose an option:" << endl;
        cout << "1. Update Book Title" << endl;
        cout << "2. Update Author Name" << endl;
        cout << "3. Update Quantity" << endl;
        cout << "4. Return to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter new Book Title (single word): ";
            cin >> book_title;
            cout << "Book title updated successfully!" << endl;
            break;
        case 2:
            cout << "Enter new Author Name (single word): ";
            cin >> author_name;
            cout << "Author name updated successfully!" << endl;
            break;
        case 3:
            cout << "Enter new Quantity: ";
            cin >> quantity;
            cout << "Quantity updated successfully!" << endl;
            break;
        case 4:
            cout << "Returning to Main Menu..." << endl;
            is_continue = false;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }

    } while(is_continue);
}


void BookManagementSystem::delete_book() 
{
    book_title = "NULL";
    author_name = "NULL";
    quantity = 0;
    cout << "Book with ID " << book_id << " has been deleted successfully!" << endl;
}


void BookManagementSystem::issue_book()
{
    if (quantity > 0) 
    {
        quantity--;
        cout << "Book issued successfully! Remaining quantity: " << quantity << endl;
    } 
    else 
    {
        cout << "Sorry, the book is currently unavailable!" << endl;
    }
}


void BookManagementSystem::return_book()
{
    quantity++;
    cout << "Book returned successfully! Updated quantity: " << quantity << endl;
}


int main() 
{
    BookManagementSystem books[50];
    int total_books{0};

    cout << "Enter the total number of books to manage: ";
    cin >> total_books;

    for (int i = 0; i < total_books; i++) 
    {
        books[i].add_book();
    }

    cout << "\nDisplaying all book data:" << endl;
    for (int i = 0; i < total_books; i++) 
    {
        books[i].display_book();
    }

    bool is_continue = true;
    int choice{0};

    do 
    {
        int book_no{0};
        cout << "\n\n\nExplore our Book Management Services [Enter the corresponding integer]:" << endl;
        cout << "1. View Book Info" << endl;
        cout << "2. Issue a Book" << endl;
        cout << "3. Return a Book" << endl;
        cout << "4. Update Book Info" << endl;
        cout << "5. Add New Book" << endl;
        cout << "6. Delete a Book" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter Book ID to view info: ";
                cin >> book_no;
                books[book_no-1].display_book();
                break;
            case 2:
                cout << "Enter Book ID to issue: ";
                cin >> book_no;
                books[book_no-1].issue_book();
                break;
            case 3:
                cout << "Enter Book ID to return: ";
                cin >> book_no;
                books[book_no-1].return_book();
                break;
            case 4:
                cout << "Enter Book ID to update: ";
                cin >> book_no;
                books[book_no-1].update_book();
                break;
            case 5:
                books[total_books].add_book();
                total_books++;
                break;
            case 6:
                cout << "Enter Book ID to delete: ";
                cin >> book_no;
                books[book_no-1].delete_book();
                break;
            case 7:
                is_continue = false;
                break;
            default:
                cout << "Invalid choice. Exiting..." << endl;
                is_continue = false;
                break;
        }

    } while(is_continue);

    return 0;
}