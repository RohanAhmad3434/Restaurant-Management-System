#include<iostream>
#include<string>
#include<fstream>
using namespace std;
static int total_sale = 0;
static int total_customers = 0;
int n_customers = 0;
static int total_orders = 0;
int wwe = 0;
static int specific_order = 0;
static int specific_price = 0;
int xl;
class menu
{
private:
	string dishname, dishcategory;
	int price;
	bool available;
public:

	static int count;
	static int ab;
	menu()
	{
		dishname = "null";
		dishcategory = "null";
		price = 0;
		available = false;
	}
	menu(const menu& p)
	{
		dishname = p.dishname;
		dishcategory = p.dishcategory;
		price = p.price;
		available = p.available;
	}
	// setter funtions:
	void setname(string a)
	{
		dishname = a;
	}
	void setcategory(string b)
	{
		dishcategory = b;
	}
	void setprice(int a)
	{
		price = a;
	}
	void setavailable(bool a)
	{
		available = a;
	}
	// getter funtions:
	string getname(menu& m)
	{
		return m.dishname;
	}
	string getcategory(menu& m)
	{
		return m.dishcategory;
	}
	int getprice(menu& m)
	{
		return m.price;
	}
	bool getavailable(menu& m)
	{
		return m.available;
	}
	void adddish(menu* p)
	{
		menu::load_menu_names();
		string by = ".txt";
		string mn;
		cout << endl;
		cout << "Enter menu name in which you add dish" << endl;
		getline(cin, mn);
		mn = mn + by;

		ofstream file;
		file.open(mn, ios::out | ios::app);
		if (!file.is_open())
		{
			cout << mn << " cannot open in add_dish function" << endl;
		}
		else
		{
			int count_menu_names = 0;
			ifstream fileu;
			string zzx;
			fileu.open("menunames.txt", ios::in);
			while (getline(fileu, zzx))
			{
				if (zzx != "")
				{
					count_menu_names++;
				}
			}

			string* qw = new string[count_menu_names];
			fileu.close();
			fileu.open("menunames.txt", ios::in);
			int f = 0;
			while (getline(fileu, zzx))
			{
				qw[f] = zzx;
				f++;
			}
			fileu.close();

			//-----------------------------------------------------
			ofstream filem;
			filem.open("menunames.txt", ios::out | ios::app);
			if (filem.is_open())
			{
				int wwr = 0;
				for (int i = 0;i < count_menu_names;i++)
				{
					if (mn == qw[i])
					{
						wwr++;
					}
				}
				if (wwr == 0)
				{
					filem << mn << endl;
				}

			}
			else
			{
				cout << "menunames.txt file cannot open for writing menu names !!!" << endl;
			}
			filem.close();
			string a, b;
			int c;
			bool x;
			cout << "For dish number :  " << count + 1 << endl;
			cout << "enter name of a dish" << endl;
			getline(cin, a);
			p[count].dishname = a;
			file << p[count].dishname << endl;
			cout << "Enter category of a dish" << endl;
			getline(cin, b);
			p[count].dishcategory = b;
			file << p[count].dishcategory << endl;
			cout << "Enter price of a dish" << endl;
			cin >> c;
			p[count].price = c;
			file << p[count].price << endl;
			cout << "Enter 1 for available otherwise enter 0" << endl;
			cin >> x;
			p[count].available = x;
			file << p[count].available << endl;
			count++;
			delete[]qw;
		}
		file.close();

	}

	static bool load_menu_names()
	{
		string mf;
		ifstream filem;
		filem.open("menunames.txt", ios::in);
		if (filem.is_open())
		{
			int i = 0;
			while (getline(filem, mf))
			{
				int mm = 0;
				for (int j = 0;mf[j] != '\0';j++)
				{
					mm++;
				}
				mm = mm - 4;
				cout << "\t\t\t\t\t\tMenu " << i + 1 << " :" << " ";
				if (mf != "")
				{
					i++;
				}

				for (int l = 0;l < mm;l++)
				{
					cout << mf[l];
				}
				cout << endl;

			}
			cout << endl;
			cout << "\t\t\t\t\t\tTotal Menus are :  " << i << endl << endl;
			if (i == 0)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		else
		{
			cout << "menunames.txt file cannot open in load_menu_names Function" << endl;
		}
	}
	void removedish(menu* p)
	{
		string by = ".txt";
		string mn;
		cout << endl;
		bool lm = menu::load_menu_names();
		if (lm == true)
		{
			cout << "Enter menu name in which you remove dish" << endl;
			getline(cin, mn);
			string vbb;
			vbb = mn;
			mn = mn + by;
			bool ku = menu::load_file_dish(p, mn);
			if (ku == true)
			{
				cout <<vbb<< " Menu Does not exist !" << endl;
			}
			else
			{
				bool ss = false;
				string a;
				cout << "Enter name of a dish you remove" << endl;
				getline(cin, a);
				for (int i = 0;i < count;i++)
				{
					if (a == p[i].dishname)
					{
						ofstream filed;
						filed.open("removedishes.txt", ios::out | ios::app);
						if (filed.is_open())
						{
							filed << a << endl;
						}
						else
						{
							cout << "removedishes file cannot open in removedish function" << endl;
						}
						filed.close();
						p[i].dishname = "nil";
						cout << "Dish removed Successfully ! " << endl << endl;
						ab++;
						ss = true;
					}
				}
				if (ss = false)
				{
					cout << "Dish not Found ! " << endl << endl;
				}
			}
		}
		else
		{
			cout << "\t\t\t\t\t\tNo Menu Exist Add a Menu" << endl << endl;
		}
	}
	static bool display(menu* p)
	{
		bool lm = menu::load_menu_names();
		string by = ".txt";
		string mn;
		cout << endl;
		if (lm == true)
		{
			cout << "Enter menu name in which you Show ALL Dishes" << endl;
			getline(cin, mn);
			string vbb;
			vbb = mn;
			mn = mn + by;
			bool ku = p->load_file_dish(p, mn);
			if (ku == true)
			{
				cout << vbb << " Menu Does not exist !" << endl;
				return true;
			}
			else
			{
				cout << "\t\t\t----------------------------------------------------" << endl;
				cout << "\t\t\t-------------------List Of All Dishes--------------- " << endl;
				cout << "\t\t\t----------------------------------------------------" << endl;
				for (int i = 0;i < count;i++)
				{
					if (p[i].dishname != "nil")
					{
						cout << "Dish name : " << p[i].dishname << endl;
						cout << "Dish category : " << p[i].dishcategory << endl;
						cout << "Dish price : " << p[i].price << endl;
						cout << "Dish availability  :  ";
						if (p[i].available == 1)
						{
							cout << "Yes it is available! " << endl;
						}
						else
						{
							cout << "It is Not available! " << endl;
						}
						cout << endl << endl;
					}
				}

				cout << "Total number of dishes :  " << count - xl << endl;
				return false;
			}
		}
		else
		{
			cout << "\t\t\t\t\t\tNo Menu Exist Add a Menu" << endl << endl;
		}
	}

	void updatedish(menu* p)
	{
		string by = ".txt";
		string mn;
		bool lm = menu::load_menu_names();
		cout << endl;
		if (lm == true)
		{
			cout << "Enter menu name in which you Update dish" << endl;
			getline(cin, mn);
			string vbb;
			vbb = mn;
			mn = mn + by;
			bool ku = menu::load_file_dish(p, mn);
			if (ku == true)
			{
				cout << vbb<< " Menu Does not exist !" << endl;
			}
			else
			{
				bool b1 = false;
				string a;
				cout << "enter name of dish you update" << endl;
				getline(cin, a);
				for (int i = 0;i < count;i++)
				{
					if (a == p[i].dishname)
					{
						ofstream filex;
						filex.open("removedishes.txt", ios::out | ios::app);
						if (filex.is_open())
						{
							filex << a << endl;
						}
						else
						{
							cout << "removedishes.txt is not open in update dish function" << endl;
						}
						filex.close();
						ofstream filez;
						filez.open(mn, ios::out | ios::app);

						cout << "Enter new name of a dish" << endl;
						getline(cin, p[i].dishname);
						filez << p[i].dishname << endl;
						cout << "Enter new category of a dish" << endl;
						getline(cin, p[i].dishcategory);
						filez << p[i].dishcategory << endl;
						cout << "Enter new price of a dish" << endl;
						cin >> p[i].price;
						filez << p[i].price << endl;
						cout << "Enter 1 for available otherwise enter 0 for new dish" << endl;
						cin >> p[i].available;
						filez << p[i].available << endl;
						cout << "Dish updated Successfully !" << endl;
						b1 = true;
						filez.close();
					}
				}
				if (b1 == false)
				{
					cout << "Dish not Found ! " << endl << endl;
				}
			}
		}
		else
		{
			cout << "\t\t\t\t\t\tNo Menu Exist Add a Menu" << endl << endl;
		}

	}


	bool load_file_dish(menu* p, string ty)
	{
		int count_delete_dishes;
		ifstream file;
		file.open(ty, ios::in);
		string a, b;
		int pd;
		bool d;
		if (!file.is_open())
		{
			//cout<<ty << " cannot open in Load file_dish Function" << endl;
			return true;
		}
		else
		{
			count = 0;
			xl = 0;
			while (getline(file, a))
			{
				getline(file, b);
				file >> pd;
				file.ignore();
				file >> d;
				file.ignore();
				ifstream filed;
				filed.open("removedishes.txt", ios::in);
				string nb;
				count_delete_dishes = 0;
				while (getline(filed, nb))
				{
					if (nb != "")
					{
						count_delete_dishes++;
					}
				}
				//cout << "Number of delete dishes in removedishes.txt :  --> " << count_delete_dishes << endl;
				string* gt = new string[count_delete_dishes];
				filed.close();
				filed.open("removedishes.txt", ios::in);
				int k = 0;
				while (getline(filed, nb))
				{
					if (nb != "")
					{
						gt[k] = nb;
						k++;
					}
				}
				filed.close();
				int zx = 0;
				for (int j = 0;j < count_delete_dishes;j++)
				{
					if (gt[j] == a)
					{
						zx++;
					}
				}
				if (zx == 0)
				{
					p[count].dishname = a;
				}
				else
				{
					p[count].dishname = "nil";
					xl++;
				}
				p[count].dishcategory = b;
				p[count].price = pd;
				p[count].available = d;
				count++;
			}
			return false;
		}
		file.close();
	}

	static void specific_dish_sale(string n)
	{
		cout << endl << endl;
		cout << "\t\t\t------------------------------------------------------" << endl;
		cout << "\t\t\t------------------Specific Dish Sale------------------" << endl;
		cout << "\t\t\t------------------------------------------------------" << endl;
		cout << endl;
		cout << "\t\t\t\t" << n << " Dish has orders " << specific_order << endl;
		cout << "\t\t\t\t" << n << " Dish total sale is " << specific_price << endl;
		specific_order = 0;
		specific_price = 0;
	}
};
int menu::count = 0;
int menu::ab = 0;
int countt = 0;

class customer
{
private:
	string name;
	string id;
	int order;
	string* ordername;
	int bill;
public:
	bool report1;
	int del_customer_count = 0;
	customer()
	{
		name = "";id = "";order = 0;ordername = NULL;bill = 0;
	}
	string get_customer_name()
	{
		return name;
	}
	int get_bill()
	{
		return bill;
	}
	customer(string n, string i, int o, string oname)
	{
		name = n;id = i;order = o;*ordername = oname;
	}
	void add_customer(customer* p, menu* s)
	{

		cout << "For Customer : " << countt + 1 << endl;
		p[countt].setcorder(p[countt], s);
		countt++;
	}

	int del_customer = 0;
	void load_file(customer* c1, menu* m1, string specific_dish_name)
	{
		int get_bill;
		string nnn;
		ifstream filew;
		filew.open("deletecustomers.txt", ios::in);
		while (getline(filew, nnn))
		{
			if (nnn != "")
			{
				del_customer++;
			}
		}
		filew.close();
		//cout << "total delete customer in deletecustomers.txt :  " << del_customer << endl;
		string* tm = new string[del_customer];
		filew.open("deletecustomers.txt", ios::in);
		int k = 0;
		while (getline(filew, nnn))
		{
			if (nnn != "")
			{
				tm[k] = nnn;
				k++;
			}
		}
		filew.close();
		countt = 0;
		string file_name, file_id;
		int file_order;
		string* p;
		ifstream file;
		file.open("customer.txt", ios::in);
		// make objects:
		if (!file.is_open())
		{
			cout << "Customer file not open in load_file Function" << endl;
		}
		else
		{
			while (getline(file, file_name))
			{
				getline(file, file_id);
				file >> file_order;
				file.ignore();
				ofstream filet;
				filet.open("assignemp.txt", ios::out);
				if (!filet.is_open())
				{
					cout << "Assign_emp file cannot open in Set_order Emp Class" << endl;
				}
				else
				{
					static int tom = 0;
					tom = tom + file_order;
					filet << tom << endl;
				}
				filet.close();
				p = new string[file_order];
				for (int i = 0;i < file_order;i++)
				{
					getline(file, p[i]);
				}
				//------------------------------------------------
				file >> get_bill;
				file.ignore();
				//------------------------------------------------
				int ww = 0;
				for (int j = 0;j < del_customer;j++)
				{
					if (tm[j] == file_name)
					{
						ww++;
					}
				}
				if (ww == 0)
				{
					c1[countt].name = file_name;
					c1[countt].id = file_id;
					c1[countt].order = file_order;
					c1[countt].ordername = new string[c1[countt].order];
					for (int j = 0;j < file_order;j++)
					{
						c1[countt].ordername[j] = p[j];
					}
					//------------------------------------------------
					c1[countt].bill = get_bill;
					//------------------------------------------------

					for (int j = 0;j < file_order;j++)
					{
						if (c1[countt].ordername[j] == specific_dish_name)
						{
							specific_order++;
							for (int k = 0;k < menu::count;k++)
							{
								if (specific_dish_name == m1[k].getname(m1[k]))
								{
									specific_price = specific_price + m1[k].getprice(m1[k]);
								}
							}
						}
					}
				}
				else
				{
					c1[countt].name = "nil";
				}

				countt++;
				delete[]p;
			}
		}
		delete[]tm;
		file.close();
		wwe = countt - del_customer;
		ofstream filee;
		filee.open("assignempnum.txt", ios::out);
		if (!filee.is_open())
		{
			cout << "Assign_emp_num file cannot open in Set_order Emp Class" << endl;
		}
		else
		{
			filee << countt << endl;
		}
		filee.close();
	}

	void setcorder(customer& m, menu* m1)
	{
		ofstream filec;
		filec.open("customer.txt", ios::out | ios::app);
		if (!filec.is_open())
		{
			cout << "Customer file not open in setorder function" << endl;
		}
		total_customers++;
		cout << "Enter customer name : " << endl;
		getline(cin, m.name);
		//filec << m.name << endl;
		cout << "Enter customer id : " << endl;
		getline(cin, m.id);
		//filec << m.id << endl;
		bool gf = menu::display(m1);
		if (gf == false)
		{
			filec << m.name << endl;
			filec << m.id << endl;
			cout << "Enter no of orders you place :" << endl;
			cin >> m.order;
			cin.ignore();
			filec << m.order << endl;
			total_orders = total_orders + m.order;


			m.ordername = new string[order];
			for (int i = 0;i < order;i++)
			{
				cout << "For order : " << i + 1 << endl << endl;
				cout << "Enter Dish Name you place : " << endl;
				getline(cin, m.ordername[i]);
				int cc = 0, vv = 0;
				for (int j = 0;j < menu::count;j++)
				{
					if (m.ordername[i] == m1[j].getname(m1[j]))
					{
						cc++;
					}
				}
				if (cc == 0)
				{
					do
					{
						cout << "You Enter invalid Dish Name Re-Enter Dish name you place :" << endl;
						getline(cin, m.ordername[i]);
						for (int k = 0;k < menu::count;k++)
						{
							if (m.ordername[i] == m1[k].getname(m1[k]))
							{
								vv++;
								total_sale = total_sale + m1[k].getprice(m1[k]);
							}
						}
						if (vv != 0)
						{
							cout << "Order places Successfully ! " << endl << endl;
							filec << m.ordername[i] << endl;
							for (int k = 0;k < menu::count;k++)
							{
								if (m.ordername[i] == m1[k].getname(m1[k]))
								{
									m.bill = m.bill + m1[k].getprice(m1[k]);
								}
							}
						}
					} while (vv == 0);
				}
				else if (cc > 0)
				{
					for (int k = 0;k < menu::count;k++)
					{
						if (m.ordername[i] == m1[k].getname(m1[k]))
						{
							total_sale = total_sale + m1[k].getprice(m1[k]);
						}
					}
					filec << m.ordername[i] << endl;
					for (int k = 0;k < menu::count;k++)
					{
						if (m.ordername[i] == m1[k].getname(m1[k]))
						{
							m.bill = m.bill + m1[k].getprice(m1[k]);
						}
					}
					cout << "Order places Successfully ! " << endl << endl;
				}
			}
			filec << m.bill << endl;
			filec.close();
		}
		else
		{
			countt--;
			m.name.clear();
			m.id.clear();
		}

	}

	void display_allcustomers_details(customer* c1, menu* m1)
	{
		bool b1 = true;
		cout << "\t\t\t----------------------------------------------------" << endl;
		cout << "\t\t\t------------------List Of All Customers------------- " << endl;
		cout << "\t\t\t----------------------------------------------------" << endl;
		for (int i = 0;i < countt;i++)
		{
			if (c1[i].name != "nil")
			{
				cout << "Customer Name : " << c1[i].name << endl;
				cout << "Customer id : " << c1[i].id << endl;
				cout << "Customer has orders : " << c1[i].order << endl << endl;
				b1 = true;
				for (int j = 0;j < c1[i].order;j++)
				{
					cout << "Order number  : " << j + 1 << endl;
					cout << "Dish name : " << c1[i].ordername[j] << endl;
					for (int k = 0;k < menu::count;k++)
					{
						if (c1[i].ordername[j] == m1[k].getname(m1[k]))
						{
							cout << "Dish category : " << m1[k].getcategory(m1[k]) << endl;
							cout << "Dish price : " << m1[k].getprice(m1[k]) << endl;
							cout << "Dish availability  :  ";
							if (m1[k].getavailable(m1[k]) == 1)
							{
								cout << "Yes it is available! " << endl;
							}
							else
							{
								cout << "It is not available! " << endl;
							}
							cout << endl;
						}
					}
				}
				cout << "Customer total Bill  : " << c1[i].get_bill() << endl;
				cout << endl;
			}
		}
		if (b1 == false)
		{
			cout << "No Customer Added ! " << endl << endl;
		}
		wwe = countt - del_customer_count - del_customer;
		cout << "Total number of Customers : " << wwe << endl << endl;
	}

	void required_customer_details(customer* c1, menu* m1)
	{
		bool a1 = false;
		string cname;
		cout << "Enter name of a customer you search :" << endl;
		getline(cin, cname);
		for (int i = 0;i < countt;i++)
		{
			if (c1[i].name == cname)
			{
				cout << "Customer Name : " << c1[i].name << endl;
				cout << "Customer id : " << c1[i].id << endl;
				cout << "Customer has orders : " << c1[i].order << endl;
				for (int k = 0;k < c1[i].order;k++)
				{
					cout << "Customer order : " << k + 1 << endl;
					cout << "Dish name : " << c1[i].ordername[k] << endl;
					for (int j = 0;j < menu::count;j++)
					{
						if (c1[i].ordername[k] == m1[j].getname(m1[j]))
						{
							cout << "Dish category : " << m1[j].getcategory(m1[j]) << endl;
							cout << "Dish price : " << m1[j].getprice(m1[j]) << endl;
							cout << "Dish availability  :  ";
							if (m1[j].getavailable(m1[j]) == 1)
							{
								cout << "Yes it is available! " << endl;
							}
							else
							{
								cout << "It is not available! " << endl;
							}
							cout << endl;
						}
					}
				}
				a1 = true;
				cout << "Customer total Bill  : " << c1[i].get_bill() << endl;
				cout << endl;
			}
		}
		if (a1 == false)
		{
			cout << "Customer not found ! " << endl << endl;
		}
	}

	void delete_customer(customer* c1, menu* m1)
	{
		bool x = false;
		string cname;
		cout << "Enter name of a customer you delete :" << endl;
		getline(cin, cname);
		for (int i = 0;i < countt;i++)
		{
			if (c1[i].name == cname)
			{
				ofstream file;
				file.open("deletecustomers.txt", ios::out | ios::app);
				if (file.is_open())
				{
					file << cname << endl;
				}
				else
				{
					cout << "deletecustomers.txt cannot open in delete customers function" << endl;
				}
				file.close();
				c1[i].name = "nil";
				cout << "Customer Deleted Successfully ! " << endl << endl;
				del_customer_count++;
				//        total customers in report class:
				total_customers--;
				// **************************************
				for (int j = 0;j < c1[i].order;j++)
				{
					for (int k = 0;k < menu::count;k++)
					{
						if (c1[i].ordername[j] == m1[k].getname(m1[k]))
						{
							total_sale = total_sale - m1[k].getprice(m1[k]);
						}
					}
				}
				x = true;
			}
		}
		if (x == false)
		{
			cout << "Customer not Found ! " << endl << endl;
		}
	}

	void update_customer_details(customer* c1, menu* m1)
	{
		bool v = false;
		string cname;
		cout << "Enter name of a customer you update :" << endl;
		getline(cin, cname);
		for (int i = 0;i < countt;i++)
		{
			if (c1[i].name == cname)
			{
				ofstream file;
				file.open("deletecustomers.txt", ios::out | ios::app);
				file << cname << endl;
				file.close();
				v = true;
				//        total customers in report class:
				total_customers--;
				// **************************************
				for (int j = 0;j < c1[i].order;j++)
				{
					for (int k = 0;k < menu::count;k++)
					{

						if (c1[i].ordername[j] == m1[k].getname(m1[k]))
						{
							total_sale = total_sale - m1[k].getprice(m1[k]);
						}
					}
				}
				c1[i].setcorder(c1[i], m1);
			}
		}
		if (v == true)
		{
			cout << "Customer updated Successfully ! " << endl;
		}
		else
		{
			cout << "Customer not Found ! " << endl << endl;
		}
	}
};

class report
{
public:

	static void total_sales()
	{
		cout << "Total Sales are :  " << total_sale << endl << endl;
	}

	static void total_nof_customers()
	{
		cout << endl;
		//cout << "Total customers are :  " << total_customers << endl;
		cout << "Total customers are :  " << wwe << endl;
	}
};
class manager
{
private:
	menu* ptr;
	string name;
	string menuname;
	string id;
public:
	manager()
	{
		//cout << "manager constructor called" << endl;
		name = "";id = "";menuname = "";
		ptr = new menu[10];
	}

	manager(string nam, string i, string namm)
	{
		name = nam;
		id = i;
		menuname = namm;
		ptr = new menu[10];
	}

	bool g = false;

	void setmanager(manager& m)
	{
		if (g == false)
		{
			cout << "Enter Manager name : " << endl;
			getline(cin, m.name);
			cout << "Enter Manager ID :" << endl;
			getline(cin, m.id);
			cout << "Enter Menu name :" << endl;
			getline(cin, menuname);
			g = true;
		}

	}


	void manages(manager& m, customer* cc, menu* mm)
	{
		int a;
		char y = 'r';
		do
		{
			cout << "\033[1;35mEnter 1 for Add dishes " << endl;
			cout << "Enter 2 for Remove dishes" << endl;
			cout << "Enter 3 for Update dishes" << endl;
			cout << "Enter 4 for Display dishes" << endl;
			cout << "Enter 5 to Show Total Sale " << endl;
			cout << "Enter 6 to Show Specific Dish Total Sale" << endl;
			cout << "Enter 7 for Exit from dish panel\033[0m" << endl;
			cin >> a;
			cin.ignore();
			cout << endl;
			switch (a)
			{
			case 1:
			{
				m.ptr->adddish(ptr);
				break;
			}
			case 2:
			{
				m.ptr->removedish(ptr);
				break;
			}
			case 3:
			{
				m.ptr->updatedish(ptr);
				break;
			}
			case 4:
			{
				m.ptr->display(ptr);
				break;
			}
			case 5:
			{
				cout << "----------------------------------------------------" << endl;
				cout << "-------------------List Of Total Sale--------------- " << endl;
				cout << "----------------------------------------------------" << endl;
				report::total_nof_customers();
				report::total_sales();
				break;
			}
			case 6:
			{
				string menu_name, dish_name;
				menu::load_menu_names();
				cout << "Enter menu name in which specific dish is placed" << endl;
				getline(cin, menu_name);
				mm->display(mm);
				cout << "Enter Dish name you see details" << endl;
				getline(cin, dish_name);
				ptr->load_file_dish(ptr, menu_name);
				cc->load_file(cc, mm, dish_name);
				menu::specific_dish_sale(dish_name);
				break;
			}
			case 7:
			{
				y = 'f';
				break;
			}
			default:
				cout << "Invalid number" << endl;
				break;
			}
			if (y != 'f')
			{
				cout << "Enter y or Y to menu" << endl;
				cin >> y;
			}
		} while (y == 'y' || y == 'Y');
	}
	menu* returnptr()
	{
		return ptr;
	}
};
class emp
{
private:
	string ename, eid;
	int emp_o, emp_in;
	string* serve_customer_name;
	int nof_customers;
public:
	int nof_emp = 0;
	int ecount = 0;
	int nof_delete_emp = 0;
	emp()
	{
		ename = '\0';eid = '\0';emp_o = 0;emp_in = 0;
	}
	//        Setter Functions
	void set_empname()
	{
		cout << "Enter Employee name :" << endl;
		getline(cin, ename);
	}
	void set_empid()
	{
		cout << "Enter Employee id :" << endl;
		getline(cin, eid);
	}
	void set_emp_orders()
	{
		cout << "Enter Employee number of orders :" << endl;
		cin >> emp_o;
		cin.ignore();
		ifstream file;
		file.open("assignemp.txt", ios::in);
		if (!file.is_open())
		{
			cout << "Assign_emp file cannot open in set_emp_order Function" << endl;
		}
		else
		{
			int rt = 0;
			while (file >> rt)
			{
				file.ignore();
				total_orders = rt;
			}
		}
		if (emp_o > total_orders)
		{
			do
			{
				cout << "You Enter invalid number of orders Re-Enter number of orders :" << endl;
				cin >> emp_o;
			} while (emp_o > total_orders);
			if (emp_o > total_orders)
			{
				cout << "Orders Assigned to this Employee Successfully !" << endl;
			}
		}
		else
		{
			cout << "Orders Assigned to this Employee Successfully !" << endl;
		}
		file.close();
	}
	void set_empincome()
	{
		cout << "Enter Employee income :" << endl;
		cin >> emp_in;
		cin.ignore();
	}
	void set_delete_emp(string v)
	{
		ename = v;
	}

	//           Getter Functions:
	string get_empname()
	{
		return ename;
	}
	string get_empid()
	{
		return eid;
	}
	int get_emp_orders()
	{
		return emp_o;
	}
	int get_empincome()
	{
		return emp_in;
	}
	void set_employee(emp& e, customer* c, menu* m1)
	{
		ofstream file;
		file.open("emp.txt", ios::out | ios::app);
		if (!file.is_open())
		{
			cout << "Employee file cannot open in set_employee function " << endl;
		}
		else
		{
			e.set_empname();
			file << e.get_empname() << endl;
			e.set_empid();
			file << e.get_empid() << endl;
			e.set_empincome();
			file << e.get_empincome() << endl;
			c->display_allcustomers_details(c, m1);
			cout << endl;
			e.set_emp_orders();
			file << e.get_emp_orders() << endl;
			cout << "How many Customers Served by this Employee :" << endl;
			cin >> e.nof_customers;
			cin.ignore();
			ifstream filem;
			filem.open("assignempnum.txt", ios::in);
			if (!filem.is_open())
			{
				cout << "Assign_emp_num file cannot open in set_emp Function" << endl;
			}
			else
			{
				int www = 0;
				while (filem >> www)
				{
					filem.ignore();
					//cout << "www :  -->  " << www << endl;
					total_customers = www;
				}
			}
			filem.close();
			if (e.nof_customers > total_customers)
			{
				do
				{
					cout << "You Enter invalid number of customers Re-Enter number of Customers :" << endl;
					cin >> e.nof_customers;
				} while (e.nof_customers > total_customers);
			}
			file << e.nof_customers << endl;
			e.serve_customer_name = new string[e.nof_customers];
			for (int i = 0;i < e.nof_customers;i++)
			{
				int countc = 0;
				cout << "Enter name of customer : " << i + 1 << " you serve :" << endl;
				cin >> e.serve_customer_name[i];
				for (int j = 0;j < countt;j++)
				{
					if (e.serve_customer_name[i] == c[j].get_customer_name())
					{
						countc++;
					}
				}

				if (countc == 0)
				{
					int vv = 0;
					do
					{
						cout << "You Enter invalid customer name Re-Enter Customer name" << endl;
						cin >> e.serve_customer_name[i];
						for (int j = 0;j < countt;j++)
						{
							if (e.serve_customer_name[i] == c[j].get_customer_name())
							{
								vv++;
							}
						}
						if (vv != 0)
						{
							file << e.serve_customer_name[i] << endl;
							cout << "Employee assigned to this Customer successfully !" << endl;
						}
					} while (vv == 0);

				}
				else
				{
					file << e.serve_customer_name[i] << endl;
					cout << "Employee assigned to this Customer successfully !" << endl;
				}

			}
		}
		//----------------------------------------
		file.close();
	}
	void add_emp(emp* s, customer* d, menu* ptr)
	{
		cout << "For Employee Number :  " << ecount + 1 << endl;
		s[ecount].set_employee(s[ecount], d, ptr);
		ecount++;
	}
	int del_e;

	void load_file_emp(emp* s, customer* d)
	{
		ecount = 0;
		string file_name, file_id;
		int file_income, file_orders;
		int n;
		string* ptr;
		ifstream filee;
		filee.open("emp.txt", ios::in);
		if (!filee.is_open())
		{
			cout << "Employee File Cannot Open in Load file_emp function" << endl;
		}
		else
		{
			ecount = 0;
			while (getline(filee, file_name))
			{
				getline(filee, file_id);
				filee >> file_income;
				filee >> file_orders;
				filee >> n;
				filee.ignore();
				ptr = new string[n];
				for (int k = 0;k < n;k++)
				{
					getline(filee, ptr[k]);
				}
				ifstream filez;
				string get_e;
				filez.open("removeemp.txt", ios::in);
				del_e = 0;
				while (getline(filez, get_e))
				{
					if (get_e != "")
					{
						del_e++;
					}

				}
				filez.close();
				//cout << "delete emp count : " << del_e << endl;
				string* trr = new string[del_e];
				filez.open("removeemp.txt", ios::in);
				int qq = 0;
				get_e.clear();
				while (getline(filez, get_e))
				{
					trr[qq] = get_e;
					qq++;
				}
				filez.close();
				int wq = 0;
				for (int j = 0;j < del_e;j++)
				{
					if (trr[j] == file_name)
					{
						wq++;
					}
				}
				if (wq == 0)
				{
					s[ecount].ename = file_name;
					s[ecount].eid = file_id;
					s[ecount].emp_in = file_income;
					s[ecount].emp_o = file_orders;
					s[ecount].nof_customers = n;
					s[ecount].serve_customer_name = new string[s[ecount].nof_customers];
					for (int k = 0;k < n;k++)
					{
						s[ecount].serve_customer_name[k] = ptr[k];
					}
					delete[]ptr;
				}
				else
				{
					s[ecount].ename = "nill";
					s[ecount].eid = file_id;
					s[ecount].emp_in = file_income;
					s[ecount].emp_o = file_orders;
					s[ecount].nof_customers = n;
					s[ecount].serve_customer_name = new string[s[ecount].nof_customers];
					for (int k = 0;k < n;k++)
					{
						s[ecount].serve_customer_name[k] = ptr[k];
					}
					delete[]ptr;
				}

				ecount++;
			}
		}
		filee.close();
	}

	void delete_employee(emp* s)
	{
		bool q = false;
		string n;
		cout << "Enter name of Employee you delete" << endl;
		getline(cin, n);
		for (int i = 0;i < ecount;i++)
		{
			if (n == s[i].get_empname())
			{
				ofstream filex;
				filex.open("removeemp.txt", ios::out | ios::app);
				if (filex.is_open())
				{
					filex << n << endl;
				}
				else
				{
					cout << "removeemp file cannot open in delete_emp function" << endl;
				}
				filex.close();
				s[i].set_delete_emp("nill");
				q = true;
				nof_delete_emp++;
			}
		}
		if (q == true)
		{
			cout << "Employee Deleted successfully !" << endl;
		}
		else
		{
			cout << "Employee you want to Delete not Found !" << endl;
		}
	}

	void req_employee_detail(emp* s)
	{
		bool q = false;
		string n;
		cout << "Enter name of Employee you Search :" << endl;
		getline(cin, n);
		for (int i = 0;i < ecount;i++)
		{
			if (n == s[i].get_empname())
			{
				q = true;
				cout << "Employee Name : " << s[i].get_empname() << endl;
				cout << "Employee id : " << s[i].get_empid() << endl;
				cout << "Employee Income : " << s[i].get_empincome() << endl;
				cout << "Employee has Orders : " << s[i].get_emp_orders() << endl;
				cout << "Employee Serve These Customers : " << endl;
				for (int j = 0;j < s[i].nof_customers;j++)
				{
					cout << "Customer  " << j + 1 << "  name : " << endl;
					cout << s[i].serve_customer_name[j] << endl;
				}
			}
		}
		if (q == false)
		{
			cout << "Employee you search not Found !" << endl;
		}
	}

	void update_employee(emp* s, customer* d, menu* ptr)
	{
		bool q = false;
		string n;
		cout << "Enter name of Employee you Update :" << endl;
		getline(cin, n);
		for (int i = 0;i < ecount;i++)
		{
			if (n == s[i].get_empname())
			{
				ofstream filez;
				filez.open("removeemp.txt", ios::out | ios::app);
				if (filez.is_open())
				{
					filez << n << endl;
				}
				else
				{
					cout << "removeemp file cannot open in delete_emp function" << endl;
				}
				filez.close();
				q = true;
				s[i].set_employee(s[i], d, ptr);
			}
		}
		if (q == true)
		{
			cout << "Employee Updated Successfully !" << endl;
		}
		else
		{
			cout << "Employee you Update not Found !" << endl;
		}
	}
	void show_all_employees(emp* s)
	{
		cout << "\t\t\t----------------------------------------------------" << endl;
		cout << "\t\t\t------------------List Of All Employees------------- " << endl;
		cout << "\t\t\t----------------------------------------------------" << endl;

		for (int i = 0;i < ecount;i++)
		{
			if (s[i].get_empname() != "nill")
			{
				cout << "Employee Name : " << s[i].get_empname() << endl;
				cout << "Employee id : " << s[i].get_empid() << endl;
				cout << "Employee Income : " << s[i].get_empincome() << endl;
				cout << "Employee has Orders : " << s[i].get_emp_orders() << endl;
				cout << "Employee Serve These Customers : " << endl;
				for (int j = 0;j < s[i].nof_customers;j++)
				{
					cout << "Customer  " << j + 1 << "  name :  " << s[i].serve_customer_name[j] << endl;
				}
				cout << endl;
			}
			cout << endl;

		}
		cout << "Total number of Employees are : " << ecount - nof_delete_emp - del_e << endl;

	}

};

int main()
{
	cout << "\t\t\t\t\033[1;36m-----------------------------------------------------------" << endl;
	cout << "\t\t\t\t------------------Restaurant Management System------------- " << endl;
	cout << "\t\t\t\t-----------------------------------------------------------\033[0m" << endl << endl << endl;
	manager m;
	customer* c = new customer[10];
	menu* ss = m.returnptr();
	emp* e = new emp[10];
	fstream empfile;
	empfile.open("emp.txt");
	fstream filem;
	char y;
	//menu::load_file_dish(ss,"desi.txt");
	e->load_file_emp(e, c);
	c->load_file(c, ss, "ere");
	//ss->load_file_dish(ss, "deserts.txt");
	do
	{
		int a;
		cout << "\033[1;33mPress 1 to Enter Manager Activities " << endl;
		cout << "Press 2 to Enter Customer Panel  " << endl;
		cout << "Press 3 to Enter Employee Panel " << endl;
		cout << "Press 4 to Exit Program\033[0m" << endl;
		cin >> a;
		cin.ignore();
		cout << endl;
		switch (a)
		{
		case 1:
		{
			//m.setmanager(m);
			cout << "\033[1;34m";
			filem.open("manager.txt", ios::in);
			if (!filem.is_open())
			{
				cout << "Manager file cannot open" << endl << endl;
			}
			else if (filem.is_open())
			{
				bool flag = false;
				string user_name, pass, user, password;
				cout << "Enter Manager Name to login" << endl;
				getline(cin, user_name);
				cout << "Enter Password :" << endl;
				getline(cin, pass);
				cout << endl;
				while (filem.eof() == 0)
				{
					getline(filem, user);
					getline(filem, password);
				}

				if (user_name == user)
				{
					if (pass == password)
					{
						flag = true;
					}
				}

				if (flag == true)
				{
					cout << "You Login Successfully !\033[0m" << endl << endl << endl;
					m.manages(m, c, ss);
				}
				else if (flag == false)
				{
					cout << "You not Login Successfully !\033[0m" << endl << endl << endl;
				}
			}
			filem.close();
			break;
		}
		case 2:
		{
			char j = 'm';
			do
			{
				cout << "\033[1;35m";
				int a;
				cout << "Enter 1 to Add Customer" << endl;
				cout << "Enter 2 to display required customer details" << endl;
				cout << "Enter 3 to delete a customer" << endl;
				cout << "Enter 4 to update a Required customer details" << endl;
				cout << "Enter 5 to show all customers details" << endl;
				cout << "Enter 6 to exit to customer panel\033[0m" << endl;
				cin >> a;
				cin.ignore();
				cout << endl;
				switch (a)
				{
				case 1:
				{
					c->add_customer(c, ss);
					break;
				}
				case 2:
				{
					c->required_customer_details(c, ss);
					break;
				}
				case 3:
				{
					c->delete_customer(c, ss);
					break;
				}
				case 4:
				{
					c->update_customer_details(c, ss);
					break;
				}
				case 5:
				{
					c->display_allcustomers_details(c, ss);
					break;
				}
				case 6:
				{
					j = 'r';
					break;
				}
				default:
					cout << "You Press invalid number !" << endl;
					break;
				}
				if (j != 'r')
				{
					cout << "Enter y or Y to show again show customer menu :" << endl;
					cin >> j;
				}
			} while (j == 'y' || j == 'Y');

			break;
		}
		case 3:
		{
			char tt = 'd';
			int n;
			do
			{
				cout << "\033[1;31mPress 1 to Add Employee" << endl;
				cout << "Press 2 to Show Required Employee Detail" << endl;
				cout << "Press 3 to Delete Employee" << endl;
				cout << "Press 4 to Update Employee" << endl;
				cout << "Press 5 to Show All Employees" << endl;
				cout << "Press 6 to Exit From Employee Panel\033[0m" << endl;
				cin >> n;
				cin.ignore();
				cout << endl;
				switch (n)
				{
				case 1:
				{
					e->add_emp(e, c, ss);
					break;
				}
				case 2:
				{
					e->req_employee_detail(e);
					break;
				}
				case 3:
				{
					e->delete_employee(e);
					break;
				}
				case 4:
				{
					e->update_employee(e, c, ss);
					break;
				}
				case 5:
				{
					e->show_all_employees(e);
					break;
				}
				case 6:
				{
					tt = 'u';
					break;
				}
				default:
					cout << "You Press Invalid Number !!!" << endl;
					break;
				}
				if (tt != 'u')
				{
					cout << "Enter Y or y to show again Employee Menu :" << endl;
					cin >> tt;
				}

			} while (tt == 'y' || tt == 'Y');
			break;
		}
		case 4:
		{
			exit(0);
		}
		default:
			cout << "You Press invalid number !" << endl;
			break;
		}
		cout << "Press y or Y to show Main Menu :" << endl;
		cin >> y;
	} while (y == 'y' || y == 'Y');
	empfile.close();
	delete[]c;
	delete[]ss;
	delete[]e;
	system("pause");
	return 0;
}