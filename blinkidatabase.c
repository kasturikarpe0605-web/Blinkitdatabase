#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

// Define a structure to hold product details
struct Product {
    int productID;
    char name[MAX_NAME_LENGTH];
    char expiryDate[11];  // Format: YYYY-MM-DD
    int stockLeft;
};

// Function to swap two product records
void swap(struct Product* a, struct Product* b) {
    struct Product temp = *a;
    *a = *b;
    *b = temp;
}

// Function to implement Bubble Sort on products based on expiry date
void bubbleSort(struct Product products[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Compare expiry dates in ascending order (closer expiry first)
            if (strcmp(products[j].expiryDate, products[j + 1].expiryDate) > 0) {
                // Swap products if they are out of order
                swap(&products[j], &products[j + 1]);
            }
        }
    }
}

// Function to display the products in the database
void displayProducts(struct Product products[], int n) {
    printf("\nProduct Database (Sorted by Expiry Date):\n");
    printf("Product ID | Name                     | Expiry Date | Stock Left\n");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-10d | %-24s | %-11s | %-10d\n", 
               products[i].productID, products[i].name, products[i].expiryDate, products[i].stockLeft);
    }
}

int main() {
    // Number of products is fixed to 3
    int n = 3;

    // Declare an array of structures to store product data
    struct Product products[n];

    // Input data for each product
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for product %d:\n", i + 1);
        printf("Product ID: ");
        scanf("%d", &products[i].productID);
        getchar();  // To consume the newline character left by scanf

        printf("Product Name: ");
        fgets(products[i].name, sizeof(products[i].name), stdin);
        products[i].name[strcspn(products[i].name, "\n")] = 0;  // Remove the newline character

        printf("Expiry Date (YYYY-MM-DD): ");
        scanf("%s", products[i].expiryDate);

        printf("Stock Left: ");
        scanf("%d", &products[i].stockLeft);
    }

    // Sort the products by expiry date using Bubble Sort
    bubbleSort(products, n);

    // Display the sorted product database
    displayProducts(products, n);

    return 0;
}
