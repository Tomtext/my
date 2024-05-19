#include <iostream>
#include <stdexcept>
using namespace std;
#define eleType int
struct ListNode{
	ListNode*next;
	int data;
	ListNode(eleType x):data(x),next(NULL){}
};
class LinkedList{
private:
	ListNode *head;
	int size;
public:
	LinkedList():head(NULL),size(0){}
	~LinkedList();
	void insert(int i,eleType value);
	void remove(int i);
	ListNode*get(int i);
	ListNode*find(eleType value);
	void update(int i,eleType value);
	void print();
	
	
};
LinkedList::~LinkedList(){
	ListNode*curr=head;
	while(curr!=NULL){
		ListNode*tmp=curr;
		curr=curr->next;
		delete tmp; 
	}
}
void LinkedList::insert(int i,eleType value){
	if(i<0||i>size){
		throw std::out_of_range("isvalid position");
	}
	ListNode*newNode=new ListNode(value);
	if(i==0){
		newNode->next;
		newNode=head;
	}else{
		ListNode*curr=head;
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
		throw std::out_of_range("isvalid position");
	}
	if(i==0){
		ListNode*tmp=head;
		head=head->next;
	}else{
		ListNode*curr=head;
		for(int j=0;j<i-1;j++){
			curr=curr->next;
		}
		ListNode*tmp=curr->next;
		curr->next=tmp->next;
		delete tmp;
	}
	--size;
}
ListNode *LinkedList::get(int i){
	if(i<0||i>=size){
		throw std::out_of_range("isvalid position");
	}
	ListNode*curr=head;
	for(int j=0;j<i-1;j++){
		curr=curr->next;
	}
	return curr;
}
ListNode*LinkedList::find(eleType value){
	ListNode*curr=head;
	while(curr&&curr->data!=value){
		curr=curr->next;
	}
	return curr;
	
}
void LinkedList::update(int i,eleType value){
	get(i)->data=value;
	
}
void LinkedList::print(){
	ListNode*curr=head;
	while(curr){
		cout<<curr->data<<" ";
		curr=curr->next;
	}
	cout<<endl;
}
int main(){
	LinkedList list;
	list.insert(0,20);
	list.insert(1,30);
	list.print();
}
