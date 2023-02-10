#include <string>
#include "product.h"
#include "util.h"


using namespace std;

class Clothing: public Product{ 
public:

Clothing(const string category, const string name, double price, int qty, string size1, string brand1);
std::set<std::string> keywords() const;
std::string displayString() const;
void dump(std::ostream& os) const;
string getSize() const;
string getBrand() const;
~Clothing();


private:
string size;
string brand;

};