//编程范式9 Programming Paradigms CS107 lecture 9
int i;
int j;
i = 10;
j = i + 7;
j++;
//-------------

	M[R1+4] = 10;   // store operation

	R2 = M[R1+4];   // load operation
	R3 = R2 + 7;    // ALU operation
	M[R1] = R3;     // store operation

	// j++
	R2 = M[R3];
	R2 = R2 + 1;
	M[R1] = R2;
//==============

int i;
short s1;
short s2;
i = 200;
s1 = i;
s2 = s1 + 1;

//------------
	M[R1+4] = 200;
	R2 = M[R1+2];
	M[R1+2] = .2R2;
	R2 = .2M[R1+2];
	R3 = R2 + 1;
	M[R1] = .2R3;

//==============

int array[4];
int i;
for(int i=0; i<4; i++){
	array[i] = 0;
}
i--;

//--------
	M[R1] = 0;

	R2 = M[R1];
	BGE R2, 4, PC+40;
	R3 = M[R1];
	R4 = R3*4;
	R5 = R1 + 4;
	R6 = R4 + R5;
	M[R6] = 0;

	R2 = M[R1];
	R2 = R2 + 1;
	M[R1] = R2;
	JMP PC-10;

//i--

//==================
struct fraction{
	int num;
	int denom;
};

struct fraction pi;
pi.num = 22;  // => M[R1] = 22
pi.denom = 7;  // =>M[R1+4] = 7;

((struct fraction*)&pi.denom)->denom = 451; // =>M[R1+8] = 451;

//编程范式10 Programming Paradigms CS107 lecture 10

void foo(int bar, int* baz)
{
	char snink[4];
	short why;
	why = (short*)snink+2;
	why = 50;
}

int main(int argc, char** argv)
{
	int i = 4;
	foo(i, &i);
	return 0;	
}

//---------
	SP = SP + 4;
	M[SP+4] = 4;
	SP = SP - 8;
	R1 = M[SP-8];
	R2 = SP + 8;
	M[SP] = R1;
	M[SP+4] = R2;
	CALL <foo>;
	SP = SP + 8;

foo:
	SP = SP - 8;

	R1 = SP + 6;
	M[SP] = R1;

	R1 = M[SP];
	M[R1] = .2 50;
	SP = SP + 8；
	RET;

//===============
int fact(int n)
{
	if( n == 0 ){
		return 1;
	}
	return n * fact(n-1);
}

<fact>:  
	R1 = M[PC+4];
	BNE R1, 0, PC+12;
	RV = 1;
	RET;
	R1 = M[SP+4];
	R1 = R1 - 1;
	SP = SP - 4;
	M[SP] = R1;
	CALL <fact>;
	SP = SP + 4;
	R1 = M[SP+4];
	RV = RV * R1;
	RET;
