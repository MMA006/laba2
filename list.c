#include<stdio.h>
#include<stdlib.h>
#include "list.h"


void init(Node** head, int val) {//инициализаи€ списка
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->value = val;
	tmp->next = NULL;
	(*head) = tmp;
}

Node* getLast(Node* head) {//нахождение последнего элемента
	if (head == NULL) {
		return NULL;
	}
	while (head->next) {
		head = head->next;//////мен€ем значение указател€
	}
	return head;
}

void push(Node** head, int data) {//добавление в начало
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->value = data;
	tmp->next = (*head);
	(*head) = tmp;
}

int pop(Node** head) {//удал€ет элемент, на который указывает head и возвращает его значение.
	Node* prev = NULL;
	int val;
	if (head == NULL)
		exit(-1);
	prev = (*head);
	val = prev->value;
	(*head) = (*head)->next;
	free(prev);
	return val;
}

Node* getNth(Node* head, int n) {//возвращает указатель на n-й элемент списка
	int counter = 0;
	while (counter < n && head) {
		head = head->next;
		counter++;
	}
	return head;
}

int deleteNth(Node** head, int n) {//удалени€ элемента списка
	if (n == 0)
		return pop(head);
	else {
		Node* prev = getNth(*head, n - 1);
		Node* elm = prev->next;
		int val = elm->value;
		prev->next = elm->next;
		free(elm);
		return val;
	}
}

void insert(Node* head, unsigned n, int val) { //вставка по индексу
	unsigned i = 0;
	Node* tmp = NULL;
	while (i < n && head->next) {
		head = head->next;
		i++;
	}
	tmp = (Node*)malloc(sizeof(Node));
	tmp->value = val;
	if (head->next)
		tmp->next = head->next;
	else
		tmp->next = NULL;
	head->next = tmp;
}

void pushBack(Node* head, int value) { // добавление в конец листа
	Node* last = getLast(head);
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->value = value;
	tmp->next = NULL;
	last->next = tmp;
}

void printLinkedList(const Node* head) { // вывод листа
	while (head) {
		printf("%d ", head->value);
		head = head->next;
	}
	printf("\n");
}

Node* getLastButOne(Node* head) {//возвращающа€ указатель на предпоследний элемент
	if (head == NULL)
		exit(-2);
	if (head->next == NULL)
		return NULL;
	while (head->next->next) {
		head = head->next;
	}
	return head;
}

void popBack(Node** head) {
	Node* lastbn = NULL;
	if (!head) //ѕолучили NULL
		exit(-1);
	if (!(*head))//—писок пуст
		exit(-1);
	lastbn = getLastButOne(*head);
	if (lastbn == NULL) { //≈сли в списке один элемент
		free(*head);
		*head = NULL;
	}
	else {
		free(lastbn->next);
		lastbn->next = NULL;
	}
}

void deleteList(Node** head) {// удаление листа
	Node* prev = NULL;
	while ((*head)->next) {
		prev = (*head);
		(*head) = (*head)->next;
		free(prev);
	}
	free(*head);
}
