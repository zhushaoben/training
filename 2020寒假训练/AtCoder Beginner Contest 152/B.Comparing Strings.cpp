#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;scanf("%d%d",&a,&b);
	if(a>b)swap(a,b);
	for(int i=0;i<b;i++)printf("%d",a);
	return 0;
}
