#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,C=26;
struct SAM{
	int trans[N<<1][C],len[N<<1],fa[N<<1],tot=1;//lenΪ�ڵ�ɱ�ʾ����Ӵ����ȣ�faָ��endpos������ǰ�ڵ������ڵ� 
//	SAM(){memset(this,0,sizeof(SAM)),tot=1;}
	int add(int c,int last){
		if(trans[last][c]&&len[last]+1==len[trans[last][c]])return trans[last][c];
		int p=last,np=++tot,nq;
		len[np]=len[p]+1;//npΪ�µ�������Ӧ�Ľڵ� 
		while(p&&!trans[p][c])trans[p][c]=np,p=fa[p];
		if(!p){fa[np]=1;return np;}
		int q=trans[p][c];//q�ڵ����ԭ�����ֹ����´������׺ 
		if(len[q]==len[p]+1)fa[np]=q;//���q�ڵ��Ӧ�����д���Ϊ��׺�Ͳ����½��ڵ� 
		else{//���򽫺�׺��q�ڵ�ת�Ƶ�nq�� 
			if(len[p]+1==len[np])nq=np,fa[nq]=fa[q],fa[q]=nq;
			else nq=++tot,len[nq]=len[p]+1,fa[nq]=fa[q],fa[q]=fa[np]=nq;
			for(int i=0;i<C;i++)trans[nq][i]=trans[q][i];
			while(p&&trans[p][c]==q)trans[p][c]=nq,p=fa[p];
		}
		return np;
	}
}S;
char s[N];
int main(){
	int n,last;scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",&s);last=1;
		for(int j=0;s[j];j++)last=S.add(s[j]-'a',last);
	}
	long long ans=0;
	for(int i=2;i<=S.tot;i++)ans+=S.len[i]-S.len[S.fa[i]];
	printf("%lld\n",ans);
	return 0;
}
