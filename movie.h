#include <string>
#include "product.h"
#include "util.h"


using namespace std;

class Movie: public Product{ 
public:

Movie(const string category, const string name, double price, int qty, string isbn1, string author1);
std::set<std::string> keywords() const;
std::string displayString() const;
void dump(std::ostream& os) const;
string getGenre() const;
string getRating() const;
~Movie();

private:
string genre;
string rating;

};