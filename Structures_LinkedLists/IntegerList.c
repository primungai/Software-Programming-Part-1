# include "IntegerList.h"


void initIntegerElement(IntegerElement* pElement, int value,
	IntegerElement* pNext)
{
	if (pElement != NULL)
	{
		pElement->value = value;
		pElement->pNextElement = pNext;
	}
}
void initIntegerList(IntegerList* pList)
{
	if (pList = !NULL)
	{
		pList->NbElements = 0;
		pList->pHead = NULL;
		pList->pTail = NULL;
	}
}


void addElementtoTail(IntegerList *pList, IntegerElement* pElement)
{
	if (pList = !NULL && pElement != NULL)
	{
		// Simple: case the list is empty
		if (pList->NbElements == 0)
		{
			//Circular, empty list
			//Head == Tail

			pList->pHead = pElement;
			pList->pTail = pElement;

			
		}
		else
		{
			// The list is not empty
			// pTail must change to the new inserted element
			// pNew of the previous tail,must change to the new element

			// "Backup " pointer on the current last element
			IntegerElement* pPreviousElement = pList->pTail;

			// Change the Tail, to the new element to be added
			pList->pTail = pElement;

			// Link the previous tail element to the new tail element
			pPreviousElement->pNextElement = pElement;

		}
		pList->NbElements++;
	}
		
}

// We want to change the tail to the pen-ultimate element
IntegerElement* removeElementFromTail(IntegerList *pList)
{
	IntegerElement* pRemovedElement = NULL;

	if (pList != NULL)
	{
		if (pList->NbElements > 0)
		{
			// current tail, to be removed
			pRemovedElement = pList->pTail;

			//The new tail should be the element before the current tail
			// --pRemovedElement

			// but the list is forward only , so we need to browse the whole list


			// The while loop will iterate over the list , from the head,
			// and stops whenever the @current item == @pRemovedElement

			// Get the cursor at the start of the list
			IntegerElement* pCurrentElement = pList->pHead;

			// while the cursor is not the one we want to remove

			BOOL stop = FALSE;
			// Is the current the one to be removed, do we carry on, 
			// are we at the end of the list
			while (pCurrentElement != pRemovedElement && stop == FALSE
				&& pCurrentElement ->pNextElement != NULL)
			{
				IntegerElement*pNext = pCurrentElement->pNextElement;
				if (pNext == pRemovedElement)
				{
					pList -> pTail = pCurrentElement;
					stop = TRUE;
				}

				pCurrentElement = pNext;
			}
			pList->NbElements--;
		}
	}
	return pRemovedElement;
}

