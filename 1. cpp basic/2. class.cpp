#include <iostream>
using namespace std;

class Student{
private:
    
public:
    int score;
    string name;
    Student(string n, int s = 0): score(s), name(n){}
    ~Student(){}

    void print()
    {
        cout << this->name << ": " << this->score << "점" << endl;
    }
};
int main(){
    
    Student class1[5] = 
    {
        {Student("비와이", 59)},
        {Student("저스디스", 90)},
        {Student("토일", 53)},
        {Student("스키니 브라운", 75)},
        {Student("애쉬 아일랜드")}
    };

    for(Student c : class1)
    {
        c.print();
    }
}