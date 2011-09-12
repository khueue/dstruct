#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "list/list_node.h"

static void
out_of_memoryXXX(void)
{
    fprintf(stderr, "Out of memory!\n");
    exit(1);
}

list_node_t *
list_node_alloc(void)
{
    list_node_t *node = (list_node_t *)malloc(sizeof(*node)); /* C++ cast. */
    if (!node)
    {
        out_of_memoryXXX();
    }
    return node;
}

list_node_t *
list_node_init(list_node_t *node, void *data)
{
    assert(node);
    node->prev = NULL;
    node->next = NULL;
    node->data = data;
    return node;
}

list_node_t *
list_node_free(list_node_t *node)
{
    free(node);
    return NULL;
}
