#include <bits/stdc++.h>
using namespace std;
class arr {
public:
    int roll;
    float cgpa;
    string name;
    arr(int roll, float cgpa, string name) {
        this->roll = roll;
        this->cgpa = cgpa;
        this->name = name;
    }
    arr() {}
};
class Stack {
public:
    arr data[30];
    int idx; 
    Stack() {
        idx = -1;
    }
};
void push(Stack*& stack, int roll, float cgpa, string name) {
    if (stack->idx == 29) {
        cout << "Stack is Overflow!" << endl;
        return;
    }
    stack->idx++; 
    stack->data[stack->idx] = arr(roll, cgpa, name);
}

void pop(Stack*& stack) {
    if (stack->idx == -1) {
        cout << "Stack is UnderFlow condition!" << endl;
        return;
    }
    stack->idx--;
}
arr top(Stack*& stack) {
    if (stack->idx == -1) { 
        cout << "Stack is UnderFlow condition!" << endl;
        return arr();
    }
    return stack->data[stack->idx]; 
}

void displayTop(Stack*& stack) {
    if (stack->idx == -1) {
        cout << "Stack is UnderFlow condition!" << endl;
    } else {
        arr topElement = top(stack);
        cout << "Top element\n";
        cout<<" Roll: " << topElement.roll << ", CGPA: " << topElement.cgpa << ", Name: " << topElement.name << endl;
    }
}

int main() {
    int n;
    cout << "Enter the Stack Size: ";
    cin >> n;
    int choice;
    int roll;
    float cgpa;
    string name;

    Stack* stack = new Stack(); 

   do {
        cout << "Main Menu:\n";
        cout << "1. Creation of Stack\n";
        cout << "2. Pop The Element\n";
        cout << "3. Compute INFIX -> POSTFIX\n";
        cout << "4. display\n";
        cout << "5. exit\n";
        cout << "Enter your choice: ";
        cin >> choice; 

        switch(choice){
            case 1:
            for(int i = 0; i<n; i++){
                cout<<"Enter the Detail "<<i+1<<"\n";
                cout<<"Enter the roll :";
                cin>>roll;
                cin.ignore();
                cout << "Name: ";
                getline(cin, name);
                cout<<"CGPA :";
                cin>>cgpa;
                push(stack, roll, cgpa, name);
            }
            break;

            case 2:
            pop(stack);
            break;

            case 3:
            break;

            case 4:
            displayTop(stack);
            break;

            case 5:
            cout << "Exiting...\n";
            break;

            default:
            cout << "Invalid choice! Please try again.\n";  

        }

        cout<< endl;

   }while(choice!= 4);

}


