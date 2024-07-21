#include<stdio.h>
#include<string.h>
#define MAX_CARS 5
#define MAX_CUSTOMERS 5
typedef struct
{
    int id;
    char model[50];
    int available;
} Car;
typedef struct
{
    int id;
    char name[50];
    int car_id;
    int days_rented;
} Customer;
Car cars[MAX_CARS];
Customer customers[MAX_CUSTOMERS];
int num_cars = 0;
int num_customers = 0;
void addCar()
{
    printf("Enter car ID: ");
    scanf("%d", &cars[num_cars].id);
    printf("Enter car model: ");
    scanf("%s", cars[num_cars].model);
    cars[num_cars].available = 1;
    num_cars++;
    printf("Car added.\n");
}
void bookCar()
{
    int car_id, customer_id;
    printf("Enter car ID to book: ");
    scanf("%d", &car_id);
    for (int i = 0; i < num_cars; i++)
    {
        if (cars[i].id == car_id && cars[i].available)
        {
            printf("Enter customer ID: ");
            scanf("%d", &customer_id);
            printf("Enter customer name: ");
            scanf("%s", customers[num_customers].name);
            printf("Enter number of days to rent: ");
            scanf("%d", &customers[num_customers].days_rented);
            customers[num_customers].id = customer_id;
            customers[num_customers].car_id = car_id;
            cars[i].available = 0;
            num_customers++;
            printf("Car booked.\n");
            return;
        }
    }
    printf("Car not available.\n");
}
void returnCar()
{
    int customer_id;
    printf("Enter customer ID to return car: ");
    scanf("%d", &customer_id);
    for (int i = 0; i < num_customers; i++)
    {
        if (customers[i].id == customer_id)
        {
            for (int j = 0; j < num_cars; j++)
            {
                if (cars[j].id == customers[i].car_id)
                {
                    cars[j].available = 1;
                    printf("Car returned. Total charges: $%d\n", customers[i].days_rented * 50);
                    for (int k = i; k < num_customers - 1; k++)
                    {
                        customers[k] = customers[k + 1];
                    }
                    num_customers--;
                    return;
                }
            }
        }
    }
    printf("Invalid customer ID.\n");
}
void displayMenu()
{
    printf("\nCar Rental Management\n");
    printf("1. Add Car\n");
    printf("2. Book Car\n");
    printf("3. Return Car\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}
void main()
{
    int choice;
    while (1)
    {
        displayMenu();
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                addCar();
                break;
            case 2:
                bookCar();
                break;
            case 3:
                returnCar();
                break;
            case 4:
                printf("Goodbye!\n");
                return;
            default:
                printf("Invalid choice.\n");
        }
    }
}
