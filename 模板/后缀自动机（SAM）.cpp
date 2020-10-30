#define PACKAGE 1

#if PACKAGE
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,C=26;
struct SAM{
	int trans[N<<1][C],len[N<<1],fa[N<<1],tot=1,last=1;//len为节点可表示的最长子串长度，fa指向endpos包含当前节点的最近节点 
	void add(int c){
		int p=last,np=last=++tot,nq,q;
		len[np]=len[p]+1;//np为新的整串对应的节点 
		while(p&&!trans[p][c])trans[p][c]=np,p=fa[p];
		if(!p){fa[np]=1;return;}
		q=trans[p][c];//q节点包含原串出现过的新串的最长后缀 
		if(len[q]==len[p]+1)fa[np]=q;//如果q节点对应的所有串都为后缀就不用新建节点 
		else{//否则将后缀从q节点转移到nq中 
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
	int ch[26],len,fa;//len为节点可表示的最长子串长度，fa指向endpos包含当前节点的最近节点 
	SAM(){memset(this,0,sizeof(SAM));}
}a[N<<1];
int last=1,tot=1;//last为当前自动机整串对应的节点 
void add(int c){
	int p=last,np=last=++tot;
	a[np].len=a[p].len+1;//np为新的整串对应的节点 
	while(p&&!a[p].ch[c])a[p].ch[c]=np,p=a[p].fa;
	if(!p){a[np].fa=1;return;}
	int q=a[p].ch[c];//q节点包含原串出现过的新串的最长后缀 
	if(a[q].len==a[p].len+1)a[np].fa=q;//如果q节点对应的所有串都为后缀就不用新建节点 
	else{//否则将后缀从q节点转移到nq中 
		int nq=++tot;a[nq]=a[q];
		a[nq].len=a[p].len+1,a[q].fa=a[np].fa=nq;
		while(p&&a[p].ch[c]==q)a[p].ch[c]=nq,p=a[p].fa;
	}
}
int main(){
	
	return 0;
}
#endif
