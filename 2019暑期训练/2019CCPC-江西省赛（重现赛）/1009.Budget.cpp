#include<cstdio>
using namespace std;
int n;char s[5];
void work(){
	int ans=0;
	for(int i=1;i<=n;i++){
		scanf("%*d.%s",s);
		int x=s[2]?s[2]-'0':0;
		ans-=(x<=4?x:x-10);
	}
	printf("%.3lf\n",ans/1000.0);
}
int main(){
	while(~scanf("%d",&n))work();
	return 0;
}
