#include<bits/stdc++.h>
using namespace std;

vector<int>factor[501];

void get_factors()
{
	int i,j;

	for(i=1;i<=500;i++)
	{
		for(j=i;j<=500;j+=i)
		{
			factor[j].push_back(i);
		}
	}
}


//Take n between 1-500
int main()
{
	int n,i,x,user,toss;
	char ans;

	srand (time(NULL));
	cout<<"Let's have a toss for who plays first. Choose Heads(H) or Tails(T): ";
	cin>>ans;
	toss = rand() % 2;
	switch(toss)
	{
		case 0: cout<<"It was Tails\n";
				break;
		case 1: cout<<"It was Heads\n";
				break;
	}
	n = rand() % 500 + 1;
	cout<<"n = "<<n<<endl;
	get_factors();
	

	if(toss==1 && ans=='H' || toss==0 && ans=='T') // user starts first
	{
		if(n==1)
		{
			cout<<"Can't subtract 1 from itself. You lost, Hahaha! :P"<<endl;
			return 0;
		}
		cout<<"Choose a factor of n to subtract from it: \n";
		for(x=0;x<factor[n].size()-1;x++)
		{
			cout<<factor[n][x]<<" ";
		}
		cout<<endl;

		cin>>user;
		n-=user;
		cout<<"Now n becomes "<<n<<endl;
	}

	for(i=1;;i++)
	{
		if(i%2==1) //comp chance
		{
			if(n==1)
			{
				cout<<"Can't subtract 1 from itself. I lost, Congratulations :/"<<endl;
				break;
			}
			else
			if(n%2==0)
			{
				for(x=factor[n].size()-1;x>=0;x--)
				{
					if(factor[n][x]%2==1)
					{
						cout<<"I subtract "<<factor[n][x]<<" from "<<n<<".";
						n-=factor[n][x];
						cout<<"Now you get "<<n<<endl;
						break;
					}
				}
			}
			else
			{
				x=factor[n].size()-2;
				cout<<"I subtract "<<factor[n][x]<<" from "<<n<<".";
				n-=factor[n][x];
				cout<<"Now you get "<<n<<endl;
			}
		}
		else //user chance
		{
			if(n==1)
			{
				cout<<"Can't subtract 1 from itself. You lost, Hahaha! :P"<<endl;
				break;
			}
			cout<<"Choose a factor of n to subtract from it: \n";
			for(x=0;x<factor[n].size()-1;x++)
			{
				cout<<factor[n][x]<<" ";
			}
			cout<<endl;

			cin>>user;
			n-=user;
			cout<<"Now n becomes "<<n<<endl;
		}
	}

	return 0;
}