#include<cstdio>
using namespace std;
const int maxn=200005;
int n,K,a[maxn],ans,flg;
struct ltl{
	int hed,til,Q[maxn];
}A,B;
inline int read(){
	int ret=0;bool f=0;char ch=getchar();
	while(ch>'9'||ch<'0') f^=ch=='-',ch=getchar();
	while(ch<='9'&&ch>='0') ret=ret*10+ch-'0',ch=getchar();
	return f?-ret:ret;
}
int main(){
	n=read(),K=read();ans=n-K+1;
	for (int i=1;i<=n;i++) a[i]=read();
	A.hed=B.hed=1;
	for (int i=1;i<=n;i++){
		while(A.hed<=A.til&&A.Q[A.hed]<i-K) A.hed++;
		while(A.hed<=A.til&&a[A.Q[A.til]]>a[i]) A.til--;
		A.Q[++A.til]=i;
		while(B.hed<=B.til&&B.Q[B.hed]<i-K) B.hed++;
		while(B.hed<=B.til&&a[B.Q[B.til]]<a[i]) B.til--;
		B.Q[++B.til]=i;
		if(A.til-A.hed+(A.Q[A.hed]!=i-K)==K)
		if(!flg) flg=1;else ans--;else
		if(A.Q[A.hed]==i-K&&B.Q[B.hed]==i) ans--;
	}
	printf("%d\n",ans);
	return 0;
}
