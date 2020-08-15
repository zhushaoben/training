#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5,Si=26;
struct palindromic_tree{
	int next[N][Si],
	fail[N],
	cnt[N],
	num[N],//种类数
	len[N],
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
	void count(){
		for(int i=p-1;i>=0;i--)cnt[fail[i]]+=cnt[i];
	}
}A;
char s[N];
int main(){
	scanf("%s",s);A.init();
	for(int i=0;s[i];i++)A.add(s[i]-'a');
	A.count();
	long long ans=0;
	for(int i=A.p-1;i>=0;i--)ans=max(ans,1ll*A.cnt[i]*A.len[i]);
	printf("%lld\n",ans);
	return 0;
} 
