









#include<bits/stdc++.h>
using namespace std;
class Queue{
    public:
    int data;
    Queue*prev;
    Queue*next;
    Queue(int data){
        this->prev = NULL;
        this->next = NULL;
        this->data = data;

    }
};

Queue* push( Queue*& front, Queue*& rear, int val, bool flage = true){
    Queue* temp = new Queue(val);

    if(flage){
        if(front == NULL){
            front = rear = temp;
        }
        else{
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
        }

    }
    else{
        if(front == NULL){
            front = rear = temp;
        }
        else{
            temp->next = front;
            front->prev = temp;
            front = temp;
        }
    }

    return front; 
}

Queue* pop( Queue*& front, Queue*& rear, bool flage = true){
    if(front == NULL){
        cout<<"Our Queue is Empty !!\n";
        return NULL;
    }
    if(flage){
        Queue*temp = front;
        front = front->next;
        if(front != NULL){
            front->prev = NULL;
        }
        else{
            rear = NULL;
        }
        delete temp;
    }
    else{
        Queue* temp = rear;
        rear = rear->prev;
        if(rear != NULL){
            rear->next = NULL;
        }
        else{
            front = NULL;
        }
    }
    return front;
}

void display(Queue* front) {
    if(front == NULL){
        cout<<"Our Queue is Empty !!\n";
        return ;
    }

    Queue* temp = front;
    Queue* pre = front;  
    cout<<"Elements in the Forward Order: [";

    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << ", ";
        pre = temp;  
        temp = temp->next;
    }
    cout << "]\n";

    cout<<"Elements in Reverse Order: [";
    while (pre != NULL) {
        cout << pre->data;
        if (pre->prev != NULL) cout << ", ";
        pre = pre->prev;  
    }
    cout << "]\n";
}


int main() {
    Queue* front = NULL;
    Queue* rear = NULL;
    int choice;
    do {
        cout << "Main Menu:\n";
        cout << "1.  Element in Queue\n";
        cout << "2. Pop Element From Queue\n";
        cout << "3. display\n";
        cout << "4. exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
			    int n;
                cout << "Enter No of Element For Queue: ";
				cin>>n;
				cout<<"\n";
				for(int i = 0; i<n; i++){
					cout<<"Enter "<<i+1<<" Element: ";
					int x ;
					cin>>x;
                    char location;
                    cout<<"Enter the Location: ";
                    cin>>location;
                    if(location =='r'|| location == 'R'){
                        push(front, rear, x);
                    }
                    if(location == 'f' || location =='F'){
                        push(front, rear, x, false);
                    }
				}
                break;

            case 2: {
                cout << "Enter the No of Time to Pop: ";
                int x;
                cin>>x;
                for(int i=0;i<x; i++){
                    char location;
                    cout<<"Enter the Location: ";
                    cin>>location;
                    if(location =='r' || location == 'R'){
                        pop(front, rear, false);
                    }
                    if(location =='f'|| location =='F'){
                        pop(front, rear);
                    }
                }
				break;

            }
            case 3:
                display(front);
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
