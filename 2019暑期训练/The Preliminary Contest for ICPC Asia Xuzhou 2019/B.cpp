#include<bits/stdc++.h>
#define ll long long
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std; 
const int N=1e6+5;
inline int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int n,q,z[N],num[N],siz,fa[N],x[N];
bool w[N];
int Find(int x){
	return fa[x]==x?x:fa[x]=Find(fa[x]);
}
int main()
{
	n=read(); q=read();
	for(int i=1;i<=q;i++){
		z[i]=read();x[i]=num[i]=read();
	}
	sort(num+1, num+q+1);
	siz=unique(num+1, num+q+1)-num-1;
	for(int i=1;i<=siz;i++)fa[i]=i; 
	for(int i=1;i<=q;i++){
		x[i]=lower_bound(num+1, num+siz+1, x[i])-num;
	}
	for(int i=1;i<=q;i++){
		if(z[i]==1){
			if(num[x[i]]==num[x[i]+1]-1)fa[x[i]]=x[i]+1;
			w[x[i]]=1;
		}
		else{
			int x1=Find(x[i]);
			printf("%d\n",(w[x1]?(num[x1])==n?-1:num[x1]+1:num[x1]));
		}
	}
	return 0;
}
