
#include <stdio.h>

int pin = 1234;
int balance = 1000;

void saveBalance() {
    FILE *fp = fopen("balance.txt", "w");
    fprintf(fp, "%d", balance);
    fclose(fp);
}

void loadBalance() {
    FILE *fp = fopen("balance.txt", "r");
    if (fp != NULL) {
        fscanf(fp, "%d", &balance);
        fclose(fp);
    } else {
        saveBalance();
    }
}

int main() {
    loadBalance();
    int enteredPin;
    printf("Enter PIN: ");
    scanf("%d", &enteredPin);

    if (enteredPin == pin) {
        while (1) {
            printf("1. Check balance\n");
            printf("2. Withdraw\n");
            printf("3. Deposit\n");
            printf("4. Exit\n");
            int choice;
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("Balance: %d\n", balance);
                    break;
                case 2:
                    printf("Enter amount to withdraw: ");
                    int withdrawAmount;
                    scanf("%d", &withdrawAmount);
                    if (withdrawAmount <= balance) {
                        balance -= withdrawAmount;
                        saveBalance();
                        printf("Withdrawal successful!\n");
                    } else {
                        printf("Insufficient balance!\n");
                    }
                    break;
                case 3:
                    printf("Enter amount to deposit: ");
                    int depositAmount;
                    scanf("%d", &depositAmount);
                    balance += depositAmount;
                    saveBalance();
                    printf("Deposit successful!\n");
                    break;
                case 4:
                    printf("Exiting...\n");
                    return 0;
                default:
                    printf("Invalid choice!\n");
            }
        }
    } else {
        printf("Invalid PIN!\n");
    }
    return 0;
}
