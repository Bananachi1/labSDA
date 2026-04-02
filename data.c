#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

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
    scanf("%49s", acc->ownerName);

    printf("Тип счета: ");
    scanf("%19s", acc->accountType);

    (*size)++;
}

void removeLastAccount(struct BankAccount **accounts, int *size) {

    if (*size > 0) {
        (*size)--;
        printf("Последний элемент удален\n");
    } else {
        printf("Список пуст\n");
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

void insertAt(struct BankAccount **accounts, int *size, int *capacity) {

    if (*size == 0) {
        printf("Список пуст, используйте обычное добавление\n");
        return;
    }

    printf("Введите позицию (0 - %d): ", *size);
    int pos;
    scanf("%d", &pos);

    if (pos < 0 || pos > *size) {
        printf("Неверная позиция!\n");
        return;
    }

    if (*size >= *capacity) {
        expandArray(accounts, capacity, *size, 2);
    }

    for (int i = *size; i > pos; i--) {
        (*accounts)[i] = (*accounts)[i-1];
    }

    struct BankAccount *acc = &((*accounts)[pos]);

    printf("Номер счета: ");
    scanf("%d", &acc->accountNumber);

    printf("Баланс: ");
    scanf("%f", &acc->balance);

    printf("Имя владельца: ");
    scanf("%49s", acc->ownerName);

    printf("Тип счета: ");
    scanf("%19s", acc->accountType);

    (*size)++;

    printf("Элемент вставлен на позицию %d\n", pos);
}

void deleteAt(struct BankAccount *accounts, int *size) {

    if (*size == 0) {
        printf("Список пуст\n");
        return;
    }

    printf("Введите индекс для удаления (0 - %d): ", *size - 1);
    int index;
    scanf("%d", &index);

    if (index < 0 || index >= *size) {
        printf("Неверный индекс!\n");
        return;
    }

    for (int i = index; i < *size - 1; i++) {
        accounts[i] = accounts[i+1];
    }

    (*size)--;

    printf("Элемент с индексом %d удален\n", index);
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

    int found = 0;

    if (searchChoice == 1) {

        char name[50];
        printf("Введите имя: ");
        scanf("%49s", name);

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
        scanf("%19s", type);

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

void sortAccounts(struct BankAccount *accounts, int size) {

    if (size == 0) {
        printf("Список пуст\n");
        return;
    }

    printf("\n--- Сортировка ---\n");
    printf("1. По имени владельца\n");
    printf("2. По номеру счета\n");
    printf("3. По балансу\n");
    printf("Выбор: ");

    int sortChoice;
    scanf("%d", &sortChoice);

    if (sortChoice < 1 || sortChoice > 3) {
        printf("Неверный выбор\n");
        return;
    }

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {

            int needSwap = 0;

            if (sortChoice == 1) {
                if (strcmp(accounts[j].ownerName, accounts[j+1].ownerName) > 0)
                    needSwap = 1;
            } else if (sortChoice == 2) {
                if (accounts[j].accountNumber > accounts[j+1].accountNumber)
                    needSwap = 1;
            } else if (sortChoice == 3) {
                if (accounts[j].balance > accounts[j+1].balance)
                    needSwap = 1;
            }

            if (needSwap) {
                struct BankAccount temp = accounts[j];
                accounts[j] = accounts[j+1];
                accounts[j+1] = temp;
            }
        }
    }

    printf("Список отсортирован!\n");
}

void saveToFile(struct BankAccount *accounts, int size, const char *filename) {

    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Ошибка: не удалось открыть файл для записи: %s\n", filename);
        return;
    }

    if (fwrite(&size, sizeof(int), 1, fp) != 1) {
        printf("Ошибка записи количества элементов\n");
        fclose(fp);
        return;
    }

    if (size > 0) {
        size_t written = fwrite(accounts, sizeof(struct BankAccount), size, fp);
        if ((int)written != size) {
            printf("Ошибка: записано %zu из %d элементов\n", written, size);
            fclose(fp);
            return;
        }
    }

    fclose(fp);
    printf("Данные сохранены в файл \"%s\" (%d записей)\n", filename, size);
}

int loadFromFile(struct BankAccount **accounts, int *size, int *capacity, const char *filename) {

    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return 0;
    }

    int savedSize = 0;
    if (fread(&savedSize, sizeof(int), 1, fp) != 1 || savedSize < 0) {
        printf("Ошибка чтения файла (повреждён?)\n");
        fclose(fp);
        return 0;
    }

    if (savedSize == 0) {
        fclose(fp);
        printf("Файл пуст, список не загружен\n");
        return 1;
    }

    if (savedSize > *capacity) {
        struct BankAccount *newArray =
            (struct BankAccount*)malloc(savedSize * sizeof(struct BankAccount));
        if (newArray == NULL) {
            printf("Ошибка выделения памяти при загрузке!\n");
            fclose(fp);
            return 0;
        }
        free(*accounts);
        *accounts = newArray;
        *capacity = savedSize;
    }

    size_t readCount = fread(*accounts, sizeof(struct BankAccount), savedSize, fp);
    fclose(fp);

    if ((int)readCount != savedSize) {
        printf("Предупреждение: прочитано %zu из %d записей\n", readCount, savedSize);
        *size = (int)readCount;
    } else {
        *size = savedSize;
    }

    printf("Загружено %d записей из файла \"%s\"\n", *size, filename);
    return 1;
}