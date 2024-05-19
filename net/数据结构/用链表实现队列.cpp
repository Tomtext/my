#include <iostream> 
#include <stdexcept>
using namespace std;
template <typename T>
class Queue{
private:
	struct Node{
		T data;
		Node*next;
		Node(T d):data(d),next(NULL){}
	};
	Node*front;
	Node*rear;
	int size;
public:
	Queue():front(NULL),rear(NULL),size(0){}
	~Queue();
	int getSize()const;
	T getFront()const;
	T dequeue();
	void emqueue(T element);
	
};
template <typename T>
Queue<T>::~Queue(){
	while(front){
		Node*tmp=front;
		front=front->next;
		delete tmp;
	}
}
template <typename T>
void Queue<T>::emqueue(T element){
	if(rear==NULL){
		rear=new Node(element);
		front=rear;
	}
	else{
		rear->next=new Node(element);
		rear=rear->next;
	}
	++size;
}
template <typename T>
T Queue<T>::dequeue(){
	if(front==NULL){
		throw std::underflow_error("Queue is Empty");
	}
	T element=front->data;
	Node*tmp=front;
	front=front->next;
	delete tmp;
	--size;
	if(size==0){
		rear=NULL;
	}
	return element;
	
}
template <typename T>
int Queue<T>::getSize()const{
	return size;
}
template <typename T>
T Queue<T>::getFront()const{
	if(front==NULL){
		throw std::underflow_error("Queue is Empty");
	}
	return front->data;	
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		Queue<int>q1,q2;
		for(int i=1;i<=n;++i){
			q1.emqueue(i);
		}
		while(q1.getSize()>3){
			int cnt=0;
			while(q1.getSize()){
				int v=q1.dequeue();
				++cnt;
				if(cnt%2==1){
					q2.emqueue(v);
				}
			}
			if(q2.getSize()<=3){
				while(q2.getSize()){
					q1.emqueue(q2.dequeue());
				}
				break;
			}
			cnt=0;
			while(q2.getSize()){
				int v=q2.dequeue();
				++cnt;
				if(cnt%3==1||cnt%3==2){
					q1.emqueue(v);
				}
			}
		}
		int flag=0;
		while(q1.getSize()){
			if(flag){
				cout<<' ';
			}
			cout<<q1.dequeue();
			flag++;
		}
		cout<<endl;
	}
}
