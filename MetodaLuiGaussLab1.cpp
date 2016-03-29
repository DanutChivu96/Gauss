#include <iostream>
#include <stdlib.h>

using namespace std;

int main () {
	int n,i,j,k;
	float a[100][100],s;

	cout << "n: "; cin >> n;

	for(i=1; i <= n; i++)
		for(j=1; j <= n+1; j++)
		{
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];
		}

	for(k=1; k<=n-1; k++)
	{
		if(a[k][k] != 0)
		{
			for(i=k+1;i<=n;i++)
			{
				a[i][k] = a[i][k]/a[k][k];
				for(j=k+1;j<=n+1;j++)
					a[i][j] = a[i][j]-a[i][k]*a[k][j];
			}
		}
		else exit(0);
	}

	if(a[n][n] == 0)
	{
		cout << "Sistemul nu are solutie unica";
		exit(0);
	}

	a[n][n+1] = a[n][n+1]/a[n][n];

	for(i=n-1;i>=1;i--)
	{
		s=0;
		for(j=i+1;j<=n;j++)
		{
			s = s+a[i][j]*a[j][n+1];
		}
		a[i][n+1] = (a[i][n+1] - s)/a[i][i];
	}

	for(i=1;i<=n;i++)
	{
		cout<< "x[" << i <<"]= " << a[i][n+1] << endl;
	}


	system("PAUSE");
	return 0;
}
