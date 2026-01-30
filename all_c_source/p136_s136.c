#include <stdio.h>
#include <stdlib.h>
#define NIL NULL

typedef struct node {
    int key;
    int priority;
    struct node *right, *left;
} Node;

Node *Delete(Node **, int);
Node *delete(Node **, int);

int find(Node *p, int x) {
    while (p != NIL) {
        if (p->key == x)
            return 1;
        else if (p->key > x)
            p = p->left;
        else
            p = p->right;
    }
    return 0;
}

void inorder(Node *a) {
    if (a->left != NIL) inorder(a->left);
    printf(" %d", a->key);
    if (a->right != NIL) inorder(a->right);
    return;
}

void preorder(Node *p) {
    printf(" %d", p->key);
    if (p->left != NIL) preorder(p->left);
    if (p->right != NIL) preorder(p->right);
    return;
}

void print(Node *p) {
    inorder(p);
    printf("\n");
    preorder(p);
    printf("\n");
    return;
}

Node *makenode(int x, int y) {
    Node *new = malloc(sizeof(Node));
    new->key = x;
    new->priority = y;
    new->left = NIL;
    new->right = NIL;
    return new;
}

Node *rightRotate(Node *p) {
    Node *q = p->left;
    p->left = q->right;
    q->right = p;
    return q;
}

Node *leftRotate(Node *p) {
    Node *q = p->right;
    p->right = q->left;
    q->left = p;
    return q;
}

Node *insert(Node **t, int key, int priority) {
    Node *new;
    if ((*t) == NIL) return new = makenode(key, priority);
    if ((*t)->key == key) return *t;

    if (key < (*t)->key) {
        (*t)->left = insert(&(*t)->left, key, priority);
        if ((*t)->priority < (*t)->left->priority) (*t) = rightRotate(*t);
    } else {
        (*t)->right = insert(&(*t)->right, key, priority);
        if ((*t)->priority < (*t)->right->priority) (*t) = leftRotate((*t));
    }
    return *t;
}

Node *Delete(Node **t, int key) {
    if ((*t) == NIL) return NIL;

    if (key < (*t)->key)
        (*t)->left = Delete(&((*t)->left), key);

    else if (key > (*t)->key)
        (*t)->right = Delete(&((*t)->right), key);

    else
        return delete (t, key);
    return *t;
}

Node *delete(Node **t, int key) {
    if ((*t)->left == NIL && (*t)->right == NIL) {
        return NIL;
    } else if ((*t)->left == NIL) {
        (*t) = leftRotate(*t);
    } else if ((*t)->right == NIL) {
        (*t) = rightRotate(*t);
    } else {
        if ((*t)->left->priority > (*t)->right->priority)
            (*t) = rightRotate(*t);
        else
            (*t) = leftRotate(*t);
    }
    return Delete(t, key);
}

int main(void) {
    int num, x, y;
    char com[8];
    Node *root = NIL;
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        scanf("%s", com);
        switch (com[0]) {
            case 'i':
                scanf("%d %d", &x, &y);
                root = insert(&root, x, y);
                break;
            case 'd':
                scanf("%d", &x);
                root = Delete(&root, x);
                break;
            case 'f':
                scanf("%d", &x);
                if (find(root, x))
                    printf("yes\n");
                else
                    printf("no\n");
                break;
            case 'p':
                print(root);
                break;
        }
    }
    return 0;
}