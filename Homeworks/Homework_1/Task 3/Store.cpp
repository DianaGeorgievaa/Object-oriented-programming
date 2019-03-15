#include <iostream>
#include "Store.h"
Store::Store()
{
	this->size = MAX_PRODUCTS;
	this->product = new Product[this->size];
	this->productCount = 0;
}

Store::~Store()
{   
	delete[] this->product;
}

void Store::Add(Product p)
{  
	if (this->productCount < this->size - 1)
	{   
		product[productCount] = p;
		productCount++;
	}
	
	else
	{
		std::cout << "The store is full! Can't add any products!" << std::endl;
	}

}

void Store::Change(const char * SKU)
{
	for (int i = 0; i < this->productCount; i++)
	{   
		if (strcmp(this->product[i].GetSKU(), SKU) == 0)
		{   
			this->product[i].Change();
			break;
		}
	}
}

void Store::Display() const
{
	for (int i = 0; i < this->productCount; i++)
	{
		std::cout << "SKU:" << this->product[i].GetSKU() << std::endl;
		std::cout << "Brand:" << this->product[i].GetBrand() << std::endl;
		std::cout << "Model:" << this->product[i].GetModel() << std::endl;
		std::cout << "Color:" << this->product[i].GetColor() << std::endl;
		std::cout << "Price:" << this->product[i].GetPrice() << std::endl;
		std::cout << "Count:" << this->product[i].GetCount() << std::endl;
		std::cout << "*****************************************************" << std::endl;
	}
}

void Store::DeleteProduct(const char * SKU)
{
	unsigned int i = 0;
	unsigned int ind = 0;
	Product *saveProduct = new Product[productCount - 1];
	while (i < this->productCount - 1)
	{    
		if (this->product[i].GetSKU() != SKU)
		{
			saveProduct[ind] = this->product[i];
			ind++;
		}
		i++;
	}
	this->product = saveProduct;
	this->productCount--; 
