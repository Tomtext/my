#include <iostream> 
#include <stdexcept>
#include <string>
#include<cstring>
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
	bool empty()const;
	
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
bool Queue<T>::empty()const{
	return size==0;
}
template <typename T>
T Queue<T>::getFront()const{
	if(front==NULL){
		throw std::underflow_error("Queue is Empty");
	}
	return front->data;	
}
int team[1000000];
int main(){
	int t;
	int cases=0;
	while(cin>>t&&t){
		++cases;
		memset(team,0,sizeof(team));
		for(int i=1;i<=t;++i){
			int n;
			cin>>n;
			while(n--){
				int x;
				cin>>x;
				team[x]=i;
			}
		}
		Queue<int>q[1001];
		int s=0,e=0;
		string str;
		cout<<"Scenario #"<<cases<<endl; 
		while(cin>>str){
			if(str=="STOP")break;
			if(str=="ENQUEUE"){
				int x,i;
				cin>>x;
				for(i=s;i<e;++i){
					if(team[q[i].getFront()]==team[x]){
						break;
					}
				}
				q[i].emqueue(x);
				if(i==e){
					++e;
				}
			}else{
				int val=q[s].dequeue();
				if(q[s].getSize()==0){
					++s;
				}
				cout<<val<<endl;
			}
		}
		cout<<endl;
	}
	
}
