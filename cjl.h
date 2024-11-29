// linkedlist.h

#ifndef LINKEDLIST_H  
#define LINKEDLIST_H

struct linkedlist
{
    int value;
    struct linkedlist *next;
    struct linkedlist *prev;
};

struct linkedlist *create_node(int new_value);
int count_ze_nodes(struct linkedlist list);
int read_list(char *json, struct linkedlist* list);
#endif
