/*
Implement using C++. Use classes for each. Make sure warning messages are printed whenever required. (For example: Popping out from an empty queue.)
b. Queues using Linked List (Name for class: QueueLL) (enqueue, dequeue, size, isEmpty)
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
			cout << current->data << "-";
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

class QueueLL{
	public:
	Node* end;
	Node* front;
	DLL l1;
	QueueLL(){
		end=NULL;
		front=NULL;
	}
	//Enqueue
	void Enqueue(int value){
		int nElement=l1.countItems();
    	l1.insertAt(nElement+1,value);
		end=l1.tail;
		if(nElement==0)front=l1.head;
	}
	//Dequeue
	void Dequeue(){
		if(size()==0){
			cout <<"You are popping out from an empty queue!"<< endl;
		}
		else{
			l1.deleteAt(1);
			front=l1.head;
			if(front==NULL) end=NULL;
		}	
	}
	//isEmpty
	bool isEmpty(){
		if(end==NULL) return true;
		return false;
	}
	//size
	int size(){
		return l1.countItems();
	}
	//display
	void display(){
		if(isEmpty()==0) l1.display();
    	else cout << "Empty stack!" << endl;
	}
	//displayFront
	void disFront(){
		if(isEmpty()==false){
    		cout << "Front = " << front->data << endl;
    	}
    	else{
    		cout << "There is no Front, Queue is empty!" << endl;
		}
	}
	//displayEnd
	void disEnd(){
	if(isEmpty()==false){
    		cout << "End = " << end->data << endl;
    	}
    	else{
    		cout << "There is no End, Queue is empty!" << endl;
		}
	}
};

int main(){
	QueueLL q1;
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
