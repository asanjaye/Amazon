#include <string>
#include <set>
#include <map>
#include <vector>
#include <string>

#include "datastore.h"
using namespace std;
class MyDataStore : public DataStore{
    public:
    /**
     * Adds a product to the data store
     */    
    void addProduct(Product* p);
    /**
     * Adds a user to the data store
     */
    void addUser(User* u);

    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
    std::vector<Product*> search(std::vector<std::string>& terms, int type);

    /**
     * Reproduce the database file from the current Products and User values
     */
    void dump(std::ostream& ofile);

    //Adding an item to our cart
    void addToCart(string username, Product* p);
    
    //printing out all of the items in the user's cart
    vector<Product*>&  viewCart(string u);

    //Buying an item from the user's cart
    void buyCart(string username);

    ~MyDataStore();
    

    private:
    std::map<std::string,User*> users;
    std::vector<Product*> products;

    //std::set<Product*> addedProducts;
    

    std::map<std::string,std::set<Product*>> keyProd;

    std::map<std::string,std::vector<Product*>> cart;
    




    
};