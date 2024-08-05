#include <iostream>
#include <vector>
#include <string>

struct Product {
    int id;
    std::string name;
    int quantity;
    double price;
};

class Inventory {
private:
    std::vector<Product> products;

    int findProductIndex(int id) {
        for (size_t i = 0; i < products.size(); ++i) {
            if (products[i].id == id) {
                return static_cast<int>(i); // تحويل size_t إلى int بوضوح
            }
        }
        return -1; // If product is not found
    }

public:
    void addProduct(int id, std::string name, int quantity, double price) {
        if (findProductIndex(id) != -1) {
            std::cout << "Product with this ID already exists.\n";
            return;
        }
        Product product = { id, name, quantity, price };
        products.push_back(product);
    }

    void updateProduct(int id, std::string name, int quantity, double price) {
        int index = findProductIndex(id);
        if (index == -1) {
            std::cout << "Product not found.\n";
            return;
        }
        products[index].name = name;
        products[index].quantity = quantity;
        products[index].price = price;
    }

    void deleteProduct(int id) {
        int index = findProductIndex(id);
        if (index == -1) {
            std::cout << "Product not found.\n";
            return;
        }
        products.erase(products.begin() + index);
    }

    void displayProducts() {
        std::cout << "ID\tName\t\tQuantity\tPrice\n";
        for (const auto& product : products) {
            std::cout << product.id << "\t" << product.name << "\t\t" << product.quantity << "\t\t" << product.price << "\n";
        }
    }
};

int main() {
    Inventory inventory;

    int choice;
    while (true) {
        std::cout << "\nInventory Management System\n";
        std::cout << "1. Add Product\n";
        std::cout << "2. Update Product\n";
        std::cout << "3. Delete Product\n";
        std::cout << "4. Display Products\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            int id, quantity;
            double price;
            std::string name;
            std::cout << "Enter product ID: ";
            std::cin >> id;
            std::cout << "Enter product name: ";
            std::cin >> std::ws; // استخدام std::ws لتجاهل المسافات الفارغة
            std::getline(std::cin, name);
            std::cout << "Enter quantity: ";
            std::cin >> quantity;
            std::cout << "Enter price: ";
            std::cin >> price;
            inventory.addProduct(id, name, quantity, price);
        }
        else if (choice == 2) {
            int id, quantity;
            double price;
            std::string name;
            std::cout << "Enter product ID to update: ";
            std::cin >> id;
            std::cout << "Enter new product name: ";
            std::cin >> std::ws; // استخدام std::ws لتجاهل المسافات الفارغة
            std::getline(std::cin, name);
            std::cout << "Enter new quantity: ";
            std::cin >> quantity;
            std::cout << "Enter new price: ";
            std::cin >> price;
            inventory.updateProduct(id, name, quantity, price);
        }
        else if (choice == 3) {
            int id;
            std::cout << "Enter product ID to delete: ";
            std::cin >> id;
            inventory.deleteProduct(id);
        }
        else if (choice == 4) {
            inventory.displayProducts();
        }
        else if (choice == 5) {
            break;
        }
        else {
            std::cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}
