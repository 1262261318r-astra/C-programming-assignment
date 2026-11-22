#include <stdio.h>
#include <string.h>

int main() {
    
    char registered_email[] = "user@gmail.com";
    char correct_password[] = "pass123";
    int correct_otp = 4567;
    int two_step_enabled = 1; 
    char email[50], password[50];
    int choice, otp, stay_signed_in;

    
    printf("--- Gmail Login Simulation ---\n");
    printf("Opening Gmail Sign-in Page...\n\n");

    
    printf("Enter registered Gmail address: ");
    scanf("%s", email);
    printf("Clicked 'Next'.\n\n");

    if (strcmp(email, registered_email) != 0) {
        printf("Error: Gmail address not found!\n");
        return 0;
    }

   
    while (1) {
        printf("Enter account password (or type 'forgot' if forgotten): ");
        scanf("%s", password);

        if (strcmp(password, "forgot") == 0) {
            printf("Redirecting to 'Forgot Password' recovery procedure...\n");
            return 0; 
        } 
        else if (strcmp(password, correct_password) == 0) {
            printf("Password verified! Clicked 'Next'.\n\n");
            break; 
        } 
        else {
            printf("Incorrect password. Please try again.\n\n");
        }
    }

    
    if (two_step_enabled == 1) {
        printf("2-Step Verification is required.\n");
        while (1) {
            printf("Enter the 4-digit verification code (Hint: 4567): ");
            scanf("%d", &otp);

            if (otp == correct_otp) {
                printf("2-Step Verification successful!\n\n");
                break; 
            } else {
                printf("Verification failed. Enter correct code again.\n\n");
            }
        }
    } else {
        printf("No additional verification required. Proceeding...\n\n");
    }

    
    printf("Stay signed in? (1 for Yes / 0 for No): ");
    scanf("%d", &stay_signed_in);
    if (stay_signed_in == 1) {
        printf("Selected 'Stay signed in'.\n\n");
    }

   
    printf("Opening Gmail inbox...\n");
    printf("Gmail account has been successfully logged in!\n");

    return 0;
}