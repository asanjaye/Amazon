//it++ needs to be added somewhere
#include <string>
#include <set>
#include <vector>
#include <map>
#include <iostream>

#include "mydatastore.h"
#include "util.h"
using namespace std;

MyDataStore::~MyDataStore(){
        //Products
    for(size_t i =0; i<products.size(); i++){
        delete products[i];
    }
		//users
    map<string, User*>::iterator it;
    for(it = users.begin(); it!=users.end(); ++it){
			delete (it->second);
		}
}

void MyDataStore::addProduct(Product* p){
    // set<Product*>::iterator it;
    // if(products.size()==0){
    //     products.insert(p);
    //     it = products.begin();
    // }
    // else{
    //     products.insert(p);
    //     ++it;
    // }

    //relating the keywords to the product name
		    products.push_back(p);

    set<string> words = p->keywords();
    for(set<string>::iterator it = words.begin(); it!= words.end(); ++it){
        if(keyProd.find(*it) == keyProd.end()){
						set<Product*> prod;
						prod.insert(p);
						keyProd.insert(make_pair(*it,prod));
				}
				else{
        	keyProd.find(*it)->second.insert(p);
				}
        
    }

}

void MyDataStore::addUser(User* u){
    //set<User*>::iterator it;
    // if(users.size() == 0){
    //     users.insert(u);
    //     it = users.begin();
    // }
    // else{
    //     users.insert(it,u);
    //     ++it;
    // }
    users[u->getName()]= u;
}

vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type){
    vector<Product*> final;
		set<Product*> keyWords;


		for(int i =0; i<terms.size(); ++i){

			if(keyProd.find(terms[i])!=keyProd.end()){
				if(keyWords.size()==0){
					keyWords = keyProd[terms[i]];
				}
				else if(type==0){

          keyWords = setIntersection(keyProd[terms[i]], keyWords);
          }
        else{
          keyWords = setUnion(keyProd[terms[i]], keyWords);

          }
			}
		}
		set<Product*>::iterator it;
		for(it = keyWords.begin(); it!=keyWords.end(); ++it){
			final.push_back(*it);
		}
		return final;
		
		
		// couthed"<<endl;
		// string temp;
    // map<string,set<Product*>>::iterator it;
    // set<Product*>::iterator it2;




    // //intersection of the sets
		// 		for(int i =0; i<terms.size(); ++i){
		// 			cout<<"terms: ";
		// 			cout<<terms[i]<<endl;
		// 		}
		// 		for(it = keyProd.begin(); it!=keyProd.end(); ++it){
		// 			cout<<"keys: ";
		// 			cout<<it->first<<endl;
		// 		}

    //     for(unsigned int i=0;i<terms.size();i++){
    //         temp = terms[i];


    //         it = keyProd.find(temp);

    //         if(it!=keyProd.end()){
    //             //adng the first set of products corresponding to the term

    //             if(result.size()==0){
    //                 for(it2= it->second.begin();it2!= it->second.end();++it2){
    //                     result.insert(*it2);
    //                 }                
    //             }
    //             //adding the second set of products corresponding to the term
    //             //calling the intersection function and merging this with result

    //             else{
    //                 set<Product*> tempProd;
    //                 for(it2= it->second.begin();it2!= it->second.end();++it2){
    //                     tempProd.insert(*it2);
    //                 }
    //                 //tempProd2 has the second set of products corresponding to the term, now we merge
    //                 if(type==0){
    //                     result = setIntersection(result, tempProd);
    //                 }
    //                 else{
    //                     result = setUnion(result, tempProd);
                        
    //                 }

    //             }   

    //         }

    //     }
    //     for(it2 = result.begin();it2!=result.end();++it2){
    //         final.push_back(*it2);
            
    //    }
    // return final;
}

void MyDataStore::addToCart(string username, Product* p){
    map<string,User*>::iterator it;
    map<string, vector<Product*>>::iterator it2;


    //finding the user object corresponding to the username
    it = users.find(username);
    if(it==users.end() ){
        //username not found
        cout<<"Invalid request"<<endl;
    }
    
    else{
        // if(p->getQty()==0){
        //     cout<<"Product out of stock"<<endl;
        // }
        //if there are no users in the cart or if the user is not in the cart
        if(cart.find(username)==cart.end()){
            // vector<Product*> tempProd;
            // tempProd.push_back(p);
            cart[username].push_back(p);
        }
        else{
            it2 = cart.find(username);
            it2->second.push_back(p);
        }
    }
}

 vector<Product*>& MyDataStore::viewCart(string username){
    map<string,vector<Product*>>::iterator it;
    vector<Product*> tempProd;


    it = cart.find(username);
    if(it == cart.end()){
        cout<<"Invalid username"<<endl;
    }
    else{
        for(unsigned int i = 0; i<cart[username].size(); ++i){
					cout << "Item "<<i+1 <<"\n"<<(cart[username][i])->displayString()<<endl;
				}
}

}

void MyDataStore::buyCart(string username){
    if(cart.find(username) == cart.end()){
			cout<<"invalid username"<<endl;
			return;
		}
		map<string, vector<Product*>>::iterator it;
    map<string, User*>::iterator it2;

    vector<Product*> tempProd;
    User* tempUser;
		vector<Product*> newVec;
    vector<Product*> empty;
    it = cart.find(username);
    it2 = users.find(username);

    tempProd = it->second;
    tempUser = it2->second;

    for(unsigned int i = 0; i<tempProd.size(); ++i){
        if(tempProd[i]->getQty()>0){
            if(tempProd[i]->getPrice()<=tempUser->getBalance()){
                tempProd[i]->subtractQty(1);
                tempUser->deductAmount(tempProd[i]->getPrice());
                //tempProd.pop_back();
            }
						else{
							newVec.push_back(tempProd[i]);
						}
        }
    }
		if(newVec.size()>0){
			it->second = newVec;
		}
		else{
			it->second = empty;
		}


}
void MyDataStore::dump(std::ostream& ofile){
        //products
			ofile<<"<products>"<<endl;
    for(unsigned int i=0;i<products.size();++i){
        products[i]->dump(ofile);
        
    }
		ofile<<"</products>"<<endl;
		//Users
		ofile<<"<users>"<<endl;
    map<string,User*>::iterator it;
    for(it=users.begin(); it!=users.end(); ++it){
        it->second->dump(ofile);
    }
		ofile<<"</users>"<<endl;



}

