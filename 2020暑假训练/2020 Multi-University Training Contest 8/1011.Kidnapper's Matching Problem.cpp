#include<bits/stdc++.h>
#define ll long long
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std;
inline int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9') {x=x*10+ch-'0',ch=getchar();}
    return x*f;
}

struct Bit{
    int a[32];
    void Insert(int x)
    {
        for(int i=30;~i;i--){
            if(x&(1<<i)){
                if(!a[i]){a[i]=x;break;}
                x^=a[i];
            }
        }
    }
    bool Find(int x){
    	for(int i=30;~i;i--)
            if(x&(1<<i)){
            	if(!a[i])return 0;
            	x^=a[i];
			}
        return 1;
	}
};
const int N=200005;
const int mod=1e9+7;
Bit S;
int pw[N],a[N],b[50005],ans[N],nex[N];
inline void Next(const int a[],int next[],int l){
	for(int i=1,k=0;i<l;i++){
		while(k>0&&!S.Find(a[i]^a[k]))k=next[k-1];
		if(S.Find(a[i]^a[k]))k++; 
		next[i]=k;
	}
}
inline void kmp(const int a[],const int b[],int next[],int l1,int l2){
	for(int i=0,q=0;i<l1;i++){
		while(q>0&&!S.Find(b[q]^a[i]))q=next[q-1];
		if(S.Find(b[q]^a[i]))q++;
		if(q==l2){ans[i-l2+2]=1;}
	}
}
void solve()
{
	int n,m,k;
	n=read(); m=read(); k=read();
	for(int i=0; i<n; i++) a[i]=read();
	for(int i=0; i<m; i++) b[i]=read();
	a[n]=b[m]=-1;
	memset(&S, 0, sizeof(S));
	memset(ans,0,sizeof(int)*(n+2));
	memset(nex,0,sizeof(int)*(n+2));
	for(int i=1; i<=k; i++) {
		int x=read();
		S.Insert(x);
	}
	
	Next(b,nex,m);
	kmp(a,b,nex,n,m);
	int res=0;
	for(int i=1; i<=n; i++)
		if(ans[i]) res=(res+pw[i-1])%mod;
	printf("%d\n",res);
}

int main()
{
	pw[0]=1;
	for(int i=1; i<=200000; i++) pw[i]=pw[i-1]*2%mod;
	int T=read();
	while(T--) solve();
}
