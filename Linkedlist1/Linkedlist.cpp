#include<iostream>
using namespace std;

class Node{
    public:
    int roll;
    float cgpa;
    string name;
    Node* next ;
    Node* prev;
    Node(int roll, float cgpa, string name){
        this->name = name;
        this->roll = roll;
        this->cgpa = cgpa;
        this->next = NULL;
        this->prev = NULL;
    }
};
class Linkedlist{
    public:
    Node* head;
    Node* tail;
    int size;
    Linkedlist(){
      head = tail = NULL; 
      size = 0; 
    }
    void student(int roll, float cgpa, string name){
        Node* temp = new Node(roll, cgpa, name);
        if(head == NULL){
            head = tail = temp;   
        }
        else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    void InsertAtBeginning(int roll, float cgpa, string name){
        Node* temp = new Node(roll, cgpa, name);
        if(head == NULL){
            head = tail = temp;
        }
        else{
            temp->next = head;
            
        }
    }

    void display(){
        Node* temp = head;
        Node* pre = head;
        while(temp != NULL){
            pre = temp;
            cout<<"("<< temp->roll<<" "<< temp->name<<" "<< temp->cgpa<<")"<<"->";
            temp = temp->next;
        }
        cout<<"NULL";
        cout<<endl<<"\n";
        while(pre != NULL){
            cout<<"("<<pre->roll<<" "<< pre->name<<" "<<pre->cgpa<<")"<<"->";
            pre = pre->prev;
        }
        cout<<"NULL";
        cout<<endl<<"\n";
    }
    

};
int main(){
    int n;
    cout<<"The No of Nodes in the linkedlist: ";
    cin>>n;
    int roll;
    float cgpa;
    string name;
    Linkedlist info;

    for(int i= 0; i<n ;i++){
        cout << "Enter student details for student " << i + 1 << ":\n";
        cout << "Roll No: ";
        cin >> roll;
        cin.ignore();
        cout << "Name: ";
        getline(cin, name);
        cout << "CGPA: ";
        cin >> cgpa;

        info.student( roll, cgpa, name);
        cout << endl;
    }
    info.display();

}