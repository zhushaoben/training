#include<cstdio>
#include<algorithm>
using namespace std;
int a[1005];
int main(){
	int size,x=1,n;//��ɢ�������С 
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	sort(a,a+n);size=unique(a,a+n)-a;//����+ȥ�� 
	scanf("%d",&x);
	int find=lower_bound(a,a+n,x)-a;//�õ�ʱ��Ӹ�lower_bound������ 
	printf("%d",find);
	return 0;
} 
