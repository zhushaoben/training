#include<bits/stdc++.h>
using namespace std;
#define maxn 4010
char s[maxn],s1[maxn];
int k;
int cal(char a[],char b[]){
	int ans=0;
	for(int i=0;b[i];i++){
		int l=0,w=0;
		for(int j=0;b[i+j]&&a[j];j++){
			if(b[i+j]!=a[j])w++;
			while(w>k)w-=(b[i+l]!=a[l]),l++;
			ans=max(ans,j-l+1);
		}
	}
	return ans;
}
void work(){
	scanf("%d%s%s",&k,s,s1);
	printf("%d\n",max(cal(s,s1),cal(s1,s)));
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
