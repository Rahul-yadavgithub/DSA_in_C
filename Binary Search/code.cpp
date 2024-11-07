#include<bits/stdc++.h>
using namespace std;

int  BS(vector<int> arr, int num){
    int n  = arr.size();
    int low = 0; 
    int high = n-1;
    while(low<=high){
        int mid = low+ (high-low)/2;
        if(num == arr[mid]){
            return mid;
        }
        else if(num> mid) low = mid+1;
        else high = mid-1;
    }
    return -1;
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
    int num;
    int idx;
    string input;
    vector<int> ans;

    while (true) {
        cout << "Enter the size of sorted Array: ";
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
                ans.clear();
                for(int i=0; i<n; i++){
                   int x;
                   cout<<"Enter the "<<i+1<<" Element:  ";
                   cin>>x;
                   ans.push_back(x);
                }
                cout<<endl;
                cout<<"Enter the number You want to Search: ";
                cin>>num;
                cout<<endl;
                display(ans);
                BS(ans, num);
                break;
               
            case 2: 
                idx = BS(ans, num);
                if(idx>=0){
                    cout<<"The Index of the Number: ";
                    cout<<idx;
                }
                else{
                    cout<<"The given Index does not exit !!\n";
                }
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