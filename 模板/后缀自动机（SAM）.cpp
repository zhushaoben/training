#define PACKAGE 1

#if PACKAGE
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,C=26;
struct SAM{
	int trans[N<<1][C],len[N<<1],fa[N<<1],tot=1,last=1;//lenΪ�ڵ�ɱ�ʾ����Ӵ����ȣ�faָ��endpos������ǰ�ڵ������ڵ� 
	void add(int c){
		int p=last,np=last=++tot,nq,q;
		len[np]=len[p]+1;//npΪ�µ�������Ӧ�Ľڵ� 
		while(p&&!trans[p][c])trans[p][c]=np,p=fa[p];
		if(!p){fa[np]=1;return;}
		q=trans[p][c];//q�ڵ����ԭ�����ֹ����´������׺ 
		if(len[q]==len[p]+1)fa[np]=q;//���q�ڵ��Ӧ�����д���Ϊ��׺�Ͳ����½��ڵ� 
		else{//���򽫺�׺��q�ڵ�ת�Ƶ�nq�� 
			nq=++tot;
			for(int i=0;i<C;i++)trans[nq][i]=trans[q][i];
			len[nq]=len[p]+1,fa[nq]=fa[q],fa[q]=fa[np]=nq;
			while(p&&trans[p][c]==q)trans[p][c]=nq,p=fa[p];
		}
	}
}S;
int main(){
	return 0;
}
#endif

#if !PACKAGE
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct SAM{
	int ch[26],len,fa;//lenΪ�ڵ�ɱ�ʾ����Ӵ����ȣ�faָ��endpos������ǰ�ڵ������ڵ� 
	SAM(){memset(this,0,sizeof(SAM));}
}a[N<<1];
int last=1,tot=1;//lastΪ��ǰ�Զ���������Ӧ�Ľڵ� 
void add(int c){
	int p=last,np=last=++tot;
	a[np].len=a[p].len+1;//npΪ�µ�������Ӧ�Ľڵ� 
	while(p&&!a[p].ch[c])a[p].ch[c]=np,p=a[p].fa;
	if(!p){a[np].fa=1;return;}
	int q=a[p].ch[c];//q�ڵ����ԭ�����ֹ����´������׺ 
	if(a[q].len==a[p].len+1)a[np].fa=q;//���q�ڵ��Ӧ�����д���Ϊ��׺�Ͳ����½��ڵ� 
	else{//���򽫺�׺��q�ڵ�ת�Ƶ�nq�� 
		int nq=++tot;a[nq]=a[q];
		a[nq].len=a[p].len+1,a[q].fa=a[np].fa=nq;
		while(p&&a[p].ch[c]==q)a[p].ch[c]=nq,p=a[p].fa;
	}
}
int main(){
	
	return 0;
}
#endif
