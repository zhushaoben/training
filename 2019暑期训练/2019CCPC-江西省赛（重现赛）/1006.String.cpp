#include<cstdio>
using namespace std;
int n;char s[200];
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
void work(){
	scanf("%s",s);
	int ans1=n*n*n*n,ans2,a=0,b=0,c=0,d=0;
	for(int i=0;s[i];i++){
		if(s[i]=='a')a++;
		else if(s[i]=='v')b++;
		else if(s[i]=='i')c++;
		else d++;
	}
	ans2=a*b*c*d;a=gcd(ans1,ans2);
	printf("%d/%d\n",ans2/a,ans1/a);
}
int main(){
	while(~scanf("%d",&n))work();
	return 0;
}
