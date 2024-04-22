// ----------------------------------------------------------------------------
// defines/macros

#define MAX_PRODUCTS 3
#define GRAMS_VALUE 64  
#define POUNDSTOKG 2.20462 

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    int skuNumber;
    double productPrice;
    int caloriesServing;
    double productWeight;
};

struct ReportData
{
    int skuNumber;
    double productPrice;
    int caloriesPerServing;
    double weightPounds;
    double weightKilos;
    int weightGrams;
    double totalServings;
    double costPerServing; 
    double costOfCalories;
    
};

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* intergerNumber);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* decimalNumber);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numOfproducts);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequenceNumber);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku_num, const double* product_price, const int calorie_serving, const double* product_weight_lbs);

// 7. Logic entry point
void start(void);


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* poundsToBeConverted, double* conversionresultToKg);

// 9. convert lbs: g
int convertLbsG(const double* poundsToBeConverted, int* conversionresultToG);

// 10. convert lbs: kg / g
void convertLbs(const double* poundsToBeConverted, double* conversionresultToKg, int* conversionresultToG);

// 11. calculate: servings based on gPerServ
double calculateServings(const int sizeInGrams, const int totalGrams, double* numOfServings);

// 12. calculate: cost per serving
double calculateCostPerServing(const double* productPrice, const double* totalServings, double* result); 

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* productPrice, const double* totalCalories, double* result);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(struct CatFoodInfo catfoodinfo);  

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData reportdata, const int cheapestOptionCheck);  

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cheapestProduct);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start(void);
