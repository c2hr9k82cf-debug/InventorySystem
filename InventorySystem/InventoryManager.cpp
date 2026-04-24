//
//  InventoryManager.cpp
//  InventorySystem
//
//  Created by Lin on 2026/4/13.
//

#include "InventoryManager.hpp"

void InventoryManager::addProduct(const Product &p){
    for(const auto& prod:m_products){
        // If a matching ID is found,abrot and notify the caller
        if(prod.id()==p.id()) throw std::invalid_argument("Error: Product with this ID already exists!");
    }
    // Successfully add the product to the storage vector
    m_products.push_back(p);
}

void InventoryManager::showAllProducts()const{
    if(m_products.empty()){
        std::cout<<"Inventory is currently empty."<<std::endl;
    }
    //Iterate through each product and display its details
    for(const auto& prod:m_products){
        std::cout<<prod.toString()<<std::endl;
    }
}

Product* InventoryManager::findProductById(int id){
    for(auto& prod:m_products){
        //Compare target ID with each product in the list
        if(id==prod.id()){
            return &prod;   //Return the memory address of the found object
        }
    }
    return nullptr;// Standard C++ way to indicate "not found"
}

void InventoryManager::saveToFile(const std::string& filename) const{
    std::ofstream outFile(filename);    //Create an output file stream
    if(!outFile){
        throw std::runtime_error("Unable to open file:" + filename);
    }
    
    for(const auto& prod :m_products){
        //Write product attributes sepatated by commas (CSV format)
        outFile <<prod.id()<<","
                <<prod.name()<<","
                <<prod.price()<<","
                <<prod.stock()<<"\n";
    }
    
    outFile.close();    // Close the file to flush data
    std::cout<<"Successfully saved data to"<<filename<<std::endl;
}

void InventoryManager::loadFromFile(const std::string& filename){
    std::ifstream inFile(filename);
    if(!inFile) return; //If file doesn't exist,exit silently
    
    m_products.clear(); //Ensure we don't duplicate data on reload
    std::string line;
    
    while (std::getline(inFile, line)) {
            if (line.empty()) continue; // Skip any accidental blank lines

            std::stringstream ss(line);
            std::string idStr, name, priceStr, stockStr;

            // Parse the line using ',' as the delimiter
            std::getline(ss, idStr, ',');
            std::getline(ss, name, ',');
            std::getline(ss, priceStr, ',');
            std::getline(ss, stockStr, ',');

            // Attempt to convert strings to numeric types
            try {
                int id = std::stoi(idStr);
                double price = std::stod(priceStr);
                int stock = std::stoi(stockStr);
                m_products.push_back(Product(id, name, price, stock));
            } catch (...) {
                continue; // Log and skip malformed or corrupted data rows
            }
        }
        std::cout << "Loaded " << m_products.size() << " products." << std::endl;
}

bool InventoryManager::removeProductById(int id){
    //
    auto it=std::find_if(m_products.begin(), m_products.end(), [id](const Product& p){
        return p.id()==id;
    });
    
    //If not found, return false to main
    if(it == m_products.end()){
        return false;
    }
    
    //If found, delete
    m_products.erase(it);
    return true;
}

void InventoryManager::updateInterface(Product *p){
    std::cout << "Updating: "<< p->name() <<std::endl;
    std::cout << "1.Update Price\n2.Update Stock\nSelect:";
    int choice; std::cin >> choice;
    if(choice==1){
        double newPrice;
                std::cout << "New Price: "; std::cin >> newPrice;
                p->setPrice(newPrice);
    }else if (choice==2){
        int newStock;
                std::cout << "New Stock: "; std::cin >> newStock;
                p->setStock(newStock);
    }else{
        return;
    }
}
