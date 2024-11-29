#include <stdio.h>
#include <stdlib.h>
#include "cjl.h"
#include <string.h>

struct linkedlist *create_node(int new_value)
{
    struct linkedlist *new_node = malloc(sizeof(struct linkedlist));
    new_node->value = new_value;
    new_node->next = NULL;
    new_node->prev = NULL;
}
int count_ze_nodes(struct linkedlist header)
{
    int count = 0;
    struct linkedlist *current = &header;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}
int read_list(char *json, struct linkedlist* list)
{
    //used to be twitter
    int x;
    // AMERRRICAAAAAAAA
    int state = 0;
    size_t length = 0;
    size_t i = 0;
    struct linkedlist *current = list;
    char *buff;
    if (json[i++] != '[')
    {
        return -1;
    }
    while (json[i] != 0) {
        // if (state == 1) {
            
        // }
        switch (json[i])
        {
        case ']':
            if (length != 0) {
                buff = malloc(sizeof(char) * length);
                memcpy(buff, &json[i - length], length);
                if (sscanf(buff, "%d", &x) == 1){
                    free(buff);
                    current->value = x;
                } else {
                    if (strspn(buff, " \n\t\r") != length) {
                        printf("you bitch");
                    } else {
                        current->prev->next = NULL; 
                        free(current);
                    }
                }
            } else {
                current->prev->next = NULL; 
                free(current);
            }
            state = 1;
            break;
        case ',':
            buff = malloc(sizeof(char) * length);
            memcpy(buff, &json[i - length], length);
            length = 0;
            if (sscanf(buff, "%d", &x) == 1){
                free(buff);
                current->value = x;
                current->next = malloc(sizeof(struct linkedlist));
                current->next->prev = current;
                current = current->next; 
            } else {
                return -1;
            }
            break;
        default:
            length++;
            break;
        }
        i++;
    }
    return 0;
}