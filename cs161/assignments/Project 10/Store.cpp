#include "Store.hpp"

#include <algorithm>

void Store::addProduct(Product* p){ //finished
   inventory.push_back(p);
}

void Store::addMember(Customer* c){ //finished
   members.push_back(c);
}

Product* Store::getProductFromID(std::string idQuery){ //finished
  
  //convert idQuery to all lowercase
    std::locale loc;
    for (int i = 0; i < idQuery.length(); i++)
        idQuery[i] = std::tolower(idQuery[i], loc); 

  // Search do-while loop
  // looper sets end condition of loop
    int looper = 0;
    
    do {
        if (inventory[looper] -> getIdCode() == idQuery)
            return inventory[looper];
        looper++;
  
    } while (looper < inventory.size());
 
    return NULL;
}
    //search for product ID. return the address of the ID.
    //the address of ID is the same as the object since it
    //is the first member of the object.
    //Product * as a type for the function means that
    //my return should read "return &pFrom Id"

Customer* Store::getMemberFromID(std::string idQuery){ //**FINISHED
     
    //convert idQuery to all lowercase
    std::locale loc;
    for (int i = 0; i < idQuery.length(); i++)
        idQuery[i] = std::tolower(idQuery[i], loc); 
 
    int looper = 0; // Declaring outside the for loop as we will be using it to
                   // control outer do-while loop
    do {
        if (members[looper] -> getAccountID() == idQuery){
            return members[looper]; 
    }      
   
    looper++;
  
    } while (looper < members.size());
    
    return NULL; //If the do-while loop returns nothing
}

std::vector<std::string>  Store::productSearch(std::string searchQuery){
 /*******************
productSearch - return a sorted vector of ID codes for every product
whose title or description contains the search string.  
*********************/
    
    //parsing searchQuery function parameter
    std::locale loc;
    std::vector<std::string> searchResults; //will hold object IDs that are returned by function
    std::string parseMe = " "; //holds the title/description of one Inventory Object at a time
   
    //convert input to lowercase
    for (int  i = 0; i < searchQuery.length(); i++)
        searchQuery[i] = std::tolower(searchQuery[i], loc);  
        
    //do-while loop for DESCRIPTION
    int looper = 0;     //controls do-while loop end condition
     
    do {
        //populate sentence_parser with first object's description
        parseMe = inventory[looper]->getDescription();
  
        //convert to lowercase
        for (int i = 0; i < parseMe.size(); i++)
            parseMe[i] = std::tolower(parseMe[i], loc);
  
        //STRING.FIND()
        std::size_t found = parseMe.find(searchQuery);
        if (found!=std::string::npos)
            searchResults.push_back(inventory[looper] -> getIdCode());

        //search for string matches in product ID
        //first reset parseMe string
        parseMe.clear();
  
        //get Product title
        parseMe = inventory[looper]->getTitle();

        //convert to lowercase
        for (int i = 0; i < parseMe.size(); i++)
            parseMe[i] = std::tolower(parseMe[i], loc);
      
        //STRING.FIND()
        found = parseMe.find(searchQuery);
        if (found!=std::string::npos)
            searchResults.push_back(inventory[looper] -> getIdCode());
    
        looper++; //END OF DO-WHILE; increment looper
    
    } while (looper < inventory.size());
  
    //sort searchResults before returning

    sort(searchResults.begin(), searchResults.end());

    return searchResults;
}

std::string Store::addProductToMemberCart(std::string pID, std::string mID){
//calls getMemberFromID and getProductFromID   
//then use results to access addProductToCart(productID)
  
//check for NULL values in input IDs
    if (!getMemberFromID(mID)){
        std::string bugOut = "member ID not found";
        return bugOut;
  }
  
    if (!getProductFromID(pID)){
        std::string bugOut = "product ID not found";
        return bugOut;
   }
   
   Customer* thisMember = NULL;
   Product* thisProduct = NULL;

   thisMember = getMemberFromID(mID);

   //check if productID is valid
   thisProduct = getProductFromID(pID);

   //make sure product is in stock
   int thisProduct_stock = thisProduct -> getQuantityAvailable();

   if (thisProduct_stock < 1){
       std::string bugOut = "product out of stock";
       return bugOut;
   }

   thisMember -> addProductToCart(pID);
   std::string addToCartSuccess = "product added to cart";

   thisMember = 0;
   thisProduct = 0;
   return addToCartSuccess;
}

double Store::checkOutMember(std::string mID){

    //if not a member, stop
    if (!getMemberFromID(mID))
        return -1;

  
  
    else {
        
        Customer *thisMember = NULL;
        
        //The customer for this function's run through
        thisMember = getMemberFromID(mID);
        
        //Holds output of getCart()
        std::vector<std::string>subTotalCart;
        subTotalCart = thisMember->getCart();

        //verify items in cart. If not found, erase from the cart vector
        for (int i = 0; i < subTotalCart.size(); i++){
            if (!getProductFromID(subTotalCart[i]))
                subTotalCart.erase(subTotalCart.begin()+i);
        }

        //subTotal will hold pre-shipping total cost
        double subTotal = 0.0;
        
        //for loop iterates through the cart string
        for (auto i = 0; i < subTotalCart.size(); i++){
            
            //thisProduct holds returned Product*
            Product* thisProduct = NULL;
            thisProduct = getProductFromID(subTotalCart[i]);
            
            //check stock
            int stock = thisProduct -> getQuantityAvailable();

            if (stock > 0){
                subTotal += thisProduct -> getPrice();
                thisProduct -> decreaseQuantity();
                }
            
        }
            //if in stock, the above runs; if not, skips to below:
            //check for membership status
            //premium members get free shipping
            //non-premium pay 7% fee
            
            bool isPremiumMember = false;

            isPremiumMember = thisMember -> isPremiumMember();

            if (isPremiumMember){
                thisMember -> emptyCart();
                thisMember = 0;
                return subTotal;
            }

            else {
                subTotal = subTotal * 1.07;
                thisMember -> emptyCart();
                thisMember = 0;
                return subTotal;
            }
    }

 }