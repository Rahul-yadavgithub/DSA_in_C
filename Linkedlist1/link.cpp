#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int roll;string name; float cgpa; Node* next;
    Node(int roll, string name, float cgpa) {
        this->name = name; this->cgpa = cgpa;
        this->roll = roll;this->next = NULL;
    }
};

Node* student(Node* &head, Node* &tail, int roll, float cgpa, string name, int& size) {
    Node* temp = new Node(roll, name, cgpa);
    if (head == NULL) {
        head = temp; tail = temp;
    } else {
        tail->next = temp; tail = temp;
    }
    size++;
    return head;
}

// Insert At Beginning
Node* InsertAtBeginning(Node* &head, int roll, float cgpa, string name, int& size) {
    Node* temp = new Node(roll, name, cgpa);
    temp->next = head; head = temp;
    size++;
    return head;
}

// Insert At the End
Node* InsertAtEnd(Node* &head, Node* &tail, float cgpa, int roll, string name, int& size) {
    Node* temp = new Node(roll, name, cgpa);
    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
    size++;
    return head;
}

// Insert At Any Index
Node* InsertAtAnyIndex(Node* &head, int cgpa, int roll, string name, int position, int& size) {
    if(position> size|| position < 0){
        cout<< "Provided Index does not exit in your linkedlist \n";
        return head;
    }
    Node* temp = new Node(roll, name, cgpa);
    if (position == 0) {
        return InsertAtBeginning(head , roll, cgpa, name, size);
    }

    Node* curr = head;
    for (int i = 1; i < position && curr->next != NULL; i++) {
        curr = curr->next;
    }

    temp->next = curr->next;
    curr->next = temp;

    return head;
}

// Delete From The Beginning
Node* deleteAtBeginning(Node*& head, int& size) {
    if (head == NULL) {
        cout << "List is already empty!\n";
        return NULL;
    } 
    else {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    size--;
    return head;
}

// Delete From The End 
Node* deleteFromEnd(Node*& head, int& size) {
    if (head == NULL) {
        cout << "List is already empty!\n";
        return NULL;
    } 
    else if (head->next == NULL) { 
        Node* temp = head;
        head = NULL;
        delete temp;
    } 
    else {
        Node* toDelete = head;
        Node* secondLast = head;
        while (toDelete->next != NULL) {
            secondLast = toDelete;
            toDelete = toDelete->next;
        }
        secondLast->next = NULL;
        delete toDelete;
    }
    size--;
    return head;
}

// Delete From Any Index
Node* deleteFromAnyIndex(Node*& head, int position, int& size) {
    if (position > size || position < 1) {
        cout << "The provided index does not exist.\n";
        cout << "Please enter a valid position!\n";
        return head;
    }
    if (head == NULL) {
        cout << "List is already empty!\n";
        return NULL;
    }
    if (position == 1) { 
        return deleteAtBeginning(head, size);
    }
    if(position == size){
        return deleteFromEnd(head, size);
    }
    Node* prev = NULL;
    Node* toDelete = head;
    for (int i = 1; i < position; i++) {
        prev = toDelete;
        toDelete = toDelete->next;
    }
    
    if (toDelete == NULL) {
        cout << "Position out of range!\n";
        return head;
    }
    prev->next = toDelete->next;
    delete toDelete;
    size--;

    return head;
}
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout<<"("<<temp->roll<<" "<<temp->cgpa<<" "<<temp->name<<")"<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL";
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int size = 0;
    int choice;
    int roll;
    float cgpa;
    string name;
    int n;
    string input;

    while (true) {
        cout << "Enter the number of Nodes: ";
        cin >> input;

        try {
            n = stoi(input);

            if (n <= 0) {
                cout << "Number of Nodes must be a positive integer.\n";
            } else {
                break;
            }
        } catch (const std::invalid_argument& error) {
            cout << "Invalid input. Please enter a valid integer.\n";
        } catch (const std::out_of_range& error) {
            cout << "Input is out of range. Please enter a smaller integer.\n";
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (int i = 0; i < n; i++) {
        cout << "Enter student details for student " << i + 1 << ":\n";
        cout << "Roll No: ";
        cin >> roll;
        cin.ignore();
        cout << "Name: ";
        getline(cin, name);
        cout << "CGPA: ";
        cin >> cgpa;

        head = student(head, tail, roll, cgpa, name, size);
        cout << endl;
    }

    do {
        cout << "Main Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display The Linked List\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int insertChoice;
                do {
                    cout << "Insertion Menu:\n";
                    cout << "1. Insert at Beginning\n";
                    cout << "2. Insert at End\n";
                    cout << "3. Insert at Any Index\n";
                    cout << "4. Back to Main Menu\n";
                    cout << "Enter your choice: ";
                    cin >> insertChoice;

                    switch (insertChoice) {
                        case 1:
                            cout << "Enter details of the student to add at the beginning:\n";
                            cout << "Roll No: ";
                            cin >> roll;
                            cin.ignore();
                            cout << "Name: ";
                            getline(cin, name);
                            cout << "CGPA: ";
                            cin >> cgpa;
                            head = InsertAtBeginning(head, roll, cgpa, name, size);
                            break;

                        case 2:
                            cout << "Enter details of the student to add at the end:\n";
                            cout << "Roll No: ";
                            cin >> roll;
                            cin.ignore();
                            cout << "Name: ";
                            getline(cin, name);
                            cout << "CGPA: ";
                            cin >> cgpa;
                            head = InsertAtEnd(head, tail, roll, cgpa, name, size);
                            break;

                        case 3:
                            int position;
                            cout << "Enter the position where you want to insert:";
                            cin >> position;
                            cout << "Enter details of the student to add at index " << position << ":\n";
                            cout << "Roll No: ";
                            cin >> roll;
                            cin.ignore();
                            cout << "Name: ";
                            getline(cin, name);
                            cout << "CGPA: ";
                            cin >> cgpa;
                            head = InsertAtAnyIndex(head, roll, cgpa, name, position, size);
                            break;

                        case 4:
                            cout << "Returning to Main Menu...\n";
                            break;

                        default:
                            cout << "Invalid choice! Please try again.\n";
                    }
                } while (insertChoice != 4);
                break;
            }

            case 2: {
                int deleteChoice;
                do {
                    cout << "Deletion Menu:\n";
                    cout << "1. Delete from Beginning\n";
                    cout << "2. Delete from End\n";
                    cout << "3. Delete from Any Index\n";
                    cout << "4. Back to Main Menu\n";
                    cout << "Enter your choice: ";
                    cin >> deleteChoice;

                    switch (deleteChoice) {
                        case 1:
                            head = deleteAtBeginning(head, size);
                            break;

                        case 2:
                            head = deleteFromEnd(head, size);
                            break;

                        case 3:
                            int l;
                            cout << "Enter the position from where you want to delete: ";
                            cin >> l;
                            head =deleteFromAnyIndex(head, l, size);
                            break;

                        case 4:
                            cout << "Returning to Main Menu...\n";
                            break;

                        default:
                            cout << "Invalid choice! Please try again.\n";
                    }
                } while (deleteChoice != 4);
                break;
            }

            case 3:
                printList(head);
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

        cout << endl;

    } while (choice != 4);
}