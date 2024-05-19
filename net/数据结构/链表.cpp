#include <iostream> 
#include <stdexcept>
using namespace std;
#define eleType int
struct ListNode{
	eleType data;
	ListNode *next;
	ListNode(eleType x):data(x),next(NULL){}
};
class LinkedList{
private:
	ListNode* head;
	int size;
public:
	LinkedList():head(NULL),size(0){}
	~LinkedList();
	void insert(int x,eleType value);
	void remove(int i);
	ListNode* find(eleType value);
	ListNode* get(int i);
	void update(int i,eleType value);
	void print();
	eleType sum();
	void append(eleType value);
	void ascInsert(eleType value);
		
};
LinkedList::~LinkedList(){
	ListNode *curr=head;
	while(curr!=NULL){
		ListNode *tmp=curr;
		curr=curr->next;
		delete tmp;
	}
}
void LinkedList::insert(int i, eleType value){
	if(i<0||i>size){
		throw std::out_of_range("Invalid position");
	}
	ListNode *newNode=new ListNode(value);
	if(i==0){
		newNode->next=head;
		head=newNode;
	}else{
		ListNode *curr=head;
		for(int j=0;j<i-1;j++){
			curr=curr->next;
		}
		newNode->next=curr->next;
		curr->next=newNode;
	}
	++size;
}
void LinkedList::remove(int i){
	if(i<0||i>=size){
		throw std::out_of_range("Invalid position");
	}
	if(i==0){
		ListNode *tmp=head;
		head=head->next;
		delete tmp;
	}else{
		ListNode *curr=head;
		for(int j=0;j<i-1;j++){
			curr=curr->next;
		}
		ListNode *tmp=curr->next;
		curr->next=tmp->next;
		delete tmp;
	}
	--size;
}
ListNode *LinkedList::find(eleType value){
	ListNode *curr=head;
	while(curr && curr->data !=value){
		curr = curr->next;
	}
	return curr;
}
ListNode *LinkedList::get(int i){
		if(i<0||i>=size){
		throw std::out_of_range("Invalid position");
	}
	ListNode *curr=head;
	for(int j=0;j<i;++j){
		curr=curr->next;
	}
	return curr;
}
void LinkedList::update(int i,eleType value){
	get(i)->data=value;
}
void LinkedList::print(){
	ListNode *curr=head;
	while(curr){
		cout<<curr->data<<" ";
		curr=curr->next;
		
	}
	cout<<endl;
}
eleType LinkedList::sum(){
	ListNode*curr=head;
	int ret=0;
	while(curr!=NULL){
		ret+=curr->data;
		curr=curr->next;
	}
	return ret;
}
void LinkedList::append(eleType value){
	insert(size,value);
}
void LinkedList::ascInsert(eleType value){
	if(size==0){
		insert(0,value);
		return ;
	}
	ListNode*curr=head;
	for(int i=0;i<size;i++){
		if(value<=curr->data){
			insert(i,value);
			return ;
		}
		curr=curr->next;
	}
	insert(size,value);
}
int main(){
	LinkedList list;
	list.insert(0,10);
	list.insert(1,20);
	list.insert(2,30);
	list.insert(3,40);
	list.insert(4,50);
	list.print();
	list.remove(1);
	list.print();
	list.get(2);
	ListNode *tmp=list.find(50);
	cout<<tmp->data<<endl;
	cout<<list.get(3)->data<<endl;
	list.print();
	list.update(2,520);
	list.print();
}
