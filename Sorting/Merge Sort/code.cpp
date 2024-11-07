









#include<bits/stdc++.h>
using namespace std;

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

void partition(vector<int>& arr){
    int n = arr.size();
    if(n/2 == 0){
        return;
    }
    int mid = n/2;
    vector<int> left;
    vector<int> right;
    for(int i=0; i<mid; i++){
        left.push_back(arr[i]);
    }
    for(int i=mid; i<n; i++){
        right.push_back(arr[i]);
    }
    partition(left);
    partition(right);
    
     arr = merge(left, right);

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
    int n;
    int choice;
    string input;
    vector<int> ans;

    while (true) {
        cout << "Enter the size of the array: ";
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


    do {
        cout << "Main Menu:\n";
        cout << "1. Input Array\n";
        cout << "2. Display The Array\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                for(int i=0; i<n; i++){
                   int x;
                   cout<<"Enter the "<<i+1<<" Element:  ";
                   cin>>x;
                   ans.push_back(x);
                }
                cout<<endl;
                display(ans);
                partition(ans);
                break;
               
            case 2: 
                display(ans, false);
                break;

            case 3:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

        cout << endl;

    } while (choice != 3);
}
