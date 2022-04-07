#include <stdio.h>
#include <stdlib.h>

int charLen(char* ch)
{
    int counter = 0;
    for (int i = 0; ch[i] != '\0'; i++) {
        counter++;
    }
    return counter;
}

void swapCases(char* ch)
{
    for (int i = 0; ch[i] != '\0'; i++) {
        if (ch[i] >= 65 && ch[i] <= 90) {
            ch[i] += 32;
        }
        else if (ch[i] >= 'a' && ch[i] <= 122) {
            ch[i] -= 32;
        }
    }
}

void reverseString(char ch[])
{
    int i, j;
    for (i = 0; ch[i] != '\0'; i++) {}
    char newString[i];
    i = i - 1;

    for (j = 0; i >= 0; i--, j++) {
        newString[j] = ch[i];
    }
    newString[j] = '\0';
    printf("Reversed string %s \n", newString);
}

void reverseStringInPlace(char* ch)
{
    int i, j;
    for (i = 0; ch[i] != '\0'; i++) { ; }
    i -= 1;
    for (j = 0; j < i; i--, j++) {
        char temp = ch[i];
        ch[i] = ch[j];
        ch[j] = temp;
    }
}

int isPalindrome(char* ch)
{
    int i, j;
    for (i = 0; ch[i] != '\0'; i++) {;}
    i -= 1;

    for (j = 0; i > j; j++, i--) {
        if (ch[i] != ch[j]) {
            return -1;
        }
    }
    return 1;
}

int main(void)
{
    char res[] = "ABCDeFl";
    int len = charLen(res);
    printf("Len of string is %d \n", len);

    char toSwap[] = "ABCDeFl";
    swapCases(toSwap);
    printf("Swapped case string %s \n", toSwap);

    char toReverse[] = "12345";
    reverseString(toReverse);

    char toReverseInPlace[] = "12345";
    reverseStringInPlace(toReverseInPlace);
    printf("Reversed string %s \n", toReverseInPlace);

    char palindrome[] = "HsaH";
    int isPalindromeCheck = isPalindrome(palindrome);
    printf("is palindrome: %d \n", isPalindromeCheck);

}