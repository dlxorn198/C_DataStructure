#include "C_DataStructure.h"
int main()
{
	printf("--------------LinkedList------------------\n");

	LLptr pList = createLinkedList();
	addNode('H', pList);
	addNode('E', pList);
	addNode('L', pList);
	addNode('L', pList);
	addNode('O', pList);
	addNode(',', pList);
	addNode('W', pList);
	addNode('O', pList);
	addNode('R', pList);
	addNode('L', pList);
	addNode('D', pList);
	addNode('!', pList);
	display(pList);

	deleteNode(',', pList);
	deleteNode('W', pList);
	display(pList);
	destroy_LinkedList(pList);
	printf("--------------------Stack-------------------\n");
	Sptr stack;
	stack = Stack_Init();
	push(stack, 'H');
	push(stack, 'E');
	push(stack, 'L');
	push(stack, 'L');
	push(stack, 'O');
	push(stack, 'W');
	push(stack, ',');
	push(stack, 'W');
	push(stack, 'O');
	push(stack, 'R');
	push(stack, 'L');
	push(stack, 'D');
	printf("%c\n", stack->top->data);
	pop(stack);
	printf("%c\n", stack->top->data);
	pop(stack);
	printf("%c\n", stack->top->data);
	pop(stack);
	printf("%c\n", stack->top->data);
	pop(stack);
	printf("%c\n", stack->top->data);

	destroy_Stack(stack);
	printf("-----------------deQueue---------------------\n");
	Qptr Queue;
	Queue = queue_init();
	insertEnd(Queue, 'H');
	insertEnd(Queue, 'E');
	insertEnd(Queue, 'L');
	insertEnd(Queue, 'L');
	insertEnd(Queue, 'O');
	insertEnd(Queue, '!');
	printf("%d\n", size(Queue));
	deleteEnd(Queue);
	deleteEnd(Queue);
	deleteEnd(Queue);
	printf("%d\n", size(Queue));
	printf("%c\n", getFront(Queue));
	printf("%c\n", getEnd(Queue));
	destroy_deQueue(Queue);
	printf("-----------------Btree---------------------\n");


	/*            5
				 / ＼
				3    7
			   /＼    ＼
			  1  4      9
					   / ＼
					  6   11
	 */

	root = BST_insert(root, 5);
	root = BST_insert(root, 3);
	root = BST_insert(root, 7);
	root = BST_insert(root, 1);
	root = BST_insert(root, 4);
	root = BST_insert(root, 9);
	root = BST_insert(root, 6);
	root = BST_insert(root, 11);


	root = BST_delete(root, 7);
	root = BST_delete(root, 9);
	BST_print(root);
	printf("\n");
	destroy_BST(root);

	printf("-----------------Graph---------------------\n");

	int max = 10;//노드 개수
	init_data(max);
	putdata(0, 'H');
	putdata(1, 'E');
	putdata(2, 'L');
	putdata(3, 'L');
	putdata(4, 'O');
	putdata(5, ',');
	putdata(6, 'W');
	putdata(7, 'O');
	putdata(8, 'R');
	putdata(9, 'L');

	display_data(max);
	printf("\n");
	AdjMatrix* graph1 = createAdjGraph(max);
	if (graph1 != NULL)
	{
		addEdge(graph1, 0, 1);
		addEdge(graph1, 0, 2);
		addEdge(graph1, 1, 3);
		addEdge(graph1, 2, 3);
		addEdge(graph1, 3, 1);
		addEdge(graph1, 4, 5);
		addEdge(graph1, 5, 6);
		addEdge(graph1, 6, 7);
		addEdge(graph1, 7, 8);
		addEdge(graph1, 8, 9);
		addEdge(graph1, 9, 9);
		printf("Graph1: Directed Graph\n");//방향 그래프
		display_graph(graph1);
	}

	deleteGraph(graph1);
	destoy_data(max);


	return 0;
}