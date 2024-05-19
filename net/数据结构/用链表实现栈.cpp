#include <iostream> 
#include <stdexcept>
using namespace std;
template <typename T>
class Stack{
private:
	struct Node{
		Node*next;
		T data;
		Node(T d):data(d),next(NULL) {}
	};
	Node*head;
	int size;
public:
	Stack():head(NULL),size(0){}
	~Stack();
	void push(T element);
	T pop();
	T top()const;
	int getSize()const;
	bool empty()const;
};
template <typename T>
Stack<T>::~Stack(){
	while(head){
		Node*tmp=head;
		head=head->next;
		delete tmp;
	}
}
template <typename T>
void Stack<T>::push(T element){
	Node*newNode=new Node(element);
	newNode->next=head;
	head=newNode;
	++size;
}
template <typename T>
T Stack<T>::pop(){
	if(head==NULL){
		throw std::underflow_error("Stack is Empty");
	}
	T result=head->data;
	Node*tmp=head;
	head=head->next;
	delete tmp;
	--size;
	return result;	
	
}
template <typename T>
T Stack<T>::top()const{
	if(head==NULL){
		throw std::underflow_error("Stack is Empty");
	}
	return head->data;	
}
template <typename T>
int Stack<T>::getSize()const{
	return size;
}
template <typename T>
bool Stack<T>::empty()const{
	return size==0;
}
int main(){
	Stack<int>s1;
	s1.push(4);
	s1.push(13);
	cout<<s1.top()<<endl;
}
