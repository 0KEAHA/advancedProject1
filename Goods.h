#define CGoods

#ifndef HGen
#define HGen
#include "General.h"
#endif

class Good
{
private:
	string _Id;
	string _Name;
	string _UpTime;
	string _SellerId;
	string _Description;
	bool _Available;
	int _Stock;
	double _Price;

public:
	string TransAvail();
	Good();
	Good(string SellerId, string Name, double Price,
		int Stock, string Descrip, string Id);
	Good(string Id, string Name, double Price, int Stock, string Descrip, string SellerId, string UpTime, string Available);
	Good(const Good&);
	void SellGood(int);
	void changePrice(double);
	void ChangeStock(int);
	void changeDescrip(string);
	void Disable();
	bool GetAvailable();
	double GetPrice()const;
	int GetStock();
	string GetName();
	string GetSellerId();
	string OutInfo();//����txt��ʽ��Ϣ
	void PrintAdmin();
	void PrintSeller();
	void PrintBuyer();
	void PrintCart();
	void LastPrint();
	void PrintBuyerAccua();
	void PrintWhenChangePri(string content);
	void PrintWhenChangeDes(string content);
	Good& operator=(const Good&);

};

class Goods
{
private:
	static Goods* P_GeneralGoods;
	map<string, Good> AllGoods;
	Goods() {};
public:
	int GetAll();
	static Goods* GetInstance();
	static void DeleteInstance();
	void ResetDocuGood();
	void InputDocuGood();
	//void ChangeGoodName(string,string);
	bool CheckGoodId(string);
	bool CheckAvailable(string Id);
	int GetGoodStock(string Id);
	string GetBySeller(string SellerId);
	string GetSellerID(string Id);
	string GetPrice(string Id);
	void SellGood(string,int);
	void ChangeGoodPrice(string, double);
	void ChangeGoodStock(string, int);
	void ChangeGoodDescrip(string, string);
	void DisableGood(string);
	/*bool CheckGoodName(string);*/
	void UpGood(string SellerId, string Name, double Price, int Stock, string Descrip);
	/*
	Print����Ϊ�����ߺ�ģʽ������ID����ƷID
	������������ Admin Seller Buyer
	ģʽ�� Last specific general Accura
	LastΪ�¼���Ʒ��Ϣ
	specificΪָ����ƷIDʹ�ã�����Ϊ������Ʒ
	generalΪ������Ȩ�鿴��Ʒ
	AccuraΪ�û��鿴��ϸ��Ϣ
	*/
	void PrintCart(string Id);
	void PrintWhenChange(string ID,string Pattern,string content);
	void PrintGoods(string, string, string UserID = "", string Id = "");
	void _SearchGood(string name, string commander);
};