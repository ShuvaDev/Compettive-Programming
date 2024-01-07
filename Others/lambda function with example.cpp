#include<bits/stdc++.h>
using namespace std;

/**
 *  Lambda Expression : [ capture clause ] (parameters) -> return-type  {}
 *  -> return type is optional
 *  Syntax used for capturing variables : 
 *      [&] : capture all external variables by reference 
 *      [=] : capture all external variables by value 
 *      [a, &b] : capture a by value and b by reference
*/

/*
    Problem:
        You have name, age and cgpa of four students. Now sort the students
        according to below's condition.
            A student who has highest cgpa will have highest piority.
            If two student has same cgpa then age will be in consideration and so on.
*/

class Student {
public: 
    string name;
    int age;
    float CGPA;
    Student(string name, int age, float CGPA) {
        this -> name = name;
        this -> age = age;
        this -> CGPA = CGPA;
    }
    void print() {
        cout << "Name : " << name << endl;
        cout << "Age  : " << age << endl;
        cout << "CGPA : " << CGPA << endl;
    }
};

int main() {
    Student s1("a", 20, 3.94);
    Student s2("b", 20, 3.94);
    Student s3("c", 21, 3.94);
    Student s4("d", 21, 3.95);

    vector<Student> vc;
    vc.push_back(s1);
    vc.push_back(s2);
    vc.push_back(s3);
    vc.push_back(s4);

    sort(vc.begin(), vc.end(), [](Student s1, Student s2) {
        if(s2.CGPA > s1.CGPA) {
            return false;
        } else if(s2.CGPA < s1.CGPA) {
            return true;
        } else {
            if(s2.age > s1.age) {
                return false;
            } else if(s2.age < s1.age) {
                return true;
            } else {
                if(s2.name > s1.name) {
                    return true;
                } else {
                    return false;
                }
            }
        }
    });

    for(auto i : vc) {
        i.print();
        cout << endl;
    }
}