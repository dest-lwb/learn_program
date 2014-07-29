//stack.h  type int

typedef struct{
	int *elems;
	int logLength;
	int allocLength;	
} stack;

void StackNew(stack *s);
void StackDispose(stack *s);
void StackPush(stack *s, int value);
int StackPop(stack *s);

//stack.c

void StackNew(stack *s)
{
	s->logLength = 0;
	s->allocLength = 4;
	s->elems = malloc(4 * sizeof(int));
	assert(s->elems != NULL);
}

void StackDispose(stack *s)
{
	free(s->elems); //no need to free(s)
}

void StackPush(stack *s, int value)
{
	if(s->logLength == s->allocLength){
		s->allocLength *= 2;
		s->elems = realloc(s->elems, s->allocLength*sizeof(int));
		assert(s->elems != NULL);		
	}
}

void Stack(stack *s)
{
	assert(s->logLength > 0);
	s->logLength--;
	return s->elems[s->logLength];
}

/* ------------------------------------------*/
//编程范式6
//stack.h
typedef struct{
	void *elems;
	int elemSize;
	int logLength;
	int allocLength;
} stack;

void StackNew(stack *s, int elemSize);
void StackDispose(stack *s);
void StackPush(stack *s, void *elemAddr);
int StackPop(stack *s, void *elemAddr);

//stack.c
void StackNew(stack *s, int elemSize)
{
	assert(s->elemSize > 0);
	s->logLength = 0;
	s->allocLength = 4;
	s->elems = malloc(4 * elemSize);
	assert(s->elems != NULL);
}

void StackDispose(Stack *s)
{
	// look line 124
	//
	//
	free(s->elems);
}

void StackPush(stack *s, void *elemAddr)
{
	if(s->logLength == s->allocLength){
		StackGrow(s);
	}
	void *target = (char*)s->elems +s->logLength*s->elemSize;
	memcpy(target, elemAdddr, s->elemSize);
	s->logLength++;
}

void  StackPop(stack *s, void *elemAddr)
{
	void *source = (char*)s->elems + (s->logLength - 1)*s->elemSize;
	memcpy(elemAddr, source, s->elemSize);
	s->logLength--;	
}

static void StackGrow(stack *s)
{
	s->allocLength *= 2;
	s->elems = realloc(s-elems, s->allocLength*s->elemSize);
}

/* ------------------------------------------*/
//编程范式7
//stack.h
typedef struct{
	void *elems;
	int elemSize;
	int logLength;
	int allocLength;
	void (*freeFn)(void*)
} stack;

//void StackNew(stack *s, int elemSize);
void StackNew(stack *s, int elemSize, void (*freeFn)(void*));
void StackDispose(stack *s);
void StackPush(stack *s, void *elemAddr);
int StackPop(stack *s, void *elemAddr);

//stack.c
void StackNew(stack *s, int elemSize, void (*freeFn)(void*))
{
	
}

void StackDispose(stack *s)
{
	if(s->freeFn != NULL){
		for(int i=0; i<s->logLength; i++){
			s->freeFn((char*)s->elems + i*s->elemSize);
		}
	}
	s->free(elems);
}

void StringFree()
{
	free(*(char**)elem)
}
// main
int main(int argc, char* argv[]) //char** argv
{
	const char* friend[] = {"Ai", "Bob", "Carl"};
	stack stringStack;
	StackNew(&stringStack, sizeof(char*));
	for(int i=0; i<3; i++){
		char* copy = strdup(friend[i]);
		StackPush(&stringStack, &copy);
	}
	
	//=============
	char* name;
	for(int i=0; i<3; i++){
		StackPop(&stringStack, &name);
		printf("%s\n", name);
		free(name);
	}
	StackDispose(&stringStack);
}

//===============================
//    ________________________________
//   |  g f s  f s  a s |             | 
//  front             middle         end
//votate 函数

void votate(void *front, void *middle, void *end)
{
	int frontSize = (char*)middle - (char*)front;
	int backSize = (char*)end - (char*)middle;
	char buffer[frontSize];
	memcpy(buffer, front, frontSize);
	memmove(front, middle, backSize);
	memcpy((char*)end - frontSize, buffer, frontSize); // ?frontSize front ?
}

//quick sort function
void qsort(void* base, int size, int elemSize, int (*cmpfn)(void*, void*));
