//Programmer: Ethan Yi Chiang
//Programmer's ID: 1538719

#include <iostream>
#include <algorithm>// swap()
using namespace std;

//class
class Leg
{
  const char* const startCity;
  const char* const endCity;
  const double distance;

  public:
  double getDistance();
  void output(ostream&);
  Leg& operator=(const Leg&);// for swap()
  Leg(const char* const, const char* const, double);
};

const int size = 8;// Leg array size is 8

int main()
{
  cout << "Programmer: Ethan Yi Chiang\n"
       << "Programmer's ID: 1538719\n"
       << "File: " << __FILE__ << "\n\n";

  Leg l[] = 
  {
    Leg("PLeasnat Hill", "Concord", 1.1),
    Leg("Concord", "Walnut Creek", 2.1),
    Leg("Walnut Creek", "Fremont", 20.1),
    Leg("Fremont", "San Ramon", 15.1),
    Leg("San Ramon", "Pleasanton", 6.7),
    Leg("Pleasanton", "Livermore", 4.2),
    Leg("Livermore", "Tracy", 10.2),
    Leg("Tracy", "Stockton", 20.2)
  };

  //sorting loop
  for(int i = 0; i < size; i++)
  {
    for(int j = i+1; j < size; j++)
    {
      if(l[i].getDistance() > l[j].getDistance())
        swap(l[i], l[j]);
    }
  }

  //output sorted legs
  for(int i = 0; i < size; i++)
  {
    l[i].output(cout);
  }

  return 0;
}

//getter functions
double Leg::getDistance()
{
  return distance;
}

void Leg::output(ostream& out)
{
  out << "Leg: " << startCity << " to " << endCity
      << ", " << distance << " miles\n";
}

//constructor
Leg::Leg(const char* const startCity, const char* const endCity, double distance)
:startCity(startCity), endCity(endCity), distance(distance) 
{
}

//assignment operator
Leg& Leg::operator=(const Leg& copyThis)
{
  Leg& host = *this; 
  if (this != &copyThis) 
  {
    const_cast<const char*&>(host.startCity) = copyThis.startCity;
    const_cast<const char*&>(host.endCity) = copyThis.endCity;
    const_cast<double&>(host.distance) = copyThis.distance;
  }
  return host; 
}