#include <iostream>
using namespace std;
#define eleType double 
struct Sequentialist{
	eleType *elements;
	int size;
	int capacity;
	
};
void ininitialist(Sequentialist *list,int capacity){
	list->elements=new eleType[capacity];
	list->size=0;
	list->capacity=capacity;
	
}
void destroyList(Sequentialist*list){
	delete[]list->elements;
}
int size(Sequentialist*list){
	return list->size;
	
}
bool isEmpty(Sequentialist*list){
	return list->size==0;
}
void insert(Sequentialist*list,int index,eleType element){
	if(index<0||index>list->size){
		throw std::invalid_argument("invalid Argument");
	}
	if(list->size==list->capacity){
		int newcapacity=list->capacity*2;
		eleType *newelements=new eleType[newcapacity];
		for(int i=0;i<list->size;++i){
			newelements[i]=list->elements[i];
		}
		delete[]list->elements;
		list->elements=newelements;
		list->capacity=newcapacity;
		
	}
	for(int i=list->size;i>index;--i){
		list->elements[i]=list->elements[i-1];
		
	}
	list->elements[index]=element;
	list->size++;
	
	
}
void deleteElements(Sequentialist*list,int index){
	if(index<0||index>=list->size){
			throw std::invalid_argument("invalid Argument");
		}
		for(int i=index;i<list->size-1;++i){
			list->elements[i]=list->elements[i+1];
			
		}
		list->size--;
}
int findELements(Sequentialist*list,eleType element){
	for(int i=0;i<list->size;++i){
		if(list->elements[i]==element){
			return i;
		}
	}
	return -1;
}
eleType getElements(Sequentialist*list,int index){
		if(index<0||index>=list->size){
				throw std::invalid_argument("invalid Argument");
			}
	return list->elements[index];
	
}
void updateElements(Sequentialist *list,int index,eleType value){
		if(index<0||index>=list->size){
				throw std::invalid_argument("invalid Argument");
			}
	 list->elements[index]=value;
		
}
int main(){
	int n;
	while(cin>>n&&n){
		Sequentialist s;
		ininitialist(&s,1);
		for(int i=0;i<n;++i){
			eleType x;
			cin>>x;
			insert(&s,i,x);
		}
		int pcnt=0,zcnt=0,ncnt=0;
		for(int i=0;i<s.size;++i){
			eleType ele=getElements(&s,i);
			if(ele>1e-8){
				++pcnt;
			}
			else if(ele<-1e-8){
				++ncnt;
			}
			else{
				++zcnt;
			}
		}
		cout<<ncnt<<' '<<zcnt<<' '<<pcnt<<endl;
	}
}
