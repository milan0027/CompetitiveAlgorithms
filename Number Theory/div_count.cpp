//using spf
int div_count(int n)
{
	int ans=1;
	while(n>1)
	{
		int k=0;
		int SPF = spf[n];
		while(n%SPF==0)
		{
			n/=SPF;
			k++;
		}
		ans*=k+1;
		//to store the factorization count use vector pair
	}
	return ans;
}

//for larger numbers
int div_count(int n)
{
	int ans=1;
	for(int i=2; i*i <= n; i++)
	{
		int count = 0;
		while(n % i == 0)
		{
			count++;
			n /= i;
		}
		ans*=count+1;
		//to store the factorization count use vector pair
	}

	if(n != 1)
		ans*=2;
	//to store the factorization count use vector pair

	return ans;
}
