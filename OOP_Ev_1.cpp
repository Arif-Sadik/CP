#include <iostream>
using namespace std;

class Student {
protected:
    int theory;
    int sessional;
public:
    void setMarks(int t, int s) { theory = t; sessional = s; }
    int getTheory() { return theory; }
    int getSessional() { return sessional; }
};

class L4Student : public Student {
    int thesis;
public:
    void setThesis(int th) { thesis = th; }
    int getThesis() { return thesis; }
    void display() {
        cout << "Student Marks:" << endl;
        cout << "Theory: " << getTheory() << endl;
        cout << "Sessional: " << getSessional() << endl;
        cout << "Thesis: " << thesis << endl;
    }
};

int main() {
    L4Student student1;
    student1.setMarks(85, 90);
    student1.setThesis(95);
    student1.display();
    return 0;
}
