#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,Si=26;
struct palindromic_tree{
	int next[N][Si],
	fail[N],//失配指针 
	cnt[N],//个数 
	num[N],//种类数 
	len[N],//节点长度 
	S[N],
	last,n,p;
	int newnode(int l){//新建节点 
		for(int i=0;i<Si;i++)next[p][i]=0;
		cnt[p]=num[p]=0,len[p]=l;
		return p++;
	}
	void init(){
		p=n=last=0;
		newnode(0),newnode(-1);
		S[0]=-1,fail[0]=1;
	}
	int get_fail(int x){
		while(S[n-len[x]-1]!=S[n])x=fail[x];
		return x;
	}
	void add(int c){
		S[++n]=c;
		int cur=get_fail(last);
		if(!next[cur][c]){
			int now=newnode(len[cur]+2);
			fail[now]=next[get_fail(fail[cur])][c];
			next[cur][c]=now,num[now]=num[fail[now]]+1;
		}
		cnt[last=next[cur][c]]++;
	}
	void count(){//计算cnt 
		for(int i=p-1;i>=0;i--)cnt[fail[i]]+=cnt[i];
	}
};
int main(){
	return 0;
} 
