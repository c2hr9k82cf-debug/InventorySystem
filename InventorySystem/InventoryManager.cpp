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
