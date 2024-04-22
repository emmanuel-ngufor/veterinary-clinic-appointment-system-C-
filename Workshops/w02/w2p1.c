#define _CRT_SECURE_NO_WARNINGS  // VS code to ignore all scanf errors

#include <stdio.h> // printf and scanf identifier

int main(void)  // program point of entry 
{   
	//Declaration of Variables
	char patSize = 'S';
	double TAX = 0.13;
	double sPrice, mPrice, lPrice;
	int qty, subtotal, taxes, total;

	printf("Set Shirt Prices\n");
	printf("================\n");
	printf("Enter the price for a SMALL shirt: $");
	scanf("%lf", &sPrice);
	printf("Enter the price for a MEDIUM shirt: $");
	scanf("%lf", &mPrice);
	printf("Enter the price for a LARGE shirt: $");
	scanf("%lf", &lPrice);

	//Displaying shirt price list using standard two-decimal precision
	printf("\nShirt Store Price List\n");
	printf("=======================\n");
	printf("SMALL  : $%.2lf\n", sPrice);
	printf("MEDIUM : $%.2lf\n", mPrice);
	printf("LARGE  : $%.2lf\n", lPrice);

	printf("\nPatty\'s shirt size is '%c'\n", patSize);
	printf("Number of shirts Patty is buying: ");
	scanf("%d", &qty);

	//Calculations
	subtotal = ((sPrice * qty) * 100);
	taxes = subtotal * TAX + 0.5;
	total = subtotal + taxes;






	//Display of shopping Cart details including breakdown of charges
	printf("Patty\'s shopping cart...\n");
	printf("Contains : %d shrits\n", qty);
	printf("Sub-total: $%.4lf\n", ((double)subtotal) / 100);
	printf("Taxes    : $ %.4lf\n", ((double)taxes) / 100);
	printf("Total    : $%.4lf\n", ((double)total) / 100);

   
    return 0;
}








