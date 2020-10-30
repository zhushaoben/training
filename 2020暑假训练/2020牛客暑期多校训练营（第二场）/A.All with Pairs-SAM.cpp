#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,mo=998244353,C=26;
typedef unsigned long long uLL;
char s[N*2];
int nex[N*2];
struct SAM{
	int trans[N<<1][C],len[N<<1],fa[N<<1],val[N<<1],tot=1;//len为节点可表示的最长子串长度，fa指向endpos包含当前节点的最近节点 
//	SAM(){memset(this,0,sizeof(SAM)),tot=1;}
	int add(int c,int last){
		if(trans[last][c]&&len[last]+1==len[trans[last][c]])return val[trans[last][c]]++,trans[last][c];
		int p=last,np=++tot,nq;
		len[np]=len[p]+1;//np为新的整串对应的节点 
		while(p&&!trans[p][c])trans[p][c]=np,p=fa[p];
		if(!p){fa[np]=1;return val[np]++,np;}
		int q=trans[p][c];//q节点包含原串出现过的新串的最长后缀 
		if(len[q]==len[p]+1)fa[np]=q;//如果q节点对应的所有串都为后缀就不用新建节点 
		else{//否则将后缀从q节点转移到nq中 
			if(len[p]+1==len[np])nq=np,fa[nq]=fa[q],fa[q]=nq;
			else nq=++tot,len[nq]=len[p]+1,fa[nq]=fa[q],fa[q]=fa[np]=nq;
			for(int i=0;i<C;i++)trans[nq][i]=trans[q][i];
			while(p&&trans[p][c]==q)trans[p][c]=nq,p=fa[p];
		}
		return val[np]++,np;
	}
}S;
int main(){
	int n,l=0,r,ans=0,last=1;scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",s+(++l));
		last=1,nex[l-1]=l-2;
		for(r=l;s[r];r++)last=S.add(s[r]-'a',last);
		nex[r]=r+1;
		for(l=--r;s[l];l--){
			int p=nex[l+1];
			while(p<=r+1&&s[p-1]!=s[l])p=nex[p];
			nex[l]=p-1;
		}
		l=r+1;
	}
	l=0;
	for(int i=0;i<n;i++){
		int p=1,pre;
		for(r=(++l);s[r];r++)p=S.trans[p][s[r]-'a'];
		while(p)
			pre=r-nex[r-S.len[p]],ans=(ans+(1ll*S.len[p]*S.len[p]-1ll*pre*pre)%mo*S.val[p]%mo)%mo,p=S.fa[p];
		l=r;
	}
	printf("%d",(ans+mo)%mo);
	return 0;
}
