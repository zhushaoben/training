#include<bits/stdc++.h>
using namespace std;
int l[105];
int main(){
	int n,ans=0;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",l+i);
	sort(l,l+n);
	for(int i=0;i<n;i++){
		int j=i+1;while(l[j]==l[i])j++;
		for(;j<n;j++){
			int k=j+1;while(l[j]==l[k])k++;
			for(;k<n;k++)if(l[i]+l[j]>l[k])ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
