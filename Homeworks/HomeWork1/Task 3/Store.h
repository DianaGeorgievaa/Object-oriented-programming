#ifndef STORE_H
#define STORE_H

#include "Product.h"

const unsigned int MAX_PRODUCTS = 100;

class Store
{
public:
	Store();
	~Store();
	void Add(Product p);
	void Change(const char * SKU);
	void Display()const;
	void DeleteProduct(const char *SKU);
private:
	Product * product;
	unsigned int productCount;
	unsigned int size;
};
#endif