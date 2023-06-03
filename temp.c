#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* freshVar(){
    static int i = 0;
    char* label = malloc(100);
    sprintf(label, "L%d", i);
    i++;
    return label;
}

int main(){
    // test for freshVar
    printf("%s\n", freshVar());
    printf("%s\n", freshVar());
    printf("%s\n", freshVar());
    printf("%s\n", freshVar());
    printf("%s\n", freshVar());
    return 0;
}