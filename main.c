#include<stdio.h>
#include<stdlib.h>
#include "list.h"

int main() {
    Node* head = NULL;
    init(&head, 10);//инициализация

    push(&head, 0);
    push(&head, 110);
    push(&head, 220);
    pushBack(head, 1);
    pushBack(head, 2);
    pushBack(head, 3);
    insert(head, 5, 4);
    printLinkedList(head);

    Node* tmp = getNth(head, 3);
    printf("\n%d\n\n", tmp->value);
    //Удаляем ..четвертый.. элемент (индексация с нуля)
    deleteNth(&head, 4);
    printLinkedList(head);
    deleteList(&head);

    return 0;
}