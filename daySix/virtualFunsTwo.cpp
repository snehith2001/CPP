#include <iostream>
using namespace std;
class B{
public:
	virtual	void fun(){cout<<"B::fun()"<<endl;}
	virtual void funOne(){cout<<"B::funOne()"<<endl; }
	virtual void funTwo(){cout<<"B::funTwo()"<<endl; }
};
class D:public B{
public:
	void fun(){cout<<"D::fun()"<<endl;}
	void funTwo(){cout<<"D::funTwo()"<<endl; }
};

using FPTR = void (*)(); // C++ Style

void funCaller(B &b){
	long *vptr = (long *)(&b);
	FPTR *vtbl = (FPTR *) (*vptr);
	vtbl[0](); //
	vtbl[1](); //
	vtbl[2](); //
	cout<<"-----------------------------------"<<endl;
}

int main(){
	B b;
	D d;
	funCaller(b);
	funCaller(d);
}
