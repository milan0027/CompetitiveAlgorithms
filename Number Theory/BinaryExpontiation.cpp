int bepower(int x,int n)
{
	if(n==0)
		return 1;
	
	if(n%2==0)
		return bepower((x*x)%mod,n/2)%mod;

	return (x*bepower((x*x)%mod,n/2))%mod;
}

int bepower(int x, int n)
{
	int res=1;
	while(n!=0)
	{
		if(n%2==1)
			res = (res*x)%mod;
		x = (x*x)%mod;
		n/=2;
	}
	return res;
}