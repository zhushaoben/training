#include<bits/stdc++.h>
using namespace std;
void work(){
	int n,pre1=0,pre2=0,a,b;bool fl=1;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		if(a<b||a<pre1||b<pre2||a-pre1<b-pre2)fl=0;
		pre1=a,pre2=b;
	}
	if(fl)puts("YES");
	else puts("NO");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
