#include <stdio.h>

int main(void)
{
        //Variable Declarations
	const double testValue = 330.99;
	const int product1ID = 111, product2ID = 222, product3ID = 111;
	const double price1 = 111.49, price2 = 222.99, price3 = 334.49;
	const char tax1 = 'Y', tax2 = 'N', tax3 = 'N';
	double avgOfprices;

	//Display Title
	printf("Product Information\n");
	printf("===================\n");

	//Product-1 information
	printf("Product-1 (ID:%d)\n", product1ID);
	printf("  Taxed: %c\n", tax1);
	printf("  Price: $%.4lf\n", price1);

	//Product-2 Information
	printf("\nProduct-2 (ID:%d)\n", product2ID);
	printf("  Taxed: %c\n", tax2);
	printf("  Price: $%.4lf\n", price2);

	//Product-3 Information
	printf("\nProduct-3 (ID:%d)\n", product3ID);
	printf("  Taxed: %c\n", tax3);
	printf("  Price: $%.4lf\n", price3);

	//Calculations of all Average of all prices
	avgOfprices = ((price1 + price2 + price3) / 3);
	printf("\nThe average of all prices is: $%.4lf\n", avgOfprices);

	//Summary of test scenarios
	printf("\nAbout Relational and Logical Expressions!\n");
	printf("========================================\n");
	printf("1. These expressions evaluate to TRUE or FALSE\n");
	printf("2. FALSE: is always represented by integer value 0\n");
	printf("3. TRUE : is represented by any integer value other than 0\n\n");

	printf("Some Data Analysis...\n");
	printf("=====================\n");
	printf("1. Is product 1 taxable? -> %d\n\n", tax1 == 'Y');
	printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n", (tax2 && tax3 == 'N'));
	printf("3. Is product 3 less than testValue ($%.2lf)? -> %d\n\n", testValue, price3 < testValue);
	printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n", price3 > (price1 + price2));
	printf("5. Is the price of product 1 equal to or more than the price difference\n"
		"   of product 3 LESS product 2? ->  %d (price difference: $%.2lf)\n\n", (price1 >= (price3 - price2)), (price3 - price2));
	printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n", price2 >= avgOfprices);
	printf("7. Based on product ID, product 1 is unique -> %d\n\n", ((product1ID != product2ID) && (product1ID != product3ID)));
	printf("8. Based on product ID, product 2 is unique -> %d\n\n", ((product2ID != product1ID) && (product2ID != product3ID)));
	printf("9. Based on product ID, product 3 is unique -> %d\n\n", ((product3ID != product1ID) && (product3ID != product2ID)));
	printf("\n");

    





    return 0;
}