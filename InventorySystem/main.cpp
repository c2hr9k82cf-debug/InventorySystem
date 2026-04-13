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
    InventoryManager myManager;

    std::cout << "=== 📦 库存管理系统测试开始 ===" << std::endl;

    // 1. 测试正常添加商品
    try {
        myManager.addProduct(Product(1, "iPhone 15", 5999.0, 10));
        myManager.addProduct(Product(2, "MacBook Air", 8999.0, 5));
        std::cout << "✅ 成功添加初始商品。" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "❌ 添加失败: " << e.what() << std::endl;
    }

    // 2. 测试 ID 重复拦截
    std::cout << "\n--- 正在尝试添加重复 ID (1) ---" << std::endl;
    try {
        myManager.addProduct(Product(1, "iPad Pro", 6999.0, 8));
    } catch (const std::exception& e) {
        std::cout << "🛡️ 拦截成功! 错误信息: " << e.what() << std::endl;
    }

    // 3. 测试查找并使用指针修改价格
    std::cout << "\n--- 正在寻找 ID 为 2 的商品并打折 ---" << std::endl;
    Product* p = myManager.findProductById(2);
    if (p != nullptr) {
        std::cout << "🔍 找到商品: " << p->toString() << std::endl;
        p->setPrice(7999.0); // 修改价格
        std::cout << "💰 价格已更新！" << std::endl;
    } else {
        std::cout << "⚠️ 未找到该商品。" << std::endl;
    }

    // 4. 显示最终所有库存
    std::cout << "\n=== 最终仓库清单 ===" << std::endl;
    myManager.showAllProducts();

    std::cout << "\n=== 测试结束 ===" << std::endl;
    return 0;
}
