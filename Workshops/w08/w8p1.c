#define _CRT_SECURE_NO_WARNINGS


// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* intergerNumber)
{
	int inputValue;
	int doAgain;

	do
	{
		scanf("%d", &inputValue);  
		if (inputValue <= 0)
		{
			printf("ERROR: Enter a positive value: ");
			doAgain = 1;
		}
		else
		{
			doAgain = 0;
		}
	} while (doAgain);

	if (intergerNumber != NULL) 
	{
		*intergerNumber = inputValue;  
	}

	return inputValue;  
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* decimalNumber) 
{
	double inputValue;
	int doAgain; 

	do
	{
		scanf("%lf", &inputValue);
		if (inputValue <= 0)
		{
			printf("ERROR: Enter a positive value: ");
			doAgain = 1;
		}
		else
		{
			doAgain = 0;
		}
	} while (doAgain);

	if (decimalNumber != NULL)   
	{
		*decimalNumber = inputValue;   
	}

	return inputValue;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numOfproducts) 
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n");
	printf("\n");

	printf("Enter the details for %d dry food bags of product data for analysis.\n", MAX_PRODUCTS);
	printf("NOTE: A 'serving' is %dg\n", GRAMS_VALUE);   
	printf("\n");
}


// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequenceNumber)  
{
	//Creating and allocating memory for an instance object of the struct CatFoodInfo called cfi
	struct CatFoodInfo catfoodinfo = {0}; 

	int return_int_value; 
	double return_double_value;

	printf("Cat Food Product #%d\n", sequenceNumber + 1);  
	printf("--------------------\n");   
	
	//SKU 
	printf("SKU           : "); 
	catfoodinfo.skuNumber = getIntPositive(&return_int_value);    

	//PRICE
    printf("PRICE         : $");
	catfoodinfo.productPrice = getDoublePositive(&return_double_value);    
	
	//WEIGHT
	printf("WEIGHT (LBS)  : "); 
	catfoodinfo.productWeight = getDoublePositive(&return_double_value);  
	
	//CALORIES/SERV
	printf("CALORIES/SERV.: ");
	catfoodinfo.caloriesServing = getIntPositive(&return_int_value); 

	printf("\n"); 

	//Returning CatFoodInfo value
	return catfoodinfo; 
}


// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku_num, const double* productPrice, const int calorieServing, const double* productWeightInLbs)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku_num, *productPrice, *productWeightInLbs, calorieServing); 
}


// 7. Logic entry point
void start(void)
{
	struct CatFoodInfo catfoodinfo[MAX_PRODUCTS] = { {0} }; 
	int i;

	openingMessage(MAX_PRODUCTS);

	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		catfoodinfo[i] = getCatFoodInfo(i); 
	}

	displayCatFoodHeader();

	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		displayCatFoodData(catfoodinfo[i].skuNumber, &catfoodinfo[i].productPrice, catfoodinfo[i].caloriesServing, &catfoodinfo[i].productWeight); 
	}

}