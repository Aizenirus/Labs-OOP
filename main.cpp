#include <iostream>
#include <string>

class Character {
private:
    std::string name;  // ��������� ����: ��� ���������
    int health;        // ��������� ����: ������� ��������
    int maxHealth;     // ��������� ����: ������������ ������� ��������
    int attack;        // ��������� ����: ������� �����
    int defense;       // ��������� ����: ������� ������

public:
    // ����������� ��� ������������� ������
    Character(const std::string& n, int h, int a, int d)
        : name(n), health(h), maxHealth(h), attack(a), defense(d) {}

    // ����� ��� ��������� ������ ��������
    int getHealth() const {
        return health;
    }

    // ����� ��� ������ ���������� � ���������
    void displayInfo() const {
        std::cout << "Name: " << name << ", HP: " << health
            << ", Attack: " << attack << ", Defense: " << defense << std::endl;
    }

    // ����� ��� ����� ������� ���������
    void attackEnemy(Character& enemy) {
        int damage = attack - enemy.defense;
        if (damage > 0) {
            enemy.takeDamage(damage);
            std::cout << name << " attacks " << enemy.name << " for " << damage << " damage!" << std::endl;
        }
        else {
            std::cout << name << " attacks " << enemy.name << ", but it has no effect!" << std::endl;
        }
    }

    // ����� ������� 
    void heal(int temp) {
        health += temp;
        if (health > maxHealth) {
            health = maxHealth;
        }
        std::cout << name << " heals for " << temp << " HP. Current HP: " << health << std::endl;
    }

    // ����� ��� ��������� �����
    void takeDamage(int temp) {
        health -= temp;
        if (health < 0) {
            health = 0;
        }
    }
};

int main() {
    // ������� ������� ����������
    Character hero("Hero", 100, 20, 10);
    Character monster("Goblin", 50, 15, 5);

    // ������� ���������� � ����������
    hero.displayInfo();
    monster.displayInfo();

    // ����� ������� �������
    hero.attackEnemy(monster);
    monster.displayInfo();

    // ������ ������� �����
    monster.attackEnemy(hero);
    hero.displayInfo();

    // ����� �������
    hero.heal(30);
    hero.displayInfo();

    // ����� �������� ����
    hero.takeDamage(50);
    std::cout << "Hero takes 50 damage!" << std::endl;
    hero.displayInfo();

    // ����� ������� ����� ���������
    hero.heal(80);
    hero.displayInfo();

    return 0;
}