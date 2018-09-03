#include <iostream>
#include "Product.h"

//constructor with no arguments
Product::Product() :count(0), price(0.0)
{
	this->SetSKU("no SKU");
	this->SetBrand("no brand");
	this->SetModel("no model");
	this->SetColor("no color");
}
//constructor with arguments
Product::Product(const char * SKU, const char * brand, const char * model, const char * color, double price, int count)
{
	this->SetSKU(SKU);
	this->SetBrand(brand);
	this->SetModel(model);
	this->SetColor(color);
	this->SetPrice(price);
	this->SetCount(count);
}

void Product::SetSKU(const char * SKU)
{   // l is variable for the length of the SKU
	int l = strlen(SKU);
	this->SKU = new char[l + 1];
	int i = 0;
	while(SKU[i]!=0 && i<=l-1)

	{
		this->SKU[i] = SKU[i];
		i++;
	}
	this->SKU[i] = 0;
}

void Product::SetBrand(const char * brand)
{
	int l = strlen(brand);
	this->brand = new char[l + 1];
	int i = 0;
	while(brand[i]!=0 && i<=l-1)
	{
		this->brand[i] = brand[i];
		i++;
	}
	this->brand[i] = 0;
}

void Product::SetModel(const char * model)
{
	int l = strlen(model);
	this->model = new char[l + 1];
	int i = 0;
	while(brand[i]!=0 && i<=l-1)
	{
		this->model[i] = model[i];
		i++;
	}
	this->model[i] = 0;
}

void Product::SetColor(const char * color)
{
	int l = strlen(color);
	this->color = new char[l + 1];
	int i = 0;
	while(color[i]!=0 && i<=l-1)
	{
		this->color[i] = color[i];
		i++;
	}
	this->color[i] = 0;
}

void Product::SetPrice(double price)
{
	if (price > 0.0)
	{
		this->price = price;
	}
	else
	{
		std::cout << "Invalid price!" << std::endl;
		this->price = 0.0;
		return;
	}
}

void Product::SetCount(int count)
{
	if (count > 0)
	{
		this->count = count;
	}
	else
	{
		std::cout << "The count can't be negative number!" << std::endl;
		this->count = 0;
		return;
	}
}

const char * Product::GetSKU() const
{
	return this->SKU;
}

const char * Product::GetBrand() const
{
	return this->brand;
}

const char * Product::GetModel() const
{
	return this->model;
}

const char * Product::GetColor() const
{
	return this->color;
}

double Product::GetPrice() const
{
	return this->price;
}

int Product::GetCount() const
{
	return this->count;
}

void Product::Change()
{
	std::cout << "Enter the new SKU:"<<std::endl;
	std::cin >> this->SKU;
	this->SetSKU(this->SKU);
	std::cout << "Enter the new brand:" << std::endl;
	std::cin >> this->brand;
	this->SetBrand(this->brand);
	std::cout << "Enter the new model:" << std::endl;
	std::cin >> this->model;
	this->SetModel(this->model);
	std::cout << "Enter the new color:" << std::endl;
	std::cin >> this->color;
	this->SetColor(this->color);
	std::cout << "Enter the new price:" << std::endl;
	std::cin >> this->price;
	this->SetPrice(this->price);
	std::cout << "Enter the new count:" << std::endl;
	std::cin >> this->count;
	this->SetCount(this->count);
}

std::istream & operator>>(std::istream & is, Product & p)

{
	std::cout << "Enter product in the correct order (SKU,Brand,Model,Color,Price and Count): " << std::endl;
	is >> p.SKU >> p.brand >> p.model >> p.color >> p.price >> p.count;
	return is;

}

std::ostream & operator<<(std::ostream & os, const Product & p)
{
	os << p.GetSKU() << p.GetBrand() << p.GetModel() << p.GetColor() << p.GetPrice() << p.GetCount();
	return os;
}