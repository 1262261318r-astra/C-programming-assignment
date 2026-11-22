#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    int choice;
    char str1[100], str2[100], temp[100];
    char ch, *ptr;

    while (1) {
        printf("\n--- STRING OPERATIONS MENU ---\n");
        printf("1. Length\n");
        printf("2. Copy\n");
        printf("3. Concatenate\n");
        printf("4. Compare\n");
        printf("5. Find Character\n");
        printf("6. Find Substring\n");
        printf("7. Tokenise\n");
        printf("8. Uppercase\n");
        printf("9. Lowercase\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline left by scanf

        switch (choice) {
            case 1: // Length
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0'; // Remove trailing newline
                printf("Length: %zu\n", strlen(str1));
                break;

            case 2: // Copy
                printf("Enter source string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';
                strcpy(str2, str1);
                printf("Copied string: %s\n", str2);
                break;

            case 3: // Concatenate
                printf("Enter first string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';
                printf("Enter second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0';
                strcat(str1, str2);
                printf("Concatenated string: %s\n", str1);
                break;

            case 4: // Compare
                printf("Enter first string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';
                printf("Enter second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0';
                int res = strcmp(str1, str2);
                if (res == 0)
                    printf("Strings are equal.\n");
                else if (res < 0)
                    printf("First string is smaller than second.\n");
                else
                    printf("First string is greater than second.\n");
                break;

            case 5: // Find Character
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';
                printf("Enter character to find: ");
                scanf("%c", &ch);
                ptr = strchr(str1, ch);
                if (ptr != NULL)
                    printf("Character '%c' found at index: %ld\n", ch, ptr - str1);
                else
                    printf("Character not found.\n");
                break;

            case 6: // Find Substring
                printf("Enter main string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';
                printf("Enter substring to find: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0';
                ptr = strstr(str1, str2);
                if (ptr != NULL)
                    printf("Substring found at index: %ld\n", ptr - str1);
                else
                    printf("Substring not found.\n");
                break;

            case 7: // Tokenise
                printf("Enter a string to tokenise: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';
                printf("Enter delimiter(s) (e.g., space or comma): ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0';
                
                strcpy(temp, str1); // strtok modifies the original string
                char *token = strtok(temp, str2);
                printf("Tokens:\n");
                while (token != NULL) {
                    printf(" - %s\n", token);
                    token = strtok(NULL, str2);
                }
                break;

            case 8: // Uppercase
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';
                for (int i = 0; str1[i]; i++) {
                    str1[i] = toupper((unsigned char)str1[i]);
                }
                printf("Uppercase: %s\n", str1);
                break;

            case 9: // Lowercase
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';
                for (int i = 0; str1[i]; i++) {
                    str1[i] = tolower((unsigned char)str1[i]);
                }
                printf("Lowercase: %s\n", str1);
                break;

            case 10: // Exit
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}