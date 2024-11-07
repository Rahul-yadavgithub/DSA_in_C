









#include<bits/stdc++.h>
using namespace std;

void swap(int& a, int& b){
    int temp = a;
     a = b;
     b = temp;
}

void sort(vector<int>& arr, int m, int n) {
    if (m >= n) {
        return;
    }
    
    int pivot_idx = (m + n) / 2;
    int pivot_el = arr[pivot_idx];
    int i = m;
    int j = m - 1; 
    
    for (i; i <= n; i++) {
        if (arr[i] < pivot_el) {
            j++;
            if (arr[j] == pivot_el) pivot_idx = i; 
            swap(arr[i], arr[j]);
        }
    }
    
    
    swap(arr[j + 1], arr[pivot_idx]);
    pivot_idx = j + 1;  
    
    sort(arr, m, pivot_idx - 1);  
    sort(arr, pivot_idx + 1, n); 
    
    return;
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
                cout << "Size should be +ve integer.\n";
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
                sort(ans,0, n-1);
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