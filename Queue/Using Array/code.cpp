









#include<bits/stdc++.h>
using namespace std;

class Queue{
	public:
	int arr[40];
	int front;
	int rear;
	Queue(){
		front = rear =  -1;
	}
};


void push(Queue*& queue, int val, bool flage = true){ 
    if(queue->rear == 39){
        cout<<"Queue is Full !! "<<"\n";
        return;
    }
    if(flage){  
        if(queue->rear == -1){  
            queue->rear = queue->front = 0;
            queue->arr[queue->rear] = val;  
        }
        else{
            queue->rear++;
            queue->arr[queue->rear] = val;
        }
    }
    else{ 
        if(queue->rear == -1){ 
            queue->front = queue->rear = 0;
            queue->arr[queue->front] = val; 
        }
        else{
           
            int idx = queue->rear;
            queue->rear++;
            while(idx >= queue->front){ 
                queue->arr[idx + 1] = queue->arr[idx];
                idx--;
            }
            queue->arr[queue->front] = val;  
        }
    }
}


void pop(Queue*& queue, int n, bool flage = true) {
    if (queue->front == -1) {
        cout << "Queue is Empty !!" << "\n";
        return;
    }

    if(flage){
        while(n>0 && queue->front<= queue->rear){
            queue->front = queue->front+1;
            n--;
        }
        if(queue->front> queue->rear){
            queue->front = queue->rear = -1;
            cout<<"Our Queue Become Fully Empty !!"<<"\n";
        }
    }
    else{
        while(n>0 && queue->rear >= queue->front){
            queue->rear--;
            n--;
        }
        if(queue->rear < queue->front){
            queue->front = queue->rear = -1;
            cout<<"Our Queue Become Fully Empty !!"<<"\n";
        }
    }


}

void display(Queue*& queue){
	if(queue->front == -1){
		cout<<"Queue is Empty !!"<<"\n";
		return;
	}
	int idx = queue->front;
	while(idx<= queue->rear){
		cout<<"element: "<< queue->arr[idx]<<"\n";
		idx++;
	}
}
int main() {
    int choice;
    string val;
    Queue* queue = new Queue();
    do {
        cout << "Main Menu:\n";
        cout << "1. Enqueue Element in Queue\n";
        cout << "2. Dequeue Element From Queue\n";
        cout << "3. display\n";
        cout << "4. exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
			    int n;
                cout << "Enter No of Element For Queue:";
				cin>>n;
				cout<<"\n";
				for(int i = 0; i<n; i++){
					cout<<"Enter "<<i+1<<" Element  :";
					int x ;
                    cin>>x;
                    char location;
                    cout<<"Enter Where you want to push : ";
                    cin>>location;
                    if(location == 'r' || location =='R'){
                        push(queue, x);
                    }
                    if(location =='f' || location == 'F'){
                        push(queue, x, false);

				    }
                }
                break;

            case 2: {
                cout << "Enter the No of Time to Pop: ";
                int x;
                cin>>x;
                char position;
                cout<<"Enter the Location :";
                cin>>position;
                if(position == 'r'|| position =='R'){
                    pop(queue, x, false);
                }
                if(position == 'f' || position == 'F'){
                    pop(queue, x);
                }
				break;

            }
            case 3:
                display(queue);
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
