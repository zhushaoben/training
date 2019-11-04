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
int n,m;
int main(){
	n=read(); m=sqrt(n);
	for(int i=m;i>=1;i--){
		if(i*(n/i)==n){
			printf("%d\n",i*2+(n/i)*2); return 0;
		}
	}
	return 0;
}
