//:SIZE.CPP -- Object sizes vs. virtual funs
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
	cout<<"int: "<<sizeof(int)<<endl;
	cout<<"no_virtual: "<<sizeof(no_virtual)<<endl;
	cout<<"void*: "sizeof(void*)<<endl;
	cout<<"one_virtual: "<<sizeof(one_virtual)<<endl;
	cout<<"two_virtual: "<<sizeof(two_virtual)<<endl;

}
