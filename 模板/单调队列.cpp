#include<cstdio>
#define maxk 2000001//maxkΪ������������� 
struct HumdrumQueue{
	int s,t,k,a[maxk],id[maxk];//aΪ�洢���ݣ�idΪ���˳��,s,t�ֱ�Ϊ����,��β+1,kΪ�������ڳ��� 
	int top(){//���ض��� 
		if(s==t)return 0;//Ϊ�վͷ���0 
		return a[s];
	}
	void pop(){//���׳��� 
		if(s!=t)s++;
	}
	void insert(int x,int i){//����x,��ǰ�ǵ�i������ 
		while(s!=t&&a[t-1]>=x){//��β�����㵥���ĳ��� 
			t--;
			if(t==-1)t=k;
		}
		if(i-id[s]>=k)pop();//������������ڻ�������,����� 
		a[t]=x,id[t++]=i,t%=maxk;//��Ϊ������Ԫ�ز�����maxk������ʹ��ѭ������ 
	}
}q;

const int N=1e5+5;
struct Q{
	int q[N],id[N],s,t,k;
	void init(){s=t=0;}
	void insert(int x,int i){
		while(s<t&&i-id[s]>=k)s++;
		while(s<t&&x>q[t-1])t--;
		q[t]=x,id[t]=i;t++;
	}
	int top(){return q[s];}
}q;
int main(){
	return 0;
} 
