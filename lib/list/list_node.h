#ifndef __LIST_NODE_H__
#define __LIST_NODE_H__

struct list_node_t;

struct list_node_t
{
    struct list_node_t *prev;
    struct list_node_t *next;
    void *data;
};

typedef struct list_node_t list_node_t;

list_node_t *
list_node_alloc(void);

list_node_t *
list_node_init(list_node_t *node, void *data);

list_node_t *
list_node_free(list_node_t *node);

#endif
