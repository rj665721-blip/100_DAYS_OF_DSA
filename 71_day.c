// Implement a hash table using quadratic probing with formula:

#include <stdio.h>
#include <string.h>

#define EMPTY -1

// Quadratic probing formula: h(k, i) = (k%m + i*i) % m
int hash(int key, int i, int m) {
    return ((key % m) + i * i) % m;
}

void insert(int* table, int m, int key) {
    for (int i = 0; i < m; i++) {
        int idx = hash(key, i, m);
        if (table[idx] == EMPTY) {
            table[idx] = key;
            return;
        }
    }
    // Table full — no slot found (quadratic probing limitation)
}

void search(int* table, int m, int key) {
    for (int i = 0; i < m; i++) {
        int idx = hash(key, i, m);
        if (table[idx] == EMPTY) {
            // Empty slot → key was never inserted here
            printf("NOT FOUND\n");
            return;
        }
        if (table[idx] == key) {
            printf("FOUND\n");
            return;
        }
    }
    printf("NOT FOUND\n");
}

int main() {
    int m, q;
    scanf("%d", &m);   // Table size
    scanf("%d", &q);   // Number of queries

    // Initialize table with EMPTY (-1)
    int table[m];
    for (int i = 0; i < m; i++)
        table[i] = EMPTY;

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);
        if (strcmp(op, "INSERT") == 0)
            insert(table, m, key);
        else if (strcmp(op, "SEARCH") == 0)
            search(table, m, key);
    }

    return 0;
}