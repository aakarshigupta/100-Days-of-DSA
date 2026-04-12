/*Problem Statement
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.

Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output
FOUND
NOT FOUND

Explanation
Collisions resolved using i² jumps.*/
#include <stdio.h>

#define MAX 100
#define EMPTY -1

int table[MAX];

int hash(int key, int m) {
    return key % m;
}

void insert(int key, int m) {
    int i = 0;

    while (i < m) {
        int index = (hash(key, m) + i*i) % m;

        if (table[index] == EMPTY) {
            table[index] = key;
            return;
        }
        i++;
    }
}

int search(int key, int m) {
    int i = 0;

    while (i < m) {
        int index = (hash(key, m) + i*i) % m;

        if (table[index] == EMPTY)
            return 0;

        if (table[index] == key)
            return 1;

        i++;
    }
    return 0;
}

int main() {

    int m, n;

    printf("Enter size of hash table: ");
    scanf("%d", &m);

    printf("Enter number of operations: ");
    scanf("%d", &n);

    for (int i = 0; i < m; i++)
        table[i] = EMPTY;

    int choice, key;

    printf("Operations:\n1 INSERT\n2 SEARCH\n");

    for (int i = 0; i < n; i++) {

        scanf("%d", &choice);

        if (choice == 1) {
            scanf("%d", &key);
            insert(key, m);
        }
        else if (choice == 2) {
            scanf("%d", &key);
            if (search(key, m))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}