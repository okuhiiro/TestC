#include<stdio.h>
#include "path.h"

int main(int argc, char **argv)
{
    char *argv0 = (char *)argv[0];

    printf("%s\n", (char *)path_tail(argv0));

    printf("Done. main\n");
}
