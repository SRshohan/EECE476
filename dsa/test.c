#include <stdio.h>
#include <string.h>

int main(){
    printf("Hello World!\n");
    char arr[100];
    printf("Enter the number of elements: ");
    scanf("%s", &arr);
    printf("You entered: %s\n", arr);
    int n = strlen(arr);
    printf("Length of size: %d\n", sizeof(arr));
    printf("Size of array: %d\n", n);
return 0;   
}