#include <string>
#include "product.h"
#include "util.h"


using namespace std;

class Book: public Product{ 
public:

Book(const string category, const string name, double price, int qty, string isbn1, string author1);
std::set<std::string> keywords() const;
std::string displayString() const;
void dump(std::ostream& os) const;
string getAuthor() const;
string getIsbn() const;
~Book();


private:
string isbn;
string author;

};