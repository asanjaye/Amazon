#include <sstream>
#include <iomanip>
#include <set>
#include "product.h"
#include "book.h"

using namespace std;

Book::Book(const string category, const string name, double price, int qty, string isbn1, string author1):Product(category, name, price, qty){
    isbn = isbn1;
    author = author1;
}
set<string> Book::keywords() const{
    set<string> isbnSet;
    set<string> nameSet;
    set<string> authorSet;
    set<string> result;

    isbnSet.insert(isbn);
   // set<string>::iterator it = isbnSet.begin();
    nameSet = parseStringToWords(name_);
    authorSet = parseStringToWords(author);
    result = setUnion(isbnSet, nameSet);
    result = setUnion(result, authorSet);

    return result;

    
}
Book::~Book(){}

string Book::getIsbn() const{
    return isbn;
}

string Book::getAuthor() const{
    return author;
}
void Book::dump(std::ostream& os) const{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" <<qty_<< "\n" <<getIsbn() << "\n" << getAuthor()<<endl;
}
string Book::displayString() const{
    stringstream content;
	content << getName() <<endl;
    content << "Author: " << author ;
    content << " ISBN: " << isbn << "\n";
    content << fixed << setprecision(2) << price_ << " " << qty_ << " left.\n";

    // string content = "";
    // content+="Author: " + author + "\n";
    // content+="ISBN: " + isbn + "\n";
    // content+="Price: " + setprecision(2)+to_string(price_) +" "+ to_string(qty_) + "left.\n";

    return content.str();
    

}


