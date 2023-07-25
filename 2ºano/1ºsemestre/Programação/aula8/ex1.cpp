#include <iostream>
#include <string>

class person  {
private:
    int pid;
    std::string pname;
public:
    person(int id, const std::string& name)
      : pid(id), pname(name) { }
    int id() const {
      return pid;
    }
    const std::string& name() const {
      return pname;
    }
    virtual void print(std::ostream& out) const {
      out << "ID: " << pid << std::endl
          << "Name: " << pname << std::endl;
    }
};

class student : public person {
private:
    std::string scourse;
public:
    student(int id, const std::string &name, const std::string &course)
            : person(id, name), scourse(course) { }
    const std::string& course() const {
        return scourse;
    }
    void print(std::ostream& out) const override {
        person::print(out);
        out << "Course: " << scourse << std::endl;
    }
};

class erasmus_student : public student {
private:
    std::string ecountry;
public:
    erasmus_student(int id, const std::string &name, const std::string &course, const std::string& country)
            : student(id,name,course), ecountry(country) { }
    const std::string& country() const {
        return ecountry;
    }
    void print(std::ostream& out) const override {
        student::print(out);
        out << "Course: " << ecountry << std::endl;
    }
};

int main(void) {
    person p(123, "Matias Oliveira");
    student s(124, "Maria Oliveira", "LEIC");
    erasmus_student es(125, "John Zorn", "LEIC", "United States");
    p.print(std::cout);
    s.print(std::cout);
    es.print(std::cout);
    return 0;
}