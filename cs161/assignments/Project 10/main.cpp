#include "Product.cpp"
#include "Customer.cpp"
#include "Store.cpp"


#include <iostream>

/*
int main() {
  Product plunger("x123", "Plunger", "Used to clear clogged toilets", 3.33, 1);
 Product hat("x456", "Hat", "Covers your bald spot", 9.99, 15);
 Product moustache("x789", "Moustache", "How'd this get here?", 1.00, 3);
  Product* plunger_ptr = &plunger; //plunger_ptr holds address of plunger Product object
 Product* hat_ptr = &hat;
 Product* moustache_ptr = &moustache;
  Product& plunger_deref = *plunger_ptr; //we can now use "plunger_deref" in lieu of the real plunger
 //At this point we could say:
 // Product* plunger_ptr_ptr = &plunger_deref; another_pointer == pointer
 //&*pointer == pointer

 Store superSaver;
 superSaver.addProduct(plunger_ptr);
 superSaver.addProduct(hat_ptr);
 superSaver.addProduct(moustache_ptr);
 std::vector<Product*> prod_disp;
prod_disp.push_back(superSaver.getProductFromID("x456"));
std::string disp = prod_disp[0]->getTitle();

std::cout << "Get Product From ID returns: " << disp << std::endl;

std::vector<std::string>str_return;

str_return = superSaver.productSearch("a");

for (auto &i: str_return) {
 std::cout << i << ", ";
}

std::cout << "CART TESTING" << std::endl;

Customer kyle("kyle", "a111", true);
Customer mayuka("mayuka", "b222", true);
Customer jim("jim", "c333", false);

Customer *mayuka_ptr = &mayuka;
Customer *kyle_ptr = &kyle;
Customer* jim_ptr = &jim;

superSaver.addMember(&kyle);
superSaver.addMember(&mayuka);
superSaver.addMember(&jim);

mayuka.addProductToCart("x123");
kyle.addProductToCart("x456");

std::cout << "getMemberFromID call is next" << std::endl;

if (superSaver.getMemberFromID("b122"))
    std::cout << "match in main" << std::endl;

    else
    
    std::cout << "no match in main" << std::endl;

std::vector<std::string>cart_test;

cart_test = mayuka.getCart();

std::cout << "In cart: " << std::endl;
for (auto &i: cart_test) {
  std::cout << i << std::endl;
}

bool boolTester = mayuka.isPremiumMember();

std::cout << "Is premium member: " << boolTester << std::endl;


superSaver.addProductToMemberCart("x123", "a111");

superSaver.addProductToMemberCart("x789", "c333");

superSaver.addProductToMemberCart("x789", "c333");

superSaver.addProductToMemberCart("x789", "c333");



double checkout = superSaver.checkOutMember("c333");

std::cout << "checkOutMember(): " << checkout << std::endl;

std::cout << "*** PRODUCT SEARCH ***" << std::endl;

std::vector<std::string>results = superSaver.productSearch("o");

for (auto i = 0; i < results.size(); i++){
  std::cout << results[i] << std::endl;
}

*/
int main(){
Product myProduct("aaa", "pet rock", "low maintenance pet, fully house-trained", 50, 2);
Customer myCustomer("Jenny", "8675309", true);
myCustomer.addProductToCart("12345");

myCustomer.getCart();

Store myStore;

myStore.addProduct(&myProduct);

myStore.addMember(&myCustomer);

myStore.productSearch("Pet");


myStore.addProductToMemberCart("aaa", "8675309");


myStore.checkOutMember(myCustomer.getAccountID());

 return 0;
}