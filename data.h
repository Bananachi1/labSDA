#ifndef DATA_H
#define DATA_H

#define DEFAULT_CAPACITY 2
#define SAVE_FILE "accounts.dat"

struct BankAccount {
    int accountNumber;
    float balance;
    char ownerName[50];
    char accountType[20];
};

void addAccount(struct BankAccount **accounts, int *size, int *capacity);
void removeLastAccount(struct BankAccount **accounts, int *size);
void expandArray(struct BankAccount **accounts, int *capacity, int size, int extra);
void clearAll(struct BankAccount **accounts, int *size, int *capacity);
void insertAt(struct BankAccount **accounts, int *size, int *capacity);
void deleteAt(struct BankAccount *accounts, int *size);

void printAccounts(struct BankAccount *accounts, int size);

void searchAccounts(struct BankAccount *accounts, int size);
void sortAccounts(struct BankAccount *accounts, int size);

void saveToFile(struct BankAccount *accounts, int size, const char *filename);
int loadFromFile(struct BankAccount **accounts, int *size, int *capacity, const char *filename);

#endif