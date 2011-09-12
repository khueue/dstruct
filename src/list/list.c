#include <stdlib.h>
#include <stdio.h>

#include "list/list.h"

static void
out_of_memory(void)
{
    fprintf(stderr, "Out of memory!\n");
    exit(1);
}

list_t *
list_alloc(void)
{
    list_t *list = (list_t *)malloc(sizeof(*list)); /* Cast for C++. */
    if (!list)
    {
        out_of_memory();
    }
    list->first = NULL;
    list->last = NULL;
    list->length = 0;
    return list;
}

list_t *
list_free(list_t *list)
{
    while (!list_is_empty(list))
    {
        list_remove_first(list);
    }
    free(list);
    return NULL;
}

int
list_length(const list_t *list)
{
    return list->length;
}

int
list_is_empty(const list_t *list)
{
    return list_length(list) == 0;
}

void
list_add_first(list_t *list, void *data)
{
    list_node_t *node = list_node_alloc();
    list_node_init(node, data);

    if (list_is_empty(list))
    {
        list->first = node;
        list->last  = node;
    }
    else
    {
        node->next = list->first;
        list->first->prev = node;
        list->first = node;
    }

    ++list->length;
}

void
list_remove_first(list_t *list)
{
    if (list_is_empty(list))
    {
        /* Crash? */
    }
    else
    {
        list_node_t *new_first = list->first->next;
        list_node_free(list->first);
        list->first = new_first;
        list->last  = new_first;
        --list->length;
    }
}

void *
list_get_first(const list_t *list)
{
    if (list_is_empty(list))
    {
        /* XXXXXX */
        return NULL;
    }
    else
    {
        return list->first->data;
    }
}
