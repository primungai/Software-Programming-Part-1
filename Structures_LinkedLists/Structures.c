# include "Structures.h"

/* This is a prvate function , not exposed in the header file
It factors the initialisation code used in createPoint2D
and createDynamicPoint2D*/

void initPoint2D(Point2D* pNewPoint, double X, double Y, char name[10])
{
	pNewPoint->X = X;
	pNewPoint->Y = Y;
	strcpy(pNewPoint->name, name);
}

void printPoint2D(const Point2D* aPoint)
{
	// The field accesor operator for a structure pointer is "->" 
	if (aPoint != NULL)
		printf("Point2D %s is (%lf, %lf\n", aPoint->name, aPoint->X, aPoint->Y);
	else
		printf("NULL Point2D pointer");

}

 // Function that creates a point
// When you want to create a collection of structures
void createPoint2D(Point2D*point, double X, double Y, char name[10])
{

	/*point->X = X;
	point->Y = Y;
	strcpy(point->name, name);*/

	initPoint2D(point, X, Y, name);

}

Point2D* createDynamicPoint2D(double X, double Y, char name[10])
{
	Point2D* pNewPoint = malloc(sizeof(Point2D));
	if (pNewPoint != NULL)
	{
		/*pNewPoint->X = X;
		pNewPoint->Y = Y;
		strcpy(pNewPoint->name, name);*/
		initPoint2D(pNewPoint, X, Y, name);
	}
	return pNewPoint;
}



void printPoint2DArray(const Point2D* pPointArray, int size)
{
	if (pPointArray != NULL)
	{
		for (int i = 0; i < size; i++)
			printPoint2D(&pPointArray[i]);
	}
}

void printDynPoint2DArray(const Point2D** pPointArray, int size)
{
	if (pPointArray != NULL)
	{
		for (int i = 0; i < size; i++)
			printPoint2D(pPointArray[i]);
	}
}

void deallocatePoint2DArray(Point2D** pPointArray, int size)
{
	if (pPointArray != NULL)
	{
		//Dellocate all the Point2Ds
		for (int i = 0; i < size; i++)
		{
			// Careful with NULL pointers
			if (pPointArray[i] != NULL)
			{
				// deallocate the point
				free(pPointArray);
				// set area to NULL
				pPointArray[i] = NULL;
			}
		}
		// All clear, deallocate the base dimension
		free(pPointArray);
		pPointArray = NULL;
	}
}
	
