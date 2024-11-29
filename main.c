#include <stdio.h>
#include <stdlib.h>
#include "cjl.h"

int main() {
    struct linkedlist list;
    int status = read_list("[ 1, 2,]", &list);
    int a = count_ze_nodes(list);
    printf("%d %d\n", a, status);
    return 0;
}