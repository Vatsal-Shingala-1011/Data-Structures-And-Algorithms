#include <iostream>
using namespace std;

const int initial_table_size = 10;
int a[initial_table_size] = {0};
int table_size = initial_table_size;
int elements = 0;

double load_factor() { //Function to find load factor 
    return static_cast<double>(elements) / table_size;
}

void rehash() {
    int new_table_size = table_size * 2 + 1; //new size = old +1
    int new_a[new_table_size] = {0};

    for (int i = 0; i < table_size; i++) { //shifting all element to new table
        if (a[i] != 0) {
            int key = a[i];
            int j = key % new_table_size;

            while (new_a[j] != 0) {
                j = (j + 1) % new_table_size;
            }

            new_a[j] = key;
        }
    }

    // Copy elements back to the original array
    for (int i = 0; i < new_table_size; i++) {
        a[i] = new_a[i];
    }

    table_size = new_table_size;

    cout<< "rehashing occur " << endl;
    cout << " load_factor " <<load_factor() << endl;
    cout << "table_size occur " << table_size << endl;

}

void insert(int key) {
    elements++;
    if (load_factor() >= 0.75) { //if load factor is greater then 0.75 then rehash 
        rehash();
    }

    int i = key % table_size; //find the index value
    while (a[i] != 0) {
        i = (i + 1) % table_size;
    }
    a[i] = key;
}

void find(int key) {
    int i = key % table_size; //find the index value
    int count = 0;
    while (count < table_size && a[i] != key) {
        i = (i + 1) % table_size;
        count++;
    }

    if (a[i] == key) {
        cout << key << " is at index " << i << endl;
    } else {
        cout << key << " is not found" << endl;
    }
}

void print() { //print the index and value at that index
    for (int i = 0; i < table_size; i++) {
        if (a[i] != 0) {
            cout << i << "-->" << a[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int key;
    char choice;

    do {
        cout << "Enter a key to insert: ";
        cin >> key;
        insert(key);

        cout << "Do you want to insert another key? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    print();

    do {
        cout << "Enter a key to find: ";
        cin >> key;
        find(key);

        cout << "Do you want to find another key? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
 /*
 Insertion:
 Time Complexity:O(1) average
 space Complexity:O(1) because no need extra space 
 
 Find:
 Time Complexity:O(1) average
 space Complexity:O(1)

 Rehashing:
 Time Complexity:O(n)
 space Complexity: O(k) where k is previous old size of hashtalbe at time t-1
 
 */