//
// Created by Maike on 08.04.2019.
//

#include "List.h"

List::List() {
    // Konstruktor für eine leere Liste
    head_tail = new Node;
    list_size = 0;
    temp = false;
    head_tail->next = head_tail;
    head_tail->prev = head_tail;
}

List::List(const List &_List) {
    // Konstruktor mit Übergabe einer Liste, die dann kopiert wird.
    // in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden sollen.
    list_form = _List.list_form;
    head_tail = new Node;
    list_size = 0;
    temp = _List.temp;
    head_tail->next = head_tail;
    head_tail->prev = head_tail;
    Node *tmp_node;
    tmp_node = _List.head_tail->next;
    while (tmp_node != _List.head_tail) {
        head_tail->prev = new Node(tmp_node->key, head_tail->prev->next, head_tail->prev);
        head_tail->prev->prev->next = head_tail->prev;
        list_size++;
        tmp_node = tmp_node->next;
    }
    if (_List.temp) delete &_List;        // ist die Übergebene Liste eine temporäre Liste? -> aus Operator +
}

List::List(const List *_List) {
    // Konstruktor mit Übergabe einer Liste, die dann kopiert wird.
    // in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden sollen.
    list_form = _List->list_form;
    head_tail = new Node;
    list_size = 0;
    temp = _List->temp;
    head_tail->next = head_tail;
    head_tail->prev = head_tail;
    Node *tmp_node;
    tmp_node = _List->head_tail->next;
    while (tmp_node != _List->head_tail) {
        head_tail->prev = new Node(tmp_node->key, head_tail->prev->next, head_tail->prev);
        head_tail->prev->prev->next = head_tail->prev;
        list_size++;
        tmp_node = tmp_node->next;
    }
    if (_List->temp) delete _List;        // ist die Übergebene Liste eine temporäre Liste? -> aus Operator +
}

List::~List() {
    // Dekonstruktor
    // Alle Knoten der Liste müssen gelöscht werden, wenn die Liste gelöscht wird.
/*
	hier alle Knoten löschen, die im Objekt List allokiert wurden
*/

//    if(this->head_tail->next != this->head_tail) {
//        Node *ptr = this->head_tail;
//        Node *temp;
//
//        this->head_tail->prev->next = nullptr;
//
//        while(ptr->next != nullptr) {
//            temp = ptr->next;
//            delete ptr;
//            ptr = temp;
//        }
//    }
//
//    this->head_tail = nullptr;
}

void List::insertFront(int key) {
    // Einfügen eines neuen Knotens am Anfang der Liste
/*
	Einen neuen Knoten mit dem Schlüsselwert key am Anfang der Liste einfügen
*/

    Node *newEntry = new Node;
    newEntry->key = key;
    newEntry->next = nullptr;
    newEntry->prev = nullptr;

    if (!this->head_tail->next) {
        this->head_tail->next = newEntry;
        newEntry->prev = head_tail;
        newEntry->next = head_tail;

        return;
    }

    Node *ptr = this->head_tail->next;

    this->head_tail->next = newEntry;
    this->head_tail->next->next = ptr;
    this->head_tail->next->prev = this->head_tail;
    ptr->prev = this->head_tail->next;
}

void List::insertFront(List &_List) {
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

    if(!_List.head_tail->next) {
        return;
    }

    if(!this->head_tail->next) {
        this->head_tail->next = _List.head_tail->next;
        _List.head_tail->next->prev = this->head_tail;

        this->head_tail->prev = _List.head_tail->prev;
        _List.head_tail->prev->next = this->head_tail;

        return;
    }

    this->head_tail->next->prev = _List.head_tail->prev;    // _List->last <-- this->first
    _List.head_tail->prev->next = this->head_tail->next;    // _List->last --> this->first

    _List.head_tail->next->prev = this->head_tail;          // this->head_tail <-- List->first
    this->head_tail->next = _List.head_tail->next;          // this->head_tail --> List->first
}

void List::insertFront(List *_List) {
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

    if(!_List->head_tail->next) {
        return;
    }

    if(!this->head_tail->next) {
        this->head_tail->next = _List->head_tail->next;
        _List->head_tail->next->prev = this->head_tail;

        this->head_tail->prev = _List->head_tail->prev;
        _List->head_tail->prev->next = this->head_tail;

        return;
    }

    this->head_tail->next->prev = _List->head_tail->prev;    // _List->last <-- this->first
    _List->head_tail->prev->next = this->head_tail->next;    // _List->last --> this->first

    _List->head_tail->next->prev = this->head_tail;          // this->head_tail <-- List->first
    this->head_tail->next = _List->head_tail->next;          // this->head_tail --> List->first
}

void List::insertBack(int key) {
    // Einfügen eines neuen Knotens am Ende der Liste
/*
	Einen neuen Knoten mit dem Schlüsselwert key am Ende der Liste einfügen
*/
    Node *newEntry = new Node;
    newEntry->key = key;
    newEntry->next = nullptr;
    newEntry->prev = nullptr;

    if (!this->head_tail->next) {
        this->head_tail->next = newEntry;
        newEntry->prev = head_tail;
        newEntry->next = head_tail;

        return;
    }

    Node *ptr = this->head_tail->next;

    while(ptr->next != this->head_tail) {
        ptr = ptr->next;
    }

    ptr->next = newEntry;
    newEntry->next = this->head_tail;
    newEntry->prev = ptr;
    this->head_tail->prev = newEntry;
}

void List::insertBack(List &_List) {
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

    if(!_List.head_tail->next) {
        return;
    }

    if(!this->head_tail->next) {
        this->head_tail->next = _List.head_tail->next;
        _List.head_tail->next->prev = this->head_tail;

        this->head_tail->prev = _List.head_tail->prev;
        _List.head_tail->prev->next = this->head_tail;

        return;
    }

    this->head_tail->prev->next = _List.head_tail->next;
    _List.head_tail->next->prev = this->head_tail->prev;
    _List.head_tail->prev->next = this->head_tail;
    this->head_tail->prev = _List.head_tail->prev;

}

void List::insertBack(List *_List) {
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
    if(!_List->head_tail->next) {
        return;
    }

    if(!this->head_tail->next) {
        this->head_tail->next = _List->head_tail->next;
        _List->head_tail->next->prev = this->head_tail;

        this->head_tail->prev = _List->head_tail->prev;
        _List->head_tail->prev->next = this->head_tail;

        return;
    }

    this->head_tail->prev->next = _List->head_tail->next;
    _List->head_tail->next->prev = this->head_tail->prev;
    _List->head_tail->prev->next = this->head_tail;
    this->head_tail->prev = _List->head_tail->prev;
}

bool List::getFront(int &key) {
    // entnehmen des Knotens am Anfang der Liste
    // der Wert wird als Parameter zurückgegeben
    // der Knoten wird entnommen
/*
	Der Wert des vorderen Schlüsselknotens wird zurückgegeben und der Knoten gelöscht.
	Die Methode del(key) darf nicht zum löschen benutzt werden.
*/

    if (!this->head_tail->next) {
        return false;
    }

    key = this->head_tail->next->key;

    if (!this->head_tail->next->next) {
        this->head_tail->next = nullptr;
        this->head_tail->prev = nullptr;

        return true;
    }

    Node *ptr = this->head_tail->next->next;

    delete(this->head_tail->next);

    this->head_tail->next = ptr;
    ptr->prev = this->head_tail;

    return true;
}

bool List::getBack(int &key) {
    // entnehmen des Knotens am Ende der Liste
    // der Wert wird als Parameter zurückgegeben
    // der Knoten wird entnommen
/*
	Der Wert des letzten Schlüsselknotens wird rückgegeben und der Knoten gelöscht.
	Die Methode del(key) darf nicht zum löschen benutzt werden.
*/

    if (!this->head_tail->prev) {
        return false;
    }

    key = this->head_tail->prev->key;

    if(this->head_tail->prev->prev == this->head_tail) {
        this->head_tail->prev = nullptr;
        this->head_tail->next = nullptr;
        return false;
    }

    //delete(this->head_tail->prev);

    Node *ptr = this->head_tail->prev;

    ptr->prev = this->head_tail;
    this->head_tail->prev = ptr->prev;

    delete(ptr);

    return true;
}

bool List::del(int key) {
    // Löschen eines gegebenen Knotens
/*
	Löschen des Knotens mit dem Schlüssel key
*/

    if (!this->head_tail->next) {
        return false;
    }

    Node *ptr = this->head_tail->next;

    while(ptr != this->head_tail) {
        if(ptr->key == key) {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;

            delete(ptr);

            return true;
        }

        ptr = ptr->next;
    }
    return false;
}

bool List::search(int key) {
    // suchen eines Knotens
/*
	suchen ob ein Knoten mit dem Schlüssel key existiert.
*/

    if(!this->head_tail->next) {
        return false;
    }

    Node *ptr = this->head_tail->next;

    while(ptr != this->head_tail) {
        if(ptr->key == key) {
            return true;
        }

        ptr = ptr->next;
    }

    return false;
}

bool List::swap(int key1, int key2) {
    // Vertauschen von zwei Knoten
    // Dabei werden die Zeiger der Knoten und deren Nachbarn verändert.
/*
	Vertauschen von zwei Knoten mit dem key1 und dem key2
	Es dürfen nicht nur einfach die Schlüssel in den Knoten getauscht werden!
	Die Knoten sind in der Kette umzuhängen.
*/
    if (!this->head_tail->next) {
        return false;
    }

    if (key1 == key2) {
        return true;
    }

    Node *ptr = this->head_tail->next;
    Node *node1 = nullptr;
    Node *node2 = nullptr;

    while(ptr != this->head_tail) {
        if(ptr->key == key1 && node1 == nullptr) {
            node1 = ptr;
        }

        if(ptr->key == key2 && node2 == nullptr) {
            node2 = ptr;
        }

        if(node1 != nullptr && node2 != nullptr) {
            break;
        }

        ptr = ptr->next;
    }

    if(node1 == nullptr|| node2 == nullptr) {
        return true;
    }

    //std::cout << node1->key << "-" << node2->key << std::endl;

    Node *temp = head_tail->next;

    while(temp->prev->key != node1->key) {
        temp = temp->next;
    }

    node1->next = node2->next;
    node2->next->prev = node1;
    node2->next = temp;
    temp->prev = node2;
    node2->prev->next = node1;
    node1->prev->next = node2;
    temp = node2->prev;
    node2->prev = node1->prev;
    node1->prev = temp;


    return true;
}

int List::size() {
    // Rückgabe der Knoten in der Liste mit O(1)
/*
	Anzahl der Knoten in der Liste zurückgeben.
*/
    if (!this->head_tail->next) {
        return 0;
    }

    Node *ptr = this->head_tail->next;
    int counter = 1;

    while(ptr->next != this->head_tail) {
        counter++;
        ptr = ptr->next;
    }

    return counter;
}

bool List::test() {
    // Testmethode: die Methode durchläuft die Liste vom Anfang bis zum Ende und zurück
    // Es werden dabei die Anzahl der Knoten gezählt.
    // Stimmt die Anzahl der Knoten überein liefert die Methode true
    Node *tmp = head_tail->next;
    int i_next = 0, i_prev = 0;
    while (tmp != head_tail) {
        tmp = tmp->next;
        std::cout << list_size;
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

List &List::operator=(const List &_List) {
    // in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden sollen.
    // Kopiert wird in das Objekt "this"
    if (this == &_List) return *this;        //  !! keine Aktion notwendig
    list_form = _List.list_form;
    Node *tmp_node;
    if (list_size) {
        Node *tmp_del;
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

List &List::operator=(const List *_List) {
    // in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden sollen.
    // Kopiert wird in das Objekt "this"
    if (this == _List) return *this;        //  !! keine Aktion notwendig
    list_form = _List->list_form;
    Node *tmp_node;
    if (list_size) {
        Node *tmp_del;
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

List &List::operator+(const List &List_Append) {
    // Die Methode +
    // Es werden zwei Listen aneinander gehangen.
    // Dabei werden beide Ursprungslisten nicht verändert. Es entsteht eine neue Ergebnisliste.
    Node *tmp_node;
    List *tmp;
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

List &List::operator+(const List *List_Append) {
    // Die Methode +
    // Es werden zwei Listen aneinander gehangen.
    // Dabei werden beide Ursprungslisten nicht verändert. Es entsteht eine neue Ergebnisliste.
    Node *tmp_node;
    List *tmp;
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

void List::format(const std::string &start, const std::string &zwischen, const std::string &ende) {
    // Setzen des Formates für die Ausgabesteuerung der Liste bei cout
    // das Format wird für den überladenen Operator << verwendet
    list_form.start = start;
    list_form.zwischen = zwischen;
    list_form.ende = ende;
}

std::ostream &operator<<(std::ostream &stream, List const &Liste) {
    // Ausgabe der Liste mit cout
    stream << Liste.list_form.start;
    for (Node *tmp = Liste.head_tail->next; tmp != Liste.head_tail; tmp = tmp->next)
        stream << tmp->key << (tmp->next == Liste.head_tail ? Liste.list_form.ende : Liste.list_form.zwischen);
    if (Liste.temp) delete &Liste;            // wurde eine temporäre Liste übergeben, dann wird diese gelöscht
    return stream;
}

std::ostream &operator<<(std::ostream &stream, List const *Liste) {
    // Ausgabe der Liste mit cout
    stream << Liste->list_form.start;
    for (Node *tmp = Liste->head_tail->next; tmp != Liste->head_tail; tmp = tmp->next)
        stream << tmp->key << (tmp->next == Liste->head_tail ? Liste->list_form.ende : Liste->list_form.zwischen);
    if (Liste->temp) delete Liste;            // wurde eine temporäre Liste übergeben, dann wird diese gelöscht
    return stream;
}
