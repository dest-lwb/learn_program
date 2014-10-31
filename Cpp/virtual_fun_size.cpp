//:SIZE.CPP -- Object sizes vs. virtual funs
#include<iostream>
using namespace std;

class no_virtual{
	int a;
public:
	void x() const{}
	int i() const{ return 1; }
};

class one_virtual{
	int a;
public:
	virtual void x() const {}
	int i() const { return 1; }
	virtual ~one_virtual();
};

class two_virtuals{
	int a;
public:
	virtual void x() const {}
	virtual int i() const { return 1; }
	virtual ~two_virtuals();
};

int main(){
	cout<<"int: "<<sizeof(int)<<endl;                    // out:int: 4
	cout<<"no_virtual: "<<sizeof(no_virtual)<<endl;      // out:no_virtual:4
	cout<<"void*: "<<sizeof(void*)<<endl;                // out:void*: 8
	cout<<"one_virtual: "<<sizeof(one_virtual)<<endl;    // out:one_virtual: 16
	cout<<"two_virtuals: "<<sizeof(two_virtuals)<<endl;  // out:two_virtuals: 16

}
