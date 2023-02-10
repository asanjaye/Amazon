#include <sstream>
#include <iomanip>
#include "product.h"
#include "movie.h"

using namespace std;

Movie::Movie(const string category, const string name, double price, int qty, string genre1, string rating1):Product(category, name, price, qty){
    genre = genre1;
    rating = rating1;
}

Movie::~Movie(){}

string Movie::getRating() const{
    return rating;
}

string Movie::getGenre() const{
    return genre;
}
set<string> Movie::keywords() const{
    set<string> nameSet;
    set<string> genreSet;
    set<string> result;
		set<string> ratingSet;

    genreSet = parseStringToWords(genre);
   // set<string>::iterator it = isbnSet.begin();
    nameSet = parseStringToWords(name_);
    result = setUnion(nameSet, genreSet);

    return result;

    
}
void Movie::dump(std::ostream& os) const{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ <<"\n" <<genre << "\n" << rating<<endl;
}
string Movie::displayString() const{
    stringstream content;
	content << getName() <<endl;
    content << "Genre: " << getGenre() ;
    content << " Rating: " << getRating() << "\n";
    content << fixed << setprecision(2) << price_ << " " << qty_ << " left.\n";

    return content.str();    

}


