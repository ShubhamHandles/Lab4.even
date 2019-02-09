/*
d. Queues using Arrays (Name for class: QueueArr)
*/

#include<iostream>
using namespace std;

class QueueArr{
	public:
	int Arr[50];
	int front, end;
	QueueArr(){
		front=-1;
		end=-1;
	}
	//Enqueue
	void Enqueue(int value){
		Arr[end+1]=value;
		end++;
		if(end==0) front=0;
	}
	//Dequeue
	void Dequeue(){
		if(isEmpty()==1){
			cout << "You are popping out from an empty queue!" << endl;
		}
		else{
			if(front==end){
				front=-1;
				end=-1;
			}
			else front++;
		}
	}
	//isEmpty
	bool isEmpty(){
		if(front==-1 and end==-1) return true;
		return false;
	}
	//size
	int size(){
		if(front==-1 and end==-1) return 0;
		else return (end-front+1);
	}
	//Display
	void display(){
		if(isEmpty()==1){
			cout << "Empty queue!" << endl;
		}
		else{
			for(int i=front; i<=end; i++){
				cout << Arr[i] << "-";
			}
			cout << endl;
		}
	}
	//DisplayFront
	void disFront(){
		if(isEmpty()==0) cout << "Front = " << Arr[front] << endl;
		else cout << "Empty queue!, no Front" << endl;
	}
	//DisplayEnd
	void disEnd(){
		if(isEmpty()==0) cout << "End = " << Arr[end] << endl;
		else cout << "Empty queue!, no End" << endl;
	}
};

int main(){
	QueueArr q1;
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

	
	q1.Enqueue(9);
	q1.display();
	q1.Dequeue();
	q1.display();
	
	return 0;
}
