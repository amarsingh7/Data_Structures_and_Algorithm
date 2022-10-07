// Priyanshu Rajput
// 07-10-2022
// 19:17
// nth fibonacci number using dp
#include<bits/stdc++.h>
using namespace std;

class fibonacci{
	
public:
int fib(int n)
{
	

	
	int f[n + 2];
	int i;


	f[0] = 0;
	f[1] = 1;

	for(i = 2; i <= n; i++)
	{
		
	
	f[i] = f[i - 1] + f[i - 2];
	}
	return f[n];
	}
};


int main ()
{
	fibonacci g;
	int n = 9;
	
	cout << g.fib(n);
	return 0;
}


