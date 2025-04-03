#include <iostream>
using namespace std;

class Hero {
    protected:
    int heroID;
    string heroName;
    int heroHealth;
    int heroLevel;
    string heroWeapon;
    public:
    Hero(int i, string n, int h, int l, string w) : heroID(i), heroName(n), heroHealth(h), heroLevel(l), heroWeapon(w) {}
    virtual void performAttack() {
        cout << heroName << " attacks with " << heroWeapon << endl;
    }
    virtual void performDefense() {
        cout << heroName << " defends against the attack " << endl;
    }
    virtual void showHeroInfo() {
        cout << "ID: " << heroID << endl;
        cout << "Name: " << heroName << endl;
        cout << "Health: " << heroHealth << endl;
        cout << "Level: " << heroLevel << endl;
        cout << "Weapon: " << heroWeapon << endl;
    }
};

class Warrior : public Hero {
    protected:
    int armorStrength;
    int meleeDamage;
    public:
    Warrior(int i, string n, int h, int l, string w, int a, int md) : Hero(i, n, h, l, w), armorStrength(a), meleeDamage(md) {}
    void performAttack() override {
        cout << heroName << " attacks with a powerful " << heroWeapon << " dealing " << meleeDamage << " damage and gaining " << armorStrength << " armor strength" << endl;
    }
};

class Mage : public Hero {
    protected:
    int manaPoints;
    int spellPower;
    public:
    Mage(int id, string n, int lvl, int hp, string weapon, int mana, int power) : Hero(id, n, hp, lvl, weapon), manaPoints(mana), spellPower(power) {}
    void performDefense() override {
        cout << heroName << " casts a magical barrier, reducing incoming damage!" << endl;
    }
};

class Archer : public Hero {
    private:
    int arrowCount;
    int rangedAccuracy;
    public:
    Archer(int id, string n, int lvl, int hp, string weapon, int arrows, int accuracy) : Hero(id, n, hp, lvl, weapon), arrowCount(arrows), rangedAccuracy(accuracy) {}
    void performAttack() override {
        if (arrowCount > 0) {
            cout << heroName << " fires an arrow with " << rangedAccuracy << "% accuracy!" << endl;
            arrowCount--;
        } else {
            cout << heroName << " has no arrows left!" << endl;
        }
    }
};

class Rogue : public Hero {
    protected:
    int stealthLevel;
    int agility;
    public:
    Rogue(int i, string n, int h, int l, string w, int s, int ag) : Hero(i, n, h, l, w), stealthLevel(s), agility(ag) {}
    void showHeroInfo() override {
        Hero::showHeroInfo();
        cout << "Stealth Level: " << stealthLevel << endl;
        cout << "Agility: " << agility << endl;
    }
};

int main() {
    Warrior warrior(1, "Ali", 20000, 1000, "Bow", 30, 25);
    Mage mage(2, "Ahmed", 9000, 100, "Staff", 100, 50);
    Archer archer(3, "Murtaza", 15000, 70, "Sword", 15, 90);
    Rogue rogue(4, "Abdullah", 13000, 120, "Dagger", 82, 1500);
    warrior.showHeroInfo();
    warrior.performAttack();
    
    mage.showHeroInfo();
    mage.performDefense();
    
    archer.showHeroInfo();
    archer.performAttack();
    
    rogue.showHeroInfo();
    
    return 0;
}