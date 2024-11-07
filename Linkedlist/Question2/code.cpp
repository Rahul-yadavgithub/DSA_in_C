









#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int roll;
    float cgpa;
    string name;
    Node*next;
    Node* prev;
    Node(int roll, float cgpa, string name){
        this-> name = name;
        this->cgpa = cgpa;
        this->roll = roll;
        this->next = NULL;
        this->prev = NULL;
    }
};

Node* student(Node* &head, Node* &tail, int roll, float cgpa, string name, int& size){
    Node* temp = new Node(roll, cgpa, name);
    if(head == NULL){
        head = temp;
        tail = temp;
    }
    else{
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    size++;
    return head;
}

// Insert At Beginning

Node* InsertAtBeginning(Node* &head, Node* &tail, int roll, float cgpa, string name, int& size){
    Node* temp = new Node(roll, cgpa, name);
    if(head == NULL){
        return student(head, tail, roll, cgpa, name, size);
    }
    else{
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    size++;
    return head;
}

// Insert At The End

Node* InsertAtEnd(Node* & head, Node* &tail, int roll, float cgpa, string name, int& size){
    Node*temp = new Node(roll, cgpa, name);
    return student(head, tail, roll, cgpa, name, size);
}

// Insert At Any Index

Node* InsertAtAnyIndex(Node* &head, Node* &tail, int roll , float cgpa, string name, int& size, int position) {
    if(position > size + 1 || position <= 0) {
        cout << "The given position is not valid !!" << endl;
        return head;
    }

    Node* temp = new Node(roll, cgpa, name);

    if(position == 1) {
        return InsertAtBeginning(head, tail, roll, cgpa, name, size);
    }

    if(position == size + 1) {
        return InsertAtEnd(head, tail, roll, cgpa, name, size);
    }
     
    Node* curr = head;
    if(position > size / 2) {
        Node* dest = tail;
        for(int i = size; i > position - 1; i--) {
            dest = dest->prev;
        }
        curr = dest;
    } 
    else {
        Node* dest = head;
        for(int i = 1; i < position - 1; i++) {
            dest = dest->next;
        }
        curr = dest;
    }
        temp->next = curr->next;
        temp->prev = curr;
        curr->next->prev = temp;
        curr->next = temp;

    size++;
    return head;
}

// delete from the beginning

Node* deleteFromBeginning(Node* &head,Node*tail, int& size) {
    if (head == NULL) {
        cout << "Linkedlist is Already Empty !!\n";
        return NULL;
    } else {
        Node* temp = head;
        head = head->next;
        if (head != NULL) { 
            head->prev = NULL;
        }
        else{
            tail = NULL;
        }
        delete temp;
        size--;
    }
    return head;
}


// delete form the end

Node* deleteFromEnd(Node* &head, Node* &tail, int& size){
    if(head == NULL){
        cout<<"Linkedlist is Already Empty !!\n";
        return NULL;
    }
    else{
        Node* temp = tail;
        tail = tail->prev;
        if(tail != NULL){
            tail->next = NULL;
        }
        else{
            head = NULL;
        }
    }
    size--;
    return head;
}

// delete form any Index

Node* deleteFromAnyIndex(Node* &head, Node* &tail, int& size, int position) {
    if (head == NULL) {
        cout << "Linkedlist is already Empty !!\n";
        return NULL;
    }
    
    if (position > size || position <= 0) {
        cout << "Invalid position for LinkedList !! \n";
        return head;
    }

    if (position == 1) {
        return deleteFromBeginning(head, tail, size);
    }
    
    if (position == size) {
        return deleteFromEnd(head, tail, size);
    }
    
    Node* todelete = head;
    Node* prevdelete = head;    
    if(position > size/2){
        todelete = tail;
        prevdelete = tail;
        for(int i = size; i> position; i--){
            prevdelete = todelete;
            todelete = todelete->prev;
        }
        prevdelete->prev = todelete->prev;
        todelete->prev->next = prevdelete;
    }
    else{
        todelete = head;
        prevdelete= head;
        for(int i=1; i<position; i++){
            prevdelete = todelete;
            todelete = todelete->next;
        }
        prevdelete->next = todelete->next;
        todelete->next->prev = prevdelete;
    }

    delete todelete;
    size--;

    return head;
}



void printList(Node* head) {
    Node* temp = head;
    Node* pre = head;
    while (temp != NULL) {
        pre = temp;
        cout<<"("<<temp->roll<<" "<<temp->cgpa<<" "<<temp->name<< ")"<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL";
    cout<<endl<<endl;
    cout<<"Reverse order of linkedlist !!";
    cout<<endl<<endl;
    while(pre != NULL){
      cout<<"("<<pre->roll<<" "<<pre->cgpa<<" "<< pre->name<<")"<<" ->";
      pre = pre->prev;
    }

    cout<<"NULL";
}

string Respect() {
    auto currTime = time(0);
    auto ltm = localtime(&currTime);

    int hour = ltm->tm_hour;

    if (hour < 12) {
        return "Good Morning Sir!";
    } else if (hour < 18) {
        return "Good Afternoon Sir!";
    } else {
        return "Good Evening Sir!";
    }
}


int main() {

    string greeting = Respect();
    cout << greeting << "\n";
    cout << "I am Rahul Yadav!\n";
    cout<<"\n\n";
    
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
                            head = InsertAtBeginning(head,tail, roll, cgpa, name, size);
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
                            head = InsertAtAnyIndex(head,tail, roll, cgpa, name, size, position);
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
                            head = deleteFromBeginning(head,tail, size);
                            break;

                        case 2:
                            head = deleteFromEnd(head,tail, size);
                            break;

                        case 3:
                            int l;
                            cout << "Enter the position from where you want to delete: ";
                            cin >> l;
                            head =deleteFromAnyIndex(head,tail, size, l);
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