
# include "Structures.h"
# include "IntegerList.h"

int main()
{
	/*example without a proper list management structure
	IntegerElement e1, e2;
	e1.value = 5;
	e1.pNextElement = NULL;

	e2.value = 10;
	e2.pNextElement = NULL;

	//chain e2 to e1
	e1.pNextElement = &e2;

	IntegerElement* pE3, *pE4;
	pE3 = malloc(sizeof(IntegerElement));
	pE4 = malloc(sizeof(IntegerElement));

	pE3->value = 50;
	pE4->value = 100;
	pE3->pNextElement = pE4;
	pE4->pNextElement = NULL;
	return 0; */


	// STATIC LIST AND ELEMENTS//
	// create a local variable l1
	IntegerList l1;
	// pass the address of l1 to initialize the list
	initIntegerList(&l1);

	IntegerElement e1;
	/*e1.value = 14;
	e1.pNextElement = NULL;*/

	// pass the  element address, value and next element address
	initIntegerElement(&e1, 14, NULL);

	IntegerElement e2;
	initIntegerElement(&e2, 54, NULL);

	addElementtoTail(&l1, &e2);

	IntegerElement *pRemoved = removeElementFromTail(&l1);

	// DYNAMIC ALLOCATION

	//Dynamic allocation of the list structure possible, yet not of particular
	// importance

	IntegerList *pList = mallocc(sizeof(IntegerList));
	initIntegerList(pList);

	IntegerElement  *e6, *e7, *e8;
	e6 = malloc(sizeof(IntegerElement));
	e7 = malloc(sizeof(IntegerElement));
	e8 = malloc(sizeof(IntegerElement));
    //chaining outside the list management function leads to a dirty list
	// Here wrong element count means a wrong tail pointer
    /*initIntegerElement(e8, 60, NULL);
	initIntegerElement(e7, 50, e8);
	initIntegerElement(e6, 40, e7);*/

	initIntegerElement(e8, 60, NULL);
	initIntegerElement(e7, 50, NULL);
	initIntegerElement(e6, 40, NULL);
	addElemetToTail(pList, e6);
	addElemetToTail(pList, e7);
	addElemetToTail(pList, e8);


	system("pause");
	return 0;


}

int main_forPoint2D_ArrayCollection()
{

	// typedef name used, so that we don't need to write struct Point2D
	Point2D A;
	// Accsessing the field of the structure via operator "."
	// Use strcpy to place the string value of A in the name field of the 
	// structure called A

	A.X = 2;
	A.Y = 5;
	strcpy(A.name , "A");

	// Takes a pointer so pass the address of A
	printPoint2D(&A);

	// We want to have a collection of Point2D

	// Option 1: With a static array
	// Point2D pointsArray[3];

	Point2D B;
	createPoint2D(&B, 1, 2, "B");
	Point2D C;
	createPoint2D(&C, 6, 10, "C");

	Point2D pointsArray[3] = { A,B,C };

	// Display the collection based on stack array
	printPoint2DArray(pointsArray, 3);

	// Create a dynamic array of points to be allocated by malloc
	int nbPoints;
	printf("How many points do you need?:");
	scanf("%d, &nbPoints");

	
	// Stack Pointer to attach memory area in the heap, given malloc
	Point2D* pDynArray = malloc(sizeof(Point2D) * nbPoints);
	if (pDynArray != NULL)
	{
		pDynArray[0] = A;
		pDynArray[1] = B;
		pDynArray[2] = C;

		printPoint2DArray(pDynArray, nbPoints);
	}
	free(pDynArray);
	pDynArray = NULL;

	// Scenario 3: A dynamic collection(array) of dynamically created points
	printf("\n ****\n Scenario 3: Dynamic array of dynamic Point2D");
	printf("How many points do you need?:");
	scanf("%d", &nbPoints);

	// Array of Point2D*: each item of the array is a pointer towards a 
	// dynamically allocated Point2D
	Point2D** pPointCollection = malloc(sizeof(Point2D*) * nbPoints);
	for (int i = 0; i < nbPoints; i++)
	{
		printf("Point %d creation\n", i + 1);

		double X, Y;
		char name[10];
		printf(" X= ");
		scanf("%lf", &X);
		printf(" Y = ");
		scanf("%lf", &Y);
		printf(" Point name = ");
		scanf("%s", &name);

		// Point2D needs to be created
		Point2D* pNewPoint = createDynamicPoint2D(X, Y, name);
		pPointCollection[i] = pNewPoint;
			
	}
	printDynPoint2DArray(pPointCollection, nbPoints);

	deallocatePoint2DArray(pPointCollection, nbPoints);


	system("pause");
}