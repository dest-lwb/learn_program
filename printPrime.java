public class javatest{
	public static void main(String[] args){
		System.out.println("Prime number is coming");	
		int m = 10000;
		int n = 0;
		int primeNumber = 0;
		boolean isPrime;

		while(n < m ){
			isPrime = true;//�Ƿ��������ı�־
			int s = (int)Math.sqrt(n);//��n������
			for( int i=s; i>1; i-- ){//n����ÿ����n������С��1�����Ȼ��
				if( n % i == 0 ){//������ܱ������ģ���������
					isPrime=false;
					break;//�˳�forѭ��
				}
			}
			if( isPrime ){//��������������ӡ����
				System.out.print(n+" ");
				primeNumber++;//��¼�����ĸ���
				if( primeNumber % 10 == 0)//���10����������
					System.out.println();
			}
			n++;
		}
	}
}

/*boolean isPrime(int n){//�ж�n�Ƿ�������
	
	int s=(int)Math.sqrt(n);//��n������
	
	for(int i=s;i>1;i--){//n����ÿ����n������С��1�����Ȼ��
		if(n%i==0){//������ܱ������ģ���������
			return false;
		}
	}
	return true;
}
*/