#include<iostream>
using namespace std;


int pow(int a,int b)
{
    int pow=1;
    for(int i=0;i<b;i++)
    {
        pow=pow*a;
    }
	return a;
}
int modexp(int x, int y, int z)
{
int remainder;
int i = 1;

while (y != 0)
{
remainder = y % 2;
y= y/2;

if (remainder == 1)
i = (i * x) % z;
x= (x * x) % z;
}
return i;
}

int mulinverse(int a,int b)
{
	int b0=b;
	int t,q;
	int x0=0;
	int x1=1;
	if(b==1)
	{
		return 1;
	}
	while(a>1)
	{
		q=a/b;
		t=b;
		b=a%b;
		a=t;
		t=x0;
		x0=x1-q*x0;
		x1=t;

	}
	if(x0<0)
	{
		x1+=b0;
	}

	return x1;
}
int addinverse(int a,int b)
{
	int x;
	for(int i=0;i<b;i++)
	{
		if((i+a)%b==0)
		return i;
	}
}
int gcd(int a,int b)
{


    int hcf=1,temp;
    if(a<b)
    {
      temp=a;
    }
    else
    {
        temp=b;
    }
    for(int i=2;i<=temp;i++)
    {

        if(a%i==0 && b%i==0)
        {

            hcf=i;
        }
    }
    return(hcf);

}
static unsigned phi(unsigned long x)
{
	unsigned ret=1,i,pow;
	for(i=2;x!=1;i++)
	{
		pow=1;
		while(!(x%i))
		{
			x/=i;
			pow*=i;
		}
			ret*=(pow-(pow/i));

	}
		return ret;
}



int main()
    {
    int a,b,c;
    cout<<"To find the a^b mod c \n fill in as requested \n";
    cin>>a>>b>>c;
    int k=modexp(a,b,c);
    cout<<"The answer is :"<<k<<"\n";
    int y;
    cout<<"Enter the number for which we have to find the inverse : ";
    cin>>y;
    cout<<"\n\nAdditive inverse\n\n";
    cout<<"\nNumber \t inverse \n";

    for(int i=1;i<y;i++)
    {
        int z=addinverse(i,y);
        cout<<i<<" \t "<<z<<"\n";
    }
    cout<<"\n\nMultiplicative inverse\n\n";
    cout<<"\n\nNumber \t inverse \n\n";
    for(int i=1;i<y;i++)
    {
    if(gcd(i,y)==1)
    {
    int z=mulinverse(i,y);
    if(z<0)
        {
            cout<<i<<" \t "<<(z+y)%y<<"\n";
        }
        else
            cout<<i<<" \t "<<z%y<<"\n";
     }
    else
       cout<<i<<" \t"<<"\"X\"" <<"\n";
    }

    cout<<"\n\n X- Does not exist \n\n";

    cout<<"\n\nMultiplative modulo "<<y<<"\n\n";
    cout<<"\t";
    for(int g=0;g<y;g++)
    {
        cout<<g<<"\t";
    }
    cout<<"\n";

    for(int i=0;i<y;++i)
    {


     for(int j=0;j<y;++j)
     {
         if(j==0)
         {
             cout<<i<<"\t";
         }
         cout<<(i*j)%y<<"\t";

     }
     cout<<"\n";
    }
    cout<<"\n\nAdditive modulo "<<y<<"\n\n\n";
    cout<<"\t";
    for(int g=0;g<y;g++)
    {
        cout<<g<<"\t";
    }
    cout<<"\n";

    for(int i=0;i<y;++i)
    {


     for(int j=0;j<y;++j)
     {
         if(j==0)
         {
             cout<<i<<"\t";
         }
         cout<<(i+j)%y<<"\t";

     }
     cout<<"\n";
    }
    cout<<"Euler function \n\n";
    int ga;
    cout<<"Enter the value for which Euler function is to be found \n\n";
    cin>>ga;
    int ans=phi(ga);
    cout<<"Eueler function is :"<<ans<<"\n";
    return 0;

    }
