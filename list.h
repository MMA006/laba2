#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int value;
	struct Node* next;
} Node;

void init(Node** head, int val);

Node* getLast(Node* head);

void push(Node** head, int data);

int pop(Node** head);

Node* getNth(Node* head, int n);

int deleteNth(Node** head, int n);

void insert(Node* head, unsigned n, int val);

void pushBack(Node* head, int value);

void printLinkedList(const Node* head);

Node* getLastButOne(Node* head);

void popBack(Node** head);

void deleteList(Node** head);
