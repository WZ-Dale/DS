#pragma once

// ������ʵ��ջ
// ���� ��ѭ�� ����ͷ
// ͷɾ + β��

typedef struct Node {
	int value;
	struct Node *next;
}	Node;

typedef struct Queue {
	Node *head;		// ����ĵ�һ�����
	Node *last;		// ��������һ�����
}	Queue;

void QInit(Queue *q) {
	q->head = NULL;
	q->last = NULL;
}

void QPush(Queue *q, int v) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = v;
	node->next = NULL;

	if (q->head == NULL) {
		q->head = node;
		q->last = node;
	}
	else {
		q->last->next = node;
		q->last = node;
	}
}

void QPop(Queue *q) {
	assert(q != NULL);
	assert(q->head != NULL);

	Node *head = q->head;
	q->head = q->head->next;
	free(head);

	if (q->head == NULL) {
		q->last = NULL;
	}
}

int QFront(Queue *q) {
	return q->head->value;
}

int QSize(Queue *q) {
	int size = 0;
	for (Node *c = q->head; c != NULL; c = c->next) {
		size++;
	}

	return size;
}

int QEmpty(Queue *q) {
	return q->head == NULL ? 1 : 0;
}
