#ifndef PRODUCT_H
#define PRODUCT_H

class Product //for laptops
{
public:

	Product();
	Product(const char* SKU, const char*brand, const char*model, const char*color, double price, int count);
	
	void SetSKU(const char*SKU);
	void SetBrand(const char*brand);
	void SetModel(const char*model);
	void SetColor(const char*color);
	void SetPrice(double price);
	void SetCount(int count);

	const char* GetSKU()const;
	const char* GetBrand()const;
	const char* GetModel()const;
	const char* GetColor()const;
	double GetPrice()const;
	int GetCount()const;
	friend std::istream & operator >>(std::istream &is, Product & p);
	friend std::ostream & operator <<(std::ostream & os, const Product & p);
	void Change();
	

private:
	char* SKU;
	char* brand;
	char* model;
	char*color;
	double price;
	int count;
};
#endif