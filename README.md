team08- Library ADT
=============
### 목록
* Node
* LinkedList
* Stack(List 기반)
* deQueue(List 기반)
* BST
* Graph(인접행렬 기반)
### 구조 설명
### Node
## 구조체 변수
# char data: 저장할 데이터 
# Nptr next: 다음 노드를 가리키는 포인터 
# Nptr prev: 전 노드를 가리키는 포인터 
## 함수 
# Nptr createNode(char data) : 새로운 노드를 동적할당을 받고 저장할 데이터와 각포인터들을 초기화하고 리턴함
### LinkedList
## 구조체 변수
# Nptr headerNode: 초기노드를 가리키는 포인터
## 함수 
* LLptr createLinkedList():초기 리스트를 생성하는 함수이다. 
* void addNode(char data, LLptr pList): 저장할 데이터를 리스트형태로 추가하는 함수이다. 추가된 노드의 next와 prev를 알맞게 설정해준다.
* void deleteNode(char data, LLptr pList): 삭제할 데이터를 리스트에서 삭제하는 함수이다. 삭제한 노드를 메모리해제까지 안전하게 한다.
* void display(LLptr pList);현 리스트 상태를 출력하는 함수이다.
* void destroy_LinkedList(LLptr pList);현 리스트에 담겨있는 각 노드들을 차례로 메모리해제를 해주는 함수이다.
### Stack(List 기반)
## 구조체 변수
* Nptr top: 가장 나중에 추가된 노드를 가리키는 포인터 
* int size: 현 스택사이즈
## 함수
* Sptr Stack_Init(): 초기애 스택을 생성하는 함수이다.
* void push(Sptr s, char data): 저장할데이터를 스택에 추가하는 함수이다.
* void pop(Sptr s): 가장 나중에 추가된 노드를 삭제하는 함수이다.
* Nptr Top(Sptr s): 가장 나중에 추가된 노드를 반환하는 함수이다.
* void destroy_Stack(Sptr s); 스택에 담겨있는 데이터들을 삭제하고 메모리해제까지 안전하게 해주는 함수이다.
### deQueue(List 기반)
## 구조체 변수
* Nptr head: 초기 노드를 나타내는 포인터
* Nptr tail: 마지막 노드를 나타내는 포인터 
* int currentsize; 현 데큐 사이즈
## 함수
* Qptr queue_init(): 초기에 데큐를 생성하는 함수이다. 
* void insertFront(Qptr q, char data):맨앞에 저장할데이터를 추가하는 함수
* void insertEnd(Qptr q, char data): 맨뒤에 저장할데이터를 추가하는 함수
* void deleteFront(Qptr q): 맨앞노드를 삭제하는 함수
* void deleteEnd(Qptr q): 맨뒤노드를 삭제하는 함수
* int getFront(Qptr q): 맨앞 노드에 저장되어있는 데이터를 반환하는 함수
* int getEnd(Qptr q): 맨뒤 노드에 저장되어있는 데이터를 반환하는 함수
* int size(Qptr q): 현 데큐의 사이즈를 반환하는 함수
* void destroy_deQueue(Qptr q): 현 데큐에 저장되어있는 데이터를 모두 삭제하고 메모리해제까지 안전하게 해주는 함수
### BST
## 전역변수
* Node_Btree* root = NULL: 루트노드를 가리키는 포인터
## 전역변수
* int value: 저장할 데이터
* struct NodeStruct* leftChild: 왼쪽자식노드를 가리키는 포인터
* struct NodeStruct* rightChild; 오른쪽자식노드를 가리키는 포인터
## 함수
* Node_Btree* BST_insert(Node_Btree* root, int value): 이진탐색트리에 저장할 데이터를 추가하는 함수
* Node_Btree* findMinNode(Node_Btree* root): 크기가 가장 작은 데이터를 반환하는 함수
* Node_Btree* BST_delete(Node_Btree* root, int value) : 삭제해야하는 노드를 삭제,삭제된 노드를 rightChildnode중에서 가장 작은 값을 가지는 노드를 대체
* Node_Btree* BST_search(Node_Btree* root, int value)
* void BST_print(Node_Btree* root): 현 이진탐색트리의 전위 순회를 나타내는 함수
* void destroy_BST(Node_Btree* root): 이진탐색트리에 저장되어있는 데이터를 모두 삭제하고 메모리해제까지 해주는 함수
### Graph(인접행렬 기반)
## 전역변수 
* char* __data = NULL: 저장할 데이터를 1차원배열로 초기화;
## 구조체 변수
* int MAX: 노드의 개수
* int** ppEdge: link를 저장하는 2차원 배열
## 함수
* AdjMatrix* createAdjGraph(int max):초기 그래프 생성하는 함수
* int addEdge(AdjMatrix* pGraph, int tail, int head): tail에서 head로 link 추가하는 함수
* int removeEdge(AdjMatrix* pGraph, int tail, int head): tail에서 head로 link 삭제하는 함수
* int getEdge(AdjMatrix* pGraph, int tail, int head): 해당 link 반환하는 함수
* void display_graph(AdjMatrix* pGraph): 그래프를 행렬모습으로 출력하는 함수 
* void deleteGraph(AdjMatrix* pGraph): 그래프에 있는 각 link들을 삭제하고 tail과 head 메모리를 해제하는 함수