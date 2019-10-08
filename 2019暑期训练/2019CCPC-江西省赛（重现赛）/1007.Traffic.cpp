#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 1005
int n,m,a[maxn],b[maxn];
void work(){
	for(int i=0;i<n;i++)scanf("%d",a+i);sort(a,a+n);
	for(int i=0;i<m;i++)scanf("%d",b+i);sort(b,b+m);b[m]=1001;
	for(int i=0;;i++){
		bool fl=1;
		for(int j=0,k=0;j<n;j++){
			while(b[k]+i<a[j])k++;
			if(b[k]+i==a[j]){
				fl=0;
				break;
			}
		}
		if(fl){
			printf("%d\n",i);return;
		}
	}
}
int main(){
	while(~scanf("%d%d",&n,&m))work();
	return 0;
} 
