#ifndef __LIST_H__
#define __LIST_H__

#include "list/list_node.h"

struct list_t;

struct list_t
{
    struct list_node_t *first;
    struct list_node_t *last;
    int length;
};

typedef struct list_t list_t;

list_t *
list_alloc(void);

list_t *
list_init(list_t *list);

list_t *
list_free(list_t *list);

int
list_length(const list_t *list);

int
list_is_empty(const list_t *list);

void
list_add_first(list_t *list, void *data);

void
list_remove_first(list_t *list);

void *
list_get_first(const list_t *list);

#endif
