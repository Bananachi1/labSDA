#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

struct BankAccount {
    int accountNumber;
    float balance;
    char ownerName[50];
    char accountType[20];
};

void addAccount(struct BankAccount **accounts, int *size, int *capacity);
void printAccounts(struct BankAccount *accounts, int size);
void removeLastAccount(struct BankAccount **accounts, int *size);
void expandArray(struct BankAccount **accounts, int *capacity, int size, int extra);
void clearAll(struct BankAccount **accounts, int *size, int *capacity);
void searchAccounts(struct BankAccount *accounts, int size);  // НОВОЕ

void addAccount(struct BankAccount **accounts, int *size, int *capacity) {

    if (*size >= *capacity) {
        expandArray(accounts, capacity, *size, 2);
    }

    struct BankAccount *acc = &((*accounts)[*size]);

    printf("Номер счета: ");
    scanf("%d", &acc->accountNumber);

    printf("Баланс: ");
    scanf("%f", &acc->balance);

    printf("Имя владельца: ");
    scanf("%s", acc->ownerName);

    printf("Тип счета: ");
    scanf("%s", acc->accountType);

    (*size)++;
}

void expandArray(struct BankAccount **accounts, int *capacity, int size, int extra) {

    int newCapacity = *capacity + extra;

    struct BankAccount *newArray =
        (struct BankAccount*)malloc(newCapacity * sizeof(struct BankAccount));

    if (newArray == NULL) {
        printf("Ошибка расширения памяти!\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        newArray[i] = (*accounts)[i];
    }

    free(*accounts);

    *accounts = newArray;
    *capacity = newCapacity;

    printf("Массив расширен до %d элементов\n", *capacity);
}

void removeLastAccount(struct BankAccount **accounts, int *size) {

    if (*size > 0) {
        (*size)--;
        printf("Последний элемент удален\n");
    } else {
        printf("Список пуст\n");
    }
}

void printAccounts(struct BankAccount *accounts, int size) {

    if (size == 0) {
        printf("Список пуст\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        printf("\n[%d]\n", i);
        printf("Номер: %d\n", accounts[i].accountNumber);
        printf("Баланс: %.2f\n", accounts[i].balance);
        printf("Владелец: %s\n", accounts[i].ownerName);
        printf("Тип: %s\n", accounts[i].accountType);
    }
}

void clearAll(struct BankAccount **accounts, int *size, int *capacity) {

    if (*accounts != NULL) {
        free(*accounts);
        *accounts = NULL;
    }

    *size = 0;
    *capacity = 0;

    printf("Память освобождена\n");
}

// ===== НОВАЯ ФУНКЦИЯ ПОИСКА =====
void searchAccounts(struct BankAccount *accounts, int size) {

    if (size == 0) {
        printf("Список пуст\n");
        return;
    }

    printf("\n--- Поиск ---\n");
    printf("1. По имени владельца\n");
    printf("2. По номеру счета\n");
    printf("3. По типу счета\n");
    printf("Выбор: ");

    int searchChoice;
    scanf("%d", &searchChoice);

    int found = 0;  // счётчик найденных совпадений

    if (searchChoice == 1) {

        char name[50];
        printf("Введите имя: ");
        scanf("%s", name);

        for (int i = 0; i < size; i++) {
            if (strcmp(accounts[i].ownerName, name) == 0) {
                printf("\n[%d]\n", i);
                printf("Номер: %d\n", accounts[i].accountNumber);
                printf("Баланс: %.2f\n", accounts[i].balance);
                printf("Владелец: %s\n", accounts[i].ownerName);
                printf("Тип: %s\n", accounts[i].accountType);
                found++;
            }
        }

    } else if (searchChoice == 2) {

        int number;
        printf("Введите номер счета: ");
        scanf("%d", &number);

        for (int i = 0; i < size; i++) {
            if (accounts[i].accountNumber == number) {
                printf("\n[%d]\n", i);
                printf("Номер: %d\n", accounts[i].accountNumber);
                printf("Баланс: %.2f\n", accounts[i].balance);
                printf("Владелец: %s\n", accounts[i].ownerName);
                printf("Тип: %s\n", accounts[i].accountType);
                found++;
            }
        }

    } else if (searchChoice == 3) {

        char type[20];
        printf("Введите тип счета: ");
        scanf("%s", type);

        for (int i = 0; i < size; i++) {
            if (strcmp(accounts[i].accountType, type) == 0) {
                printf("\n[%d]\n", i);
                printf("Номер: %d\n", accounts[i].accountNumber);
                printf("Баланс: %.2f\n", accounts[i].balance);
                printf("Владелец: %s\n", accounts[i].ownerName);
                printf("Тип: %s\n", accounts[i].accountType);
                found++;
            }
        }

    } else {
        printf("Неверный выбор\n");
        return;
    }

    if (found == 0) {
        printf("Ничего не найдено\n");
    } else {
        printf("\nНайдено: %d\n", found);
    }
}
// ===== КОНЕЦ НОВОЙ ФУНКЦИИ =====

int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF-8");

    int size = 0;
    int capacity = 2;

    struct BankAccount *accounts =
        (struct BankAccount*)malloc(capacity * sizeof(struct BankAccount));

    if (accounts == NULL) {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }

    int choice;

    do {
        printf("\n===== МЕНЮ =====\n");
        printf("1. Добавить счет\n");
        printf("2. Вывести счета\n");
        printf("3. Удалить последний счет\n");
        printf("4. Очистить список\n");
        printf("5. Поиск\n");   // НОВОЕ
        printf("0. Выход\n");
        printf("Выбор: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addAccount(&accounts, &size, &capacity);
                break;
            case 2:
                printAccounts(accounts, size);
                break;
            case 3:
                removeLastAccount(&accounts, &size);
                break;
            case 4:
                clearAll(&accounts, &size, &capacity);
                break;
            case 5:                                       // НОВОЕ
                searchAccounts(accounts, size);           // НОВОЕ
                break;                                    // НОВОЕ
        }

    } while(choice != 0);

    clearAll(&accounts, &size, &capacity);

    return 0;
}