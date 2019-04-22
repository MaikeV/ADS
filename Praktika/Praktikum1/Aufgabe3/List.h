//
// Created by Maike on 08.04.2019.
//

#include "Node.h"
#include <string>
#include <iostream>

template <class T> class List {
    /*
    Die Klasse List dient zur Verwaltung von Knoten (Node). Mit Hilfe der Klasse List
    kann ein Stapel oder Warteschlange realisiert werden.
    */

							// normalerweise false; ist true, wenn es sich um eine temoräre Liste handelt
                                            // die innerhalb der überladenen Operatoren angelegt wird
public:
    List();
    struct form { std::string start = "<< "; std::string zwischen = ", "; std::string ende = " >>\n"; } list_form;
    Node<T> * head_tail;
    // Zeiger auf Kopf- und End-Element -> next der 1. Knoten; -> prev der letzte Knoten
    int list_size;							// Länge der Kette
    bool temp;
    List(const List<T> & _List);				// Kopie Konstruktor
    List(const List<T> * _List);				// Kopie Konstruktor
    ~List();
    void insertFront(T key);				// Einfügen eines Knotens am Anfang
    void insertFront(List<T> & _List);			// Einfügen einer vorhandenen Liste am Anfang
    void insertFront(List<T> * _List);			// Einfügen einer vorhandenen Liste am Anfang
    void insertBack(T key);				    // Einfügen eines Knotesn am Ende
    void insertBack(List<T> & _List);			// Einfügen einer vorhandenen Liste am Ende
    void insertBack(List<T> * _List);			// Einfügen einer vorhandenen Liste am Ende
    bool getFront(T & key);				    // Entnehmen eines Knoten am Anfang
    bool getBack(T & key);				    // Entnehmen eines Knoten am Ende
    bool del(T key);						// löschen eines Knotens [key]
    bool search(T key);				    	// Suchen eines Knoten
    bool swap(T key1, T key2);			    // Knoten in der Liste vertauschen
    int size();							    // Größe der Lise (Anzahl der Knoten)
    bool test();						    // Überprüfen der Zeigerstruktur der Liste
    void format(const std::string & start, const std::string & zwischen, const std::string & ende);
    // Mit der format-Methode kann die Ausgabe gesteuert werden: operator <<
    // start: stirng vor der Ausgabe der Liste
    // zwischen: string zwischen Listenknoten
    // ende: string am Ende der Liste
    List<T> & operator = (const List<T> & _List);						// Zuweisungsoperator definieren
    List<T> & operator = (const List<T> * _List);						// Zuweisungsoperator definieren
    List<T> & operator + (const List<T> & List_Append);				// Listen zusammenführen zu einer Liste
    List<T> & operator + (const List<T>* List_Append);				// Listen zusammenführen zu einer Liste

    //template <typename T>
    template<class Tf> friend std::ostream & operator << (std::ostream & stream, List<T> const & Liste);		// Ausgabeoperator überladen

    //template <typename T>
    template<class Tf> friend std::ostream & operator << (std::ostream & stream, List<T> const * Liste);		// Ausgabeoperator überladen

    //template <typename T>
    template<class Tf> friend Node<T>* get_anker(List<T>& l);

    //template <typename T>
    template<class Tf> friend int get_AnzahlNodes(List<T>& l);
};

template <typename T>
List<T>::List() {
    // Konstruktor für eine leere Liste
    head_tail = new Node<T>;
    list_size = 0;
    temp = false;
    head_tail->next = head_tail;
    head_tail->prev = head_tail;
}

template <typename T>
List<T>::List(const List<T> &_List) {
    // Konstruktor mit Übergabe einer Liste, die dann kopiert wird.
    // in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden sollen.
    list_form = _List.list_form;
    head_tail = new Node<T>;
    list_size = 0;
    temp = _List.temp;
    head_tail->next = head_tail;
    head_tail->prev = head_tail;
    Node<T> *tmp_node;
    tmp_node = _List.head_tail->next;
    while (tmp_node != _List.head_tail) {
        head_tail->prev = new Node<T>(tmp_node->key, head_tail->prev->next, head_tail->prev);
        head_tail->prev->prev->next = head_tail->prev;
        list_size++;
        tmp_node = tmp_node->next;
    }
    if (_List.temp) delete &_List;        // ist die Übergebene Liste eine temporäre Liste? -> aus Operator +
}

template <typename T>
List<T>::List(const List<T> *_List) {
    // Konstruktor mit Übergabe einer Liste, die dann kopiert wird.
    // in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden sollen.
    list_form = _List->list_form;
    head_tail = new Node<T>;
    list_size = 0;
    temp = _List->temp;
    head_tail->next = head_tail;
    head_tail->prev = head_tail;
    Node<T> *tmp_node;
    tmp_node = _List->head_tail->next;
    while (tmp_node != _List->head_tail) {
        head_tail->prev = new Node<T>(tmp_node->key, head_tail->prev->next, head_tail->prev);
        head_tail->prev->prev->next = head_tail->prev;
        list_size++;
        tmp_node = tmp_node->next;
    }
    if (_List->temp) delete _List;        // ist die Übergebene Liste eine temporäre Liste? -> aus Operator +
}

template <typename T>
List<T>::~List() {
    // Dekonstruktor
    // Alle Knoten der Liste müssen gelöscht werden, wenn die Liste gelöscht wird.
/*

	hier alle Knoten löschen, die im Objekt List allokiert wurden
*/

    if(this->size() == 0){
        delete this->head_tail;
        return;
    }
    this->head_tail->prev->next = 0;

    while (this->head_tail!= nullptr) {
        Node<T> *ptr = this->head_tail->next;
        delete this->head_tail;
        this->head_tail = ptr;
    }
}

template <typename T>
void List<T>::insertFront(T key) {
    // Einfügen eines neuen Knotens am Anfang der Liste
/*
	Einen neuen Knoten mit dem Schlüsselwert key am Anfang der Liste einfügen
*/


    Node<T> *newEntry = new Node<T>;
    newEntry->key = key;
    newEntry->next = nullptr;
    newEntry->prev = nullptr;

    if (this->head_tail->next == this->head_tail) {
        this->head_tail->next = newEntry;
        newEntry->prev = this->head_tail;
        newEntry->next = this->head_tail;
        this->head_tail->prev = newEntry;

        this->list_size++;

        return;
    }

    Node<T> *ptr = this->head_tail->next;

    this->head_tail->next = newEntry;
    newEntry->prev = this->head_tail;
    newEntry->next = ptr;
    ptr->prev = newEntry;

    this->list_size++;
}

template <typename T>
void List<T>::insertFront(List<T> &_List) {
    // Einfügen einer vorhandenen Liste am Anfang
    /*
    Die einzufügenden Knoten werden übernommen (nicht kopiert)
    Die einzufügende Liste _List ist anschließend leer.
    Es darf keine Schleife und kein new benutzt werden.
    */
/*
	Es wird ein Objekt übergeben in dem Knoten vorhanden sein können.
	Diese Knoten (koplette Kette) werden an den Anfang der Liste (this) übertragen ohne sie zu kopieren!
*/

    if(_List.head_tail->next == _List.head_tail) {
        return;
    }

    if(this->head_tail->next == this->head_tail) {
        this->head_tail->next = _List.head_tail->next;
        _List.head_tail->next->prev = this->head_tail;

        this->head_tail->prev = _List.head_tail->prev;
        _List.head_tail->prev->next = this->head_tail;

        this->list_size += _List.list_size;

        return;
    }

    this->head_tail->next->prev = _List.head_tail->prev;    // _List->last <-- this->first
    _List.head_tail->prev->next = this->head_tail->next;    // _List->last --> this->first

    _List.head_tail->next->prev = this->head_tail;          // this->head_tail <-- List->first
    this->head_tail->next = _List.head_tail->next;          // this->head_tail --> List->first

    _List.head_tail->next = _List.head_tail ;
    _List.head_tail->prev = _List.head_tail;

    this->list_size += _List.list_size;
}

template <typename T>
void List<T>::insertFront(List<T> *_List) {
    // Einfügen einer vorhandenen Liste am Anfang
    /*
    Die einzufügenden Knoten werden übernommen (nicht kopiert)
    Die einzufügende Liste _List ist anschließend leer.
    Es darf keine Schleife und kein new benutzt werden.
    */
/*
	Es wird ein Objekt übergeben in dem Knoten vorhanden sein können.
	Diese Knoten (koplette Kette) werden an den Anfang der Liste (this) übertragen ohne sie zu kopieren!
*/

    if(_List->head_tail->next == _List->head_tail) {
        return;
    }

    if(this->head_tail->next == this->head_tail) {
        this->head_tail->next = _List->head_tail->next;
        _List->head_tail->next->prev = this->head_tail;

        this->head_tail->prev = _List->head_tail->prev;
        _List->head_tail->prev->next = this->head_tail;

        this->list_size += _List->list_size;

        return;
    }

    this->head_tail->next->prev = _List->head_tail->prev;    // _List->last <-- this->first
    _List->head_tail->prev->next = this->head_tail->next;    // _List->last --> this->first

    _List->head_tail->next->prev = this->head_tail;          // this->head_tail <-- List->first
    this->head_tail->next = _List->head_tail->next;          // this->head_tail --> List->first

    _List->head_tail->next = _List->head_tail ;
    _List->head_tail->prev = _List->head_tail;

    this->list_size += _List->list_size;
}

template <typename T>
void List<T>::insertBack(T key) {
    // Einfügen eines neuen Knotens am Ende der Liste
/*
	Einen neuen Knoten mit dem Schlüsselwert key am Ende der Liste einfügen
*/
    Node<T> *newEntry = new Node<T>;
    newEntry->key = key;
    newEntry->next = nullptr;
    newEntry->prev = nullptr;

    if (this->head_tail->next == this->head_tail) {
        this->head_tail->next = newEntry;
        newEntry->prev = head_tail;
        newEntry->next = head_tail;
        this->head_tail->prev = newEntry;

        this->list_size++;

        return;
    }

    Node<T>*ptr = this->head_tail->prev;

    ptr->next = newEntry;
    newEntry->next = this->head_tail;
    newEntry->prev = ptr;
    this->head_tail->prev = newEntry;

    this->list_size++;
}

template <typename T>
void List<T>::insertBack(List<T> &_List) {
    // Einfügen einer vorhandenen Liste am Ende
    /*
    Die einzufügenden Knoten werden übernommen (nicht kopiert)
    Die einzufügende Liste _List ist anschließend leer.
    Es darf keine Schleife und kein new benutzt werden.
    */
/*
	Es wird ein Objekt übergeben in dem Knoten vorhanden sein können.
	Diese Knoten (koplette Kette) werden an das Ende der Liste (this) angehangen ohne sie zu kopieren!
*/

    if(_List.head_tail->next == _List.head_tail) {
        return;
    }

    int size = _List.list_size;

    if(this->head_tail->next == this->head_tail) {
        this->head_tail->next = _List.head_tail->next;
        _List.head_tail->next->prev = this->head_tail;

        this->head_tail->prev = _List.head_tail->prev;
        _List.head_tail->prev->next = this->head_tail;

        this->list_size += size;

        return;
    }

    this->head_tail->prev->next = _List.head_tail->next;    // this->last --> List->first
    _List.head_tail->next->prev = this->head_tail->prev;    // this->last <-- List->first

    _List.head_tail->prev->next = this->head_tail;          // this->head_tail <-- List->last
    this->head_tail->prev = _List.head_tail->prev;          // this->head_tail --> List->last

    _List.head_tail->next = _List.head_tail ;
    _List.head_tail->prev = _List.head_tail;

    this->list_size += size;
}

template <typename T>
void List<T>::insertBack(List<T> *_List) {
    // Einfügen einer vorhandenen Liste am Ende
    /*
    Die einzufügenden Knoten werden übernommen (nicht kopiert)
    Die einzufügende Liste _List ist anschließend leer.
    Es darf keine Schleife und kein new benutzt werden.
    */
/*
	Es wird ein Objekt übergeben in dem Knoten vorhanden sein können.
	Diese Knoten (koplette Kette) werden an das Ende der Liste (this) angehangen ohne sie zu kopieren!
*/
    if(_List->head_tail->next == _List->head_tail) {
        return;
    }

    if(this->head_tail->next == this->head_tail) {
        this->head_tail->next = _List->head_tail->next;
        _List->head_tail->next->prev = this->head_tail;

        this->head_tail->prev = _List->head_tail->prev;
        _List->head_tail->prev->next = this->head_tail;

        this->list_size += _List->list_size;

        return;
    }

    this->head_tail->prev->next = _List->head_tail->next;
    _List->head_tail->next->prev = this->head_tail->prev;

    _List->head_tail->prev->next = this->head_tail;
    this->head_tail->prev = _List->head_tail->prev;

    _List->head_tail->next = _List->head_tail ;
    _List->head_tail->prev = _List->head_tail;

    this->list_size += _List->list_size;
}

template <typename T>
bool List<T>::getFront(T &key) {
    // entnehmen des Knotens am Anfang der Liste
    // der Wert wird als Parameter zurückgegeben
    // der Knoten wird entnommen
/*
	Der Wert des vorderen Schlüsselknotens wird zurückgegeben und der Knoten gelöscht.
	Die Methode del(key) darf nicht zum löschen benutzt werden.
*/

    if (this->head_tail->next == this->head_tail) {
        return false;
    }

    key = this->head_tail->next->key;

    if (this->head_tail->next->next == this->head_tail) {
        this->head_tail->next = this->head_tail;
        this->head_tail->prev = this->head_tail;

        this->list_size = 0;

        return true;
    }

    Node<T> *ptr = this->head_tail->next->next;

    delete this->head_tail->next;

    this->head_tail->next = ptr;
    ptr->prev = this->head_tail;

    this->list_size--;

    return true;
}

template <typename T>
bool List<T>::getBack(T &key) {
    // entnehmen des Knotens am Ende der Liste
    // der Wert wird als Parameter zurückgegeben
    // der Knoten wird entnommen
/*
	Der Wert des letzten Schlüsselknotens wird rückgegeben und der Knoten gelöscht.
	Die Methode del(key) darf nicht zum löschen benutzt werden.
*/

    if (this->head_tail->prev == this->head_tail) {
        return false;
    }

    key = this->head_tail->prev->key;

    if(this->head_tail->prev->prev == this->head_tail) {
        this->head_tail->prev = this->head_tail;
        this->head_tail->next = this->head_tail;

        this->list_size = 0;

        return false;
    }

    Node<T> *ptr = this->head_tail->prev->prev;

    delete this->head_tail->prev;

    this->head_tail->prev = ptr;
    ptr->next = this->head_tail;

    this->list_size--;

    return true;
}

template <typename T>
bool List<T>::del(T key) {
    // Löschen eines gegebenen Knotens
/*
	Löschen des Knotens mit dem Schlüssel key
*/

    if (this->head_tail->next == this->head_tail) {
        return false;
    }

    Node<T> *ptr = this->head_tail->next;

    while(ptr != this->head_tail) {
        if(ptr->key == key) {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;

            delete(ptr);

            this->list_size--;

            return true;
        }

        ptr = ptr->next;
    }

    return false;
}

template <typename T>
bool List<T>::search(T key) {
    // suchen eines Knotens
/*
	suchen ob ein Knoten mit dem Schlüssel key existiert.
*/

    if(this->head_tail->next == this->head_tail) {
        return false;
    }

    Node<T> *ptr = this->head_tail->next;

    while(ptr != this->head_tail) {
        if(ptr->key == key) {
            return true;
        }

        ptr = ptr->next;
    }

    return false;
}

template <typename T>
bool List<T>::swap(T key1, T key2) {
    // Vertauschen von zwei Knoten
    // Dabei werden die Zeiger der Knoten und deren Nachbarn verändert.
/*
	Vertauschen von zwei Knoten mit dem key1 und dem key2
	Es dürfen nicht nur einfach die Schlüssel in den Knoten getauscht werden!
	Die Knoten sind in der Kette umzuhängen.
*/
    Node<T> *ptr = this->head_tail->next;
    Node<T> *ptr1 = this->head_tail;
    Node<T> *ptr2 = this->head_tail;


    while (ptr != this->head_tail) {
        if (ptr->key == key1 && ptr1 == this->head_tail) {
            ptr1 = ptr;
        } else if(ptr->key == key2 && ptr2 == this->head_tail){
            ptr2 = ptr;
        }
        ptr = ptr->next;
    }

    if (ptr1->next == ptr2) {
        Node<T> *ptr_next = ptr2->next;
        Node<T> *ptr_prev = ptr1->prev;

        ptr1->next = ptr_next;
        ptr1->prev = ptr2;
        ptr_next->prev = ptr1;

        ptr2->next = ptr1;
        ptr2->prev = ptr_prev;
        ptr_prev->next = ptr2;

        return true;
    } else if (ptr2->next == ptr1) {
        Node<T> *ptr_next = ptr1->next;
        Node<T> *ptr_prev = ptr2->prev;

        ptr2->next = ptr_next;
        ptr2->prev = ptr1;
        ptr_next->prev = ptr2;

        ptr1->next = ptr2;
        ptr1->prev = ptr_prev;
        ptr_prev->next = ptr1;
        return true;
    }

    if (ptr1 != this->head_tail && ptr2 != this->head_tail) {
        Node<T> *ptr_next = ptr2->next;
        Node<T> *ptr_prev = ptr2->prev;

        ptr2->next = ptr1->next;
        ptr2->prev = ptr1->prev;
        ptr1->prev->next = ptr2;
        ptr1->next->prev = ptr2;

        ptr1->next = ptr_next;
        ptr1->prev = ptr_prev;
        ptr_prev->next = ptr1;
        ptr_next->prev = ptr1;

        return true;
    }

    return false;
}

template <typename T>
int List<T>::size() {
    // Rückgabe der Knoten in der Liste mit O(1)
/*
	Anzahl der Knoten in der Liste zurückgeben.
*/
    if (this->head_tail->next == this->head_tail) {
        return 0;
    }

    Node<T> *ptr = this->head_tail->next;
    int counter = 0;

    while(ptr != this->head_tail) {
        counter++;
        ptr = ptr->next;
    }

    return counter;
}

template <typename T>
bool List<T>::test() {
    // Testmethode: die Methode durchläuft die Liste vom Anfang bis zum Ende und zurück
    // Es werden dabei die Anzahl der Knoten gezählt.
    // Stimmt die Anzahl der Knoten überein liefert die Methode true
    Node<T> *tmp = head_tail->next;
    int i_next = 0, i_prev = 0;
    while (tmp != head_tail) {
        tmp = tmp->next;
        if (i_next > list_size) return false;
        i_next++;
    }
    if (i_next != list_size) return false;
    tmp = head_tail->prev;
    while (tmp != head_tail) {
        tmp = tmp->prev;
        if (i_prev > list_size) return false;
        i_prev++;
    }
    return i_prev == i_next;
}

template <typename T>
List<T> &List<T>::operator=(const List<T> &_List) {
    // in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden sollen.
    // Kopiert wird in das Objekt "this"
    if (this == &_List) return *this;        //  !! keine Aktion notwendig
    list_form = _List.list_form;
    Node<T> *tmp_node;
    if (list_size) {
        Node<T> *tmp_del;
        tmp_node = head_tail->next;
        while (tmp_node != head_tail)        // Alle eventuell vorhandenen Knoten in this löschen
        {
            tmp_del = tmp_node;
            tmp_node = tmp_node->next;
            delete tmp_del;
        }
        list_size = 0;
        head_tail->next = head_tail;
        head_tail->prev = head_tail;
    }
    tmp_node = _List.head_tail->next;        // Die Listen-Knotenwerte werden kopiert
    while (tmp_node != _List.head_tail) {
        insertBack(tmp_node->key);
        tmp_node = tmp_node->next;
    }
    if (_List.temp) delete &_List;            // ist die Übergebene Liste eine temporäre Liste? -> aus Operator +
    return *this;
}

template <typename T>
List<T> &List<T>::operator=(const List<T> *_List) {
    // in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden sollen.
    // Kopiert wird in das Objekt "this"
    if (this == _List) return *this;        //  !! keine Aktion notwendig
    list_form = _List->list_form;
    Node<T> *tmp_node;
    if (list_size) {
        Node<T> *tmp_del;
        tmp_node = head_tail->next;
        while (tmp_node != head_tail)        // Alle eventuell vorhandenen Knoten in this löschen
        {
            tmp_del = tmp_node;
            tmp_node = tmp_node->next;
            delete tmp_del;
        }
        list_size = 0;
        head_tail->next = head_tail;
        head_tail->prev = head_tail;
    }
    tmp_node = _List->head_tail->next;
    while (tmp_node != _List->head_tail)    // Die Listen-Knotenwerte werden kopiert
    {
        insertBack(tmp_node->key);
        tmp_node = tmp_node->next;
    }
    if (_List->temp) delete _List;            // ist die Übergebene Liste eine temporäre Liste? -> aus Operator +
    return *this;
}

template <typename T>
List<T> &List<T>::operator+(const List<T> &List_Append) {
    // Die Methode +
    // Es werden zwei Listen aneinander gehangen.
    // Dabei werden beide Ursprungslisten nicht verändert. Es entsteht eine neue Ergebnisliste.
    Node<T> *tmp_node;
    List<T> *tmp;
    if (temp) {                                        // this ist eine temporäre Liste und kann verändert werden
        tmp = this;
    } else {
        tmp = new List(this);                        // this ist keine temporäre Liste -> Kopie erzeugen
        tmp->temp = true;                            // Merker setzten, dass es sich um eine temporäre Liste handelt
    }
    if (List_Append.list_size) {                    // anhängen der übergebenen Liste an tmp
        tmp_node = List_Append.head_tail->next;
        while (tmp_node != List_Append.head_tail) {
            tmp->insertBack(tmp_node->key);
            tmp_node = tmp_node->next;
        }
    }
    if (List_Append.temp) delete &List_Append;        // wurde eine temporäre Liste übergeben, dann wird diese gelöscht
    return *tmp;
}

template <typename T>
List<T> &List<T>::operator+(const List<T> *List_Append) {
    // Die Methode +
    // Es werden zwei Listen aneinander gehangen.
    // Dabei werden beide Ursprungslisten nicht verändert. Es entsteht eine neue Ergebnisliste.
    Node<T> *tmp_node;
    List<T> *tmp;
    if (temp) {                                        // this ist eine temporäre Liste und kann verändert werden
        tmp = this;
    } else {
        tmp = new List(this);                        // this ist keine temporäre Liste -> Kopie erzeugen
        tmp->temp = true;                            // Merker setzten, dass es sich um eine temporäre Liste handelt
    }
    if (List_Append->list_size) {                    // anhängen der übergebenen Liste an tmp
        tmp_node = List_Append->head_tail->next;
        while (tmp_node != List_Append->head_tail) {
            tmp->insertBack(tmp_node->key);
            tmp_node = tmp_node->next;
        }
    }
    if (List_Append->temp) delete List_Append;        // wurde eine temporäre Liste übergeben, dann wird diese gelöscht
    return *tmp;
}

template <typename T>
void List<T>::format(const std::string &start, const std::string &zwischen, const std::string &ende) {
    // Setzen des Formates für die Ausgabesteuerung der Liste bei cout
    // das Format wird für den überladenen Operator << verwendet
    list_form.start = start;
    list_form.zwischen = zwischen;
    list_form.ende = ende;
}

template <typename T>
std::ostream &operator<<(std::ostream &stream, List<T> const &Liste) {
    // Ausgabe der Liste mit cout
    stream << Liste.list_form.start;
    for (Node<T> *tmp = Liste.head_tail->next; tmp != Liste.head_tail; tmp = tmp->next)
        stream << tmp->key << (tmp->next == Liste.head_tail ? Liste.list_form.ende : Liste.list_form.zwischen);
    if (Liste.temp) delete &Liste;            // wurde eine temporäre Liste übergeben, dann wird diese gelöscht
    return stream;
}

template <typename T>
std::ostream &operator<<(std::ostream &stream, List<T> const *Liste) {
    // Ausgabe der Liste mit cout
    stream << Liste->list_form.start;
    for (Node<T> *tmp = Liste->head_tail->next; tmp != Liste->head_tail; tmp = tmp->next)
        stream << tmp->key << (tmp->next == Liste->head_tail ? Liste->list_form.ende : Liste->list_form.zwischen);
    if (Liste->temp) delete Liste;            // wurde eine temporäre Liste übergeben, dann wird diese gelöscht
    return stream;
}