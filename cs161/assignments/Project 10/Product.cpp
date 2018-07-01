#include "Product.hpp"

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