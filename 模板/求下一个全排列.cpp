#include<cstdio>
#include<algorithm>
using namespace std; 
void nextpermutation(int a[],int k){//下一个全排列 
	for(int i=k-2;i>=0;i--){
		if(a[i]<a[i+1]){//找到最后一个非降序的值 
			int j;
			for(j=k-1;j>i;j--){
				if(a[i]<a[j])break;
			}
			a[i]^=a[j],a[j]^=a[i],a[i]^=a[j];//将最后一个非降序的数与后面第一个大于它的数互换 
			reverse(a+i+1,a+k);//将后面的数按升序排序,但因为是降序,所以反转一下就行了 
			return;
		}
	}
}
int main(){
	return 0;
}
