//
//  main.cpp
//  InventorySystem
//
//  Created by Lin on 2026/4/13.
//

#include <iostream>
#include <vector>
#include "Product.hpp" // 必须包含头文件才能识别 Product 类

#include <iostream>
#include "InventoryManager.hpp"

int main() {
    InventoryManager manager;
    const std::string dbFile = "inventory.csv";

    // 1. 启动时加载
    manager.loadFromFile(dbFile);

    // 2. 只有在仓库为空时才添加初始测试数据
    // 否则每次运行都会试图重复添加，导致报错
    try {
        if (manager.findProductById(1) == nullptr) {
            //manager.addProduct(Product(1, "iPhone 15", 5999.0, 10));
        }
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    // 3. 显示当前所有商品
    manager.showAllProducts();

    // 4. 程序结束前保存
    manager.saveToFile(dbFile);

    std::cout << "Current path is: " << std::filesystem::current_path() << std::endl;
    
    return 0;
}
