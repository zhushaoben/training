const int maxn=100000;
int f[maxn+5],g[maxn+5];
//g[i]��ʾi�ڵ������еĽڵ㵽i�ڵ��������
//f[i]��ʾi�ڵ������е�ֱ��
void search(int x){
	int ma=0,ma1=0; 
	for(i��x���ӽڵ�){
		search(i);
		f[x]=max(f[x],f[i]);
		if(g[i]+1>ma)ma1=ma,ma=g[i]+1;
		else if(g[i]+1>ma1)ma1=g[i]+1;
	}
	g[x]=ma;
	f[x]=max(f[x],ma+ma1);
}
