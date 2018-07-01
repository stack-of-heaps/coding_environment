#include <iostream>
#include <vector>
#include <locale>
#include <string>

/**************************************************************************
                              PRODUCT CLASS
***************************************************************************/
class Product
{
private:
    std::string idCode;
    std::string title;
    std::string description;
    double price;
    int quantityAvailable;
public:
    Product(std::string id, std::string t, std::string d, double p, int qa);
    std::string getIdCode();
    std::string getTitle();
    std::string getDescription();
    double getPrice();
    int getQuantityAvailable();
    void decreaseQuantity();
};


/**************************************************************************
                              CUSTOMER CLASS
***************************************************************************/

class Customer
{
private:
   std::vector<std::string> cart;
   std::string name;
   std::string accountID;
   bool premiumMember;
public:
   Customer(std::string n, std::string a, bool pm);
   std::string getAccountID();
   std::vector<std::string> getCart();
   void addProductToCart(std::string);
   bool isPremiumMember();
   void emptyCart();
};


/**************************************************************************
                              STORE CLASS
***************************************************************************/


class Store
{
private:
    std::vector<Product*> inventory;
    std::vector<Customer*> members;
public:
    void addProduct(Product* p);
    void addMember(Customer* c);
    Product* getProductFromID(std::string);
    Customer* getMemberFromID(std::string);
    std::vector<std::string>  productSearch(std::string str);
    std::string addProductToMemberCart(std::string pID, std::string mID);
    double checkOutMember(std::string mID);
};


/**************************************************************************
                              PRODUCT FUNCTIONS 
***************************************************************************/

Product::Product(std::string id, std::string t, std::string d, double p, int qa){
  idCode = id;
  title = t;
  description = d;
  price = p;
  quantityAvailable = qa;
  }


std::string Product::getIdCode(){
    return idCode;
}

std::string Product::getTitle(){
    return title;
}

std::string Product::getDescription(){
    return description;
}

double Product::getPrice(){
    return price;
}

int Product::getQuantityAvailable(){
    return quantityAvailable;
}

void Product::decreaseQuantity(){
    quantityAvailable--;
}

/**************************************************************************
                              CUSTOMER FUNCTIONS 
***************************************************************************/

Customer::Customer(std::string n, std::string a, bool pm){
    
    name = n;
    accountID = a;
    premiumMember = pm;
}

std::string Customer::getAccountID(){
    return accountID;
}

std::vector<std::string> Customer::getCart(){
    
    std::vector<std::string>cartContents;
    for (int i = 0; i < cart.size(); i++)
        cartContents.push_back(cart[i]);
    
    return cartContents;
}

void Customer::addProductToCart(std::string pID){
    cart.push_back(pID);
}

bool Customer::isPremiumMember(){
    return premiumMember;
}

void Customer::emptyCart(){
    cart.clear();
}


/**************************************************************************
                              STORE FUNCTIONS 
***************************************************************************/

void Store::addProduct(Product* p){
    inventory.push_back(p);
    
}

void Store::addMember(Customer* c){
    members.push_back(c);
}

Product* Store::getProductFromID(std::string idQuery){
    
    for (auto i = 0; i < inventory.size(); i++){
            if (inventory[i] -> getIdCode() == idQuery)
            return inventory[i]; // does this express the address correctly?
            
            else
            return NULL;
    }
}
            
            //search for product ID. return the address of the ID. 
            //the address of ID is the same as the object since it 
            //is the first member of the object.
            //Product * as a type for the function means that
            //my return should read "return &pFrom Id"

Customer* Store::getMemberFromID(std::string idQuery){
    Customer** customerPointer = &members[0];
    
    for (auto i = 0; i < members.size(); i++){
            if ((*customerPointer + i) -> getAccountID() == idQuery)
            return customerPointer[i]; // does this express the address correctly?
            
            else
            return NULL;
    }
}
    
    
std::vector<std::string>  Store::productSearch(std::string str){
    
    std::vector<std::string> searchResults;
    
    //convert input to lowercase
    std::locale loc;
    for (unsigned int i = 0; i < str.length(); i++)
        str[i] = std::tolower(str[i], loc);
        
         std::cout << "HI";
        
    //declare a pointer to de-reference elements of the inventory vector
    
  
    //search for string matches in the inventory vector    
    for (int i = 0; i < inventory.size(); i++){
        if (inventory[i]->getDescription() == str) 
            searchResults.push_back(inventory[i]->getIdCode());
    }
    return searchResults;
}

std::string Store::addProductToMemberCart(std::string pID, std::string mID){
//calls getMemberFromID and getProductFromID    
    
}

double Store::checkOutMember(std::string mID){
    //call getMemberFromID first, then use it to access their cart
    
    
    
}


void getVal (int * a) {
    *a = 10;
}
int main() {
  
  Product plunger("x123", "Plunger", "Used to clear clogged toilets", 3.33, 10);
  Product hat("x456", "Hat", "Covers your bald spot", 9.99, 15);
  Product moustache("x789", "Moustache", "How'd this get here?", .99, 1);
  
  Product* plunger_ptr = &plunger;
  Product* hat_ptr = &hat;
  Product* moustache_ptr = &moustache;
  
  
  Store superSaver;
  superSaver.addProduct(plunger_ptr);
  superSaver.addProduct(hat_ptr);
  superSaver.addProduct(moustache_ptr);
  
 
 std::vector<Product*> prod_disp;
 
 prod_disp.push_back(superSaver.getProductFromID("x123"));
  
std::cout << prod_disp[0]->getTitle();

  
  return 0;
}

