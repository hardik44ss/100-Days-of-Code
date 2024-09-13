#include <iostream>
#include <cstring> // For using string functions
using namespace std;

class Hero {
    
    // Properties
    private:
    int health;       // Private member variable (Encapsulation)

    public:
    char *name;       // Dynamic memory allocation for name
    char level;       // Character to represent level
    static int timeToComplete;  // Static member variable, shared by all objects

    // Default Constructor
    Hero() {
        cout << "Default Constructor called" << endl;
        name = new char[10];  // Dynamically allocate memory for name
    }

    // Parameterized Constructor with health only
    Hero(int health) {
        this->health = health;  // Use 'this' pointer to differentiate between member and local variables
    }

    // Parameterized Constructor with health and level
    Hero(int health, char level) {
        this->level = level;
        this->health = health;
    }

    // Copy Constructor (Commented out in your code)
    // It ensures deep copying for dynamically allocated memory
    /*
    Hero(Hero& temp) {
        char *ch = new char[strlen(temp.name) + 1]; // Deep copy the name
        strcpy(ch, temp.name);
        this->name = ch;

        cout << "Copy Constructor called" << endl;
        this->health = temp.health;
        this->level = temp.level;
    }
    */

    // Getter for health
    int getHealth() {
        return health;
    }

    // Getter for level
    char getLevel() {
        return level;
    }

    // Setter for health
    void setHealth(int h) {
        health = h;
    }

    // Setter for level
    void setLevel(char ch) {
        level = ch;
    }

    // Setter for name
    void setName(char name[]) {
        strcpy(this->name, name);  // Assign new name
    }

    // Static function to demonstrate static member access
    static int random() {
        //Static function can only access static members
        return timeToComplete;
    }

    // Print function to display the properties of Hero
    void print(){
        cout << endl;
        cout << "[ Name: " << this->name << ", ";
        cout << "Health: " << this->health << ", ";
        cout << "Level: " << this->level << " ]" << endl;
    }

    // Destructor to release dynamically allocated memory
    ~Hero() {   
        cout << "Destructor called, releasing resources" << endl;
        delete[] name;  // Deallocate dynamically allocated memory
    }
};

// Initialize static variable outside the class
int Hero::timeToComplete = 5;

int main() {

    // Accessing static member using class name
    cout << "Static Time to Complete: " << Hero::random() << endl;

    // Create object using default constructor
    Hero hero1;

    // Setting properties using setters
    hero1.setHealth(100);
    hero1.setLevel('A');
    char name1[7] = "Babbar";
    hero1.setName(name1);

    // Print the object details
    hero1.print();

    // Using the copy constructor (Uncomment if needed)
    // Hero hero2(hero1);
    // hero2.print();

    // Modify original object's name to see effect of deep/shallow copy
    hero1.name[0] = 'G'; // Modify name
    hero1.print(); // Now "Babbar" becomes "Gabbar"

    // Assign one object to another (assignment operator, shallow copy)
    // hero2 = hero1;
    // hero1.print();
    // hero2.print();

    // Static allocation
    Hero ramesh(80, 'B');
    ramesh.print();

    // Dynamic allocation using new
    Hero *h = new Hero(90, 'C');
    h->print();
    
    // Manually delete dynamically allocated object to call destructor
    delete h;

    // Destructor will automatically be called for static objects at program end

    return 0;
}
