#pragma once
# include "Libraries.h"

//typedef requires two arguements
//argument 1 = struct IntegerElement
// arguement 2????
typedef struct IntegerElement;

// There is a structure called IElement, defined later in the code
// This allows the compiler to be aware and allow the existance of struct IElement
struct IElement;

// the name of the structure is IElement
// The structure's typedef is IntegerElement 
typedef struct IElement
{
	//data part
	int value;

	// We want a pointer pNext, pointer on IntegerElement*
	// but I am in the process of declaring IntegerElement
	// Cyclic definition problem
	// IntegerElement* pNextElement

	struct IElement* pNextElement;

}IntegerElement;

typedef struct
{
	int NbElements;
	IntegerElement* pHead;
	IntegerElement* pTail;
}IntegerList;

// List Management function
void initIntegerList(IntegerList* pList);

void addElementtoTail(IntegerList *pList, IntegerElement* pElement);

/*Traditionally,when you remove elements from linked list, the list management
function (removeElementFromTail) should not be in charge of deallocating the memory
of the element*/
IntegerElement* removeElementFromTail(IntegerList *pList);
// List Element Management function

void initIntegerElement(IntegerElement* pElement, int value,
	IntegerElement* pNext);