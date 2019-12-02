#include<cstdio>
#include<algorithm>
using namespace std;
int a[1005];
int main(){
	int size,x=1,n;//离散后数组大小 
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	sort(a,a+n);size=unique(a,a+n)-a;//排序+去重 
	scanf("%d",&x);
	int find=lower_bound(a,a+n,x)-a;//用的时候加个lower_bound就行了 
	printf("%d",find);
	return 0;
} 
