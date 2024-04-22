#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main(void)
{
       //Variable Declarations
	const double GRAMS_IN_LBS = 453.5924;
	char coffeeType1, coffeeType2, coffeeType3, withCream1, withCream2, withCream3, strenghtOfcoffee, suggestCream; 
	int bagWeight1, bagWeight2, bagWeight3, dailyServings; 

	//Display Title
	printf("Take a Break - Coffee Shop\n");
	printf("==========================\n\n");

	printf("Enter the coffee product information being sold today...\n\n"); 

	//Coffee-1 information
	printf("COFFEE-1...\n"); 
	printf("Type ([L]ight,[M]edium,[R]ich): "); 
	scanf(" %c", &coffeeType1);
	printf("Bag weight (g): "); 
	scanf(" %d", &bagWeight1);
	printf("Best served with cream ([Y]es,[N]o): ");
	scanf(" %c", &withCream1);

	//Coffee-2 information
	printf("\nCOFFEE-2...\n");
	printf("Type ([L]ight,[M]edium,[R]ich): ");
	scanf(" %c", &coffeeType2);
	printf("Bag weight (g): ");
	scanf(" %d", &bagWeight2);
	printf("Best served with cream ([Y]es,[N]o): ");
	scanf(" %c", &withCream2);

	//Coffee-3 information
	printf("\nCOFFEE-3...\n");
	printf("Type ([L]ight,[M]edium,[R]ich): ");
	scanf(" %c", &coffeeType3);
	printf("Bag weight (g): ");
	scanf(" %d", &bagWeight3);
	printf("Best served with cream ([Y]es,[N]o): ");
	scanf(" %c", &withCream3);

	printf("\n");

	//Displaying Product data
	printf("---+------------------------+---------------+-------+\n");
	printf("   |    Coffee              |   Packaged    | Best  |\n");
	printf("   |     Type               |  Bag Weight   | Served|\n");
	printf("   +------------------------+---------------+ With  |\n");
	printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
	printf("---+------------------------+---------------+-------|\n");
	
	printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", (coffeeType1 == 'l' || coffeeType1 == 'L'), (coffeeType1 == 'm' || coffeeType1 == 'M'), (coffeeType1 == 'r' || coffeeType1 == 'R'), 
		bagWeight1, bagWeight1 / GRAMS_IN_LBS, ((withCream1 == 'y') || (withCream1 == 'Y')));  
	printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", (coffeeType2 == 'l' || coffeeType2 == 'L'), (coffeeType2 == 'm' || coffeeType2 == 'M'), (coffeeType2 == 'r' || coffeeType2 == 'R'),  
		bagWeight2, bagWeight2 / GRAMS_IN_LBS, ((withCream2 == 'y') || (withCream2 == 'Y')));  

	printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", (coffeeType3 == 'l' || coffeeType3 == 'L'), (coffeeType3 == 'm' || coffeeType3 == 'M'), (coffeeType3 == 'r' || coffeeType3 == 'R'), 
		bagWeight3, bagWeight3 / GRAMS_IN_LBS, ((withCream3 == 'y') || (withCream3 == 'Y')));  
		 
	//Prompting User Preferences
	printf("\nEnter how you like your coffee...\n\n");
	printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
	scanf(" %c", &strenghtOfcoffee);
	printf("Do you like your coffee with cream ([Y]es,[N]o): ");
	scanf(" %c", &suggestCream);
	printf("Typical number of daily servings: ");
	scanf(" %d", &dailyServings);

	printf("\nThe below table shows how your preferences align to the available products:\n\n");

	//Displaying Summary data
	printf("--------------------+-------------+-------+\n");
	printf("  |     Coffee      |  Packaged   | With  |\n");
	printf("ID|      Type       | Bag Weight  | Cream |\n");
	printf("--+-----------------+-------------+-------+\n");

	printf(" 1|       %d         |      %d      |   %d   |\n", ((coffeeType1 == 'l' || coffeeType1 == 'L') && (strenghtOfcoffee == 'l' || strenghtOfcoffee == 'L')), ((bagWeight1 > 0 && bagWeight1 <= 250) && (dailyServings > 1 && dailyServings < 4)),
		((withCream1 == 'y' || withCream1 == 'Y') && (suggestCream == 'y' || suggestCream == 'Y'))); 

	printf(" 2|       %d         |      %d      |   %d   |\n", ((coffeeType2 == 'r' || coffeeType2 == 'R') && (strenghtOfcoffee == 'r' || strenghtOfcoffee == 'R')), ((bagWeight2 > 0 && bagWeight2 <= 500) && (dailyServings >= 5 && dailyServings <= 9)), 
		((withCream2 == 'n' || withCream2 == 'N') && (suggestCream == 'n' || suggestCream == 'N')));  
	printf(" 3|       %d         |      %d      |   %d   |\n", ((coffeeType3 == 'm' || coffeeType3 == 'M') && (strenghtOfcoffee == 'm' || strenghtOfcoffee == 'M')), ((bagWeight3 > 0 && bagWeight1 <= 1000) && (dailyServings > 10)), 
		((withCream3 == 'n' || withCream3 == 'N') && (suggestCream == 'n' || suggestCream == 'N')));  

	//Prompting User Preferences
	printf("\nEnter how you like your coffee...\n\n");   
	printf("Coffee strength ([L]ight, [M]edium, [R]ich): "); 
	scanf(" %c", &strenghtOfcoffee); 
	printf("Do you like your coffee with cream ([Y]es,[N]o): "); 
	scanf(" %c", &suggestCream); 
	printf("Typical number of daily servings: "); 
	scanf(" %d", &dailyServings); 

	printf("\nThe below table shows how your preferences align to the available products:\n\n"); 

	//Displaying Summary data
	printf("--------------------+-------------+-------+\n"); 
	printf("  |     Coffee      |  Packaged   | With  |\n"); 
	printf("ID|      Type       | Bag Weight  | Cream |\n"); 
	printf("--+-----------------+-------------+-------+\n"); 

	printf(" 1|       %d         |      %d      |   %d   |\n", ((coffeeType1 == 'l' || coffeeType1 == 'L') && (strenghtOfcoffee == 'l' || strenghtOfcoffee == 'L')), ((bagWeight1 > 0 && bagWeight1 <= 250) && (dailyServings > 1 && dailyServings < 4)), 
		((withCream1 == 'y' || withCream1 == 'Y') && (suggestCream == 'y' || suggestCream == 'Y'))); 

	printf(" 2|       %d         |      %d      |   %d   |\n", ((coffeeType2 == 'r' || coffeeType2 == 'R') && (strenghtOfcoffee == 'r' || strenghtOfcoffee == 'R')), ((bagWeight2 > 0 && bagWeight2 <= 500) && (dailyServings >= 5 && dailyServings <= 9)), 
		((withCream2 == 'n' || withCream2 == 'N') && (suggestCream == 'n' || suggestCream == 'N'))); 
	printf(" 3|       %d         |      %d      |   %d   |\n", ((coffeeType3 == 'm' || coffeeType3 == 'M') && (strenghtOfcoffee == 'm' || strenghtOfcoffee == 'M')), ((bagWeight3 > 0 && bagWeight1 <= 1000) && (dailyServings > 10)), 
		((withCream3 == 'n' || withCream3 == 'N') && (suggestCream == 'n' || suggestCream == 'N'))); 

	
	//Closing Message
	printf("\nHope you found a product that suits your likes!\n");

        return 0;
}

