#include <iostream>
using namespace std;

class Student {
private:
    int id;
    int english_score;
    int math_score;

public:
    // Konstruktor z parametrami
    Student(int id, int english, int math) 
        : id(id), english_score(english), math_score(math) {}

    // Konstruktor domyślny
    Student() : id(0), english_score(0), math_score(0) {}

    // Operator przypisania (kopiuje tylko oceny, nie ID)
    Student& operator=(const Student& other) {
        if (this != &other) {
            english_score = other.english_score;
            math_score = other.math_score;
        }
        return *this;
    }

    // Operator wyjścia (<<)
    friend ostream& operator<<(ostream& os, const Student& s) {
        os << "ID: " << s.id 
           << ", English: " << s.english_score 
           << ", Math: " << s.math_score;
        return os;
    }

    // Operator wejścia (>>)
    friend istream& operator>>(istream& is, Student& s) {
        is >> s.id >> s.english_score >> s.math_score;
        return is;
    }

    // Gettery
    int getID() const {
        return id;
    }

    int getEnglish() const {
        return english_score;
    }

    int getMath() const {
        return math_score;
    }
};

// DO NOT MODIFY ANYTHING BELOW, MAY RESULT WITH FAILED HOMEWORK
int main() 
{ 
    int id1, id2, e1, e2, m1, m2, variant;
    cin >> id1 >> e1 >> m1 >> id2 >> e2 >> m2 >> variant;
    Student s1(id1, e1, m1), s2(id2, e2, m2);
    if (variant == 1)
    {
        s1 = s2;
        cout << s1.getID()<< " " << s1.getEnglish() << " " << s1.getMath();
    }
    else if (variant == 2)
    {
        s1 = s1;
        cout << s1.getID()<< " " << s1.getEnglish() << " " << s1.getMath();
    }
    else if (variant == 3)
    {
        cin >> s1;
        cout << s1.getID()<< " " << s1.getEnglish() << " " << s1.getMath();
    }
    else if (variant == 4)
    {
        cout << s1;
    }
    else
    {
        return 1;
    }
    return 0; 
}
