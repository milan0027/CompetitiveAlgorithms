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