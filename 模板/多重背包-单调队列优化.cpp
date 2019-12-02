#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 100005
#define maxw 40005
int n,w,f[maxw],que[maxn],id[maxn],s,t,l;
void insert(int x,int i,int limit){
	while(s<t&&i-id[s]>limit)s++;
	while(s<t&&que[t-1]<=x)t--;
	que[t]=x,id[t++]=i;
}
int main(){
	scanf("%d%d",&n,&w);
	int x,y,z;
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);//读入每个物品的价值，价格，数量 
		for(int j=0;j<y;j++){//对于每个容量%价格建立一个单调队列 
			s=t=l=0;
			for(int k=j;k<=w;k+=y,l++){//队列包含的容量都从单调队列转移 
				insert(f[k]-l*x,l,z);
				f[k]=max(f[k],que[s]+l*x);
			}
		}
	}
	printf("%d",f[w]);
	return 0;
} 
