#include <bits/stdc++.h>
using namespace std;

class BT {
public:
    int val;
    BT* left;
    BT* right;
    BT(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

BT* construct(vector<int> arr) {
    if (arr.empty()) return NULL;

    queue<BT*> q;
    BT* root = new BT(arr[0]);
    q.push(root);
    int n = arr.size();
    int i = 1;
    int j = 2;

    while (q.size() > 0 && i < n) {
        BT* temp = q.front();
        q.pop();
        BT* l = nullptr;
        BT* r = nullptr;

        if (i < n && arr[i] != INT_MIN) {
            l = new BT(arr[i]);
        }
        if (j < n && arr[j] != INT_MIN) {
            r = new BT(arr[j]);
        }

        temp->left = l;
        temp->right = r;

        if (l != NULL) q.push(l);
        if (r != NULL) q.push(r);

        i += 2;
        j += 2;
    }

    return root;  // return the root of the tree
}

void traversal(BT* root) {
    stack<BT*> st;
    st.push(root);
    BT* curr = root;

    while (curr != NULL || !st.empty()) {
        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();

        cout<<curr->val<<" ";
        curr = curr->right;
    }
}

void display(vector<int> arr, BT* root, bool flag = true) {
    if (flag) {
        cout << "\nYour Initial Tree is :\n";
        cout << "[\n";
        queue<BT*> q;
        q.push(root);

        while (!q.empty()) {
            BT* temp = q.front();
            q.pop();
            cout << temp->val;
            cout << " -> ";

            if (temp->left != NULL) {
                q.push(temp->left);
                cout << temp->left->val << " ";
            }
            if (temp->right != NULL) {
                q.push(temp->right);
                cout << temp->right->val << " ";
            }

            cout << endl;
        }
        cout << "]\n";
    }
    else {
        cout << "\nYour Post-order Traversal is: ";
        traversal(root);
        cout << endl;
    }
}

int main() {
    int choice;
    int n;
    vector<int> arr;
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
                cout << "\nEnter the Number of Nodes For Tree: ";
                cin >> n;
                arr.clear();
                for (int i = 0; i < n; i++) {
                    cout << "\nEnter the " << i + 1 << " Node: ";
                    int val;
                    cin >> val;
                    arr.push_back(val);
                }
                root = construct(arr); // Assign the return value to root
                break;

            case 2:
                display(arr, root);
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
