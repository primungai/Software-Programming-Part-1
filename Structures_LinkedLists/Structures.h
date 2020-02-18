#pragma once

# include "Libraries.h"

// typedef takes 2 arguments
	// 1. The actual data type: anonymous structure(no name after struct keyword)
	// 2. new data type name: Point2D
// Anonymous structure, no name after keyword struct
typedef struct
{
	// 2 scalar attributes and one vector attribute
	double X;
	double Y;
	char name[10];
} Point2D;

// This procedure was made for initializing an existing point in the stack
void createPoint2D(Point2D*point, double X, double Y, char name[10]);

Point2D* createDynamicPoint2D(double X, double Y, char name[10]);
// Traditionally we pass structure by pointer
//  Why use "const": this a print/display procedure, so under no circumstances
// should this code be able to modify the content of a point passed by reference
void printPoint2D(const Point2D* aPoint);

// Passing a collection (array) of points
// strings are exceptions, in C and C++, the size of an array is unknown
void printPoint2DArray(const Point2D* pPointArray, int size);

void printDynPoint2DArray(const Point2D** pPointArray, int size);

void deallocatePoint2DArray(Point2D** pPointArray, int size);