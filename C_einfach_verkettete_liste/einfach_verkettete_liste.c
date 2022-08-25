#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    struct ListElement *next;
} ListElement;

typedef struct {
    ListElement *first;
} List;

void insertElement(ListElement *newElement, List *list) {
    ListElement *tmp;
    tmp = list->first;
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = newElement;
}

void deleteElement(ListElement *delElement, List *list) {
    ListElement *tmp;
    ListElement *del;
    tmp = list->first;

    if(tmp == delElement) {
        list->first = tmp->next;
        free(tmp);
        return;
    }

    while(tmp != NULL) {
        if(tmp->next == delElement) {
            del = tmp->next;
            tmp->next = del->next;
            free(del);
        }
        tmp = tmp->next;
    }
}

void printList(List *list) {
    ListElement *tmp = list->first;
    while(tmp != NULL) {
        printf("%d\n", tmp->val);
        tmp = tmp->next;
    }
    printf("_________\n");
}

int main() {
    List list;

    ListElement *a;
    a = malloc(sizeof(ListElement));
    a->val = 10;
    a->next = NULL;

    ListElement *b;
    b = malloc(sizeof(ListElement));
    b->val = 15;
    b->next = NULL;

    insertElement(a, &list);
    insertElement(b, &list);

    printList(&list);

    deleteElement(b, &list);

    return 0;
}