









#include<bits/stdc++.h>
using namespace std;

class Stack {
public:
    char arr[40];
    int idx;
    Stack() {
        idx = -1;
    }
};

void push(Stack*& stack, string val) {
    if (stack->idx == 39) {
        cout << "Stack is in OverFlow Condition !!\n";
        return;
    }
    int size = val.size();
    for (int i = 0; i < size; i++) {
        char ch = val[i];
        stack->idx++;
        stack->arr[stack->idx] = ch;
    }
}

void pop(Stack*& stack, bool flage = true) {
    if (stack->idx == -1) {
        cout << "Our Stack is underFlow !!\n";
        return;
    }
    char temp = stack->arr[stack->idx];
    if (flage) {
        cout << "Poped Element is :" << temp << "\n";
    }
    stack->idx--;
}

char top(Stack*& stack) {
    if (stack->idx == -1) {
        cout << "Our Stack is Empty !\n";
        return '\0';
    }
    return stack->arr[stack->idx];
}

int cmp(char a) {
    if (a == '^') {
        return 3;
    } else if (a == '*' || a == '/') {
        return 2;
    } else if (a == '+' || a == '-') {
        return 1;
    } else {
        return 0;
    }
}

vector<char> infix_to_postfix(Stack*& stack, string val, vector<char>& ans) {
    if (stack->idx == -1) {
        push(stack, "(");
    }
    int n = val.size();
    for (int i = 0; i < n; i++) {
        if (val[i] == '(') {
            push(stack, "(");
        } 
        else if (val[i] == ')') {
            while (top(stack) != '(') {
                ans.push_back(top(stack));
                pop(stack, false);
            }
            pop(stack, false);
        } 
        else if (val[i] >= '0' && val[i] <= '9') {  
            ans.push_back(val[i]); 
        } 
        else { 
            char ch = top(stack);
            int a = cmp(ch);
            int b = cmp(val[i]);

            while (stack->idx != -1 && a > b && ch != '(') {
                ans.push_back(top(stack));
                pop(stack, false);
                ch = top(stack);
                a = cmp(ch);
            }

            string st(1, val[i]);
            push(stack, st);
        }
    }

    while (stack->idx != -1) {
        if (top(stack) == '(') {
            pop(stack, false);
        } else {
            ans.push_back(top(stack));
            pop(stack, false);
        }
    }
    return ans;
}

void display(vector<char> ans) {
    string st = "";
    if(ans.size() == 0){
        cout<<"Our Stack Has no element !!\n";
        return;
    }
    for (int i = 0; i < ans.size(); i++) {
        st += ans[i];
    }
    cout << "Our Final Output: \n" << st << endl;
}

int main() {
    int choice;
    string val;
    Stack* stack = new Stack();
    vector<char> ans;

    do {
        cout << "Main Menu:\n";
        cout << "1. Creation of Stack\n";
        cout << "2. Pop The Element\n";
        cout << "3. Compute INFIX -> POSTFIX\n";
        cout << "4. display\n";
        cout << "5. exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter Required String:\n";
                getline(cin, val);
                push(stack, val);
                break;

            case 2: {
                cout << "Enter the No of Time to Pop: ";
                int x;
                
                   while (true) {
                      cin >> x;
                      if (cin.fail() || cin.peek() != '\n') {
                      cin.clear(); 
                      cin.ignore(numeric_limits<streamsize>::max(), '\n');  
                      cout << "Invalid input! Please enter again: ";
                    } 
                    else if (x <= 0) {
                       cout << "Please enter Again: ";
                    } 
                    else {
                        break; 
                    }
                }
                int n = stack->idx + 1;
                int rem;
                if (x > n) {
                    rem = x - n;
                }
                while (x--) {
                    if (rem > 2 && x == rem - 2) break;
                    pop(stack, true);
                }
                break;
            }

            case 3:
                cout << "Enter the Expression For Infix to Postfix: ";
                if (stack->idx != -1) {
                    while (stack->idx != -1) {
                        pop(stack, false);
                    }
                }
                getline(cin, val);
                infix_to_postfix(stack, val, ans);
                break;

            case 4:
                display(ans);
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
        cout << endl;

    } while (choice != 5);
}
