#include <iostream>
#include<string>
#include<list>

struct Employee
{
    std::string name;
    std::string company;
    int age;

    Employee(std::string name, std::string company, int age)
    {
        this->name = name;
        this->company = company;
        this->age = age;
    }
    
    bool operator==(const Employee& emp) const {
        return this->name == emp.name;
    }

};

std::ostream& operator<<(std::ostream& COUT, Employee& employee) {
    COUT << "Name: " << employee.name << std::endl;
    COUT << "Company: " << employee.company << std::endl;
    COUT << "Age: " << employee.age << std::endl;

    return COUT;
}


struct MyCollection
{
    std::list<Employee> employees;

    void operator+=(Employee& employee) {
        this->employees.push_back(employee);
    }

    void operator-=(Employee& employee) {
        this->employees.remove(employee);
    }
};

std::ostream& operator<<(std::ostream& COUT, MyCollection& coll) {
    for(Employee emps: coll.employees)
    {
        COUT << emps << std::endl;
    }
    return COUT;
}

int main()
{
    Employee* p;
    Employee emp("Peter", "Apple", 25);
    Employee emp1("Jane", "Orange", 40);
    Employee emp2("Tom", "Banana", 30);
    Employee emp3("Ken", "Peas", 21);
    Employee emp4("Robert", "Beans", 28);
    Employee emp5("Maci", "Oats", 18);

    p = &emp;

    //std::cout << "name: " << p->name << std::endl;

    //std::cout << emp;

    //std::cout << emp << emp1;

     MyCollection m_collection;
     m_collection += emp;
     m_collection += emp1;
     m_collection += emp2;
     m_collection += emp3;
     m_collection += emp4;
     m_collection += emp5;

     std::cout << m_collection;

     std::cout << "******************************" << std::endl;

     m_collection -= emp;
     m_collection -= emp1;
     m_collection -= emp2;
     m_collection -= emp3;

      std::cout << m_collection;

}
