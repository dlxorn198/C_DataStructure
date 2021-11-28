#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/////////////////////////
//NODE
/////////////////////////
typedef struct _Node* Nptr;
typedef struct _LinkedList* LLptr;
typedef struct _Node {
	char data;
	Nptr next;
	Nptr prev;
}Node;
Nptr createNode(char data);

Nptr createNode(char data)
{
	Nptr newNode = (Nptr)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}
///////////////////////////////////////////////////////////////////
//Linked List
////////////////////////////////////////////////////////////////////
typedef struct _LinkedList* LLptr;
typedef struct _LinkedList {
	Nptr headerNode;
}LinkedList;
LLptr createLinkedList();
void addNode(char data, LLptr pList);
void deleteNode(char data, LLptr pList);
void display(LLptr pList);
void destroy_LinkedList(LLptr pList);

LLptr createLinkedList() {
	LLptr Lptr = NULL;
	Lptr = (LLptr)malloc(sizeof(LinkedList));
	if (Lptr != NULL)
		Lptr->headerNode = NULL;
	else {
		return NULL;
	}

	return Lptr;
}
void addNode(char data, LLptr pList)
{
	Nptr currentNode = NULL;
	Nptr temp = NULL;
	if (pList->headerNode == NULL)
	{
		pList->headerNode = createNode(data);

	}
	else {
		currentNode = pList->headerNode;
		while (currentNode->next != NULL)
			currentNode = currentNode->next;
		temp = createNode(data);
		currentNode->next = temp;
		temp->prev = currentNode;
	}

}

void deleteNode(char data, LLptr pList)
{
	if (pList->headerNode->data == data)//삭제할 노드가 헤드노드일때
	{
		if (pList->headerNode->next != NULL) {
			pList->headerNode->next->prev = NULL;
			pList->headerNode = pList->headerNode->next;
			return;
		}
		else {
			pList->headerNode == NULL;
			return;
		}
	}
	//삭제할 노드가 헤드노드가 아닐때
	Nptr currentNode = pList->headerNode;
	Nptr preNode = NULL;
	while (currentNode->next != NULL && currentNode->data != data) {
		preNode = currentNode;
		currentNode = currentNode->next;
	}
	if (currentNode->data == data) {
		preNode->next = currentNode->next;
		currentNode->prev = preNode;

		free(currentNode);
	}

	/*Nptr currentNode = pList->headerNode;
	Nptr preNode = currentNode;
	while (currentNode != NULL) {
		if (currentNode->data == data) {
			preNode->next = currentNode->next;
			currentNode->prev = preNode;
			if (currentNode == pList->headerNode)
				pList->headerNode = currentNode->next;
			free(currentNode);
			return;
		}
		preNode = currentNode;
		currentNode = currentNode->next;
	}*/
}

void display(LLptr pList) {
	Node* currentNode = pList->headerNode;
	if (pList->headerNode == NULL)
		return;

	for (; currentNode != NULL; currentNode = currentNode->next) {
		printf("%c ", currentNode->data);
	}
	printf("\n");
}
void destroy_LinkedList(LLptr pList) {
	Nptr currentNode = pList->headerNode;
	Nptr nextNode = currentNode;

	while (currentNode != NULL) {
		nextNode = currentNode->next;
		free(currentNode);
		currentNode = nextNode;
	}
	free(pList);
}
//////////////////////////////////////////////////////////////////////
//stack
//////////////////////////////////////////////////////////////////////

typedef struct _Stack* Sptr;
typedef struct _Stack {
	Nptr top;
	int size;
} Stack;
Sptr Stack_Init();
void push(Sptr s, char data);
void pop(Sptr s);
Nptr Top(Sptr s);
void destroy_Stack(Sptr s);
Sptr Stack_Init()
{
	Sptr stack;
	stack = (Sptr)malloc(sizeof(Stack));
	stack->top = NULL;
	stack->size = 0;
	return stack;
}

void push(Sptr s, char data)
{

	Node* newNode = createNode(data);

	Node* currentTop;

	//Top node가 없을때
	if (s->top == NULL) {
		s->top = newNode;
	}

	else {
		currentTop = s->top;
		currentTop->next = newNode;
		newNode->prev = currentTop;
		s->top = newNode;
	}

	s->size++;
}
void pop(Sptr s)
{
	Nptr currentTop = s->top;
	Nptr newTop;
	if (currentTop == NULL)printf("Empty Stack!!\n");
	else {
		newTop = s->top->prev;
		newTop->next = NULL;
		s->top = newTop;
	}
	free(currentTop);
}
Nptr Top(Sptr s)
{
	return s->top;
}
void destroy_Stack(Sptr s)
{
	Nptr delNode = s->top;
	while (delNode != NULL)
	{
		s->top = s->top->prev;
		free(delNode);
		delNode = s->top;
	}
	free(s);
}
////////////////////////////////////////
//deQueue
///////////////////////////////////////
typedef struct _Queue* Qptr;
typedef struct _Queue {
	Nptr head;
	Nptr tail;
	int currentsize;
}Queue;
Qptr queue_init() {
	Qptr q = (Qptr)malloc(sizeof(Queue));
	q->head = q->tail = NULL;
	q->currentsize = 0;
	return q;
}

void insertFront(Qptr q, char data)
{
	Nptr newNode = createNode(data);
	if (q->head == NULL)
		q->head = q->tail = newNode;
	else {
		newNode->next = q->head;
		q->head->prev = newNode;
		q->head = newNode;
	}
	q->currentsize++;
}
void insertEnd(Qptr q, char data) {

	Nptr newNode = createNode(data);
	if (q->tail == NULL) {

		q->head = q->tail = newNode;
	}
	else {

		newNode->prev = q->tail;
		q->tail->next = newNode;

		q->tail = newNode;
	}

	q->currentsize++;
}
void deleteFront(Qptr q) {
	if (q->head == NULL) {
		return;
	}
	if (q->head == q->tail) {
		q->head = q->tail = NULL;
	}
	else {
		Nptr temp = q->head;
		q->head = q->head->next;
		q->head->prev = NULL;

		free(temp);
	}

	q->currentsize--;
}
void deleteEnd(Qptr q) {
	if (q->tail == NULL) {
		return;
	}
	if (q->head == q->tail) {

		q->head = q->tail = NULL;
	}
	else {
		Nptr temp = q->tail;
		q->tail = q->tail->prev;
		q->tail->next = NULL;
		free(temp);
	}

	q->currentsize--;
}
int getFront(Qptr q) {
	return q->head->data;

}
int getEnd(Qptr q) {
	return q->tail->data;
}
int size(Qptr q) {
	return q->currentsize;
}
void destroy_deQueue(Qptr q)
{
	q->tail = NULL;
	while (q->head != NULL) {
		Nptr temp = q->head;
		q->head->prev = NULL;
		q->head = q->head->next;
		free(temp);
	}
	free(q);

}
/////////////////////////////////////////////
//BST
///////////////////////////////////////////
typedef struct NodeStruct
{
	int value;
	struct NodeStruct* leftChild;
	struct NodeStruct* rightChild;
}Node_Btree;

Node_Btree* root = NULL;

Node_Btree* BST_insert(Node_Btree* root, int value)         //insert부분
{
	if (root == NULL)                            //NULL을 만나면 해당위치에 노드를 삽입하고 종료
	{
		root = (Node_Btree*)malloc(sizeof(Node_Btree));
		root->leftChild = root->rightChild = NULL;
		root->value = value;
		return root;
	}
	else
	{
		if (root->value > value)                 //insert값이 현재 노드 값보다 작으면 leftChild방문
			root->leftChild = BST_insert(root->leftChild, value);
		else                                    //insert값이 현재 노드 값보다 크면 rightChild방문
			root->rightChild = BST_insert(root->rightChild, value);
	}
	return root;
}

Node_Btree* findMinNode(Node_Btree* root)                    //root가 주어졌을 때 최솟값을 찾는 코드
{
	Node_Btree* tmp = root;
	while (tmp->leftChild != NULL)
		tmp = tmp->leftChild;
	return tmp;
}

Node_Btree* BST_delete(Node_Btree* root, int value)          //delete부분(삭제해야하는 노드를 삭제),삭제된 노드를 대체해야함=>rightChildnode중에서 가장 작은 값을 가지는 노드를 대체해주면 됨.
{
	Node_Btree* tNode = NULL;
	if (root == NULL)
		return NULL;

	if (root->value > value)
		root->leftChild = BST_delete(root->leftChild, value);
	else if (root->value < value)
		root->rightChild = BST_delete(root->rightChild, value);
	else
	{
		if (root->rightChild != NULL && root->leftChild != NULL)
		{
			tNode = findMinNode(root->rightChild);
			root->value = tNode->value;
			root->rightChild = BST_delete(root->rightChild, tNode->value);
		}
		else
		{
			tNode = (root->leftChild == NULL) ? root->rightChild : root->leftChild;
			free(root);
			return tNode;
		}
	}

	return root;
}

Node_Btree* BST_search(Node_Btree* root, int value)    //search부분,search값이 루트노드보다 클 경우 rightChild노드 방문,작을 경우 leftChild노드 방문,같을 경우 search를 멈춤 
{                                          //방문한 노드가 NUll이 될 때까지 search값을 못 찾으면 트리에 탐색값이 없음            
	if (root == NULL)
		return NULL;

	if (root->value == value)
		return root;
	else if (root->value > value)
		return BST_search(root->leftChild, value);
	else
		return BST_search(root->rightChild, value);
}
void BST_print(Node_Btree* root)
{
	if (root == NULL)
		return;

	printf("%d ", root->value);
	BST_print(root->leftChild);
	BST_print(root->rightChild);
}

void destroy_BST(Node_Btree* root)
{
	if (root != NULL)
	{
		destroy_BST(root->leftChild);
		destroy_BST(root->rightChild);
		printf("destroy node: %d\n", root->value);
		free(root);
	}
}
////////////////////////////////////////////////\
//Graph
////////////////////////////////////////////////
typedef struct Graph {
	int MAX;//노드의 개수
	int** ppEdge;//link를 저장하는 2차원 배열
}AdjMatrix;

char* __data = NULL;
void init_data(int max)
{
	__data = (char*)malloc(sizeof(char) * max);
}
void putdata(int index, char _data)
{
	__data[index] = _data;
}
void destoy_data(int max)
{
	for (int i = max; i = 0; i--) {
		__data[i] = NULL;
	}
	free(__data);
}
void display_data(int max)
{
	for (int i = 0; i < max; i++)
		printf("%c ", __data[i]);
}

AdjMatrix* createAdjGraph(int max);//그래프 생성
int addEdge(AdjMatrix* pGraph, int tail, int head);//link 추가
int removeEdge(AdjMatrix* pGraph, int tail, int head);//link 삭제
int getEdge(AdjMatrix* pGraph, int tail, int head);//해당 link 반환
void display_graph(AdjMatrix* pGraph);//행렬로 출력
void deleteGraph(AdjMatrix* pGraph);//메모리 해제

AdjMatrix* createAdjGraph(int max)
{
	int i = 0;
	AdjMatrix* pReturn = NULL;
	pReturn = (AdjMatrix*)malloc(sizeof(AdjMatrix));
	if (pReturn == NULL)
	{
		return NULL;
	}
	pReturn->MAX = max;
	pReturn->ppEdge = (int**)malloc(sizeof(int*) * max);
	if (pReturn->ppEdge == NULL)
	{
		return NULL;
	}
	for (i = 0; i < max; i++)
	{
		pReturn->ppEdge[i] = (int*)malloc(sizeof(int) * max);
		if (pReturn->ppEdge[i] == NULL)
		{
			return NULL;
		}
		for (int j = 0; j < max; j++)
		{
			pReturn->ppEdge[i][j] = 0;
		}
	}
	return pReturn;
}
int addEdge(AdjMatrix* pGraph, int tail, int head)
{
	pGraph->ppEdge[tail][head] = 1;
	return 0;
}
int removeEdge(AdjMatrix* pGraph, int tail, int head)
{
	pGraph->ppEdge[tail][head] = 0;
	return 0;
}
int getEdge(AdjMatrix* pGraph, int tail, int head)
{
	return pGraph->ppEdge[tail][head];
}
void display_graph(AdjMatrix* pGraph)
{
	int i = 0, j = 0, k = 0;
	int count = 0;
	if (pGraph != NULL)
	{
		count = pGraph->MAX;
		printf(" :");
		for (k = 0; k < count; k++)
			printf("%c", __data[k]);
		printf("\n");
		for (i = 0; i < count; i++)
		{
			printf("%c:", __data[i]);
			for (j = 0; j < count; j++)
			{
				printf("%d", getEdge(pGraph, i, j));
			}
			printf("\n");
		}
	}
}
void deleteGraph(AdjMatrix* pGraph)
{
	int i = 0;
	if (pGraph != NULL)
	{
		for (i; i < pGraph->MAX; i++)
		{
			free(pGraph->ppEdge[i]);
		}
		free(pGraph->ppEdge);
		free(pGraph);
	}
}