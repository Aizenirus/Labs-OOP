#include<iostream>
#include <string>

class Character {
private:
    std::string name;
    int health;
    int attack;
    int defense;

public:
    Character(const std::string& n, int h, int a, int d)
        : name(n), health(h), attack(a), defense(d) {
        std::cout << "Character " << name << " created!\n";
    }
    //
    ~Character() {
        std::cout << "Character " << name << " destroyed!\n";
    }

    void displayInfo() const {
        std::cout << "Name: " << name << ", HP: " << health
            << ", Attack: " << attack << ", Defense: " << defense << std::endl;
    }
};

class Monster {
private:
    std::string name;
    int health;
    int attack;
    int defense;

public:
    Monster(const std::string& n, int h, int a, int d)
        : name(n), health(h), attack(a), defense(d) {
        std::cout << "Monster " << name << " created!\n";
    }

    ~Monster() {
        std::cout << "Monster " << name << " destroyed!\n";
    }

    void displayInfo() const {
        std::cout << "Name: " << name << ", HP: " << health
            << ", Attack: " << attack << ", Defense: " << defense << std::endl;
    }
};

class Weapon {
private:
    std::string name;
    int damage;
    float weight;

public:
    Weapon(const std::string& n, int d, float w)
        : name(n), damage(d), weight(w) {
        std::cout << "Weapon " << name << " created!\n";
    }

    ~Weapon() {
        std::cout << "Weapon " << name << " destroyed!\n";
    }

    void displayInfo() const {
        std::cout << "Weapon: " << name << ", Damage: " << damage
            << ", Weight: " << weight << " kg" << std::endl;
    }
};

int main() {
    Character hero("Colt", 100, 15, 10);
    Monster wizard("Wizard", 200, 25, 15);

    hero.displayInfo();
    wizard.displayInfo();

    std::cout << "\n=== Weapons ===\n";
    Weapon sword("Sword", 30, 3.5);
    Weapon bow("Bow", 20, 1.2);
    Weapon axe("Axe", 35, 5.0);

    std::cout << "\n=== Weapons Info ===\n";
    sword.displayInfo();
    bow.displayInfo();
    axe.displayInfo();

    std::cout << "\n=== Destructors ===\n";
    return 0;
}