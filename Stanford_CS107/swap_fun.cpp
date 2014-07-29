//版本1：交换两个int类型变量值

void swap(int *ap, int *bp)
{
	int temp = *ap;
	*ap = *bp;
	*bp = temp;
}

//版本2，通用交换变量值

void swap(void *vp1, void *vp2, int size)
{
	char* buffer[size];
	/***
	memcpy(void *p1, void *p2, int size);
	位拷贝函数
	parm1:目标位置
	parm2:源位置
	parm3:拷贝长度size
	
	***/
	memcpy(buffer, vp1, size); 
	memcpy(vp1, vp2, size);
	memcpy(vp2, buffer,  size);
}

Example:
char* husband *strdup("Fred");
char* wife *strdup("Wilma");

//use like this:
swap(& husband, &wife, sizeof(char*)); //交换指针变量的值即地址

//do not use like this:
swap(husband, wife, sizeof(char*)); //交换的是F和W,即指针所指向的内容(*p)

//线性搜索算法
//版本1: 搜索某个int类型值key在int类型数组中的索引，
int lsearch(int key, int arry[], int size)
{	
	for(int i=0; i<size; i++){
		if(arry[i] == key){
			return i;
		}
	}
	return -1;
}

//版本2: 通用版本
/*	key:搜索值
	base:数组地址
	n:数组大小
	elemSize:元素大小
*/
void *lsearch(void* key, void* base, int n, int elemSize)
{
	for(int i=0; i<n; i++){
		void *elmeAddr = (char*)base + i*elemSize;
		if(memcmp(key, elemAddr, elemSize) == 0){
			return elemAddr;
		}
	}
	return NULL;	
}
//版本3: 第五个参数

void *lsearch( void* key, void* base, int n, int elemSize,
			  int* cpmFn(void*, void*) )
{
	for(int i=0; i<n; i++){
		void *elmeAddr = (char*)base + i*elemSize;
		if(comFn(key, elemAddr) == 0){
			return elemAddr;
		}
	}
	return NULL;
}

//版本3: int 类型

int array[] = {4, 3, 2, 7, 11, 6};
int size = 6;
int number = 7;
int *found(&number, array, 6, sizeof(int), intCmp);

int intCmp(void* elem1, void* elem2)
{
	int *ip1 = elem1;
	int *ip2 = elem2;
	return *ip1 - *ip2;
}

//字符串线性查找
char* notes[] = {"Ab", "F#", "B", "Gb", "D"};
char* favorateNote = "Eb";

char** found = lsearch(&favorateNote, notes, sizeof(char*), StrCmp()); 

//二分法搜索
void *bsearch(void* key, void* base, int n, int elemsize, int (*cmp)(void*, void*))
