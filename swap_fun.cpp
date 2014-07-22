//版本1：交换两个int类型变量值

void swap(int *ap, int *bp){
	int temp = *ap;
	*ap = *bp;
	*bp = temp;
}

//版本2，通用交换变量值

void swap(void *vp1, void *vp2, int size){
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