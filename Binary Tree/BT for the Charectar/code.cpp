#include <bits/stdc++.h>
using namespace std;

class BT {
public:
    char ch;
    BT* left;
    BT* right;
    BT(char ch) {
        this->ch = ch;
        this->left = NULL;
        this->right = NULL;
    }
};

BT* construct(vector<char> arr) {
    if (arr.empty()) return NULL;

    BT* root = new BT(arr[0]);
    queue<BT*> q;
    q.push(root);
    int n = arr.size();
    int i = 1;
    int j = 2;

    while (q.size() > 0 && i < n) {
        BT* temp = q.front();
        q.pop();
        BT* l = nullptr;
        BT* r = nullptr;

        if (arr[i] != ' ') {
            l = new BT(arr[i]);
        }
        else{
            l = NULL;
        }
        if (j < n && arr[j] != ' ') {
            r = new BT(arr[j]);
        }
        else{
            r = NULL;
        }

        temp->left = l;
        temp->right = r;

        if (l != NULL) q.push(l);
        if (r != NULL) q.push(r);

        i += 2;
        j += 2;
    }
    return root;
}

void traversal(BT* root) {
    if (root == NULL) return;
    traversal(root->left);
    traversal(root->right);
    cout<<root->ch <<" -> ";
}


void display(vector<char> arr, BT* root, bool flag = true){
    int n = arr.size();
    if(flag){
        cout<<"\nYour Initial Tree is :";
        cout<<"[\n";
        queue<BT*>q;
        q.push(root);
        while(!q.empty()){
            BT* temp = q.front();
            q.pop();
            cout<<temp->ch;
            cout<<"->  ";
            if(temp->left != NULL){
                q.push(temp->left);
                cout<<temp->left->ch<<"  ";
            }
            if(temp->right != NULL){
                q.push(temp->right);
                cout<<temp->right->ch<<"  ";
            }
            cout<<endl;
        } 
    }
    else{
        cout<<"\nYour Post Order Traversal is : ";
        traversal(root);
    }
}



int main() {
    int choice;
    int i = 1;
    string ch;
    vector<char> arr;
    BT* root = NULL;

    do {
        cout << "\n Main Menu \n";
        cout << "1. Give Tree Element\n";
        cout << "2. Display The Post-order Traversal\n";
        cout << "3. Exit\n";
        cout << "Enter Your Choice:";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "\n\nIf You want to exit From the list Please Enter [Exit] || [exit]\n";
                while (true) {
                    cout << "\nEnter the " << i << " Character Node: ";
                    getline(cin, ch);

                    if (ch.length() > 1 && (ch != "Exit" && ch != "exit")) {
                        cout << "Please Enter a valid single character\n";
                        continue;
                    }

                    if (ch == "exit" || ch == "Exit") {
                        cout << "Exiting the input loop.\n";
                        break;
                    }
                    arr.push_back(ch[0]);
                    i++;
                }
                root = construct(arr);
                break;

            case 2:
                display(arr, root);
                display(arr, root, false);
                break;

            case 3:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
        cout << endl;

    } while (choice != 3);

    return 0;
}
