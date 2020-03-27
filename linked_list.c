#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} node;

void print(node *n) {
    if (!n)
        return;
    printf("%d\n", n->value);
    print(n->next);
}

int count(node *n) {
    if (!n)
        return 0;
    return count(n->next) + 1;
}

int is_empty(node *n) {
    return !n;
}

int is_ordered(node *n) {
    if (!n)
        return 1;
    
    if (n->next && n->value > n->next->value)
        return 0;
    
    return is_ordered(n->next);
}

node* create(int v) {
    node *n = (node*) malloc(sizeof(node));
    n->value = v;
    n->next = NULL;
    return n;
}

// Pushes node to linked list.
node* push(node *r, node *n) {
    if (!r)
        r = n;
    else
        r->next = push(r->next, n);
    
    return r;
}

// Pushes node to an ordered linked list. 
node* push_ordered(node *r, node *n) {
    if (!r)
        r = n;
    else if (r->next && r->next->value < n->value)
        r->next = push_ordered(r->next, n);
    else {
        n->next = r->next;
        r->next = n;
    }
    
    return r;
}

// Pushes node to queue.
node* push_queue(node *r, node *n) {
    if (!r)
        r = n;
    else
        r->next = push_queue(r->next, n);
    
    return r;
}

// Pushes node to stack.
node* push_stack(node *r, node *n) {
    if (!r)
        r = n;
    else
        r->next = push_stack(r->next, n);
    return r;
}

// Pops node from linked list.
node* pop(node **n, int v) {
    if (!(*n))
        return (*n);
    
    node *temp;
    
    if ((*n)->value == v) {
        temp = (*n);
        (*n) = (*n)->next;
        return temp;
    } else if ((*n)->next && (*n)->next->value == v) {
        temp = (*n)->next;
        (*n)->next = (*n)->next->next;
        return temp;
    }
    
    return (*n);
}

// Pops node from queue.
node* pop_queue(node **n) {
    node *temp = (*n);
    (*n) = (*n)->next;
    return temp;
}

// Pops node from stack.
node* pop_stack(node **n) {
    if (!(*n))
        return NULL;
        
    if ((*n)->next)
        pop_stack(&((*n)->next));
    else {
        node *temp = (*n);
        (*n) = NULL;
        free((*n));
        return temp;
    }
    
    return (*n);
}

// Removes node from linked list.
node* delete(node *n, int v) {
    if (!n)
        return NULL;
    
    if (n->value == v) {
        node *temp = n;
        n = n->next;
        free(temp);
    } else {
        n->next = delete(n->next, v);
    }
    
    return n;
}

// Removes node from queue.
node* delete_queue(node *n) {
    node *temp = n;
    n = n->next;
    free(temp);
    return n;
}

// Removes node from stack.
node* delete_stack(node *n) {
    if (!n)
        return NULL;
    
    if (n->next)
        n->next = delete_stack(n->next);
    else {
        n = NULL;
        free(n);
        return NULL;
    }
    
    return n;
}

int main()
{
    return 0;
}
