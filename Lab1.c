#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Setting Database size and static variable integer to track changes
char databaseName[100];
static int changeCount = 0;

// Declaring Functions
void printRecords();
void addRecord();
void deleteLastRecord();
void printNumRecords();
void printDatabaseSize();
void printNumChanges(bool print);
void passValue(int mySelection);
int passAndReturn(int sampleValue);

int main(int argc, char *argv[]) {
    // Check if the database name is provided
    if (argc < 2) {
        printf("You must provide a database name to continue.\n");
        return 1; // Exit the program
    }

    // Assign the database name from command line arguments to the global variable
    strcpy(databaseName, argv[1]);

    int looper = 6;
    int selection;

    while (looper <= 6) {
        printf("\nParts Inventory Manager - Database: %s\n", databaseName);
        printf("1. Print all records\n");
        printf("2. Add a Record\n");
        printf("3. Delete the last record\n");
        printf("4. Print number of records\n");
        printf("5. Print database size\n");
        printf("6. Print number of changes\n");
        printf("7. Exit\n\n");
        
        printf("Please enter your selection: ");
        scanf("%d", &selection);

        switch (selection) {
            case 1:
                printRecords();
                break;

            case 2:
                addRecord();
                break;

            case 3:
                deleteLastRecord();
                break;

            case 4:
                printNumRecords();
                break;

            case 5:
                printDatabaseSize();
                break;

            case 6:
                printNumChanges(true);
                break;

            case 7:
                printf("\nExiting the program...\n");
                looper = selection;
                break;

            default:
                printf("Invalid selection. Please enter a number between 1 and 7.\n");
        }
    }
    return 0;
}

// Function to print all records
void printRecords() {
    printf("\nYou have entered the Print all records function.\n");
}

// Function to add a new record
void addRecord() {
    int partNumber;
    char partName[50];
    float partSize;
    char partSizeMetric[10];
    float partCost;

    printf("Enter Part Number: ");
    scanf("%d", &partNumber);
    getchar();

    printf("Enter Part Name: ");
    fgets(partName, sizeof(partName), stdin);
    partName[strcspn(partName, "\n")] = 0;

    printf("Enter Part Size: ");
    scanf("%f", &partSize);
    getchar();

    printf("Enter Part Size Metric: ");
    fgets(partSizeMetric, sizeof(partSizeMetric), stdin);
    partSizeMetric[strcspn(partSizeMetric, "\n")] = 0;

    printf("Enter Part Cost: ");
    scanf("%f", &partCost);

    printf("\nYou entered:\n");
    printf(" Part number = %d\n", partNumber);
    printf(" Part name = \"%s\"\n", partName);
    printf(" Part size = %.2f\n", partSize);
    printf(" Part size metric = \"%s\"\n", partSizeMetric);
    printf(" Part cost = $%.2f\n", partCost);

    printNumChanges(false);
}

// Function to delete the last record
void deleteLastRecord() {
    printf("\nYou have entered the Delete last record function.\n");
    printNumChanges(false);
}

// Function to print the number of records
void printNumRecords() {
    printf("\nYou have entered the Print number of records function.\n");
}

// Function to print the database size
void printDatabaseSize() {
    printf("\nYou have entered the Print database size function.\n");
}

// Function to print the number of changes or increment the change count
void printNumChanges(bool print) {
    if (print) {
        printf("\nDatabase %s has been modified %d times.\n", databaseName, changeCount);
    } else {
        changeCount++;
        printf("\nDatabase modification count is now: %d\n", changeCount);
    }
}

// Function to pass and print a value
void passValue(int mySelection) {
    printf("\nInvoking the passValue Function\n");
    printf("\nYou entered: %d\n", mySelection);
}

// Function to pass a value, modify it, and return the modified value
int passAndReturn(int sampleValue) {
    printf("\nInvoking the passAndReturn Function\n");
    printf("\nYou entered: %d\n", sampleValue);
    printf("\nChanging it to a 7 which will end the program.\n\n");
    return 7;
}
