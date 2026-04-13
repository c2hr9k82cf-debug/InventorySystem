//
//  Product.hpp
//  InventorySystem
//
//  Created by Lin on 2026/4/13.
//

#ifndef Product_hpp
#define Product_hpp

#include <string>
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <sstream>

class Product {
private:
    int m_id=0;             // 苹果风格：私有成员加 m_ 前缀
    std::string m_name;
    double m_price=0.0;
    int m_stock=0;

public:
    // 构造函数：要求必须传入完整信息
    Product(int id, std::string name, double price, int stock);

    // Getter 访问器 (注意 const 关键字，承诺不修改数据)
    int id() const { return m_id; }
    std::string name() const { return m_name; }
    double price() const { return m_price; }
    int stock() const { return m_stock; }

    // Setter 修改器
    void setStock(int newStock);
    void setPrice(double newPrice);

    // 将商品信息格式化为一行字符串，方便打印或存入文件
    std::string toString() const;
};

#endif /* Product_hpp */
