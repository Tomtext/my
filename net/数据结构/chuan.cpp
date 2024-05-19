#include <iostream> 
#include <cstring>
using namespace std;
class String{
private:
	char*str;
	size_t length;
public:
	String();
	String(const char*s);
	~String();
	String(const String&s);
	size_t getlength()const;
	char operator[](size_t index)const;
	String&operator=(const String&s);
	bool operator==(const String&s)const;
	bool operator!=(const String&s)const;
	String copy()const;
	String operator+(const String&s)const;
	friend ostream&operator<<(ostream&out,const String&s);
	
};
String::String(){
	length=0;
	str=new char[1];
	str[0]='\0';
}
size_t String::getlength()const{
	return length;
}
char String::operator[](size_t index)const{
	return str[index];
}
String::~String(){
	delete []str;
}
bool String::operator==(const String&s)const{
	return strcpy(str,s.str)==0;
}
bool String::operator!=(const String&s)const{
	return strcpy(str,s.str)!=0;
}
String&String::operator=(const String&s){
	if(this!=&s){
		delete []str;
		length=s.length;
		str=new char[length+1];
		strcpy(str,s.str);
	}
	return *this;
}
String String::operator+(const String&s)const{
	String result;
	result.length=length+s.length;
	result.str=new char[result.length+1];
	strcpy(result.str,str);
	strcat(result.str,s.str);
	return result;	
}
String::String(const char*s){
	length=strlen(s);
	str=new char[length+1];
	strcpy(str,s);
}
ostream& operator<<(ostream&out,const String&s){
	out<<s.str;
	return out;
}
String String::copy()const{
	String s=*this;
	return s;
}
String::String(const String&s){
	length=s.length;
	str=new char[length+1];
	strcpy(str,s.str);
}
