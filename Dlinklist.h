#ifndef _CIRCLELIST_H_
#define _CIRCLELIST_H_

typedef void DLinklist;

typedef struct _tag_DLinklistNode
{
	struct _tag_DLinklistNode * next;
	struct _tag_DLinklistNode * pre;
}DLinklistNode;

DLinklist* DLinklist_Create();

void DLinklist_Destroy(DLinklist* list);

void DLinklist_Clear(DLinklist* list);

int DLinklist_Length(DLinklist* list);

int DLinklist_Insert(DLinklist* list, DLinklistNode* node, int pos);

DLinklistNode* DLinklist_Get(DLinklist* list, int pos);

DLinklistNode* DLinklist_Delete(DLinklist* list, int pos);

//add

DLinklistNode* DLinklist_DeleteNode(DLinklist* list, DLinklistNode* node);

DLinklistNode* DLinklist_Reset(DLinklist* list);

DLinklistNode* DLinklist_Current(DLinklist* list);

DLinklistNode* DLinklist_Next(DLinklist* list);

DLinklistNode* DLinklist_Pre(DLinklist* list);

#endif