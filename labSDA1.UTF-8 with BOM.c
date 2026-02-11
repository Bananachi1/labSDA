#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

#define SIZE 3

struct BankAccount {
    int accountNumber;
    float balance;
    char ownerName[50];
    char accountType[20];
};

void inputAccounts(struct BankAccount accounts[], int size);
void printAccounts(struct BankAccount accounts[], int size);
void editAccount(struct BankAccount accounts[], int size);
void searchAccount(struct BankAccount accounts[], int size);
void depositMoney(struct BankAccount accounts[], int size);
void withdrawMoney(struct BankAccount accounts[], int size);

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF-8");

    struct BankAccount accounts[SIZE];
    int choice;

    do {
        printf("\n===== МЕНЮ =====\n");
        printf("1. Ввод данных\n");
        printf("2. Вывод всех счетов\n");
        printf("3. Редактирование счета\n");
        printf("4. Поиск счета по номеру\n");
        printf("5. Пополнение счета\n");
        printf("6. Снятие денег\n");
        printf("0. Выход\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: inputAccounts(accounts, SIZE); break;
            case 2: printAccounts(accounts, SIZE); break;
            case 3: editAccount(accounts, SIZE); break;
            case 4: searchAccount(accounts, SIZE); break;
            case 5: depositMoney(accounts, SIZE); break;
            case 6: withdrawMoney(accounts, SIZE); break;
            case 0: printf("Выход...\n"); break;
            default: printf("Неверный выбор!\n");
        }

    } while(choice != 0);

    return 0;
}

// Ввод данных
void inputAccounts(struct BankAccount accounts[], int size) {
    for(int i = 0; i < size; i++) {
        printf("\nСчет %d\n", i);
        printf("Номер счета: ");
        scanf("%d", &accounts[i].accountNumber);
        printf("Баланс: ");
        scanf("%f", &accounts[i].balance);
        printf("Имя владельца: ");
        scanf("%s", accounts[i].ownerName);
        printf("Тип счета: ");
        scanf("%s", accounts[i].accountType);
    }
}

// Вывод данных
void printAccounts(struct BankAccount accounts[], int size) {
    for(int i = 0; i < size; i++) {
        printf("\nИндекс: %d\n", i);
        printf("Номер счета: %d\n", accounts[i].accountNumber);
        printf("Баланс: %.2f\n", accounts[i].balance);
        printf("Владелец: %s\n", accounts[i].ownerName);
        printf("Тип счета: %s\n", accounts[i].accountType);
    }
}

// Редактирование
void editAccount(struct BankAccount accounts[], int size) {
    int index;
    printf("Введите индекс счета для редактирования: ");
    scanf("%d", &index);

    if(index >= 0 && index < size) {
        int field;
        printf("Что изменить?\n");
        printf("1. Номер счета\n");
        printf("2. Баланс\n");
        printf("3. Имя владельца\n");
        printf("4. Тип счета\n");
        scanf("%d", &field);

        switch(field) {
            case 1:
                printf("Новый номер: ");
                scanf("%d", &accounts[index].accountNumber);
                break;
            case 2:
                printf("Новый баланс: ");
                scanf("%f", &accounts[index].balance);
                break;
            case 3:
                printf("Новое имя: ");
                scanf("%s", accounts[index].ownerName);
                break;
            case 4:
                printf("Новый тип: ");
                scanf("%s", accounts[index].accountType);
                break;
            default:
                printf("Неверный выбор!\n");
        }
    } else {
        printf("Неверный индекс!\n");
    }
}

// Поиск по номеру счета
void searchAccount(struct BankAccount accounts[], int size) {
    int number;
    printf("Введите номер счета для поиска: ");
    scanf("%d", &number);

    for(int i = 0; i < size; i++) {
        if(accounts[i].accountNumber == number) {
            printf("\nСчет найден!\n");
            printf("Владелец: %s\n", accounts[i].ownerName);
            printf("Баланс: %.2f\n", accounts[i].balance);
            printf("Тип счета: %s\n", accounts[i].accountType);
            return;
        }
    }
    printf("Счет не найден!\n");
}

// Пополнение счета
void depositMoney(struct BankAccount accounts[], int size) {
    int number;
    float amount;

    printf("Введите номер счета: ");
    scanf("%d", &number);

    for(int i = 0; i < size; i++) {
        if(accounts[i].accountNumber == number) {
            printf("Введите сумму пополнения: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Баланс обновлен. Новый баланс: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Счет не найден!\n");
}

// Снятие денег
void withdrawMoney(struct BankAccount accounts[], int size) {
    int number;
    float amount;

    printf("Введите номер счета: ");
    scanf("%d", &number);

    for(int i = 0; i < size; i++) {
        if(accounts[i].accountNumber == number) {
            printf("Введите сумму снятия: ");
            scanf("%f", &amount);

            if(accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Операция выполнена. Новый баланс: %.2f\n", accounts[i].balance);
            } else {
                printf("Недостаточно средств!\n");
            }
            return;
        }
    }
    printf("Счет не найден!\n");
}
