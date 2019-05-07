///////////////////////////////////////
/*
      �ܼ����Ḯ��Ʈ �����ϱ�
									 */
///////////////////////////////////////
//head ������ ��带 ����Ű�� ������
//����Ʈ ������ ����� ������ ��:NULL
//ü������ ����� ����
// ���= data+link

#include <cstdio>
#include <cstdlib>

//�ܼ� ���� ����Ʈ�� ��� ������ ����ü�� ����
typedef struct node {
	int data;
	struct node* link;

}node;

//����Ʈ�� ������ ��Ÿ���� head ��带 ����ü�� ����
typedef struct {
	node* head;
}listhead;

//���� ���� ����Ʈ�� �����ϴ� ����
listhead* create_Listhead(void) {
	listhead* L;
	L = (listhead*)malloc(sizeof(listhead)); //�޸� �����Ҵ�
	L->head = NULL; //���� ����Ʈ�̹Ƿ� ���� ����� �ּҰ��� NULL
	return L;
}

//��� �����ϴ� ����
node* create_Node(int x) {
	node* newNode;
	newNode = (node*)malloc(sizeof(node));
	newNode->data = x;
	newNode->link = NULL;
	return newNode;
}

//��� ã�� ����
node* search_Node(listhead* L, int x) {
	node* p;
	p = L->head;
	while (p != NULL) {//���� ����Ʈ�� ������ ������ ã��
		if (p->data == x)
			return p;//ã�� ��� ��ȯ
		p = p->link;
	}
	return NULL;
}

//��� �����ϴ� ����
void insert_Node(listhead* L, node* preNode, node* newNode) {
	if (L == NULL) {//���� ����Ʈ�� ���
		L->head = newNode; //�� ��带 ù ��°���� ������ ���� ����
	}
	else if (preNode == NULL) {//���� ��ġ�� �����ϴ� ������ pre�� NULL�� ���
		newNode->link = L->head;
		L->head = newNode;//�� ��带 ù ��° ���� ����
	}
	else {
		newNode->link = L->head;
		L->head = newNode; //�� ��带 ù ��° ���� ����
		preNode->link = newNode;
	}
}

//��� �����ϴ� ����
int remove_Node(listhead* L, int x) {
	node* p;
	node* removeNode;
	p = L->head;

	while (p != NULL) {//���� ����Ʈ�� ������ ������ ã��
		if (p->link != NULL) {
			if (p->link->data == x)
				break;
		}
		p = p->link;
	}
	if (p != NULL) {
		removeNode = p->link; //������ ��带 remove�� ����Ű�� ��
		p->link = removeNode->link;//������ ��� �������� ���� ��� ����
		free(removeNode); //�޸� ����
		return 0;
	}
	else {
		return -1;
	}
}

//��� ���� ������ ����
void reverse(listhead* L) {
	node* p;//���� ����Ʈ
	node* q;//�������� ���� ����Ʈ
	node* r;//�ӽ����� ���

	p = L->head;
	q = NULL;
	r = NULL;
	
	//����Ʈ�� ù��° ������ �̵��ϸ鼭 ��尣�� ������ �ٲ�
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	L->head = q;
}

//���� ����Ʈ�� ��ü �޸𸮸� �����ϴ� ����
void freelisthead(listhead* L) {
	node* p;
	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}

//���� ����Ʈ�� ������� ����ϴ� ����
void printList(listhead* L) {
	node* p;
	p = L->head; //p�� ù��° ������

	printf("L=(");
	while (p != NULL) {//������ ������ �ϳ��� �̵� �� �ݺ��� ����
		printf("%d", p->data);//�湮�� ����� ������(���ĺ� ���)
		p = p->link;//�������� �̵�
		if (p != NULL) printf(", ");//������ ��尡 �ƴ϶��, ���
	}
	printf(") \n");
}

int main() {
	listhead* L;
	L = create_Listhead();
	printf("(1) ���� ����Ʈ �����ϱ�! \n");
	printList(L);
	printf("\n");

	printf("(2) ù��° ��忡 �� �����ϱ�! \n");
	insert_Node(L, NULL, create_Node(60)); //60
	printList(L);
	insert_Node(L, NULL, create_Node(50)); //50->60
	printList(L);
	insert_Node(L, NULL, create_Node(30)); //30->50->60
	printList(L);
	insert_Node(L, NULL, create_Node(20)); //20->30->50->60
	printList(L);
	insert_Node(L, NULL, create_Node(10)); //10->20->30->50->60
	printList(L);
	printf("\n");

	printf("(2) �߰���� 30 �ڿ� ��� �����ϱ�! \n");
	node* p = search_Node(L, 30);//�����Ͱ� 30�� ��� �˻�
	insert_Node(L, p, create_Node(40));//�˻��� p��� ������ 40 �߰�
	printList(L);
	printf("\n");

	printf("(3) ������ ������ �� �����ϱ�! \n");
	remove_Node(L, 60); //�����Ͱ� 60�� ��� ����
	printList(L);//10->20->30->40->50->60
	printf("\n");

	printf("(4) ����Ʈ�� �������� �ٲٱ�! \n");
	reverse(L);
	printList(L);//50->40->30->20->10
	printf("\n");

	printf("(5) ����Ʈ ���� \n");
	freelisthead(L);
	printList(L);

	return 0;
}