//
//  InventoryManager.hpp
//  InventorySystem
//
//  Created by Lin on 2026/4/13.
//

#ifndef InventoryManager_hpp
#define InventoryManager_hpp


#include <vector>
#include <fstream>
#include <sstream>
#include "Product.hpp"

class InventoryManager {
private:
    // 这就是我们的“大口袋”，里面装的是 Product 对象
    std::vector<Product> m_products;

public:
    // 1. 添加商品
    void addProduct(const Product& p);

    // 2. 显示所有商品信息
    void showAllProducts() const;

    // 3. 根据 ID 查找商品（这个有点难，你可以先想想怎么写）
    // 提示：如果找到了，返回它的索引；没找到返回 -1
    Product* findProductById(int id) ;
    
    //
    void saveToFile(const std::string& filename) const;
    
    //
    void loadFromFile(const std::string& filename);
    
    //find and then remove
    bool removeProductById(int id);
    
    //Change
    void updateInterface(Product* p);
};

#endif /* InventoryManager_hpp */
