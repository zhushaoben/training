#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,C=26;
struct SAM{
	int trans[N<<1][C],len[N<<1],fa[N<<1],si[N<<1],tot=1,last=1;//lenΪ�ڵ�ɱ�ʾ����Ӵ����ȣ�faָ��endpos������ǰ�ڵ������ڵ� 
	void add(int c){
		int p=last,np=last=++tot,nq,q;
		si[np]=1,len[np]=len[p]+1;//npΪ�µ�������Ӧ�Ľڵ� 
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
vector<int>V[N<<1];
char s[N];
long long ans=0;
void dfs(int x){
	for(auto v:V[x]){
		dfs(v);
		S.si[x]+=S.si[v];
	}
	if(S.si[x]!=1)ans=max(ans,1ll*S.si[x]*S.len[x]);
}
int main(){
	scanf("%s",s);
	for(int i=0;s[i];i++)S.add(s[i]-'a');
	for(int i=2;i<=S.tot;i++)V[S.fa[i]].push_back(i);
	dfs(1);
	printf("%lld",ans);
	return 0;
}
