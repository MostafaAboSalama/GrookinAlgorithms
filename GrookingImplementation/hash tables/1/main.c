#include <stdio.h>
#include "hashtable.h"

int main() {
    ht_t* book = ht_create(10);

    ht_set(book, "apple", 0.67);
    ht_set(book, "milk", 1.49);
    ht_set(book, "avocado", 1.49);

    ht_print(book);

    float price = ht_get(book, "apple");
    printf("The price of an apple is %f\n", price);

    price = ht_get(book, "banana");
    printf("The price of a banana is %f\n", price);

    return 0;
}
