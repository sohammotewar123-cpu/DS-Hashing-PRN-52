#include <iostream>
#include <vector>
using namespace std;

#define TABLE_SIZE 29

// PRN: 202501100052
// Project: Hash Table
// Domain: Student Marks
// Hash Method: Division Method
// Collision Resolution: Linear Probing

int calculateHash(int key) {
    return key % TABLE_SIZE;
}

int main() {
    cout << "Q2 Hash Table Project" << endl;
    cout << "PRN: 202501100052" << endl;
    cout << "Domain: Student Marks" << endl;
    cout << "Hash Method: Division Method" << endl;
    cout << "Collision Resolution: Linear Probing" << endl;
    cout << "Table Size: " << TABLE_SIZE << endl;

    // Generate personalized dataset using PRN seed S = 52
    int seed = 52;
    vector<int> data;

    for (int i = 0; i < 20; i++) {
        int value = (seed + 13 * i) % 100;
        data.push_back(value);
    }

    cout << "\nPersonalized Dataset:\n";
    for (int value : data) {
        cout << value << " ";
    }
    cout << endl;

    // Display hash index calculation
    cout << "\nHash Index Calculation:\n";
    for (int key : data) {
        cout << "Key: " << key
             << " | Calculation: " << key << " % " << TABLE_SIZE
             << " | Hash Index: " << calculateHash(key) << endl;
    }

    // Create hash table; -1 represents an empty slot
    vector<int> hashTable(TABLE_SIZE, -1);
    int collisionEvents = 0;
    int totalElements = 0;

    // Insert values using Linear Probing
    for (int key : data) {
        int index = calculateHash(key);
        int originalIndex = index;

        while (hashTable[index] != -1) {
            collisionEvents++;
            index = (index + 1) % TABLE_SIZE;

            // Stop if the table is full
            if (index == originalIndex) {
                cout << "Hash table is full. Could not insert " << key << endl;
                break;
            }
        }

        if (hashTable[index] == -1) {
            hashTable[index] = key;
            totalElements++;
        }
    }

    cout << "\nHash Table using Linear Probing:\n";
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << "Index " << i << ": ";
        if (hashTable[i] == -1) {
            cout << "Empty";
        } else {
            cout << hashTable[i];
        }
        cout << endl;
    }

    cout << "\nCollision Details:\n";
    cout << "Total collision events: " << collisionEvents << endl;
    cout << "Collision resolution: Next available index (Linear Probing)" << endl;

    cout << "\nFinal Validation:\n";
    cout << "Total input values: " << data.size() << endl;
    cout << "Total inserted elements: " << totalElements << endl;
    cout << "Collision events: " << collisionEvents << endl;

    if (totalElements == static_cast<int>(data.size())) {
        cout << "Validation: SUCCESS" << endl;
    } else {
        cout << "Validation: FAILED" << endl;
    }

    return 0;
}
