#include <stdio.h>

int binary_banao(int n, int num[]);
void decimal(int num[]);
int power(int n, int exp);
void binary_add(int n1[], int n2[]);
void binary_add_alag(int n1[], int n2[]);

int m;
int q;
int m1[4];
int m1neg[4];
int q1[4];


int a[4];

int qMin1;
int n;

int main()
{
	for (int i = 0; i < 4; i++)
	{
		a[i] = 0;
	}
	
	qMin1 = 0;
	n = 4;
	
	printf("Enter m: ");
	scanf("%d", &m);
	
	printf("Enter q: ");
	scanf("%d", &q);
	
	binary_banao(m, m1);
	
	
	for (int i = 0; i < 4; i++)
	{
		if (m1[i] == 0) m1neg[i] = 1;
		else if (m1[i] == 1) m1neg[i] = 0;
	}
	
	int one[] = {1};
	
	binary_add_alag(m1neg, one);
				
	printf("Binary number: ");
	for (int i = 3; i >= 0; i--)
	{
		printf("%d", m1neg[i]);
	}
	
	
	binary_banao(q, q1);
	
	while (n > 0)
	{
		if (qMin1 == 0 && q1[0] == 0)
		{
			
		}
		
		else if (qMin1 == 0 && q1[0] == 1)
		{
			
		}
		
		else if (qMin1 == 1 && q1[0] == 0)
		{
			
		}
		
		else if (qMin1 == 1 && q1[0] == 1) 
		{
			
		}
		
		n--;
	}
	
	
	

	return 0;
}

int binary_banao(int n, int num[])
{
	int count = 0;
	
	while (n != 0)
	{
		num[count] =  n % 2;
		n = n/2;
		count++;
	}
	
	return count;
}

void decimal(int num[])
{
		int sum = 0;
		
		for (int i = 0; i < 8; i++)
		{
			sum += power(2, 7 - i)*num[i];
		}
		
		printf("Decimal value is: %d", sum);
}

int power(int n, int exp)
{
	int sum = 1;
	for (int i = 0; i < exp; i++)
	{
		sum *= n;
	}
	
	return sum;
}

void binary_add(int n1[], int n2[])
{
	int carry = 0;
	int sum[4];
	
	
	for (int i = 0; i < 4; i++)
	{
		if (n1[i] == 0 && n2[i] == 0)
		{
			if (carry == 0)
			{
				sum[i] = 0;
			}
			else if (carry == 1)
			{
				sum[i] = 1;
				carry = 0;
			}
		}
		
		else if (n1[i] == 1 && n2[i] == 0)
		{
			if (carry == 0)
			{
				sum[i] = 1;
			}
			
			else if (carry == 1)
			{
				sum[i] = 0;
				carry = 1;
			}
		}
		
		else if (n1[i] == 0 && n2[i] == 1)
		{
			if (carry == 0)
			{
				sum[i] = 1;
			}
			
			else if (carry == 1)
			{
				sum[i] = 0;
				carry = 1;
			}
		}
		
		else if (n1[i] == 1 && n2[i] == 1)
		{
			if (carry == 0)
			{
				sum[i] = 0;
				carry = 1;
			}
			else if (carry == 1)
			{
				sum[i] = 1;
				carry = 1;
			}
		}
	}
	
	for (int i = 0; i < 4; i++)
	{
		n1[i] = sum[i];
	}
}

void binary_add_alag(int n1[], int n2[])
{
	int carry = 1;
	int sum[4];
	
	
	for (int i = 0; i < 4; i++)
	{
		if (n1[i] == 0)
		{
			if (carry == 0)
			{
				sum[i] = 0;
			}
			else if (carry == 1)
			{
				sum[i] = 1;
				carry = 0;
			}
		}
		
		else if (n1[i] == 1)
		{
			if (carry == 0)
			{
				sum[i] = 1;
			}
			
			else if (carry == 1)
			{
				sum[i] = 0;
				carry = 1;
			}
		}
		
		else if (n1[i] == 0)
		{
			if (carry == 0)
			{
				sum[i] = 1;
			}
			
			else if (carry == 1)
			{
				sum[i] = 0;
				carry = 1;
			}
		}
		
		else if (n1[i] == 1)
		{
			if (carry == 0)
			{
				sum[i] = 0;
				carry = 1;
			}
			else if (carry == 1)
			{
				sum[i] = 1;
				carry = 1;
			}
		}
	}
	
	for (int i = 0; i < 4; i++)
	{
		n1[i] = sum[i];
	}
}
