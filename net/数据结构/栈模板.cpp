#include <iostream> 
#include <stdexcept>
using namespace std;
template<typename T>
class Stack{
private:
	T *data;
	int size;
	int capacity;
	void resize();
public:
	Stack():data(new T[capacity]),size(0),capacity(0){}
	~Stack();
	void push(T element);
	T pop();
	T top()const;
	int getSize()const;
	
	
	
};
template<typename T>
Stack<T>::~Stack(){
	delete []data;
}
template<typename T>
void Stack<T>::resize(){
	int newCapacity=capacity*2;
	T*newData=new T[newCapacity];
	for(int i=0;i<size;++i){
		newData[i]=data[i];
	}
	delete []data;
	data=newData;
}
template<typename T>
void Stack<T>::push(T element){
	if(size==capacity){
		resize();
	}
	data[size++]=element;
}
template<typename T>
T Stack<T>::pop(){
	if(size==0){
		throw std::underflow_error("Stack is Empty");
	}
	return data[--size];
}
template<typename T>
T Stack<T>::top()const{
	if(size==0){
		throw std::underflow_error("Stack is Empty");
	}
	return data[size-1];
}
template<typename T>
int Stack<T>::getSize()const{
	return size;
}
int main(){
	Stack<int>stack1;
	stack1.push(4);
	stack1.push(7);
	stack1.push(13);
	cout<<stack1.top()<<endl;
	stack1.push(17);
	cout<<stack1.top()<<endl;
	stack1.pop();
	stack1.pop();
	cout<<stack1.getSize()<<endl;
}
