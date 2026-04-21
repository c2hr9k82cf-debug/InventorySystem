//
//  main.cpp
//  InventorySystem
//
//  Created by Lin on 2026/4/13.
//

#include <iostream>
#include <limits> // 用于清理输入缓冲区
#include "InventoryManager.hpp"

void showMenu() {
    std::cout << "\n========== 📦 Inventory System ==========" << std::endl;
    std::cout << "1. Add New Product" << std::endl;
    std::cout << "2. Show All Products" << std::endl;
    std::cout << "3. Find Product by ID" << std::endl;
    std::cout << "4. Exit and Save" << std::endl;
    std::cout << "==========================================" << std::endl;
    std::cout << "Select an option (1-4): ";
}

int main() {
    InventoryManager manager;
    const std::string filename = "inventory.csv";

    // Step 1: Load existing data at startup
    manager.loadFromFile(filename);

    int choice = 0;
    do {
        showMenu();
        
        // 处理非数字输入的异常情况
        if (!(std::cin >> choice)) {
            std::cout << "⚠️ Invalid input! Please enter a number." << std::endl;
            std::cin.clear(); // 清除错误标记
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 跳过缓冲区
            continue;
        }

        switch (choice) {
            case 1: { // Add Product
                int id, stock;
                std::string name;
                double price;

                std::cout << "Enter ID: "; std::cin >> id;
                std::cout << "Enter Name: ";
                std::cin.ignore(); // 跳过之前的回车符
                std::getline(std::cin, name);
                std::cout << "Enter Price: "; std::cin >> price;
                std::cout << "Enter Stock: "; std::cin >> stock;

                try {
                    manager.addProduct(Product(id, name, price, stock));
                    std::cout << "✅ Product added successfully!" << std::endl;
                } catch (const std::exception& e) {
                    std::cout << "❌ Error: " << e.what() << std::endl;
                }
                break;
            }
            case 2: // Show All
                manager.showAllProducts();
                break;
            case 3: { // Find by ID
                int id;
                std::cout << "Enter ID to search: "; std::cin >> id;
                Product* p = manager.findProductById(id);
                if (p) {
                    std::cout << "🔍 Found: " << p->toString() << std::endl;
                } else {
                    std::cout << "⚠️ Product not found." << std::endl;
                }
                break;
            }
            case 4: // Exit
                std::cout << "Saving and exiting... Goodbye!" << std::endl;
                break;
            default:
                std::cout << "⚠️ Please select a valid option (1-4)." << std::endl;
        }

    } while (choice != 4);

    // Step 2: Save data before program ends
    manager.saveToFile(filename);

    return 0;
}
