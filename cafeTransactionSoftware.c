#include<stdio.h>

//prototypes
void greeting(); //greeting prototype
void order(double *balance); //order prototype
void viewAccount(double *balance); //viewAccount prototype
void transaction(double *balance, double price); //transaction prototype
void reload(double *balance); //reload prototype
void displayMenu(); //displayMenu prototpe

int main() //main function begins
{
    double balance = 0.00; //money balance
    double *total = &balance; //points to money balance
    int choice; //user's input

    greeting(); //greets the user

    while(choice != 5) //while the user has not chosen to exit
    {
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("CHOOSE AN ACTION BELOW!\n\n"); 
        printf("1 -- View Account Balance...\n"); //choice 1
        printf("2 -- Order an Item...\n"); //choice 2
        printf("3 -- View Menu Items...\n"); //choice 3
        printf("4 -- Reload Account Balance\n"); //choice 4
        printf("5 -- Exit...\n\n"); //choice 5
        printf("PLEASE ENTER THE CORRESPONDING NUMBER TO YOUR ACTION: ");
        scanf(" %d", &choice); //gets user input and assigns the input to choice

        if(choice == 1) //user chose option 1
        {
            viewAccount(total); //calls the function
        }
        else if(choice == 2) //user chose option 2
        {
            order(total); //calls the function
        }
        else if(choice == 3) //user chose option 3
        {
            displayMenu(); //calls the function
        }
        else if(choice == 4) //user chose option 4
        {
            reload(total); //calls the function
        }
        else if(choice == 5) //user chose option 5
        {
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("HAVE A GOOD ONE!\n");
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        }
        else //user chose invalid option
        {
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("PLEASE CHOOSE A VALID OPTION!\n");
        }
    }

    return 0; //ends main function
}

void greeting() //greets the user
{
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Welcome to Knightro's Coffee Shop!\n");
}

void order(double *balance) //order function
{
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    int choice; //user's choice
    printf("PLEASE ORDER FROM THE CHOICES BELOW:\n\n");
    printf("1 -- Hot Coffee -- $3.53\n");
    printf("2 -- Iced Coffee -- $4.20\n");
    printf("3 -- Hot Latte -- $3.13\n");
    printf("4 -- Iced Latte -- $4.12\n");
    printf("5 -- Bagel (includes cream cheese) -- $3.99\n");
    printf("6 -- Big Scone -- $4.99\n");
    printf("7 -- Frozen Coffee -- $5.03\n");
    printf("8 -- Bottle Water -- $1.50\n\n");
    printf("PLEASE ENTER THE CORRESPONDING NUMBER OF WHAT YOU WOULD LIKE TO ORDER: ");
    scanf(" %d", &choice); //takes choice from user

    while(choice < 1 || choice > 8) //while choice is invalid
    {
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("PLEASE MAKE A VALID CHOICE!\n");
        printf("WHAT WOULD YOU LIKE TO ORDER: ");
        scanf(" %d", &choice); //takes choice from user
    }

    if(choice == 1) //if user selects choice 1
    {
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("1 ORDER OF HOT COFFEE WILL COST $3.53.\n");
        transaction(balance, 3.53); //passes 2 values to the transaction function
    }
    else if(choice == 2) //if user selects choice 2
    {
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("1 ORDER OF ICED COFFEE WILL COST $4.20.\n");
        transaction(balance, 4.20); //passes 2 values to the transaction function
    }
    else if(choice == 3) //if user selects choice 3
    {
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("1 ORDER OF HOT LATTE WILL COST $3.13.\n");
        transaction(balance, 3.13); //passes 2 values to the transaction function
    }
    else if(choice == 4) //if user selects choice 4
    {
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("1 ORDER OF ICED LATTE WILL COST $4.12.\n");
        transaction(balance, 4.12); //passes 2 values to the transaction function
    }
    else if(choice == 5) //if user selects choice 5
    {
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("1 ORDER OF BAGEL (includes cream cheese) WILL COST $3.99.\n");
        transaction(balance, 3.99); //passes 2 values to the transaction function
    }
    else if(choice == 6) //if user selects choice 6
    {
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("1 ORDER OF BIG SCONE WILL COST $4.99.\n");
        transaction(balance, 4.99); //passes 2 values to the transaction function
    }
    else if(choice == 7) //if user selects choice 7
    {
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("1 ORDER OF FROZEN COFFEE WILL COST $5.03.\n");
        transaction(balance, 5.03); //passes 2 values to the transaction function
    }
    else //if user selects choice 8
    {
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("1 ORDER OF BOTTLE WATER WILL COST $1.50.\n");
        transaction(balance, 1.50); //passes 2 values to the transaction function
    }
}

void viewAccount(double *balance) //function which shows account balance
{
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("The current balance of your account is $%.2lf.\n", *balance); //prints balance
}

void transaction(double *balance, double price) //function which handles the transaction
{
    while(price > *balance) //while the user cannot afford the item
    {
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("YOU DO NOT HAVE ENOUGH MONEY!\n");
        printf("PLEASE RELOAD YOUR ACCOUNT!\n");
        reload(balance); //function which allows user to reload account
    }
    *balance -= price; //subtracts the price of the item from the users balance
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("PURCHASE SUCCESSFUL!\n");
}

void reload(double *balance) //this function allows the user to add money to their account
{
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    int reload; //amount
    int n = 1; 
    printf("Would you like to add $1, $5, or $10?\n");
    printf("Enter the integer value: ");
    scanf(" %d", &reload); //takes amount from the user
    while(n == 1) //true
    {
        if(reload == 1 || reload == 5 || reload == 10) //if the user makes a valid choice
        {
            *balance += reload; //adds money to user's account
            printf("$%d has been added to your balance.\n", reload);
            n = 0; //false
        }
        else //the user makes an invalid choice
        {
            printf("Invalid Response!\n");
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("Would you like to add $1, $5, or $10?\n");
            printf("Enter the integer value: ");
            scanf(" %d", &reload); //user makes another choice
        }
    }
}

void displayMenu() //displays the menu of the coffee shop
{
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Hot Coffee -- $3.53\n");
    printf("Iced Coffee -- $4.20\n");
    printf("Hot Latte -- $3.13\n");
    printf("Iced Latte -- $4.12\n");
    printf("Bagel (includes cream cheese) -- $3.99\n");
    printf("Big Scone -- $4.99\n");
    printf("Frozen Coffee -- $5.03\n");
    printf("Bottle Water -- $1.50\n");
}