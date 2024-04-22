#define MAX_PRODUCTS 3
#define GRAMS_VALUE 64  

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    int skuNumber;
    double productPrice;
    int caloriesServing;
    double productWeight;
};


// ----------------------------------------------------------------------------
// function prototypes


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
void displayCatFoodData(const int skuNumber, const double* productPrice, const int calorieServing, const double* productWeightInLbs);    

// 7. Logic entry point
void start(void);
