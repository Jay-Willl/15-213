#include <stdio.h>

int main() {
    char buffer[10];

    printf("Enter a string: ");
    if (gets(buffer) != NULL) {
        printf("You entered: %s\n", buffer);
    } else {
        printf("Error reading input.\n");
    }

    return 0;
}