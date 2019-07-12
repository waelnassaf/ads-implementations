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
//          head = new Node(name, country, year, head);
        }

        if (size > 100) size = 100;
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

        if (size > 100) size = 100;
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
        }
        else {
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
        }
        else {
            Node* temp = head;
            while (temp->next != tail)
                temp = temp->next;
            delete tail;
            tail = temp;
            tail->next = 0;
            return true;
        }
    }



    // A function that takes a planet name as input
    // then removes all Astronauts that visited this planet.


    void removeAstro(string planetName) {
        Node* prev = 0;
        Node* curr = head;
        while (curr != 0) {
            bool found = false;
            for (int i = 0; i < curr->a.planetCount; ++i) {
                if (curr->a.planets[i] == planetName) {
                    found = true;
                    break;
                }
            }
            if (found == true) {
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
            cout << temp->a.name << endl;
            for (int i = 0; i < temp->a.planetCount; ++i)
                  cout << "\t" << temp->a.planets[i] << endl;
            temp = temp->next;
        }
    }
};

class Stack {
public:
    List l;

    void Push(string name, string country, int year, string p[], int size) {
        l.AddToHead(name, country, year, p, size);
    }

    bool Pop() {
        return l.DeleteHead();
    }

    Astro Top() {
        return l.head->a;
    }

    void Clear() {
        while (l.head != 0)
            l.DeleteHead();
    }

    bool IsEmpty() {
        return l.head == 0;
    }


    void Print() {
        l.Print();
    }

};


int main() {

    List l1;

    string p1[3] = {"Ploto", "Uranus", "Mars"};
    string p2[3] = {"Sun", "Moon", "Uranus"};

    l1.AddToHead("Wael", "Beirut", 2033, p1, 3);
    l1.AddToHead("Sami", "Cairo", 1988, p2, 3);

    l1.Print();
    l1.removeAstro("Sun");

    cout << "After deletion .. " << endl;
    l1.Print();


    cout<<"stack is coming soon"<<endl;
    Stack s;
    s.Push("omar","senegal",2000,p2,3);
    s.Push("khaled","Syria",1950,p1,3);
    s.Push("Abdo","Syria",1950,p2,3);
    s.Push("Hussam","Syria",1950,p1,3);
    s.Print();
    Astro temp = s.Top();
    cout<<temp.name<<endl;
    s.Pop();
    cout<<"----------------------------------------"<<endl;
    s.Print();

    return 0;
}
