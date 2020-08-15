#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
inline char getc(void) { 
    static char buf[1 << 18], *fs, *ft;
    return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}
inline int read(void) { 
    register int res = 0;
    register char tmp = getc();
    while(!isgraph(tmp)) tmp = getc();
    while(isdigit(tmp))
        res = ((res + (res << 2)) << 1) + (tmp ^ 0x30),
        tmp = getc();
    return res;
}
struct Node{
	int a,nex,w;
	bool operator < (const Node &b){return a<b.a;}
	bool operator >= (const Node &b){return a>=b.a;}
	bool operator <= (const Node &b){return a<=b.a;}
}a[N];
int b[N];
int lowbou(int l,int r,int tar){
	while(l<=r){
		int mid=(l+r)/2;
		if (a[mid].a<tar) l=mid+1;
		else r=mid-1;
	}
	return l;
}
int partition(Node a[], int low, int high){
    Node tmp = a[low];
    while(low < high){
        while(low<high&&a[high].a>=tmp.a){
            high--;
        }
        a[low] = a[high];
        while(low<high&&a[low].a<=tmp.a){
            low++;
        }
        a[high] = a[low];
    }
    a[low] = tmp;
    return low;
}

void quickSort(Node a[], int low, int high){
    if(low >= high){
        return;
    }
    int pivot = partition(a, low, high);
    quickSort(a, low, pivot-1);
    quickSort(a, pivot+1, high);
}
int main(){
//	freopen("a.in","r",stdin);
	int n,m,k,si=1;n=read(),m=read();
	for(int i=0;i<n;i++){
		k=read();
		for(int i=0;i<k;i++)b[i]=read();
		sort(b,b+k),b[k]=0;
		for(int i=0;i<k;i++)a[si++]={b[i],b[i+1],0};
		a[si-k].w=1;
	}
	int ans=1e9,now=0,w=0;
	quickSort(a,1,si-1);a[si]={ans<<1,0,ans};
	for(int i=1;i<si;i++){
		while(w<m)w+=a[++now].w;
		ans=min(ans,a[now].a-a[i].a);
		w-=a[i].w;
		if(a[i].nex){
			int x=lowbou(1,si-1,a[i].nex);
			a[x].w++;w+=(x<=now);
		}
		else{
			n--;
			if(n<m)break;
		}
	}
	printf("%d",ans);
	return 0;
}
