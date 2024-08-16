
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 1000
#define INFO 100
#define STATES 20
#define FILENAME "library2.txt"

int num_books = 0;
char library[SIZE][INFO]; // Multi-dimensional array for library



// Function prototypes
void library_menu();
void add_book();
void view_library();
void edit_library();
void delete_book();
void search_book();
void save_to_file();
void load_from_file();
void read_from_file(FILE* file);


int main() {
    // Load existing library from file
    load_from_file();

    library_menu();

    printf("\n\t### Goodbye! ###\n");

    return 0;
}

// Library submenu with various operations
void library_menu() {
    int submenu_choice;
    // Display the library menu until the user chooses to quit (option 7)
    do {
        printf("\n======== Library Menu ========\n");
        printf("1 - Add a new book\n");
        printf("2 - View library\n");
        printf("3 - Edit library\n");
        printf("4 - Delete a book\n");
        printf("5 - Search a book\n");
        printf("6 - Save to file\n");
        printf("7 - Quit \n");
        printf("Enter your choice: ");
        scanf_s("%d", &submenu_choice);

        switch (submenu_choice) {
        case 1:
            printf("\n-------- Add a New Book --------\n");
            add_book(); // Call the function to add a new book
            break;
        case 2:
            printf("\n-------- View Library --------\n");
            view_library(); // Call the function to view the library
            break;
        case 3:
            printf("\n-------- Edit Library --------\n");
            edit_library(); // Call the function to edit the library
            break;
        case 4:
            printf("\n-------- Delete a Book --------\n");
            delete_book(); // Call the function to delete a book
            break;
        case 5:
            printf("\n-------- Search in File --------\n");
            search_book(); // Call the function to search for a book
            break;
        case 6:
            printf("\n-------- Save to File --------\n");
            save_to_file(); // Call the function to save the library to a file
            break;
        case 7:
            printf("\n-------- closeed Library --------\n");
            break;
        default:
            printf("*** Wrong Choice ***\n");
        }
    } while (submenu_choice != 7);
}

// Add a new book to the library
void add_book() {
    if (num_books < SIZE) { //check if there is space to save more books
        printf("\nEnter Book Name: ");
        scanf_s(" %[^\n]", library[num_books], sizeof(library[num_books]));
        printf("\nEnter Author's Name: ");
        scanf_s(" %[^\n]", library[num_books + 1], sizeof(library[num_books + 1]));
        printf("\nEnter Rating (1 to 5): ");
        int c;
        c = 0;
        do { //Input and checl for the validation of rating

            // Clear the input buffer to avoid an infinite loop
            while (getchar() != '\n') {
                ;
            }
            if (scanf_s("%d", &c) != 1) {
                printf("Invalid input. Please enter a number.\nTry again: ");
                continue;  // Skip the rest of the loop and start over
            }



            switch (c) {
            case 1:
                //We used sizeof to make sure that the strcpy_s function knows the size of the destination buffer to prevent buffer overflow.
                strcpy_s(library[num_books + 2], sizeof(library[num_books + 2]), "One");
                break;
            case 2:
                //We used sizeof to make sure that the strcpy_s function knows the size of the destination buffer to prevent buffer overflow.
                strcpy_s(library[num_books + 2], sizeof(library[num_books + 2]), "Two");
                break;
            case 3:
                //We used sizeof to make sure that the strcpy_s function knows the size of the destination buffer to prevent buffer overflow.
                strcpy_s(library[num_books + 2], sizeof(library[num_books + 2]), "Three");
                break;
            case 4:
                //We used sizeof to make sure that the strcpy_s function knows the size of the destination buffer to prevent buffer overflow.
                strcpy_s(library[num_books + 2], sizeof(library[num_books + 2]), "Four");
                break;
            case 5:
                //We used sizeof to make sure that the strcpy_s function knows the size of the destination buffer to prevent buffer overflow.
                strcpy_s(library[num_books + 2], sizeof(library[num_books + 2]), "Five");
                break;
            default:
                printf("Invalid input. Please enter a rating between 1 and 5.\nTry again: ");

            }
        } while (c < 1 || c > 5);


        // Display options for book states
        printf("\nState\n");
        printf("[1] To Be Read\n");
        printf("[2] Reading\n");
        printf("[3] Completed\n");

        // Declare a variable to store user's choice
        int choice;

        // Repeat until a valid choice is entered
        do {
            // Prompt the user to enter a choice
            printf("Enter the choice: ");

            // Check if scanf_s successfully reads an integer
            if (scanf_s("%d", &choice) != 1) {
                // Print an error message if the input is not an integer
                printf("Invalid input. Please enter a number.\nTry again: ");

                // Clear the input buffer to avoid an infinite loop
                while (getchar() != '\n');

                // Continue to the next iteration of the loop
                continue;
            }

            // Process the user's choice using a switch statement
            switch (choice) {
            case 1:
                // Set the book state to "To Be Read"
                //We used sizeof to make sure that the strcpy_s function knows the size of the destination buffer to prevent buffer overflow.
                strcpy_s(library[num_books + 3], sizeof(library[num_books + 3]), "To Be Read");
                break;
            case 2:
                // Set the book state to "Reading"
                strcpy_s(library[num_books + 3], sizeof(library[num_books + 3]), "Reading");
                break;
            case 3:
                // Set the book state to "Completed"
                strcpy_s(library[num_books + 3], sizeof(library[num_books + 3]), "Completed");
                break;
            default:
                // Print an error message for an invalid choice
                printf("Invalid choice. Please try again.\n");
            }
        } while (choice != 1 && choice != 2 && choice != 3);


        // Increment the number of books
        num_books += 4;
    }
    else {
        printf("Library is full. Cannot add more books.\n");
    }
}

// View the contents of the library
void view_library() {
    printf("\n");
    if (num_books > 0) {
        printf("%-25s%-25s%-10s%-15s\n", "Book Name", "Author", "Rating", "State");
        // a loop to go through the library array and then print them 
        for (int i = 0; i < num_books; i += 4) {
            printf("%-25s%-25s%-10s%-15s\n", library[i], library[i + 1], library[i + 2], library[i + 3]);
        }
    }
    else {
        printf("Library is empty.\n");
    }
}

// Edit information about a book in the library
void edit_library() {
    char search_name[INFO];
    int i;

    printf("\nEnter the name of the book to edit: ");
    scanf_s(" %[^\n]", search_name, sizeof(search_name));

    for (i = 0; i < num_books; i += 4) {
        //used for loop to check all the books  
        if (strcmp(search_name, library[i]) == 0) { //compares and checks if this is the right book
            printf("\nEnter new information for the book:\n");
            printf("\nEnter Book Name: ");
            scanf_s(" %[^\n]", library[i], sizeof(library[i]));
            printf("\nEnter Author's Name: ");
            scanf_s(" %[^\n]", library[i + 1], sizeof(library[i + 1]));
            printf("\nEnter Rating (1 to 5): ");
            int c;
            c = 0;
            do {
                // Clear the input buffer to avoid an infinite loop
                while (getchar() != '\n') {
                    ;
                }
                if (scanf_s("%d", &c) != 1) {
                    printf("Invalid input. Please enter a number.\nTry again: ");
                    continue;  // Skip the rest of the loop and start over
                }


                switch (c) {
                case 1:
                    //We used sizeof to make sure that the strcpy_s function knows the size of the destination buffer to prevent buffer overflow.
                    strcpy_s(library[i + 2], sizeof(library[i + 2]), "One");
                    break;
                case 2:
                    //We used sizeof to make sure that the strcpy_s function knows the size of the destination buffer to prevent buffer overflow.
                    strcpy_s(library[i + 2], sizeof(library[i + 2]), "Two");
                    break;
                case 3:
                    //We used sizeof to make sure that the strcpy_s function knows the size of the destination buffer to prevent buffer overflow.
                    strcpy_s(library[i + 2], sizeof(library[i + 2]), "Three");
                    break;
                case 4:
                    //We used sizeof to make sure that the strcpy_s function knows the size of the destination buffer to prevent buffer overflow.
                    strcpy_s(library[i + 2], sizeof(library[i + 2]), "Four");
                    break;
                case 5:
                    //We used sizeof to make sure that the strcpy_s function knows the size of the destination buffer to prevent buffer overflow.
                    strcpy_s(library[i + 2], sizeof(library[i + 2]), "Five");
                    break;
                default:
                    printf("Invalid input. Please enter a rating between 1 and 5.\nTry again: ");

                }
            } while (c < 1 || c > 5);

            //print state menu
            printf("\nState\n");
            printf("[1] To Be Read\n");
            printf("[2] Reading\n");
            printf("[3] Completed\n");

            // Declare a variable to store user's choice
            int choice;

            // Repeat until a valid choice is entered
            do {
                // Prompt the user to enter a choice
                printf("Enter the choice: ");

                // Check if scanf_s successfully reads an integer
                if (scanf_s("%d", &choice) != 1) {
                    // Print an error message if the input is not an integer
                    printf("Invalid input. Please enter a number.\nTry again: ");

                    // Clear the input buffer to avoid an infinite loop
                    while (getchar() != '\n');

                    // Continue to the next iteration of the loop
                    continue;
                }

                // Process the user's choice using a switch statement
                switch (choice) {
                case 1:
                    // Set the book state to "To Be Read"
                    //We used sizeof to make sure that the strcpy_s function knows the size of the destination buffer to prevent buffer overflow.
                    strcpy_s(library[i + 3], sizeof(library[i + 3]), "To Be Read");
                    break;
                case 2:
                    // Set the book state to "Reading"
                    strcpy_s(library[i + 3], sizeof(library[i + 3]), "Reading");
                    break;
                case 3:
                    // Set the book state to "Completed"
                    strcpy_s(library[i + 3], sizeof(library[i + 3]), "Completed");
                    break;
                default:
                    // Print an error message for an invalid choice
                    printf("Invalid choice. Please try again.\n");
                }
            } while (choice != 1 && choice != 2 && choice != 3);
            printf("Book information updated successfully.\n");
            break;
        }
    }

    if (i == num_books) {
        printf("Book not found in the library.\n");
    }
}

// Delete a book from the library
void delete_book() {
    char delete_name[INFO];
    int i, j;
    ; // Asks the user to enter the name of the book to be deleted
    printf("Enter the name of the book to delete: ");
    scanf_s(" %[^\n]", delete_name, sizeof(delete_name));
    // Loops through the library to find the book
    for (i = 0; i < num_books; i += 4) {
        if (strcmp(delete_name, library[i]) == 0) {
            // Shift remaining books to fill the gap
            for (j = i; j < num_books - 4; j += 4) {
                // Copies the book information to the previous position
                strcpy_s(library[j], INFO, library[j + 4]);
                strcpy_s(library[j + 1], INFO, library[j + 5]);
                strcpy_s(library[j + 2], INFO, library[j + 6]);
                strcpy_s(library[j + 3], STATES, library[j + 7]);
            }

            // Decrement the number of books
            num_books -= 4;
            printf("Book deleted successfully.\n");
            // Breaks out of the loop once the book is deleted
            break;
        }
    }


    if (i != num_books) {
        printf("Book not found in the library.\n");
    }
}


// Search for a book by name
void search_book() {
    char search_name[INFO];
    bool found = false;

    // Prompt user to enter the name of the book to search
    printf("Enter the name of the book to search: ");
    scanf_s(" %[^\n]", search_name, sizeof(search_name));

    // Iterate through the library to find a match
    for (int i = 0; i < num_books; i += 4) {
        if (strcmp(search_name, library[i]) == 0) {
            // Display book details if found
            printf("\nBook Found:\n");
            printf("%-25s%-25s%-10s%-15s\n", "Book Name", "Author", "Rating", "State");
            printf("%-25s%-25s%-10s%-15s\n", library[i], library[i + 1], library[i + 2], library[i + 3]);
            found = true;
            break;
        }
    }

    // Display a message if the book is not found
    if (!found) {
        printf("Book '%s' not found in the library.\n", search_name);
    }
}

// Save the library into a file 
void save_to_file() {
    // a pointer to handle the file
    FILE* file;

    // open the library file using 'w' writting mode
    fopen_s(&file, FILENAME, "w");

    // a loop to go through each book info then write it to the file
    if (file != NULL) {
        for (int i = 0; i < num_books; i += 4) {
            fprintf(file, "%s,%s,%s,%s\n", library[i], library[i + 1], library[i + 2], library[i + 3]);
        }
        //closing the file    
        fclose(file);
        printf("Library saved to file successfully.\n");
    }
    //print message in case the file didn't open corectly
    else {
        printf("Error opening file for writing.\n");
    }
}


// Function to read from file and store content in the library array
void read_from_file(FILE* file) {

    // a loop to read all info from the file till it ends 
    while (fscanf_s(file, " %[^,],%[^,],%[^,],%[^\n]\n", library[num_books], sizeof(library[num_books]),
        library[num_books + 1], sizeof(library[num_books + 1]),
        library[num_books + 2], sizeof(library[num_books + 2]),
        library[num_books + 3], sizeof(library[num_books + 3])) == 4) {
        // Move to the next set of 4 elements in the 'library' array   
        num_books += 4;
        // a warning massege to the user  
        if (num_books >= SIZE) {
            printf("Warning: Maximum library size reached while loading from file.\n");
            break;
        }
    }
}

// function that load books info from the file 
void load_from_file() {
    // a pointer to handle the file
    FILE* file;
    // opening the file in read 'r' mode
    fopen_s(&file, FILENAME, "r");
    // if file found call raed from file function
    if (file != NULL) {
        read_from_file(file);
        fclose(file);
        printf("Library loaded from file successfully.\n");
    }
    else {
        printf("No existing file found. Starting with an empty library.\n");
    }
}



