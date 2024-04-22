#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"
// string library to implement string functions
#include <string.h>


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
        "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
            "Number: %05d\n"
            "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
            patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
            "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
            "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
    const struct Appointment* appoint,
    int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
            appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
        patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
            "=========================\n"
            "1) PATIENT     Management\n"
            "2) APPOINTMENT Management\n"
            "-------------------------\n"
            "0) Exit System\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
            "=========================\n"
            "1) VIEW   Patient Data\n"
            "2) SEARCH Patients\n"
            "3) ADD    Patient\n"
            "4) EDIT   Patient\n"
            "5) REMOVE Patient\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
            "=========================\n"
            "1) NAME : %s\n"
            "2) PHONE: ", patient->patientNumber, patient->name);

        displayFormattedPhone(patient->phone.number);

        printf("\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
            "==============================\n"
            "1) VIEW   ALL Appointments\n"
            "2) VIEW   Appointments by DATE\n"
            "3) ADD    Appointment\n"
            "4) REMOVE Appointment\n"
            "------------------------------\n"
            "0) Previous menu\n"
            "------------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function! 
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i, recFound = 0;

    if (fmt == FMT_TABLE)
    {
        displayPatientTableHeader();
    }

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            displayPatientData(&patient[i], fmt);
            recFound = 1;
        }
    }

    if (!recFound)
    {
        printf("*** No records found ***\n\n");
    }

    printf("\n");
}

// Search for a patient record based on patient number or phone number
// (Copy your code from MS#2)
void searchPatientData(const struct Patient patient[], int max)
{
    int searchOption;

    // Displaying a menu with two search options and prompting user to select one
    do {
        printf("Search Options\n"
            "==========================\n"
            "1) By patient number\n"
            "2) By phone number\n"
            "..........................\n"
            "0) Previous menu\n"
            "..........................\n");
        printf("Selection: ");
        scanf("%d", &searchOption);
        // searchOption = inputIntPositive(); Not Working !!!!
        printf("\n");

        if (searchOption == 1)
        {
            searchPatientByPatientNumber(patient, max);
            clearInputBuffer();
            suspend();
        }
        else if (searchOption == 2)
        {
            searchPatientByPhoneNumber(patient, max);
            clearInputBuffer();
            suspend();
        }
    } while (searchOption != 0);
}


// Add a new patient record to the patient array
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max)
{
    int number, index, locate;
    int i = 0;

    // Checking for first empty space
    do {
        locate = 0;
        if (patient[i].patientNumber == 0)
        {
            locate = 1;
            index = i;
        }
        i++;
    } while (i < max && locate == 0);

    if (locate == 0)
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
    else
    {
        // Assigning the value
        number = nextPatientNumber(patient, max);
        patient[index].patientNumber = number;
        inputPatient(&patient[index]);
        printf("*** New patient record added ***\n\n");
    }
}

// Edit a patient record from the patient array
// (Copy your code from MS#2)
void editPatient(struct Patient patient[], int max)
{
    int patientNum, index;
    printf("Enter the patient number: ");
   // scanf("%d", &patientNum);
    patientNum = inputIntPositive();  
   //Not Working !!!!!
    printf("\n");

    if (findPatientIndexByPatientNum(patientNum, patient, max) != -1)
    {
        index = findPatientIndexByPatientNum(patientNum, patient, max);
        menuPatientEdit(patient + index);
    }
    else
    {
        printf("ERROR: Patient record not found!\n");
    }

}

// Remove a patient record from the patient array
// (Copy your code from MS#2)
void removePatient(struct Patient patient[], int max)
{
    int pNumber, index;
    char choice, ch;
    printf("Enter the patient number: ");
    scanf("%d", &pNumber);
    // pNumber = inputIntPositive(); Not Working !!!!!
    printf("\n");

    // Checking if patient number exists
    if (findPatientIndexByPatientNum(pNumber, patient, max) != -1)
    {
        index = findPatientIndexByPatientNum(pNumber, patient, max);
        printf("Name  : %s\n", patient[index].name);
        printf("Number: %05d\n", patient[index].patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patient[index].phone.number);
        printf(" (%s)", patient[index].phone.description);
        printf("\n\n");

        printf("Are you sure you want to remove this patient record? (y/n): ");

        int flag = 1;

        do
        {
            scanf(" %c%c", &choice, &ch);
            // inputCharOption(); Not Working !!!!!

            if ((choice == 'n' || choice == 'N') && (ch == '\n'))
            {
                printf("Operation aborted.\n\n");
                flag = 0;
                clearInputBuffer();
            }
            else if ((choice == 'y' || choice == 'Y') && (ch == '\n'))
            {
                // Assigning patient to safe empty state so that the other function can't access it
                patient[index].patientNumber = 0;
                printf("Patient record has been removed!\n\n");
                flag = 0;
            }
            else
            {
                clearInputBuffer();
                printf("ERROR: Character must be one of [yn]: ");
            }
        } while (flag);
    }
    else
    {
        printf("ERROR: Patient record not found!\n\n");
        clearInputBuffer();
    }
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
// This function function displays all the avaialble appointment times and dates available
void viewAllAppointments(struct ClinicData* data)
{
    int i, j;

    // Sorting the data in the array
    sort(data->appointments, data->maxAppointments);

    // Displaying the patients
    displayScheduleTableHeader(NULL, 1);
    for (i = 0; i < data->maxAppointments; i++)
    {
        for (j = 0; j < data->maxPatient; j++)
        {
            if (data->appointments[i].patientNumber && data->patients[j].patientNumber)
            {
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber)
                {
                    displayScheduleData(&data->patients[j], &data->appointments[i], 1);
                }
            }
        }
    }

    printf("\n");
}



// View appointment schedule for the user input date
// Todo:
// This function displays only the appointments scheduled for a specific date
void viewAppointmentSchedule(struct ClinicData* data)
{
    int finalDay = 31;
    int i, j;
    struct Date date;

    // Year as input
    printf("Year        : ");
    date.year = inputIntPositive();

    // Month as input
    printf("Month (1-12): ");
    date.month = inputIntRange(1, 12);

    // Day as input
    printf("Day (1-");
    if (date.month == 4 || date.month == 9 || date.month == 11)
    {
        finalDay = 30;
    }
    if (date.month == 2)
    {
        finalDay = 28;
    }
    if (date.year % 4 == 0 && date.month == 2)
    {
        finalDay = 29;
    }

    printf("%d)  : ", finalDay);
    date.day = inputIntRange(1, finalDay);
    printf("\n");




    // Sorting the data is the array
    sort(data->appointments, data->maxAppointments);

    // Displaying the patients
    displayScheduleTableHeader(&date, 0);
    for (i = 0; i < data->maxAppointments; i++)
    {
        for (j = 0; j < data->maxPatient; j++)
        {
            if (data->appointments[i].patientNumber && data->patients[j].patientNumber)
            {
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber)
                {
                    if (data->appointments[i].date.year == date.year && data->appointments[i].date.month == date.month && data->appointments[i].date.day == date.day)
                    {
                        displayScheduleData(&data->patients[j], &data->appointments[i], 0);
                    }
                }
            }
        }
    }

    printf("\n");

}


// Add an appointment record to the appointment array
// Todo:
// This function tests if there is available elements in the appointment array for a new appointment to be added.
void addAppointment(struct Appointment* app, int maxAppointments, struct Patient* pt, int maxPatients)
{
    // Declaring two temporary structs
    struct Date date;
    struct Time time;

    // Declaring variables
    int finalDay = 31;
    int patientNumber, index, slotNotAvailable = 1;

    // Using the patient number as input
    printf("Patient Number: ");
    patientNumber = inputIntPositive();
    index = findPatientIndexByPatientNum(patientNumber, pt, maxPatients);

    if (index >= 0)
    {
        while (slotNotAvailable)
        {
            // Year as input
            printf("Year        : ");
            date.year = inputIntPositive();

            // Month as input
            printf("Month (1-12): ");
            date.month = inputIntRange(1, 12);

            // Day as input
            printf("Day (1-");
            if (date.month == 4 || date.month == 9 || date.month == 11)
            {
                finalDay = 30;
            }
            if (date.month == 2)
            {
                finalDay = 28;
            }
            if (date.year % 4 == 0 && date.month == 2)
            {
                finalDay = 29;
            }

            printf("%d)  : ", finalDay);
            date.day = inputIntRange(1, finalDay);

            printf("Hour (0-23)  : ");
            time.hour = inputIntRange(0, 23);

            printf("Minute (0-59): ");
            time.min = inputIntRange(0, 59);

            // Checking the availability of the time slot
            if (scheduleSlotOpen(date, time, app, maxAppointments))
            {
                printf("\nERROR: Appointment timeslot is not available!\n\n");
            }
            else
            {
                while ((time.hour < START_HOUR || time.hour > END_HOUR) || (time.hour == END_HOUR && time.min > 0) || (time.min % MINUTE_INTERVAL != 0))
                {
                    printf("ERROR: Time must be between %02d:00 and %02d:00 in %02d minute intervals.\n\n", START_HOUR, END_HOUR, MINUTE_INTERVAL);
                    printf("Hour (0-23)  : ");
                    time.hour = inputIntRange(0, 23);
                    printf("Minute (0-59): ");
                    time.min = inputIntRange(0, 59);
                }
                slotNotAvailable = 0;
            }
        }

        // Assigning the values to the next available slot
        index = upcomingSlotAvailable(app, maxAppointments);
        app[index].date = date;
        app[index].time = time;
        app[index].patientNumber = patientNumber;
        printf("\n*** Appointment scheduled! ***\n\n");
    }
    else
    {
        printf("\nERROR: Patient record not found!\n\n");
    }
    return;
}




// Remove an appointment record from the appointment array
// Todo:
// This function removes appointments by number and specific dates. The entered patient number is validated and if there is a match,
// the patient information is displayed a confirmation of removal is displayed. If there is no match, the removal is denied
void removeAppointment(struct Appointment* app, int maxAppointments, struct Patient* pt, int maxPatients)
{
    struct Date date;
    int index, patientNumber, finalDay = 0, aptIndex;

    // Taking the patient number as input
    printf("Patient Number: ");
    patientNumber = inputIntPositive();
    index = findPatientIndexByPatientNum(patientNumber, pt, maxPatients);

    if (index >= 0)
    {
        // Year as input
        printf("Year        : ");
        date.year = inputIntPositive();

        // Month as input
        printf("Month (1-12): ");
        date.month = inputIntRange(1, 12);

        // Day as input
        printf("Day (1-");
        if (date.month == 4 || date.month == 9 || date.month == 11)
        {
            finalDay = 30;
        }
        if (date.month == 2)
        {
            finalDay = 28;
        }
        if (date.year % 4 == 0 && date.month == 2)
        {
            finalDay = 29;
        }
        printf("%d)  : ", finalDay);
        date.day = inputIntRange(1, finalDay);

        aptIndex = verifiedAppointment(patientNumber, date, app, maxAppointments);

        if (aptIndex >= 0)
        {
            printf("\n");

            displayPatientData(&pt[index], FMT_FORM);
            printf("Are you sure you want to remove this appointment (y,n): ");

            if (inputCharOption("yn") == 'y')
            {
                app[aptIndex].patientNumber = 0;
                printf("\nAppointment record has been removed!\n\n");
            }

            else
            {
                printf("ERROR: No appointment for this date!\n\n");
            }
        }
    }
    else
    {
        printf("ERROR: Patient record not found!\n\n");
    }
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int patientID, index;
    printf("Search by patient number: ");
    scanf("%d", &patientID); 
    printf("\n");

    // Checking if patient number exists
    if (findPatientIndexByPatientNum(patientID, patient, max) != -1)
    {
        index = findPatientIndexByPatientNum(patientID, patient, max);
        printf("Name  : %s\n", patient[index].name);
        printf("Number: %05d\n", patient[index].patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patient[index].phone.number);
        printf(" (%s)", patient[index].phone.description);
        printf("\n\n");
    }

    else
    {
        printf("*** No records found ***\n\n");
    }
}

// Search and display patient records by phone number (tabular)
// (Copy your code from MS#2)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int i, recFound = 0;
    char phoneNumber[PHONE_LEN + 1];
    clearInputBuffer();
    printf("Search by phone number: ");
    fgets(phoneNumber, sizeof(phoneNumber), stdin);
    printf("\n");

    displayPatientTableHeader();

    for (i = 0; i < max + 1; i++)
    {
        if (strcmp(patient[i].phone.number, phoneNumber) == 0)
        {
            printf("%05d %-15s ", patient[i].patientNumber, patient[i].name);
            displayFormattedPhone(patient[i].phone.number);
            printf(" (%s)\n", patient[i].phone.description);
            recFound++;
        }
    }
    printf("\n");

    if (recFound == 0)
    {
        printf("*** No records found ***\n\n");
    }
}

// Get the next highest patient number
// (Copy your code from MS#2)
int nextPatientNumber(const struct Patient patient[], int max)
{
    int nextNumber, maxNumber = patient[0].patientNumber, i;

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber > maxNumber)
        {
            maxNumber = patient[i].patientNumber;
        }
    }

    nextNumber = maxNumber + 1;
    return nextNumber;
}

// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)
int findPatientIndexByPatientNum(int patientNumber,
    const struct Patient patient[], int max)
{
    int i;
    // Searches the patient array for the element that matches the "patientNumber"
    // argument value
    // if the record is found! Returns the index position of the matched element
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == patientNumber)
        {
            return i;
        }
    }
    // Returns -1 if the record can't be located
    return -1;
}


// Function for arranging the values using the bubble sort technique.
void sort(struct Appointment appoints[], int max)
{
    int i, j;
    struct Appointment temp;

    // Storing all the date and time values in minutes for comparison
    for (i = 0; i < max; i++)
    {
        appoints[i].time.min = (appoints[i].date.year * 12 * 30 * 24 * 60) + (appoints[i].date.month * 30 * 24 * 60)
            + (appoints[i].date.day * 24 * 60) + (appoints[i].time.hour * 60) + appoints[i].time.min;
    }

    // Using bubble sort technique to compare minutes and swapping the structs
    for (i = max - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (appoints[j].time.min > appoints[j + 1].time.min)
            {
                temp = appoints[j];
                appoints[j] = appoints[j + 1];
                appoints[j + 1] = temp;
            }
        }
    }

    // Converting total minutes back to minutes
    for (i = 0; i < max; i++) {
        appoints[i].time.min = appoints[i].time.min - (appoints[i].date.year * 12 * 30 * 24 * 60) - (appoints[i].date.month * 30 * 24 * 60)
            - (appoints[i].date.day * 24 * 60) - (appoints[i].time.hour * 60);
    }

}


// Checks to see if a schedule time slot is available
int scheduleSlotOpen(struct Date date, struct Time time, struct Appointment* app, int maxAppointments)
{
    int i, emptySlot = 0;

    for (i = 0; i < maxAppointments; i++)
    {
        // Checking if time slot is available
        if (date.year == app[i].date.year && date.month == app[i].date.month && date.day == app[i].date.day && time.hour == app[i].time.hour && time.min == app[i].time.min)
        {
            emptySlot = 1;
        }
    }

    return emptySlot;
}

// Verifies if the next slot available and return the index position
int upcomingSlotAvailable(struct Appointment* app, int maxAppointments)
{
    int i = 0, freeSlot = 0;
    while (freeSlot == 0 && i < maxAppointments)
    {
        if (app[i].patientNumber < 1)
        {
            freeSlot = 1;
        }
        i++;
    }
    return i;
}

// Verifies to see if an appointment is valid or acceptable
int verifiedAppointment(int patientNumber, struct Date date, struct Appointment* app, int maxAppointments)
{
    int i = 0, valid = 0;

    while (valid == 0 && i < maxAppointments)
    {
        if ((app[i].patientNumber == patientNumber) && (app[i].date.day == date.day) && (app[i].date.month == date.month) && (app[i].date.year == date.year))
        {
            valid = 1;
        }
        i++;
    }
    return i - 1;
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    putchar('\n');
    inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
// (Copy your code from MS#2)
void inputPhoneData(struct Phone* phone) {
    int choice;
    char inputNumber[PHONE_LEN + 1];
    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    choice = inputIntRange(1, 4);
    putchar('\n');

    switch (choice)
    {
    case 1:
        // Storing the description in the struct
        strncpy(phone->description, "CELL", PHONE_DESC_LEN);
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        inputCStringNumbers(inputNumber, 10, 10);
        strcpy(phone->number, inputNumber);
        putchar('\n');

        break;

    case 2:
        // Storing the description in the struct
        strncpy(phone->description, "HOME", PHONE_DESC_LEN);
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        inputCStringNumbers(inputNumber, 10, 10);
        strcpy(phone->number, inputNumber);
        putchar('\n');

        break;

    case 3:
        // Storing the description in the struct
        strncpy(phone->description, "WORK", PHONE_DESC_LEN);
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        inputCStringNumbers(inputNumber, 10, 10);
        strcpy(phone->number, inputNumber);
        putchar('\n');

        break;

    case 4:
        // Storing the description in the struct
        strncpy(phone->description, "TBD", PHONE_DESC_LEN);
        *phone->number = '\0';
        break;
    }
}



//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max)
{
    // Declaring variables
    int i = 0;

    // Opening the file
    FILE* fp;
    fp = fopen(datafile, "r");

    // Checking for to make sure that the pointer is not empty(NULL)
    if (fp != NULL)
    {
        i = 0;
        while (fscanf(fp, "%d|%[^|]|%[^|]|%[^\n]", &patients[i].patientNumber,
            patients[i].name,
            patients[i].phone.description,
            patients[i].phone.number) != EOF)
        {
            i++;
            if (i >= max)
                break;
        }

        // Closing the file
        fclose(fp);
    }

    else
    {
        printf("ERROR: File could not be read\n");
    }

    // Returning the number of records read
    return i;
}


// Import appointment data from file into an Appointment array (returns #n of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max)
{
    // Declaring variables
    int i, count = 0;

    // Opening the file
    FILE* fp;
    fp = fopen(datafile, "r");

    // Checking for to make sure that the pointer is not empty(NULL)
    if (fp != NULL)
    {

        // Iterating until file reaches the end of file or the max is reached
        for (i = 0; i < max && !feof(fp); i++)
        {
            // Reading values from file and storing them
            fscanf(fp, "%d,%d,%d,%d,%d,%d", &appoints[i].patientNumber, &appoints[i].date.year, &appoints[i].date.month, &appoints[i].date.day,
                &appoints[i].time.hour, &appoints[i].time.min);

            // Incrementing count if the end of file is not reached
            if (!feof(fp))
            {
                count++;
            }
        }

        // Closing the file
        fclose(fp);
    }

    else
    {
        printf("ERROR: File could not be read\n");
    }

    // Returning the number of records read
    return count;
}


