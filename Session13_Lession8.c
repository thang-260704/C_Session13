#include <stdio.h>
int UCLN(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int number1, number2;
    printf("Nhap so a: ");
    scanf("%d", &number1);
    printf("Nhap so b: ");
    scanf("%d", &number2);
    int result = UCLN(number1, number2);
    printf("UCLN cua %d va %d la: %d\n", number1, number2, result);
    return 0;
}

