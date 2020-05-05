#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
inline char getc(void) { 
    static char buf[1 << 18], *fs, *ft;
    return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}
inline int read(void) { 
    register int res = 0;
    register char tmp = getc();
    register bool f = true;
    while(!isgraph(tmp)) tmp = getc();
    if(tmp == '-') f = false, tmp = getc();
    while(isdigit(tmp))
        res = ((res + (res << 2)) << 1) + (tmp ^ 0x30),
        tmp = getc();
    if(f) return res;
    return ~res + 1;
}
struct Edge{
	int x,y,w,v;
	bool operator <(const Edge &b){
		return w<b.w;
	}
}a[N*N];
int ma1[N],ma2[N];
void work(){
	int n=read(),x,s=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[++s].w=read();
			a[s].x=i+1;a[s].y=j+1;
		}
	}
	sort(a+1,a+s+1);
	int ans=0,l=1,w1=0;
	for(int i=1;i<=s;i++){
		if(a[i].w!=a[l].w){
			for(int j=l;j<i;j++)ma1[a[j].x]=max(ma1[a[j].x],w1),ma2[a[j].y]=max(ma2[a[j].y],w1);
			l=i,w1=0;
		}
		a[i].v=max(ma1[a[i].x],ma2[a[i].y])+1;
		w1=max(w1,a[i].v);
	}
	for(int j=l;j<=s;j++)ma1[a[j].x]=max(ma1[a[j].x],a[j].v),ma2[a[j].y]=max(ma2[a[j].y],a[j].v);
	for(int i=1;i<=n;i++)ans=max(ans,ma1[i]);
	printf("%d\n",ans);
}
int main(){
	int T=1;
//	scanf("%d",&T);
	while(T--)work();
	return 0;
} 
