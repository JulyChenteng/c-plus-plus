#include <iostream>
#include <string.h>

using namespace std;

class  CGoods
{
public:
	void   RegisterGoods(char name[], int amount, float price);
	void   CountTotalValue(void);
	char*  GetName();
	int    GetAmount(void);
	float  GetPrice(void);
	float  GetTotal_value(void);

private:
	char   m_name[21];
	int    m_amount;
	float  m_price;
	float  m_total_value;
};

int main()
{
	CGoods good;

	good.RegisterGoods("basketBall", 5, 125.5);
	good.CountTotalValue();

	cout << "name   : " << good.GetName() << endl;
	cout << "amount : " << good.GetAmount() << endl;
	cout << "price  : " << good.GetPrice() << endl << endl;
	cout << "Total_Value : " << good.GetTotal_value() << endl;

	system("pause");
	return 0;
}

void CGoods::RegisterGoods(char *name, int amount, float price)
{
	strcpy(m_name, name);
	m_amount = amount;
	m_price = price;
}

void CGoods::CountTotalValue(void)
{
	m_total_value = m_amount * m_price;
}

char* CGoods::GetName()
{
	return m_name;
}

int CGoods::GetAmount()
{
	return m_amount;
}

float CGoods::GetPrice()
{
	return m_price;
}

float CGoods::GetTotal_value()
{
	return m_total_value;
}