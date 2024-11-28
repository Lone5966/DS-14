//Consider a student database of TYBTECH class (at least15records). Database contains 
//different fieldsofeverystudentlikeRollNo,Name,SGPAandDepartment.Performthefollowingoperations:
/* 1. Add Student
   2. Sort students by Rollno (Bubble Sort)
   3. Sort students by Name (Insertion Sort)
    4. Find top 10 students by SGPA (Quick Sort)
    5. Search students by SGPA (Linear Search)
    6. Search for a student by Name (Binary Search)
    7. Check if a student is in Computer department (Fibonacci Search)
*/


#include <iostream>
#include <cstring>
using namespace std;

const int MAX_STUDENTS = 50;
int studentCount = 15; // Initial count of students

struct Student {
    int rollNo;
    char name[50];
    float sgpa;
    char department[50];
};

// Initial inbuilt student data
Student students[MAX_STUDENTS] = {
    {1, "Aarav", 8.5, "Computer"},
    {2, "Ishita", 7.9, "Mechanical"},
    {3, "Vivaan", 8.2, "Electrical"},
    {4, "Diya", 6.8, "Civil"},
    {5, "Riya", 9.1, "Computer"},
    {6, "Kabir", 7.2, "Mechanical"},
    {7, "Anaya", 8.9, "Computer"},
    {8, "Aryan", 6.5, "Civil"},
    {9, "Tanish", 7.8, "Electrical"},
    {10, "Saanvi", 8.7, "Mechanical"},
    {11, "Aadhya", 8.0, "Civil"},
    {12, "Atharv", 9.3, "Computer"},
    {13, "Myra", 7.3, "Electrical"},
    {14, "Kiaan", 8.1, "Computer"},
    {15, "Krish", 7.5, "Civil"}
};

// Function to display all students
void displayAllStudents() {
    for (int i = 0; i < studentCount; i++) {
        cout << "Roll No: " << students[i].rollNo << ", Name: " << students[i].name
             << ", SGPA: " << students[i].sgpa << ", Department: " << students[i].department << endl;
    }
}

// Function to add a new student
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "Database is full, cannot add more students.\n";
        return;
    }
    Student newStudent;
    cout << "Enter Roll No: ";
    cin >> newStudent.rollNo;
    cout << "Enter Name (single word): ";
    cin >> newStudent.name;
    cout << "Enter SGPA: ";
    cin >> newStudent.sgpa;
    cout << "Enter Department (single word): ";
    cin >> newStudent.department;
    students[studentCount++] = newStudent;
    cout << "Student added successfully.\n";
}

// Bubble Sort by Roll Number
void bubbleSortByRollNo() {
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = 0; j < studentCount - i - 1; j++) {
            if (students[j].rollNo > students[j + 1].rollNo) {
                swap(students[j], students[j + 1]);
            }
        }
    }
    cout << "Students sorted by Roll Number.\n";
}

// Insertion Sort by Name
void insertionSortByName() {
    for (int i = 1; i < studentCount; i++) {
        Student key = students[i];
        int j = i - 1;
        while (j >= 0 && strcmp(students[j].name, key.name) > 0) {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = key;
    }
    cout << "Students sorted by Name.\n";
}

// Quick Sort by SGPA (to find top 10)
int partition(int low, int high) {
    float pivot = students[high].sgpa;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (students[j].sgpa > pivot) { // For descending order
            i++;
            swap(students[i], students[j]);
        }
    }
    swap(students[i + 1], students[high]);
    return (i + 1);
}

void quickSortBySGPA(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);
        quickSortBySGPA(low, pi - 1);
        quickSortBySGPA(pi + 1, high);
    }
}

void top10BySGPA() {
    quickSortBySGPA(0, studentCount - 1);
    cout << "Top 10 students by SGPA:\n";
    for (int i = 0; i < min(10, studentCount); i++) {
        cout << "Roll No: " << students[i].rollNo << ", Name: " << students[i].name
             << ", SGPA: " << students[i].sgpa << ", Department: " << students[i].department << endl;
    }
}

// Linear Search by SGPA
void searchBySGPA(float sgpa) {
    bool found = false;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].sgpa == sgpa) {
            cout << "Roll No: " << students[i].rollNo << ", Name: " << students[i].name
                 << ", SGPA: " << students[i].sgpa << ", Department: " << students[i].department << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No student found with SGPA " << sgpa << ".\n";
    }
}

// Binary Search by Name
int binarySearchByName(const char* name) {
    int low = 0, high = studentCount - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int comparison = strcmp(students[mid].name, name);
        if (comparison == 0) return mid;
        else if (comparison < 0) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Fibonacci Search for Computer department
bool isInComputerDepartment(const char* department) {
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;

    while (fibM < studentCount) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;
    while (fibM > 1) {
        int i = min(offset + fibMMm2, studentCount - 1);
        if (strcmp(students[i].department, department) < 0) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        } else if (strcmp(students[i].department, department) > 0) {
            fibM = fibMMm2;
            fibMMm1 -= fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        } else {
            return true;
        }
    }
    return false;
}

int main() {
    int choice;
    while (true) {
        cout << "\n--- Student Database Menu ---\n";
        cout << "1. Add Student\n";
        cout << "2. Sort students by Rollno (Bubble Sort)\n";
        cout << "3. Sort students by Name (Insertion Sort)\n";
        cout << "4. Find top 10 students by SGPA (Quick Sort)\n";
        cout << "5. Search students by SGPA (Linear Search)\n";
        cout << "6. Search for a student by Name (Binary Search)\n";
        cout << "7. Check if a student is in Computer department (Fibonacci Search)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                bubbleSortByRollNo();
                displayAllStudents();
                break;
            case 3:
                insertionSortByName();
                displayAllStudents();
                break;
            case 4:
                top10BySGPA();
                break;
            case 5: {
                float sgpa;
                cout << "Enter SGPA to search: ";
                cin >> sgpa;
                searchBySGPA(sgpa);
                break;
            }
            case 6: {
                char name[50];
                cout << "Enter Name to search: ";
                cin >> name;
                int index = binarySearchByName(name);
                if (index != -1) {
                    cout << "Roll No: " << students[index].rollNo << ", Name: " << students[index].name
                         << ", SGPA: " << students[index].sgpa << ", Department: " << students[index].department << endl;
                } else {
                    cout << "Student with name " << name << " not found.\n";
                }
                break;
            }
            case 7: {
                if (isInComputerDepartment("Computer")) {
                    cout << "There is at least one student in the Computer department.\n";
                } else {
                    cout << "No students found in the Computer department.\n";
                }
                break;
            }
            case 0:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}
