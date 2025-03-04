// Lab Partner: Audrey Thomas
#include <iostream>
#include <vector>
#include <string>
#include "GroceryItem.hpp"

int main() {
  std::cout << "Welcome to Kroger.  Place grocery items into your shopping cart by entering each item's information.\n"
            << "Enclose string entries in quotes, separate fields with comas.\n"
            << "For example: \" 00016000306707\", \"Betty Crocker\", \"Betty Crocker Double Chocolate Chunk Cookie Mix\", 17.19\n"
            << "Enter CTL- Z( Windows ) or CTL - D( Linux ) to quit\n\n"
            << "Enter UPC, Product Brand, Product Name, and Price\n";

  std::vector<GroceryItem> shoppingCart;
  GroceryItem              item;

  while (true) {
    if (std::cin >> item) {
      shoppingCart.push_back( std::move( item ) );

      std::cout << "Item added to shopping cart: " << shoppingCart.back() << "\n\n";
      std::cout << "Enter UPC, Product Brand, Product Name, and Price\n";
    }
    else
    {
      if (std::cin.eof())
        break;

      std::cin.clear();
      std::string dummy;
      std::getline( std::cin, dummy );
      std::cout << "Enter UPC, Product Brand, Product Name, and Price\n";
    }
  }

  std::cout << "Here is an itemized list of the items in your shopping cart:\n";
  for (const auto &g : shoppingCart) {
    std::cout << g << "\n";
  }
  return 0;
}
