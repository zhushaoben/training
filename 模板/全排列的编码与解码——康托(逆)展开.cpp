#include<cstdio>
const int fac[]={1, 1, 2, 6, 24, 120, 720, 5040, 40320};//�׳�,�����ÿ����ټ� 
int cantor(int a[],int k){//����չ�� 
	int ans=0,tmp;
	for(int i=0;i<k;i++){
		tmp=0;//��¼�м�������С���� 
		for(int j=i+1;j<k;j++){
			if(a[j]<a[i])tmp++;
		}
		ans+=tmp*fac[k-i-1];
	}
	return ans;
}
void uncantor(int a[],int k,int num){//�濵��չ��
	int b[10];//b��ʾʣ�µ���,���Ұ��������� 
	for(int i=0;i<k;i++)b[i]=i+1;
	b[k]=0;
	for(int i=0,x;i<k;i++){
		x=num/fac[k-i-1],num%=fac[k-i-1],a[i]=b[x];//x��ʾ��ǰ����ʣ�µ����еĵڼ��� 
		for(int j=x;b[j];j++){
			b[j]=b[j+1];
		}
	}
}
int main(){
	return 0;
} 
