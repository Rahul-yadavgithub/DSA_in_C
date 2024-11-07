#include<bits/stdc++.h>
using namespace std;

void swap(int& x, int& y){
    int temp = x;
    x = y;
    y = temp;
}

void sort(vector<int>& arr){
    int n = arr.size();
    for(int i=0; i<n-1; i++){
        bool swapped = false;
        for(int j=0; j<n-i-1; j++){
            if(arr[j]> arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }
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
                sort(ans);
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

