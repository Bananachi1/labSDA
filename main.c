#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include "data.h"

int main(void) {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF-8");

    int size     = 0;
    int capacity = DEFAULT_CAPACITY;

    struct BankAccount *accounts =
        (struct BankAccount*)malloc(capacity * sizeof(struct BankAccount));

    if (accounts == NULL) {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }

    printf("Попытка загрузить данные из \"%s\"...\n", SAVE_FILE);
    loadFromFile(&accounts, &size, &capacity, SAVE_FILE);

    int choice;

    do {
        printf("\n===== МЕНЮ =====\n");
        printf("1. Добавить счет (в конец)\n");
        printf("2. Вывести счета\n");
        printf("3. Удалить последний счет\n");
        printf("4. Очистить список\n");
        printf("5. Поиск\n");
        printf("6. Сортировка\n");
        printf("7. Вставить на позицию\n");
        printf("8. Удалить по индексу\n");
        printf("9. Сохранить в файл\n");
        printf("10. Загрузить из файла\n");
        printf("0. Выход\n");
        printf("Выбор: ");
        scanf("%d", &choice);

        switch (choice) {
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
                capacity = DEFAULT_CAPACITY;
                accounts = (struct BankAccount*)malloc(capacity * sizeof(struct BankAccount));
                if (accounts == NULL) {
                    printf("Ошибка выделения памяти!\n");
                    return 1;
                }
                break;
            case 5:
                searchAccounts(accounts, size);
                break;
            case 6:
                sortAccounts(accounts, size);
                break;
            case 7:
                insertAt(&accounts, &size, &capacity);
                break;
            case 8:
                deleteAt(accounts, &size);
                break;
            case 9:
                saveToFile(accounts, size, SAVE_FILE);
                break;
            case 10:
                loadFromFile(&accounts, &size, &capacity, SAVE_FILE);
                break;
            case 0:
                break;
            default:
                printf("Неверный выбор\n");
        }

    } while (choice != 0);

    printf("\nСохранение данных перед выходом...\n");
    saveToFile(accounts, size, SAVE_FILE);

    clearAll(&accounts, &size, &capacity);

    return 0;
}