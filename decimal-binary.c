#include <stdio.h>

int binary_banao(int n, int num[]);
void decimal(int num[]);
int power(int n, int exp);

int main()
{
	int n;
	int num[32];
	int c;
	
	printf("Enter 1 for decimal to binary, and 2 for binary to decimal.\n");
	printf("Enter your choice: ");
	scanf("%d", &c);
	
	
	while (c < 3)
	{
	switch(c)
	{
		case 1:
			printf("Enter the number: ");
			scanf("%d", &n);
	
			int count = binary_banao(n, num);
			
			printf("Binary number: ");
			for (int i = count; i >= 0; i--)
			{
				printf("%d", num[i]);
			}

			
			break;
		case 2:
			printf("Enter the binary number: ");
			
			int temp[32] = {0};
			
			for (int i = 0; i < 8; i++)
			{
				scanf("%d", &num[i]);
			} 
			
			
			for (int i = 0; i < 8; i++)
			{
				if (temp[i] != 0 || temp[i] != 1)
				{
					break;
				}
				
				num[i] = temp[i];
			}
			
			decimal(num);
	}
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
