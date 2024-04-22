#define _CRT_SECURE_NO_WARNINGS


// System Libraries
#include <stdio.h>


// User-Defined Libraries
#include "w8p2.h" 

// 1. Get user input of int type and validate for a positive non - zero number
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
	struct CatFoodInfo catfoodinfo = { 0 };

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
void displayCatFoodData(const int sku_num, const double* product_price, const int calorie_serving, const double* product_weight_lbs)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku_num, *product_price, *product_weight_lbs, calorie_serving); 
}



// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* poundsToBeConverted, double* conversionresultToKg)
{
	double weightInKg = (*poundsToBeConverted) / POUNDSTOKG;

	if (conversionresultToKg != NULL)
	{
		*conversionresultToKg = weightInKg; 
	}
	return weightInKg; 
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* poundsToBeConverted, int* conversionresultToG)
{

	double kgResult = convertLbsKg(poundsToBeConverted, NULL);
	int weightInG = (int)(kgResult * 1000);   

	if (conversionresultToG != NULL) 
	{
		*conversionresultToG = weightInG;  
	}
	return weightInG;  
}

// 10. convert lbs: kg and g
void convertLbs(const double* poundsToBeConverted, double* conversionresultToKg, int* conversionresultToG)
{
	double weightInKg = convertLbsKg(poundsToBeConverted, conversionresultToKg);  
	int weightInG = convertLbsG(poundsToBeConverted, conversionresultToG);

	if (conversionresultToKg != NULL && conversionresultToG != NULL)
	{
		*conversionresultToKg = weightInKg;  
		*conversionresultToG = weightInG; 
    }
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int sizeInGrams, const int totalGrams, double* numOfServings)
{
	double totalServings = ((double)totalGrams) / sizeInGrams;
	if (numOfServings != NULL) 
	{
		*numOfServings = totalServings; 
	}
	return totalServings;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* productPrice, const double* numberOfServings, double* result) 
{
	double costPerServing = (*productPrice) / (*numberOfServings);
	if (result != NULL)
	{
		*result = costPerServing;
	}
	return costPerServing;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* productPrice, const double* totalCalories, double* result)
{
	double costPerCal = (*productPrice) / (*totalCalories);

	if (result != NULL)
	{
		*result = costPerCal; 
	}
	return costPerCal; 
}


// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData( struct CatFoodInfo catfoodinfo)  
{
	struct ReportData reportdata;

	// Assigning Values
	reportdata.skuNumber = catfoodinfo.skuNumber; 
	reportdata.productPrice = catfoodinfo.productPrice;   
	reportdata.weightPounds = catfoodinfo.productWeight; 
	reportdata.caloriesPerServing = catfoodinfo.caloriesServing;



	// Assigning calculated values
	reportdata.weightKilos = convertLbsKg(&reportdata.weightPounds, &reportdata.weightKilos); 
	reportdata.weightGrams = convertLbsG(&reportdata.weightPounds, &reportdata.weightGrams); 
	reportdata.totalServings = calculateServings(GRAMS_VALUE, reportdata.weightGrams, &reportdata.totalServings);  

	// Total calories
	double totalCalories = reportdata.caloriesPerServing* reportdata.totalServings;   


	reportdata.costPerServing = calculateCostPerServing(&reportdata.productPrice, &reportdata.totalServings, &reportdata.costPerServing);  
	reportdata.costOfCalories = calculateCostPerCal(&reportdata.productPrice, &totalCalories, &reportdata.costOfCalories);   

	return reportdata;
}
 


// 15. Display the formatted table header for the analysis results
void displayReportHeader(void) 
{
	printf("Analysis Report (Note: Serving = %dg)\n", GRAMS_VALUE);  
	printf("---------------\n"); 
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n"); 
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n"); 
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData reportdata, const int cheapestOptionCheck)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", reportdata.skuNumber, reportdata.productPrice, reportdata.weightPounds, reportdata.weightKilos,
		reportdata.weightGrams, reportdata.caloriesPerServing, reportdata.totalServings, reportdata.costPerServing, reportdata.costOfCalories);   
}
// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo catfoodinfo) 
{
	printf("Final Analysis\n"); 
	printf("--------------\n"); 
	printf("Based on the comparison data, the PURRR-fect economical option is:\n"); 
	printf("SKU:%07d Price: $%5.2lf\n", catfoodinfo.skuNumber, catfoodinfo.productPrice);    
	printf("\n"); 

	// Ending line
	printf("Happy shopping!\n"); 
	printf("\n"); 
}

// ----------------------------------------------------------------------------


// 7. Logic entry point
void start(void)
{
	// Struct Arrays
	struct ReportData reportdata[MAX_PRODUCTS] = { {0} }; 
	struct CatFoodInfo catfoodinfo[MAX_PRODUCTS] = { {0} };   

	// Declaring variables
	int i, cheapestIndex = 0;

	// Printing the opening message
	openingMessage(MAX_PRODUCTS);

	// Filling the cfi array
	for (i = 0; i < MAX_PRODUCTS; i++) 
	{
		catfoodinfo[i] = getCatFoodInfo(i);
		reportdata[i] = calculateReportData(catfoodinfo[i]); 
	}

	// Dsiplaying cat food header
	displayCatFoodHeader();

	// Displaying cat food data
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		displayCatFoodData(catfoodinfo[i].skuNumber, &catfoodinfo[i].productPrice, catfoodinfo[i].caloriesServing, &catfoodinfo[i].productWeight);
	}


	// Determining the cheapest product's sku and price
	double cheapestProductPrice = reportdata[0].costPerServing; 
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		if (reportdata[i].costPerServing <= cheapestProductPrice) 
		{
			cheapestProductPrice = reportdata[i].costPerServing; 
			cheapestIndex = i; 
		}
	}

	printf("\n"); 

	// Displaying the report header
	displayReportHeader(); 

	// Displaying the report data
	for (i = 0; i < MAX_PRODUCTS; i++) 
	{
		displayReportData(reportdata[i], cheapestIndex); 

		if (cheapestIndex == i) 
		{
			printf(" ***\n"); 
		}
		else
		{
			printf("\n"); 
		}
	}
	printf("\n"); 

	// Displaying final analysis
	for (i = 0; i < MAX_PRODUCTS; i++) 
	{
		if (i == cheapestIndex) 
		{
			displayFinalAnalysis(catfoodinfo[i]); 
		}
	}


}
