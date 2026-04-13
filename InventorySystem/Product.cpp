//
//  Product.cpp
//  InventorySystem
//
//  Created by Lin on 2026/4/13.
//

#include "Product.hpp"

Product::Product(int id, std::string name, double price, int stock):m_id(id),m_name(name),m_price(price),m_stock(stock){
    if(id==0) throw std::invalid_argument("id不能为0！");
    if(name.empty()) throw std::invalid_argument("商品名称不能为空！");
    if(price<0) throw std::invalid_argument("价格不能为负！");
    if(stock<0) throw std::invalid_argument("库存不能为负！");
}

std::string Product::toString() const {
    std::ostringstream oss;
    oss << "Product{"
        << "id=" << m_id << ", "
        << "name=\"" << m_name << "\", "
        << "price=" << std::fixed << std::setprecision(2) << m_price<<", "
        << "stock=" << m_stock
        << "}";
    return oss.str();
}

void Product::setStock(int newStock){
    if(newStock<0) throw std::invalid_argument("Invalid stock amount: negative values are not allowed.");
    m_stock=newStock;
}

void Product::setPrice(double newPrice){
    if(newPrice<0) throw std::invalid_argument("Invalid Price: negative values are not allowed.");
    m_price=newPrice;
}
