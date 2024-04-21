#include <stdio.h>
#include <string.h>

typedef struct production {
    char customer_name[22];
    int customer_id;
    int product_id;
    int product_price;
    char product_name[33];
    char payment_method[22];
    char result[34];
    int quantity;
} Prc;

void list_of_product(Prc *I1, int n, int *Bill) {
    *Bill = 0;

    for (int i = 0; i < n; i++) {
        printf("Enter the name of product %d: ", i + 1);
        scanf("%s", I1[i].product_name);

        printf("Enter the product ID for %s: ", I1[i].product_name);
        scanf("%d", &I1[i].product_id);

        printf("Enter the product price for %s: ", I1[i].product_name);
        scanf("%d", &I1[i].product_price);

        printf("Enter the quantity of %s: ", I1[i].product_name);
        scanf("%d", &I1[i].quantity);

        *Bill += I1[i].product_price * I1[i].quantity;
    }
}

void payment_bill(Prc *I1, int n, int Bill, FILE *outputFile) {
    fprintf(outputFile, "Name: %s\n", I1[0].customer_name);
    fprintf(outputFile, "ID: %d\n\n", I1[0].customer_id);
    fprintf(outputFile, "|   No.   |   ID   |     Name     |  Price  | Quantity | Total  |\n");

    for (int i = 0; i < n; i++) {
        fprintf(outputFile, "|   %d   |   %d   |   %-10s   |  %5d  |    %3d    |  %5d  |\n", 
                i + 1, I1[i].product_id, I1[i].product_name, 
                I1[i].product_price, I1[i].quantity, 
                I1[i].product_price * I1[i].quantity);
    }

    fprintf(outputFile, "\nTotal Bill: %d\n", Bill);
}

void payment_methods(Prc *I1, int n, int Bill, FILE *outputFile) {
    const char *payment_methods[] = {"Cash On Delivery", "Online Payment", "Another way"};

    int choice;
    printf("Choose the payment method (1 - Cash On Delivery, 2 - Online Payment, 3 - Another way): ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 3) {
        strcpy(I1[0].payment_method, payment_methods[choice - 1]);
        fprintf(outputFile, "\nPayment Method: %s\n", I1[0].payment_method);
        fprintf(outputFile, "Result: Success\n");
        fprintf(outputFile, "\n%s has successfully paid $%d", I1[0].customer_name, Bill);
        fprintf(outputFile, "\n\t\t THANK YOU\n");
    } else {
        fprintf(outputFile, "Result: Unsuccessful\n");
        fprintf(outputFile, "\n%s has not successfully paid $%d", I1[0].customer_name, Bill);
        fprintf(outputFile, "\n\t\t PLEASE RETRY\n");
    }
}

int main(void) {
    int n, Bill;

    printf("Number of products: ");
    scanf("%d", &n);

    Prc I1[n];

    printf("Enter the customer name: "); 
    scanf("%s", I1[0].customer_name);

    printf("Enter your customer ID: ");
    scanf("%d", &I1[0].customer_id);

    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        perror("Error opening output.txt");
        return 1;
    }

    list_of_product(I1, n, &Bill);
    fprintf(outputFile, "Products Purchased:\n");
    payment_bill(I1, n, Bill, outputFile);
    payment_methods(I1, n, Bill, outputFile);

    fclose(outputFile);

    return 0;
}