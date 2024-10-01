#include <stdio.h>
#include <math.h>

int d2b(int n, int a[]) {
    int i = 0;
    while (n != 0) {
        a[i] = n % 2;
        n = n / 2;
        i++;
    }
    return i;
}

void d2bDec(double n, int a[]) {
    for (int i = 0; i < 10; i++) {
        if ((n - floor(n)) == 0.0) {
            break;
        }
        a[i] = (n - floor(n)) * 2;
        n = n * 2;
    }
}

void d2bDec2(double n, int a[]) {
    for (int i = 0; i < 23; i++) {
        if ((n - floor(n)) == 0.0) {
            break;
        }
        a[i] = (n - floor(n)) * 2;
        n = n * 2;
    }
}

int main() {
    int b1[10] = {0}, b2[10] = {0}, mant[50] = {0}, expB[10] = {0};
    int b3[23] = {0}, sign = 0, intPart = 0;
    int len1 = 0, cnt = 0, exp = 0, j = 0, bias = 127, lenExp = 0;
    double num = 0, decPart = 0;

    printf("Enter a decimal number: ");
    scanf("%lf", &num);
    printf("The IEEE-754 Floating Point Representation of the number is: \n");

    if (num < 0) {
        sign = 1;
    }

    if (fabs(num) < 1) {
        d2bDec2(fabs(num), b3);

        for (int i = 0; i < 23; i++) {
            if (b3[i] == 1) {
                break;
            }
            cnt++;
        }

        exp = cnt + 1;
        bias = bias - exp;

        lenExp = d2b(bias, expB);

        printf("%d ", sign);
        for (int i = lenExp - 1; i >= 0; i--) {
            printf("%d", expB[i]);
        }
        printf(" ");

        for (int i = exp; i < 23; i++) {
            printf("%d", b3[i]);
        }

        for (int i = 0; i < exp; i++) {
            printf("0");
        }
    }
    else {
        intPart = floor(fabs(num));
        decPart = fabs(num) - floor(fabs(num));

        len1 = d2b(intPart, b1);
        d2bDec(decPart, b2);

        for (int i = len1 - 1; i >= 0; i--) {
            if (b1[i] == 1) {
                break;
            }
            cnt++;
        }

        exp = len1 - cnt - 1;
        for (int i = exp - 1; i >= 0; i--) {
            mant[j] = b1[i];
            j++;
        }

        for (int i = 0; i < 10; i++) {
            mant[j + i] = b2[i];
        }

        bias = bias + exp;
        lenExp = d2b(bias, expB);

        printf("%d ", sign);
        for (int i = lenExp - 1; i >= 0; i--) {
            printf("%d", expB[i]);
        }
        printf(" ");

        for (int i = 0; i < j + 10; i++) {
            printf("%d", mant[i]);
        }

        for (int i = 0; i < 23 - (j + 10); i++) {
            printf("0");
        }
    }
    printf("\n");
    return 0;
