#include<bits/stdc++.h>
using namespace std;
#define maxn 400000
int c[maxn+5],fp[maxn+5];
inline int lowbit(int x){return x&(-x);}
void add(int x,int num){
    while(x<=maxn){
        c[x]+=num;
        x+=lowbit(x);
    }
}
int sum(int x){
    int ans=0;
    while(x){
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
int main(){
	int q,l=2e5,r=2e5+1,w;char op[5];scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%s%d",op,&w);
		if(op[0]=='L')add(fp[w]=l--,1);
		else if(op[0]=='R')add(fp[w]=r++,1);
		else{
			w=sum(fp[w]);
			printf("%d\n",min(w-1,r-l-1-w));
		}
	}
	return 0;
}
