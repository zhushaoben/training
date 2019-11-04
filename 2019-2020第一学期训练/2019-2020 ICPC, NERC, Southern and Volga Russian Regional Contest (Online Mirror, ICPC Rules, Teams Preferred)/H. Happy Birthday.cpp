#include<bits/stdc++.h>
#define ll long long
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std;
const int N=11;
inline int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int c[N];
void work(){
	int mi=1e9,w=1;
	for(int i=0;i<10;i++)c[i]=read();
	for(int i=1;i<10;i++)if(c[i]<mi)mi=c[i],w=i;
	if(mi>c[0]){
		putchar('1');
		for(int i=0;i<=c[0];i++)putchar('0');
	}
	else for(int i=0;i<=c[w];i++)putchar(w+'0');
	puts("");
}
int main()
{
	int t=read();
	while(t--)work();
	return 0;
}
