#include <stdio.h>
#include <malloc.h>
#include "DLinklist.h"

typedef struct _tag_DLinklist
{
	DLinklistNode header;
	DLinklistNode* slider;
	int length;
} DLinklist;

DLinklist* DLinklist_Create() // O(1)
{
	DLinklist* ret = (DLinklist*)malloc(sizeof(DLinklist));
	if (ret == NULL)
	{
		return NULL;
	}
	
	ret->length = 0;
	ret->header.next = NULL;
	ret->header.pre = NULL;
	ret->slider = NULL;
	return ret;
}

void DLinklist_Destroy(DLinklist* list) // O(1)
{
	if (list == NULL)
	{
		return ;
	}
	free(list);
}

void DLinklist_Clear(DLinklist* list) // O(1)
{
	DLinklist* sList = (DLinklist*)list;
	if (sList == NULL)
	{
		return ;
	}
	sList->length = 0;
	sList->header.next = NULL;
	sList->header.pre = NULL;
	sList->slider = NULL;
}

int DLinklist_Length(DLinklist* list) // O(1)
{
	DLinklist* sList = (DLinklist*)list;
	int ret = -1;
	if (list == NULL)
	{
		return ret;
	}
	ret = sList->length;
	return ret;
}

int DLinklist_Insert(DLinklist* list, DLinklistNode* node, int pos) // O(n)
{ 
	int ret = 0, i=0;
	DLinklist* sList = (DLinklist*)list;

	if (list == NULL || node== NULL || pos<0)
	{
		return -1;
	}
	//if( ret )
	{
		DLinklistNode* current = (DLinklistNode*)sList;
		DLinklistNode* next = NULL;//需要增加next指针

		for(i=0; (i<pos) && (current->next != NULL); i++)
		{
			current = current->next;
		}

		next = current->next;
		//步骤1-2
		current->next = node;
		node->next = next; 
		//步骤3-4
		if(next != NULL)//当链表插入第一个元素，需要特殊处理
		{
			next->pre = node;
		}
		node->pre = current;

		//当链表插入第一个元素处理游标
		if( sList->length == 0 )
		{
			sList->slider = node;
		}
		//若在0位置插入，需要特殊处理，新来节点next前pre指向null
		if( current == (DLinklistNode*)sList )
		{
			node->pre = NULL;
		}
		sList->length++;
	}
	return ret;
}

DLinklistNode* DLinklist_Get(DLinklist* list, int pos) // O(n)
{
	DLinklist* sList = (DLinklist*)list;
	DLinklistNode* ret = NULL;
	int i = 0;

	if (list==NULL || pos<0)
	{
		return NULL;
	}
	//if( (sList != NULL) && (pos >= 0) && (sList->length > 0) )
	{
		DLinklistNode* current = (DLinklistNode*)sList;

		for(i=0; i<pos; i++)
		{
			current = current->next;
		}

		ret = current->next;
	}

	return ret;
}

DLinklistNode* DLinklist_Delete(DLinklist* list, int pos) // O(n)
{
	DLinklist* sList = (DLinklist*)list;
	DLinklistNode* ret = NULL;
	int i = 0;

	if( (sList != NULL) && (pos >= 0) && (sList->length > 0) )
	{
		DLinklistNode* current = (DLinklistNode*)sList;
		DLinklistNode* next = NULL;//需要增加next指针

		for(i=0; i<pos; i++)
		{
			current = current->next;
		}

		ret = current->next;
		next = ret->next;

		
		//步骤1
		current->next = next;
		//步骤2
		if(next != NULL)//需要特殊处理
		{
			next->pre = current;
			if(current == (DLinklistNode*)slist)//若第0个位置，需要特殊处理
			{
				next->pre = NULL;
			}
		}
	
		if(slist->slider == ret)
		{
			slist->slider = next;
		}
		sList->length--;
		
	}

	return ret;
}

DLinklistNode* DLinklist_DeleteNode(DLinklist* list, DLinklistNode* node) // O(n)
{
	DLinklist* sList = (DLinklist*)list;
	DLinklistNode* ret = NULL;
	int i = 0;

	if( sList != NULL )
	{
		DLinklistNode* current = (DLinklistNode*)sList;
		
		DLinklistNode* ret = NULL;
		int i = 0;
		if(slist != NULL)
		{
			DLinklistNode* current = (DLinklistNode*)slist;
			for(i = 0; i < slist->length; i++)
			{
				ret = current->next;
				break;
			}
			current = current->next;
		}
		
		if( ret != NULL )
		{
			DLinklist_Delete(sList, i);
		}
	}

	return ret;
}

DLinklistNode* DLinklist_Reset(DLinklist* list) // O(1)
{
	DLinklist* sList = (DLinklist*)list;
	DLinklistNode* ret = NULL;

	if( sList != NULL )
	{
		sList->slider = sList->header.next;
		ret = sList->slider;
	}

	return ret;
}

DLinklistNode* DLinklist_Current(DLinklist* list) // O(1)
{
	DLinklist* sList = (DLinklist*)list;
	DLinklistNode* ret = NULL;

	if( sList != NULL )
	{
		ret = sList->slider;
	}

	return ret;
}

DLinklistNode* DLinklist_Next(DLinklist* list) // O(1)
{
	DLinklist* sList = (DLinklist*)list;
	DLinklistNode* ret = NULL;

	if( (sList != NULL) && (sList->slider != NULL) )
	{
		ret = sList->slider;
		sList->slider = ret->next;
	}

	return ret;
}

DLinklistNode* DLinklist_Pre(DLinklist* list) // O(1)
{
	DLinklist* sList = (DLinklist*)list;
	DLinklistNode* ret = NULL;

	if( (sList != NULL) && (sList->slider != NULL) )
	{
		ret = sList->slider;
		sList->slider = ret->pre;
	}

	return ret;
}
