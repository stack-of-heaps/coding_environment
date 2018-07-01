#include "Customer.hpp"

Customer::Customer(std::string n, std::string a, bool pm){
    name = n;
    accountID = a;
    premiumMember = pm;
    std::vector<std::string>cart;
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