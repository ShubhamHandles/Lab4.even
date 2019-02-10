/*
2. Implement a queue using two stacks.
[Hint: You already have a stack implemented (Q1). 
Now you have to implement a queue using not the generic setup that you did in Q1 
rather implement it using the functions and data (top pointer) of two stacks]
*/

#include<iostream>
using namespace std;

//define node
class Node{
	public:
	//data
	int data;
	//pointers
	Node* next;
	Node* prev;
	//constructor for the default pointers
	Node(int value){
		next=NULL;
		prev=NULL;
		data=value;
	}	
};

class DLL{
	//chain of nodes
	public:
	//head and tail
	Node* head;
	Node* tail;
	//constructor for default head and tail
	DLL(){
		head=NULL; tail=NULL;
	}
	//insert
	void insert(int data){
		//Node with value
		Node* temp = new Node(data);
		//update head and tail
		//for first node
		if(head==NULL){
			head=temp;
		}
		//for others
		else{
			tail->next=temp;
			temp->prev=tail;
		}
		tail=temp;
	}
	//insertAt
	void insertAt(int pos, int data){
		//if pos exists
		int check=countItems();
		if(pos<=check+1){
			//create the node
			Node * temp = new Node(data);
			if(pos>=2){
				//reach one place before the pos
				Node* current=head;
				for(int i=1;i<pos-1;i++){
					current=current->next;
				}
				//join the node to successor
				temp->next=current->next;
				if(current!=tail){
					current->next->prev=temp;
				}
				//join predecessor
				temp->prev=current;
				current->next=temp;
				//update tail
				if(pos==check+1) tail=temp; 
			}
			else if(pos==1){
				temp->next=head;
				if(head==NULL) tail=temp;
				head=temp;
			}
		}
		//if not
		else{
			cout << "Linked List does not have that many elements" << endl;
		}
	}
	//delete
	void delet(){
		//store tail in temp
		Node* temp=tail;
		//cout << tail->data << endl;
		//reach before tail
		Node* current = head;
		while(current->next!=tail){
			current=current->next;
		}
		//break tail
		current->next=NULL;
		//update tail
		tail= current;
		//delete tail
		delete temp;
	}
	//deleteAt
	void deleteAt(int pos){
		//if pos exists
		int check = countItems();
		if(pos<=check and pos!=1){
			//reach before the pos
			Node* current = head;
			for(int i=1;i<pos-1;i++){
				current=current->next;
			}
			//store next into temp
			Node* temp=current->next;
			if(pos!=1 and pos!=check){
				//join current next to temp next
				current->next = temp->next;
				//join temp next prev to current
				if(current->next!=tail){
					temp->next->prev = current;
				}
			}
			//update tail and head
			else if(pos==check) {
				tail=current; 
				tail->next=NULL;
			}
			else if(pos==1) head=temp->next;
			//delete temp
			delete temp;
		}
		else if(pos==1){
			Node* temp = head;
			head=temp->next;
			delete temp;
		}
		else{
			cout << "Linked List does not have that many elements" << endl;
		}
	}
	//countItems
	int countItems(){
		int count=1;
		Node* current=head;
		if(head==NULL){
			return 0;
		}
		else{
			while(current!=tail){
				count++;
				current=current->next;
			}
			return count;
		}
	}
	//display
	void display(){
		displayR(head); //print from head
		cout << endl;
		cout << "Number of nodes = " << countItems() << endl;
	}
	void displayR(Node* current){
		if(current!=NULL){
			cout << "-" << current->data;
			displayR(current->next); //next node
		}	
	}
	void revDisplay(){
		revDisplay2(head);
		cout << endl;
		cout << "Number of nodes = " << countItems() << endl;
	}
	void revDisplay2(Node* current){
		if(current!=NULL){
			revDisplay2(current->next);
			cout << current->data << "-";
		}
	}
};

class StackLL{
	public:
    Node* top;
    DLL l1;
    StackLL(){
        top=NULL;
    }
    //push
    void push(int value){
    	l1.insertAt(1,value);
    	top=l1.head;
	}
    //pop
    void pop(){
    	if(size()==0){
    		cout << "You are popping out from an empty queue!" << endl; 
		}
		else{
	    	l1.deleteAt(1);
	    	top=l1.head;
	    }
	}
    //size
    int size(){
    	return l1.countItems();
	}
    //isEmpty
    bool isEmpty(){
    	if(top==NULL) return true;
    	return false;
	}
    //topDisplay
    void topDisplay(){
    	if(isEmpty()==false){
    		cout << " " << top->data << endl;
    	}
    	else{
    		cout << " There is no front or end, queue is empty!" << endl;
		}
	}
    //Display
    void display(){
    	if(isEmpty()==0) l1.display();
    	else cout << "Empty Queue!" << endl;
	}
};

class QueueStk{
	public:
	StackLL s1;
	StackLL s2;
	
	//Enqueue
	void Enqueue(int value){
		s1.push(value);
	}
	//Dequeue
	void Dequeue(){
		int counts=s1.size();
		for(int i=1; i<counts; i++){
			s2.push(s1.top->data);
			s1.pop();
		}
		s1.pop();
		for(int i=1; i<counts; i++){
			s1.push(s2.top->data);
			s2.pop();
		}
	}
	//isEmpty
	bool isEmpty(){
		return s1.isEmpty();
	}
	//size
	int size(){
		return s1.size();
	}
	//Display
	void display(){
		s1.display();
	}
	//DisplayFront
	void disFront(){
		int counts=s1.size();
		for(int i=1; i<counts; i++){
			s2.push(s1.top->data);
			s1.pop();
		}
		cout << "Front =";
		s1.topDisplay();
		for(int i=1; i<counts; i++){
			s1.push(s2.top->data);
			s2.pop();
		}
	}
	//DisplayEnd
	void disEnd(){
		cout << "End =";
		s1.topDisplay();
	}
	
};

int main(){
	QueueStk q1;
	
	for(int i=1; i<6; i++){
		q1.Enqueue(i);
		q1.display();
	}
	
	q1.Dequeue();
	q1.display();

	q1.Dequeue();
	q1.display();
	q1.Dequeue();
	q1.display();
	q1.Dequeue();
	q1.display();
	
	q1.disFront();
	q1.disEnd();
	
	q1.Dequeue();
	q1.display();
	
	q1.disEnd();
	
	q1.Dequeue();
	q1.display();
	
	return 0;
}
