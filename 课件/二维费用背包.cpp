

for(int i=1;i<=n;i++)
	for(int j=V;j>=v[i];j--)
		for(int k=W;k>=w[i];k--)
			f[i][j][k]=max(f[i-1][j][k],f[i-1][j-v[i]][k-w[i]]+val[i]);