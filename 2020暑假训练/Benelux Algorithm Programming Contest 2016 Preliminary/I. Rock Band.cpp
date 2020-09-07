#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int *a[N],num[N];
int main(){
	int m,s,num1=0;scanf("%d%d",&m,&s);
	for(int i=0;i<m;i++){
		a[i]=new int[s]; 
		for(int j=0;j<s;j++){
			scanf("%d",a[i]+j);
		}
	}
	for(int i=0;i<s;i++){
		for(int j=0;j<m;j++)
			num1+=(++num[a[j][i]])==m;
		if(num1==i+1)break;
	}
	sort(a[0],a[0]+num1);printf("%d\n",num1);
	for(int i=0;i<num1;i++)printf("%d ",a[0][i]);
	return 0;
}
