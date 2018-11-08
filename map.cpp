#include <map>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Person {
public:

  // Default constructor
  Person() : m_name(""), m_age(0) {};

  // Constructor
  Person(const string & name, const size_t & age) :m_name(name), m_age(age) {};

  // Copy constructor
  Person(const Person & other) : m_name(other.m_name), m_age(other.m_age) {};
  
  // Operator overloading (needed for std::map).
  bool operator<(const Person& other) const {
    if (m_name == other.m_name) {
      return m_age < other.m_age;
    } else {
      return m_name < other.m_name;
    }
  };
  	
  // Print() method should be const!
  // because Person() instances are used
  // as map keys.
  void print() const {
    cout << "Name: " << m_name << ", Age: " << m_age << flush;
  }

private:
  string m_name;
  size_t m_age;
};

int main() {

  map<Person, int> people;
	
  people[Person("Mike", 30)] = 12;
  people[Person("Kate", 12)] = 42;
  people[Person("Mike", 444)] = 121;

  for (auto it = people.begin(); it != people.end(); it++) {
    cout <<  it->second << " " << flush;
    it->first.print();
    cout << endl;
  }

    return 0;
}
