//编程范式11 Programming Paradigms CS107 lecture 11
//c++ and assembly

// swap in c
void foo()
{
	int x;
	int y;
	x = 11;
	y = 17;
	swap(&x, &y);
}

void swap(int* ap, int* bp)
{
	int temp = *ap;
	*ap = *bp;
	*bp = temp;
}
//---------------
	SP = SP - 8;
	M[SP + 4] = 11;
	M[SP] = 17;

	R1 = SP; //&y
	R2 = SP + 4; //&x
	SP = SP - 8;
	M[SP] = R2;
	M[SP + 4] = R2;
	CALL <swap>;
	SP = SP + 8;

	SP = SP + 8;
	RET

<swap>:
	SP = SP -4;
	
	R1 = M[SP + 8];
	R2 = M[R1];
	M[SP] = R2;
	
	R1 = M[SP + 12];
	R2 = M[R1];
	R3 = M[SP + 8];
	M[R3] = R2;
	
	R1 = M[SP];
	R2 = M[SP + 12];
	M[R2] = R1;
	
	SP = SP + 4;
	RET;

// swap in cpp
void foo()
{
	int x;
	int y;
	x = 11;
	y = 17;
	swap(&x, &y);
}

// cpp swap fun use reference
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//------------------

class binky{
	public:
		int dunky(int x, int y);
		char* minky(int *z){
			int w = *z;
			return slinky + dunky(winky, winky);
		}
	private:
		int winky;
		char* blinky;
		char slinky[8];
};

int main()
{
	int n = 17;
	binky b;
	b.minky(&n);
	//binky::minky(&b, &n);
}

//==============
//static have 76 mean in CPP
class fraction{
	public:
		function(int n, int d = 1);
		//
		//
		//
		void reduce();
	private:
		static int gcd(int x, int y);
};
