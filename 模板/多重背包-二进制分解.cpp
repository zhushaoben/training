#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 100005
int n,w,s,weight[maxn],val[maxn],f[40005];
int main(){
	scanf("%d%d",&n,&w);
	int x,y,z;
	for(int i=0,j;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);//读入每个物品的价值，价格，数量 
		for(j=1;j<=z;j<<=1){//将一个物品二进制分解成多个物品 
			weight[++s]=j*y,val[s]=j*x,z-=j;
		}
		if(z)weight[++s]=z*y,val[s]=z*x;
	}
	for(int i=1;i<=s;i++){//对每个分解出的物品进行01背包 
		for(int j=w;j>=weight[i];j--){
			f[j]=max(f[j],f[j-weight[i]]+val[i]);
		}
	}
	printf("%d",f[w]);
	return 0;
} 
