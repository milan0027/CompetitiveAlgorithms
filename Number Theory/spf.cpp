int sizee=1000000;
int spf[sizee+1];
//call this function form int main
void pre_calculate()
{
	for(int i=0;i<=sizee;i++)
		spf[i]=i;

	for(int i=2;i<=sizee;i++)
	{
		if(spf[i]==i)
		{
			for(int j=i*i;j<=sizee;j+=i)
			{
				if(spf[j]==j)
					spf[j]=i;
			}

		}
	}
}