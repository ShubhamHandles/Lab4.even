/*
c. Stacks using Arrays (Name for class: StackArr)
*/

#include<iostream>
using namespace std;

class StackArr{
	public:
	int Arr[50];
	int Top;
	StackArr(){
		Top=-1;
	}
	//push
	void push(int value){
		Arr[Top+1]=value;
		Top++;
	}
	//pop
	void pop(){
		if(isEmpty()==1){
			cout << "You are popping out from an empty stack!" << endl;
		}
		else{
			Top--;
		}
	}
	//size
	int size(){
		return Top+1;
	}
	//isEmpty
	bool isEmpty(){
		if(Top==-1) return true;
		else return false;
	}
	//displayTop
	void disTop(){
		if(isEmpty()==0) cout << "Top = " << Arr[Top] << endl;
		else cout << "Empty stack!, no Top" << endl;
	}
	//display
	void display(){
		if(isEmpty()==1){
			cout << "Empty stack!" << endl;
		}
		else{
			for(int i=0; i<=Top; i++){
				cout << Arr[i] << "-";
			}
			cout << endl;
		}
	}
};

int main(){
	StackArr s1;
	for(int i=1;i<6;i++){
		s1.push(i);
		s1.display();
	}
	s1.disTop();
	
	s1.pop();
    s1.display();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display(); 
	s1.pop();
    s1.display();
    
    s1.disTop();
    
    s1.push(9);
    s1.display();
    
	return 0;
}
