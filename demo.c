#include <stdio.h>
#include "_daemon.c"

int _daemon(int, int);

int main() {
    getchar();
    _daemon(0, 0);
    return 0;
}
