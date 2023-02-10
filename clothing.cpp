#include <sstream>
#include <iomanip>
#include "product.h"
#include "clothing.h"

using namespace std;

Clothing::Clothing(const string category, const string name, double price, int qty, string size1, string brand1):Product(category, name, price, qty){
    size = size1;
    brand = brand1;
}

Clothing::~Clothing(){}

string Clothing::getSize() const{
    return size;
}

string Clothing::getBrand() const{
    return brand;
}
set<string> Clothing::keywords() const{
    set<string> brandSet;
    set<string> nameSet;
    set<string> result;

    brandSet.insert(brand);
   // set<string>::iterator it = isbnSet.begin();
    nameSet = parseStringToWords(name_);
    result = setUnion(brandSet, nameSet);

    return result;

    
}
void Clothing::dump(std::ostream& os) const{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ <<"\n" <<getSize() << "\n" << getBrand()<<endl;
}
string Clothing::displayString() const{
    stringstream content;
	content << getName() <<endl;
    content << "Size: " << getSize() ;
    content << " Brand: " << getBrand() << "\n";
    content << fixed << setprecision(2) << price_ << " " << qty_ << " left.\n";

    // string content = "";
    // content+="Size: " + size + "\n";
    // content+="Brand: " + brand + "\n";
    // content+="Price: " + to_string(price_) + "\n";
    // content+="Qty: " + to_string(qty_) + "left.\n";

    return content.str();
    

}


