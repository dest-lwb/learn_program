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
