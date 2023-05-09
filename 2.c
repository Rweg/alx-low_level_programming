#include <stdio.h>
#include <fcntl.h>

int main(void) {
    printf("O_RDONLY << 1: %d\n", O_RDONLY << 1);
    printf("0: %d\n", 0);
    printf("O_RDONLY | O_WRONLY: %d\n", O_RDONLY | O_WRONLY);
    printf("3 & 2: %d\n", 3 & 2);
    printf("O_RDONLY && O_WRONLY: %d\n", O_RDONLY && O_WRONLY);
    printf("2: %d\n", 2);
    printf("3 | 2: %d\n", 3 | 2);
    printf("O_RDONLY & O_WRONLY: %d\n", O_RDONLY & O_WRONLY);
    printf("1 << 1: %d\n", 1 << 1);
    printf("3: %d\n", 3);
    printf("O_WRONLY << 1: %d\n", O_WRONLY << 1);
    printf("O_RDONLY + O_WRONLY: %d\n", O_RDONLY + O_WRONLY);
    printf("O_RDONLY: %d\n", O_RDONLY);
    printf("O_WRONLY: %d\n", O_WRONLY);
    
    return 0;
}
