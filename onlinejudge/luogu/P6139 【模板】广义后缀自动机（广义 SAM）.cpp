#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,C=26;
struct SAM{
	int trans[N<<1][C],len[N<<1],fa[N<<1],tot=1;//len为节点可表示的最长子串长度，fa指向endpos包含当前节点的最近节点 
//	SAM(){memset(this,0,sizeof(SAM)),tot=1;}
	int add(int c,int last){
		if(trans[last][c]&&len[last]+1==len[trans[last][c]])return trans[last][c];
		int p=last,np=++tot,nq;
		len[np]=len[p]+1;//np为新的整串对应的节点 
		while(p&&!trans[p][c])trans[p][c]=np,p=fa[p];
		if(!p){fa[np]=1;return np;}
		int q=trans[p][c];//q节点包含原串出现过的新串的最长后缀 
		if(len[q]==len[p]+1)fa[np]=q;//如果q节点对应的所有串都为后缀就不用新建节点 
		else{//否则将后缀从q节点转移到nq中 
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
