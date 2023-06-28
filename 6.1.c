#include <stdio.h>

#define SWAP(type, a, b) \
    do { \
        type temp = a; \
        a = b; \
        b = temp; \
    } while (0)

int main() {
    int intA, intB;
    printf("Enter intA: ");
    scanf("%d", &intA);
    printf("Enter intB: ");
    scanf("%d", &intB);
    printf("Before swap: intA = %d, intB = %d\n", intA, intB);
    SWAP(int, intA, intB);
    printf("After swap: intA = %d, intB = %d\n", intA, intB);
    
    float floatA, floatB;
    printf("Enter the value of floatA: ");
    scanf("%f", &floatA);
    printf("Enter the value of floatB: ");
    scanf("%f", &floatB);
    printf("Before swap: floatA = %f, floatB = %f\n", floatA, floatB);
    SWAP(float, floatA, floatB);
    printf("After swap: floatA = %f, floatB = %f\n", floatA, floatB);
    
    char charA, charB;
    printf("Enter charA: ");
    scanf(" %c", &charA);
    printf("Enter charB: ");
    scanf(" %c", &charB);
    printf("Before swap: charA = %c, charB = %c\n", charA, charB);
    SWAP(char, charA, charB);
    printf("After swap: charA = %c, charB = %c\n", charA, charB);
    
    return 0;
}