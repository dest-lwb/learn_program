/* -------------------------
C++Primer 第四版习题
Exercises Secetion 4.3
解释下列5个定义的含义，指出哪些定义非法
4.19:
    (a) int i;  //int类型的普通变量
	(b) const int ic; //int类型常量，常量必须初始化
	(c) const int *pic; //指向常量的指针
	(d) int *const cpi; //int类型的const指针 ，必须初始化
	(e) const int *const cpic; //指向int类型的const指针，必须初始化
下列哪些初始化是合法的？为什么？
4.20:
	(a)	int i = -1; //yes
	(b)	const int ic = 5; //yes
	(c)	const int *pic = &ic; //yes
	(d)	int *const cpi = &i; //no:不能把常量地址赋给常指针
	(e)	const int *const cpic = &ic; //yes
*/