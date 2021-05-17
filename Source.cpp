//Створити базовий клас ПЕРЕВЕЗЕННЯ АВТОМОБІЛЕМ(задаються номер автомобіля, дані про водія).
//Створити похідні класи ВАНТАЖНЕ ПЕРЕВЕЗЕННЯ(задаються кількість тон, вартість перевезення 
//1 тони на 1 кілометр) та ПЕРЕВЕЗЕННЯ АВТОБУСОМ(задаються вартість перевезення 1 пасажира
//на 10 кілометрів, мінімальна кількість пасажирів).Для введених даних про замовлені
//перевезення відсортувати їх за зростанням сумарних доходів водіїв і визначити водія,
//який приніс найбільший дохід. Для перевірки використати масив вказівників на об’єкти 
//базового класу, яким присвоїти адреси об’єктів похідних класів.

#include <iostream>
#include <string>

#define M 4

using namespace std;

class BaseTransportCar
{
protected:
	string numcar;
	string firstnamedriver;
	string secondnamedriver;
	int income;

public:

	BaseTransportCar() 
	{
		numcar = "--0000--";
		firstnamedriver = "None";
		secondnamedriver = "None";
	}

	BaseTransportCar(string nc, string fstname, string secname) 
	{
		this->numcar = nc;
		this->firstnamedriver = fstname;
		this->secondnamedriver = secname;
	}

	~BaseTransportCar() { } 

	void SetNumcar() 
	{
		cin >> numcar;
	}

	string GetNumcar() 
	{
		return numcar;
	}

	void SetFstname() 
	{
		cin >> firstnamedriver;
	}

	string GetFstname() 
	{
		return firstnamedriver;
	}

	void SetSecname() 
	{
		cin >> secondnamedriver;
	}

	string GetSecname() 
	{
		return secondnamedriver;
	}

	void SetIncome(int inc) 
	{
		income = inc;
	}

	int GetIncome() 
	{
		return income;
	}

	void SetBaseInform()
	{
		cin >> numcar;
		cin >> firstnamedriver;
		cin >> secondnamedriver;
	}

	void PrintBaseInform()
	{
		cout << "\t" << numcar << "\t";
		cout << firstnamedriver << ' ';
		cout << secondnamedriver << "\t\t";
	}

	virtual void SetClassInform() { }
	virtual void PrintAllInform() { }
	virtual int Income() { return 0; }


};


class WeightTransport : public BaseTransportCar
{
private:
	int kstton;
	int kstdistance;
	int kstprice;

public:

	WeightTransport() : BaseTransportCar()   
	{
		kstton = 0;
		kstdistance = 0;
		kstprice = 0;
		income = 1;
	}

	WeightTransport(string nc, string fstname, string secname, int kton, int kdistance, int kprice, int inc) : BaseTransportCar(nc, fstname, secname) 
	{
		kstton = kton;
		kstdistance = kdistance;
		kstprice = kprice;
		income = inc;
	}

	~WeightTransport() { } 


	void SetClassInform() override
	{
		SetBaseInform();
		cin >> kstton;
		cin >> kstdistance;
		cin >> kstprice;
		cout << "\n";
	}

	void PrintAllInform() override
	{
		if (income != 0)
		{
			cout << "\t" << "Номер машини:\t" << "Дані про водія: \t" << "К-сть тонн:\t" << "Відстань:\t" << "Ціна:\t" << "\tДохід:" << endl;
			PrintBaseInform();
			cout << kstton << "\t\t";
			cout << kstdistance << "\t\t";
			cout << kstprice << "\t\t";
			cout << income << "\n";
		}
	}

	int Income() override
	{
		return (kstton * kstdistance * kstprice);
	}

};


class BusTransport : public BaseTransportCar
{
private:
	int kstpricebus;
	int kstdistancebus;
	int kstminpersons;

public:

	BusTransport() : BaseTransportCar()  
	{
		kstpricebus = 0;
		kstdistancebus = 0;
		kstminpersons = 0;
		income = 1;
	}

	BusTransport(string nc, string fstname, string secname, int kprice, int kdistance, int kminp, int inc) : BaseTransportCar(nc, fstname, secname) 
	{
		kstpricebus = kprice;
		kstdistancebus = kdistance;
		kstminpersons = kminp;
		income = inc;
	}

	~BusTransport() { } 

	void SetClassInform() override
	{
		SetBaseInform();
		cin >> kstpricebus;
		cin >> kstdistancebus;
		cin >> kstminpersons;
		cout << "\n";
	}

	void PrintAllInform() override
	{
		if (income != 0)
		{
			cout << "\t" << "Номер машини:\t" << "Дані про водія: \t" << "Ціна:\t\t" << "Відстань:\t" << "Мін. к-сть пасажирів:" << "\tДохід:" << endl;
			PrintBaseInform();
			cout << kstpricebus << "\t\t";
			cout << kstdistancebus << "\t\t";
			cout << kstminpersons << "\t\t";
			cout << "\t" << income << "\n";
		}
	}

	int Income() override
	{
		return (kstpricebus * kstdistancebus * kstminpersons) / 10;
	}

};


void Income2(BaseTransportCar* Inform[]);
void Sort(BaseTransportCar* Inform[]);


int main()
{
	system("chcp 1251");
	BaseTransportCar* Inform[M];
	Inform[0] = new WeightTransport();
	Inform[1] = new WeightTransport();
	Inform[2] = new BusTransport();
	Inform[3] = new BusTransport();

	cout << "Початкові дані по перевезеннях: " << endl;
	for (int i = 0; i < M; i++)
	{
		Inform[i]->PrintAllInform();
	}
	cout << "\n\n";

	cout << "Введіть дані по перевезеннях: " << endl;
	for (int i = 0; i < M; i++)
	{
		Inform[i]->SetClassInform();
	}
	cout << "\n\n";

	cout << "Вивід введених даних: " << endl;
	for (int i = 0; i < M; i++)
	{
		Inform[i]->PrintAllInform();
	}
	cout << "\n\n";

	cout << "Знаходження сумарних доходів кожного водія: " << endl;
	Income2(Inform);
	for (int i = 0; i < M; i++)
	{
		Inform[i]->PrintAllInform();
	}
	cout << "\n\n";

	cout << "Відсортовані дані по перевезеннях: " << endl;
	Sort(Inform);
	for (int i = 0; i < M; i++)
	{
		Inform[i]->PrintAllInform();
	}

	cout << "Водій який отримав найбільший дохід: " << endl;
	cout << Inform[M - 1]->GetFstname() << ' ';
	cout << Inform[M - 1]->GetSecname() << endl;

	for (int i = 0; i < M; i++)
	{
		delete Inform[i];
	}

	system("pause");
	return 0;
}

void Income2(BaseTransportCar* Inform[])
{
	for (int i = 0; i < M; i++)
	{
		int income;
		if (Inform[i]->GetIncome() != 0)
		{
			income = Inform[i]->Income();
			Inform[i]->SetIncome(income);
		}
		else {
			while (Inform[i]->GetIncome() == 0)
			{
				i++;
			}
			income = Inform[i]->Income();
			Inform[i]->SetIncome(income);
		}

		for (int j = i + 1; j < M; j++)
		{
			if (Inform[i]->GetFstname() == Inform[j]->GetFstname() && Inform[i]->GetSecname() == Inform[j]->GetSecname())
			{
				income += Inform[j]->Income();
				Inform[j]->SetIncome(0);
				Inform[i]->SetIncome(income);
			}
		}
	}
}

void Sort(BaseTransportCar* Inform[]) 
{
	BaseTransportCar* p;
	for (int i = 1; i < M; i++) 
	{
		for (int j = 0; j < M - i; j++)      
		{
			if (Inform[j]->GetIncome() > Inform[j + 1]->GetIncome())
			{
				p = Inform[j];          
				Inform[j] = Inform[j + 1];
				Inform[j + 1] = p;
			}
		}

	}
}