#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include <vector>

class HashTable {
public:
	HashTable(int size);		// Konstruktor
	~HashTable();				// Destruktor
	int insert(int item);		// fuegt ein Element der Hashtabelle hinzu
	int at(int i);				// Liefert das i-te Element der Hashtabelle zurueck
	int getCollisionCount();    // Liefert die Anzahl der Kollisionen zurueck
	int getSize();				// Liefert die Groesse der Hashtabelle zurueck
	int getElements();			// Liefert die Anzahl der Elemente der Hashtabelle zurueck



private:
	int size;					// Groesse der HashTable
	int elements;				// Anz. d. Elemente in HashTable
	int collisionCount;			// Anz. d. Kollisionen beim Einfuegen
	std::vector<int>* hashTable;		// HashTable
	int hashValue(int item);	// Hashindex berechnen
};


#endif 