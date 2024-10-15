#include <stdio.h>

int binary_banao(int n, int num[]);
void decimal(int num[]);
int power(int n, int exp);

int main()
{
    int n;
    int num[32];
    int c;

    do
    {
        printf("Enter 1 for decimal to binary, and 2 for binary to decimal.\n");
        printf("Enter your choice: ");
        scanf("%d", &c);

        switch (c)
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
                printf("\n");
                break;

            case 2:
                printf("Enter the 8-bit binary number: ");
                for (int i = 0; i < 8; i++)
                {
                    scanf("%d", &num[i]);
                    if (num[i] != 0 && num[i] != 1)
                    {
                        printf("Invalid binary digit entered.\n");
                        return 1;
                    }
                }

                decimal(num);
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (c < 3);

    return 0;
}

int binary_banao(int n, int num[])
{
    int count = 0;

    while (n != 0)
    {
        num[count] = n % 2;
        n = n / 2;
        count++;
    }

    return count - 1;
}

void decimal(int num[])
{
    int sum = 0;

    for (int i = 0; i < 8; i++)
    {
        sum += power(2, 7 - i) * num[i];
    }

    printf("Decimal value is: %d\n", sum);
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
