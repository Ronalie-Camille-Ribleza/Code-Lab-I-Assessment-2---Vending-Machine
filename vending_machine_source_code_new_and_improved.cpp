#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
using namespace std;

struct item
{
	char name[100];
	float price;
	unsigned quantity;
};

struct item rowA[5] = {
	{"Lay's Potato Chips Salt", 0.90, 20,},
	{"Sohar Potato Chips", 3.25, 20,},
	{"Tiffany Bugles Ketchup", 0.40, 20,},
	{"Sunbites Cheese and Herbs Bread Bites", 3.10, 20,},
	{"Mr Krisps Salad Chips", 0.80, 20,},
};
struct item rowB[5] = {
	{"Tiffany Monsta Mini Chocolate Chip Cookies", 1.00, 20},
	{"Meiji Hello Panda Double Chocolate Biscuit", 2.00, 20},
	{"Britannia Little Hearts Biscuits", 1.70, 20},
	{"Tiffany Vanilla Flavored Cream Biscuits", 1.15, 20},
	{"Oreo Original", 1.00, 20},
};
struct item rowC[10] = {
	{"Nestle Chocapic Cereals Bar", 2.80, 20},
	{"Be-Kind Whole Grains Raspberry Cereal Bar", 3.60, 20},
	{"Nestle Fitness Strawberry Breakfast Cereal Bar", 2.90, 20},
	{"Nature Valley Whole Grain Granola Bar Oats And Honey", 1.00, 20},
	{"Honey Cheerios Bar", 2.15, 20},
	{"Best Sunflower Seeds", 2.25, 20},
	{"Bayara Extra Mixed Nuts", 3.90, 20},
	{"Bayara Cashews Salted", 3.00, 20},
	{"Bayara Peanuts", 0.80, 20},
	{"Ding Dong Mixed Nuts", 2.20, 20},
};
struct item rowD[10] = {
	{"Al Ain Bottled Drinking Water", 0.95, 20},
	{"Al Ain Bottled Drinking Water", 0.95, 20},
	{"Al Ain Bottled Drinking Water", 0.95, 20},
	{"Al Ain Bottled Drinking Water", 0.95, 20},
	{"Al Ain Bottled Drinking Water", 0.95, 20},
	{"Aquafina Bottled Drinking Water", 0.90, 20},
	{"Aquafina Bottled Drinking Water", 0.90, 20},
	{"Aquafina Bottled Drinking Water", 0.90, 20},
	{"Aquafina Bottled Drinking Water", 0.90, 20},
	{"Aquafina Bottled Water", 0.90, 20},
};
struct item rowE[10] = {
	{"Pokka Cappuccino Real Brewed Coffee Drink", 4.60, 20},
	{"Pokka Milk Coffee Drink", 4.80, 20},
	{"Marmum Pure And Fresh Strawberry Milk", 1.50, 20},
	{"Al Rawabi Fresh Chocolate Milk", 1.60, 20},
	{"Almarai Premium Mango Milk", 2.00, 20},
	{"Nada Blackberry And Raspberry Greek Yogurt Drink", 4.95, 20},
	{"Nada Drinking Greek Yoghurt Apple", 4.95, 20},
	{"Safa Laban Up Drink", 0.80, 20},
	{"Balade Farms Ayran Laban", 1.30, 20},
	{"Almarai Laban Mango Flavor", 2.70, 20},
};
struct item rowF[10] = {
	{"Gatorade Sports Drink Orange", 5.00, 20},
	{"Gatorade Sports Drink Cool Blue Raspberry", 5.00, 20},
	{"Gatorade Sports Drink Lemon Lime", 5.00, 20},
	{"Gatorade Sports Drink Fruit Punch", 5.00, 20},
	{"Pocari Sweat Pet Bottle", 5.00, 20},
	{"Pokka Japanese Green Tea", 3.10, 20},
	{"Lipton Red Fruits Ice Tea", 3.95, 20},
	{"Lipton Zero Sugar Peach Iced Tea", 3.60, 20},
	{"Lipton Lemon Ice Tea", 3.70, 20},
	{"Lipton Peach Ice Tea", 2.50, 20},
};
// array of row arrays
struct item *rows[6] = {
	rowA,
	rowB,
	rowC,
	rowD,
	rowE,
	rowF,
};
int rows_lengths[6] = {
	sizeof(rowA) / sizeof(rowA[0]),
	sizeof(rowB) / sizeof(rowB[0]),
	sizeof(rowC) / sizeof(rowC[0]),
	sizeof(rowD) / sizeof(rowD[0]),
	sizeof(rowE) / sizeof(rowE[0]),
	sizeof(rowF) / sizeof(rowF[0]),
};

int main()
{
	cout << "Affordabites Food and Drink Vending Machine" << endl;
	cout << "All snacks available for AED5 and below!" << endl;
	cout << " " << endl;

	cout << "Please select which row you want to get an item from: " << endl;
	cout << "Row A - Savory Snacks\t\tRow B - Sweet Snacks\t\t\t\tRow C - Cereal Bars and Nuts" << endl;
	cout << "Row D - Drinking Water\t\tRow E - Coffee and Other Dairy Products\t\tRow F - Healthy Drinks" << endl;
	char myRow;
	cin >> myRow; // makes the user select a specific row on the vending machine, but only one row at a time

	myRow = toupper(myRow);
	cout << fixed;
	cout << setprecision(2);
	if ((myRow > 'F') || (myRow < 'A'))
	{
		cout << "Invalid input" << endl;
	}
	else
	{
		struct item *row = rows[myRow - 'A'];
		int row_len = rows_lengths[myRow - 'A'];

		int choice = 1;

		while (true)
		{
			for (int i = 0; i < row_len; i++)
			{
				cout << i + 1 << ". " << row[i].name << "\r\t\t\t\t\t\t" << row[i].price << "\t(" << row[i].quantity << ") in stock" << endl;
			}
			cout << "11. Exit" << endl;
			cin >> choice;
			if (choice == 11)
			{
				cout << "Come back next time!" << endl;
				break;
			}
			else if (choice >= 1 && choice <= row_len)
			{
				if (row[choice - 1].quantity == 0)
				{
					cout << row[choice - 1].name << " is currently unavailable";
					continue;
				}
				else
				{
					row[choice - 1].quantity--;
					float cash;
					cout << "Insert any number of coins or cash: " << endl;
					cin >> cash;
					float price = row[choice - 1].price;
					if (cash < price)
					{
						cout << "Insufficient amount " << endl;
						continue;
					}
					else
					{
						float change = cash - price;
						cout << row[choice - 1].name << " has been dispensed" << endl;
						cout << "Enjoy your snack!" << endl;
						cout << "Change: " << change << endl;
					}
				}
			}
			else
			{
				cout << "Invalid input" << endl;
			}
		}
	}
	return 0;
}
