/* ü�ι����� ������ �ؽ�(���) */
#ifndef ___ChainHash
#define ___ChainHash
#include "Global.h"

/*--- ��Ŷ�� ��Ÿ���� ��� ---*/
typedef struct __node {
	DATA data;			/* ������ */
	struct __node *next;	/* ���� ��忡 ���� ������ */
} Node;

/*--- �ؽ� ���̺� ---*/
typedef struct {
	int size;				/* �ؽ� ���̺��� ũ�� */
	Node **table;			/* �ؽ� ���̺��� ù ��° ��ҿ� ���� ������ */
} ChainHash;

/*--- �ؽ� ���̺� �ʱ�ȭ ---*/
int Initialize(ChainHash *h, int size);

/*--- �˻� ---*/
Node *Search(const ChainHash *h, const int x);

/*--- ������ �߰� ---*/
int Add(ChainHash *h, const DATA *x);

/*--- ������ ���� ---*/
int Remove(ChainHash *h, const DATA *x);

/*--- �ؽ� ���̺� ����(dump) ---*/
void Dump(const ChainHash *h, int x, int* y);

/*--- ��� ������ ���� ---*/
void Clear(ChainHash *h);

/*--- �ؽ� ���̺� ���� ---*/
void Terminate(ChainHash *h);
#endif