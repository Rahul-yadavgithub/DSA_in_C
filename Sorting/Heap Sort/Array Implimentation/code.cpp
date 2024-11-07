#include<bits/stdc++.h>
using namespace std;


class BST{
    public:
    int arr[40];
    int root;
    int leaf;
    BST(){
        root= leaf = 0;
    }
};

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void rearrange( BST*& bst, int index){
    if(index == 1){
        return;
    }
    int par = index/2;

    if(bst->arr[par]< bst->arr[index]){
        return;
    }
    else{
        swap(bst->arr[par], bst->arr[index]);
    }

    rearrange(bst, par);

}

void delrearrange(BST*& bst, int start){
    int lc = 2 * start; 
    int rc = 2 * start + 1; 
    int smallest = start;

    if (lc <= bst->leaf && bst->arr[lc] < bst->arr[smallest]) {
        smallest = lc;
    }

    if (rc <= bst->leaf && bst->arr[rc] < bst->arr[smallest]) {
        smallest = rc;
    }

    if (smallest != start) {
        swap(bst->arr[start], bst->arr[smallest]);
        delrearrange(bst, smallest);
    }
}


void construct( BST*& bst , int val){
    if(bst->root == 0){
        bst->root++;
        bst->leaf++;
        bst->arr[bst->root] = val;
    }
    else{
        bst->leaf++;
        bst->arr[bst->leaf] = val;
        int par = (bst->leaf)/2;

        if(bst->arr[par]> bst->arr[bst->leaf]){
            rearrange(bst, bst->leaf);
        }
    }
    
}

void del(BST*& bst, vector<int>& arr){
    if(bst->root > bst->leaf || bst->root == 40){
        cout<<"Our Heaf Become Empty !!\n";
        return;
    }

    int val = bst->arr[bst->root];
    arr.push_back(val);

    bst->arr[bst->root] = bst->arr[bst->leaf];
    bst->leaf--;
    delrearrange(bst, bst->root);

    
}

vector<int> merge(vector<int> a, vector<int> b){ 
    int i = 0;
    int j = 0;
    int k= 0;
    vector<int> res(a.size()+b.size(),0);
    while(i<a.size()  && j<b.size()){
        if(a[i]< b[j]){
            res[k]= a[i];
            k++;
            i++;
        }
        else{
            res[k]= b[j];
            k++;
            j++;
        }
    }
    if(i==a.size()){
        while(j<b.size()){
            res[k]= b[j];
            j++;
            k++;
        }
    }
    if(j==b.size()){
        while(i<a.size()){
            res[k]= a[i];
            k++;
            i++;
        }
    }
    return res;
}



void display(vector<int>ans, bool flag = true){
    int n = ans.size();
    if(flag){
        cout<<"Your Initial Array: "<<"[";
        for(int i=0; i<n; i++){
            cout<<ans[i];
            if(i!= n-1) cout<<",";
        }
        cout<<"]";
        cout<<endl;
    }
    else{
        cout<<"Your Final Array:  "<<"[";
        for(int i=0; i<n; i++){
            cout<<ans[i];
            if(i !=n-1) cout<<",";
        }
        cout<<"]";
        cout<<endl;
    }

    
}

int main() {
    int choice;
    BST*bst = new BST();
    vector<int>ans;
    vector<int>arr;
    vector<int>final;
    int m;
    do {
        cout << "Main Menu:\n";
        cout << "1. Input Number\n";
        cout << "2. sort The array\n";
        cout << "3. Display The Array\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout<<"Give the Input size: ";
                int n;
                cin>>n;
                if(n> 40){
                    cout<<"Input size is Exceed !!\n";
                    break;
                }
                for(int i=0; i<n; i++){
                   int x;
                   cout<<"Enter the "<<i+1<<" Element:  ";
                   cin>>x;
                   construct(bst, x);
                   ans.push_back(x);
                }
                cout<<endl;
                display(ans);
                break;
               
            case 2: 
                m = ans.size()- arr.size();
                final = arr;
                arr.clear();
                for (int i = 0; i < m; i++) {
                    del(bst, arr);
                }
               final =  merge(final, arr);

                break;

            case 3:
               if(final.size() == 0){
                display(ans);
               }
               else{
                display(final, false);
               }
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








