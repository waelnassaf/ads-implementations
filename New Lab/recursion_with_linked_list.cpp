#include <iostream>
#include <string>
using namespace std;


class Astro {
public:
    string name;
    string country;
    int year;
    int planetCount;
    string* planets;

    Astro(string name, string country, int year) {
        this->name = name;
        this->country = country;
        this->year = year;
        this->planetCount = 0;
        this->planets = new string[100];
    }
    Astro() {
        this->name = "";
        this->country = "";
        this->year = 0;
        this->planetCount = 0;
        this->planets = new string[100];
    }
};

class Node {
public:
    Astro a;
    Node* next;

    Node(string name, string country, int year, Node* next = 0) {
        a = Astro(name, country, year);
        this->next = next;
    }
    Node() {
        a = Astro();
        this->next = 0;
    }

    void addPlanet(string name) {
        a.planets[a.planetCount++] = name;
    }
};

class List {
public:
    Node* head;
    Node* tail;

    List() {    head = tail = 0;    }

    void AddToHead(string name, string country, int year, string p[], int size) {
        if (head == 0) head = tail = new Node(name, country, year);
        else {
            Node* temp = new Node(name, country, year);
            temp->next = head;
            head = temp;
//            head = new Node(name, country, year, head); Only this line could do.
        }

        size = size > 100 ? 100 : size;

        for (int i = 0; i < size; ++i) {
            head->addPlanet(p[i]);
        }

    }
    void AddToTail(string name, string country, int year, string p[], int size) {
        if (head == 0) head = tail = new Node(name, country, year);
        else {
            tail->next = new Node(name, country, year);
            tail = tail->next;
            tail->next = 0;
        }

        size = size > 100 ? 100 : size;

        for (int i = 0; i < size; ++i) {
            tail->addPlanet(p[i]);
        }

    }

    bool DeleteHead() {
        if (head == 0) return false;
        else if (head == tail) {
            delete head;
            head = tail = 0;
            return true;
        } else {
            Node* temp = head->next;
            delete head;
            head = temp;
            return true;
        }
    }
    bool DeleteTail() {
        if (head == 0) return false;
        else if (head == tail) {
            delete tail;
            head = tail = 0;
            return true;
        } else {
            Node* temp = head;
            while (temp->next != tail)
                temp = temp->next;
            delete tail;
            tail = temp;
            tail->next = 0;
            return true;
        }
    }

    // A function that takes a planet name and remove all astronauts
    // that have visited this planet.
    void RemoveAstro(string name) {
        Node* prev = 0;
        Node* curr = head;

        while (curr != 0) {
            bool found = false;
            for (int i = 0; i < curr->a.planetCount; ++i) {
                if (curr->a.planets[i] == name) {
                    found = true;
                    break;
                }
            }
            if (found) {
                if (curr == head) {
                    if (head == tail) {
                        delete head;
                        curr = head = tail = 0;
                    } else {
                        Node* temp = head->next;
                        delete head;
                        head = temp;
                        curr = head;
                    }
                } else {
                    prev->next = curr->next;
                    delete curr;
                    curr = prev->next;
                }
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
    }

    void Print() {
        Node* temp = head;
        while (temp != 0) {
            cout << "++++++++++++++++" << endl;
            cout << "Name: " << temp->a.name << endl;
            cout << "Country: " << temp->a.country << endl;
            cout << "Year: " << temp->a.year << endl;
            cout << "Planets: " << endl;
            for (int i = 0; i < temp->a.planetCount; ++i)
                cout << "\t" << temp->a.planets[i] << endl;
            cout << "++++++++++++++++\n" << endl;
            temp = temp->next;
        }
    }

    // Truncate List recursively.
    void Clear(Node* head) {
        if (head) {
            Clear(head->next);
            DeleteHead();
        }
    }

    // Print list in Odd/Even order recursively.
    void PrintAlternate(Node* head, bool odd) {
        if (head) {
            if (odd) cout << head->a.name << endl;
            PrintAlternate(head->next, !odd);
        }
    }

    int MaxAllowedIndex(Node* temp) {
        int MaxIndex = 0;
        while (temp) {
            temp = temp->next;
            MaxIndex++;
        }
        return MaxIndex;
    }


    // Insert a node at a given index recursively.
    Node* InsertNodeRecursive
            (
                    Node* head, string name, string country,
                    int year, string p[], int size,
                    int index
            )
    {
        /*---   Sanitize Index  ---*/
        if (index < 0) index = 0;
        index = index > MaxAllowedIndex(head) ? MaxAllowedIndex(head) : index;


        if (index > 0) {
            head->next
                    =
                    InsertNodeRecursive(head->next, name, country, year, p, size, index-1);
            return head;
        }
        Node* newNode = new Node(name, country, year);
        size = size > 100 ? 100 : size;
        for (int i = 0; i < size; ++i) newNode->addPlanet(p[i]);

        newNode->next = head;
        return newNode;
    }
};



int main() {

    List l;

    string p1[3] = {"Ploto", "Uranus", "Mars"};
    string p2[3] = {"Sun", "Moon", "Uranus"};
    string p3[4] = {"Earth", "Jupiter", "Saturn", "Mercury"};
    string p4[1] = {"Sun"};

    l.AddToHead("Wael", "Beirut", 2033, p1, 3);
    l.AddToHead("Rami", "Cairo", 1988, p2, 3);
    l.AddToTail("Hadi", "Damascus", 2099, p3, 4);

    l.InsertNodeRecursive(l.head, "NewNode", "Florence", 2022, p4, 1, 2);

    l.Print();

    return 0;
}
