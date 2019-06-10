#include "hashtable.h"
#include <iostream>

HashTable::HashTable(int size) {
    this->size = size;
    this->collisionCount = 0;
    this->elements = 0;
    this->hashTable = new std::vector<int>(size, -1);
}

HashTable::~HashTable() {
    delete this->hashTable;
}

int HashTable::hashValue(int item) {
    int index = 0;
    int i = 1;

	index = item % this->size;

    while(this->hashTable->at(index) != -1 && this->elements < this->size) {
        this->collisionCount++;
        index = (item + i * i) % this->size;

        i++;
    }

	return index;
}

int HashTable::insert(int item) {
    int hashindex = hashValue(item);

	if(this->hashTable->at(hashindex) == -1) {
        this->hashTable->at(hashindex) = item;
	    this->elements++;
	}

	return 0; //dummy return
}

int HashTable::at(int i) {
	return hashTable->at(i);
}

int HashTable::getCollisionCount() {
	return this->collisionCount;
}

int HashTable::getSize() {
	return this->size;
}

int HashTable::getElements() {
	return this->elements;
}
