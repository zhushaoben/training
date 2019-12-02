void Next(const char a[],int nex[],int l){
	nex[0]=-1;
	for(int i=0,j=-1;i<l;i++){
		while(j!=-1&&a[i]!=a[j])j=nex[j];
		nex[i+1]=++j;
	}
}
int kmp(const char a[],const char b[],int nex[],int l1,int l2){
	int ans=0;
	for(int i=0,j=0;i<l1;i++){
		while(j==l2||(j!=-1&&a[i]!=b[j]))j=nex[j];
		ans=max(ans,++j);
	}
	return ans;
}
