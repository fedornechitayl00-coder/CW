#pragma once
#include "Date.h"


class Product {
    std::string title;
    float price;
    Date madeDate;
    int termSave;

public:
    Product();
    Product(std::string title, float price, Date madeDate, int termSave);

    void setTitle(std::string title);
    std::string getTitle()const;
    void setPrice(float price);
    float getPrice()const;
    Date getMadeDate()const;
    int getTerm()const;

    bool isExpired()const;
    friend std::ostream& operator << (std::ostream& out, const Product& obj);
    friend std::istream& operator >> (std::istream& in, Product& obj);
};

