#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
        const double TAX = 0.13;
	const char patSize = 'S', salSize = 'M', tomSize = 'L';


	double sPrice, mPrice, lPrice;
	int qtyP, subtotP, taxP, totalP;
	int qtyT, subtotT, taxT, totalT;
	int qtyS, subtotS, taxS, totalS;
	int maxSubtot, maxTax, maxTotal, maxQty;

	const int TOONIES = 200, LOONIES = 100, QUARTERS = 25, DIMES = 10, NICKELS = 5, PENNIES = 1; 
	int coins; 
	double avgCostwithouttax, avgCostwithtax; 


	printf("Set Shirt Prices\n");                             // \n is for new line
	printf("================\n"); 
	printf("Enter the price for a SMALL shirt: $"); 
	scanf("%lf", &sPrice);                                    // scanf(format, address)
	printf("Enter the price for a MEDIUM shirt: $"); 
	scanf("%lf", &mPrice);                                    // %lf = format (begins with a % (conversion identifier)
	printf("Enter the price for a LARGE shirt: $"); 
	scanf("%lf", &lPrice); 

	printf("\nShirt Store Price List\n"); 
	printf("======================\n"); 
	printf("SMALL  : $%.2lf\n", sPrice); 
	printf("MEDIUM : $%.2lf\n", mPrice); 
	printf("LARGE  : $%.2lf\n", lPrice); 

	printf("\nPatty's shirt size is '%c'\n", patSize); 
	printf("Number of shirts Patty is buying: "); 
	scanf("%d", &qtyP); 

	printf("\nTommy's shirt size is '%c'\n", tomSize); 
	printf("Number of shirts Tommy is buying: "); 
	scanf("%d", &qtyT); 

	printf("\nSally's shirt size is '%c'\n", salSize); 
	printf("Number of shirts Sally is buying: ");  
	scanf("%d", &qtyS); 

	
	//Patty's Calculations
	subtotP = ((sPrice * qtyP) * 100);
	taxP = ((subtotP * TAX) + 0.5);
	totalP = subtotP + taxP;

	//Sally's Calculations
	subtotS = ((mPrice * qtyS) * 100); 
	taxS = ((subtotS * TAX) + 0.5); 
	totalS = subtotS + taxS; 

	//Tommy's Calculations
	subtotT = ((lPrice * qtyT) * 100);  
	taxT = ((subtotT * TAX) + 0.5); 
	totalT = subtotT + taxT; 

	//maxCalculations
	maxSubtot = subtotP + subtotS + subtotT;
	maxTax = taxP + taxS + taxT;
	maxTotal = totalP + totalS + totalT; 

	printf("\nCustomer Size Price Qty Sub-Total       Tax     Total\n");  
	printf("-------- ---- ----- --- --------- --------- ---------\n"); 
	printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, sPrice, qtyP, ((double)subtotP) / 100, ((double)taxP) / 100, ((double)totalP) / 100);
	printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, mPrice, qtyS, ((double)subtotS) / 100, ((double)taxS) / 100, ((double)totalS) / 100);     
	printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, lPrice, qtyT, ((double)subtotT) / 100, ((double)taxT) / 100, ((double)totalT) / 100);      
	printf("-------- ---- ----- --- --------- --------- ---------\n"); 
	printf("%33.4lf %9.4lf %9.4lf\n\n", ((double)maxSubtot) / 100, ((double)maxTax) / 100, ((double)maxTotal) / 100); 
	

	printf("Daily retail sales represented by coins\n"); 
	printf("=======================================\n\n"); 
	printf("Sales EXCLUDING tax\n"); 
	printf("Coin     Qty   Balance\n"); 
	printf("-------- --- ---------\n"); 
	printf("%22.4lf\n", ((double)maxSubtot) / 100);


	maxQty = qtyP + qtyS + qtyT;  
	avgCostwithouttax = ((((double)maxSubtot) / 100) / maxQty); 

	//TOONIES
	coins = maxSubtot / TOONIES; 
	maxSubtot %= TOONIES; 
	printf("Toonies  %3d %9.4lf\n", coins, ((double)maxSubtot) / 100);

	//LOONIES
	coins = maxSubtot / LOONIES;
	maxSubtot %= LOONIES;
	printf("Loonies  %3d %9.4lf\n", coins, ((double)maxSubtot) / 100);

	//QUARTERS
	coins = maxSubtot / QUARTERS;
	maxSubtot %= QUARTERS;
	printf("Quarters %3d %9.4lf\n", coins, ((double)maxSubtot) / 100);

	//DIMES
	coins = maxSubtot / DIMES;
	maxSubtot %= DIMES;
	printf("Dimes    %3d %9.4lf\n", coins, ((double)maxSubtot) / 100);

	//NICKLES
	coins = maxSubtot / NICKELS; 
	maxSubtot %= NICKELS;
	printf("Nickels  %3d %9.4lf\n", coins, ((double)maxSubtot) / 100);

	//PENNIES
	coins = maxSubtot / PENNIES;
	maxSubtot %= PENNIES;
	printf("Pennies  %3d %9.4lf\n", coins, ((double)maxSubtot) / 100);

	printf("\nAverage cost/shirt: $%.4lf\n", avgCostwithouttax);  



	printf("\nSales INCLUDING tax\n"); 
	printf("Coin     Qty   Balance\n"); 
	printf("-------- --- ---------\n"); 
	printf("%22.4lf\n", ((double)maxTotal) / 100);

	 
	avgCostwithtax = ((((double)maxTotal) / 100) / maxQty); 

	//TOONIES
	coins = maxTotal / TOONIES;  
	maxTotal %= TOONIES;  
	printf("Toonies  %3d %9.4lf\n", coins, ((double)maxTotal) / 100);  

	//LOONIES
	coins = maxTotal / LOONIES;  
	maxTotal %= LOONIES; 
	printf("Loonies  %3d %9.4lf\n", coins, ((double)maxTotal) / 100);  

	//QUARTERS
	coins = maxTotal / QUARTERS; 
	maxTotal %= QUARTERS; 
	printf("Quarters %3d %9.4lf\n", coins, ((double)maxTotal) / 100);  

	//DIMES
	coins = maxTotal / DIMES;   
	maxTotal %= DIMES; 
	printf("Dimes    %3d %9.4lf\n", coins, ((double)maxTotal) / 100);    

	//NICKLES
	coins = maxTotal / NICKELS;   
	maxTotal %= NICKELS;  
	printf("Nickels  %3d %9.4lf\n", coins, ((double)maxTotal) / 100);   

	//PENNIES
	coins = maxTotal / PENNIES;   
	maxTotal %= PENNIES;  
	printf("Pennies  %3d %9.4lf\n", coins, ((double)maxTotal) / 100);  


	printf("\nAverage cost/shirt: $%.4lf\n", avgCostwithtax); 

    return 0;
}