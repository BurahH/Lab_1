#include <iostream>

using namespace std;

#include "Class.h"

int main()
{
	int number, data, numberlist;
	size_t index;
	List firstlist;
	List secondlist;
	number = 0;
	data = 0;
	index = 0;
	numberlist = 0;
	cout << "1. Adding to the end of the list\n2. Adding to the beginning of the list\n3. Removing the last item\n4. Removing the first item\n5. Adding an element by index.\n6. Getting an element by index\n7. Deleting an element by index\n8. Getting the size of the list\n9. Removing all list items\n10. Replacing the element by index with the transmitted element.\n11. Checking if the list is empty\n12. Insert another list at the end\n13. Exiting the program \n";
	while (1)
	{
		cout << "Enter the instruction number\n";
		cin >> number;
		while ((number < 1) or (number > 13))
		{
			cout << "Incorrect number entered repeat\n";
			cin >> number;
		}
		try {
			if (number == 1)
			{
				cout << "Select a list number (1 or 2)\n";
				cin >> numberlist;
				while ((numberlist < 1) or (numberlist > 2))
				{
					cout << "Incorrect number entered repeat\n";
					cin >> numberlist;
				}
				cout << "Enter the data to write to the new array element\n";
				cin >> data;
				if (numberlist == 1)
					firstlist.push_back(data);
				else
					secondlist.push_back(data);
			}
			if (number == 2)
			{
				cout << "Select a list number (1 or 2)\n";
				cin >> numberlist;
				while ((numberlist < 1) or (numberlist > 2))
				{
					cout << "Incorrect number entered repeat\n";
					cin >> numberlist;
				}
				cout << "Enter the data to write to the new array element\n";
				cin >> data;
				if (numberlist == 1)
					firstlist.push_front(data);
				else
					secondlist.push_front(data);
			}
			if (number == 3)
			{
				cout << "Select a list number (1 or 2)\n";
				cin >> numberlist;
				while ((numberlist < 1) or (numberlist > 2))
				{
					cout << "Incorrect number entered repeat\n";
					cin >> numberlist;
				}
				if (numberlist == 1)
					firstlist.pop_back();
				else
					secondlist.pop_back();
			}
			if (number == 4)
			{
				cout << "Select a list number (1 or 2)\n";
				cin >> numberlist;
				while ((numberlist < 1) or (numberlist > 2))
				{
					cout << "Incorrect number entered repeat\n";
					cin >> numberlist;
				}
				if (numberlist == 1)
					firstlist.pop_front();
				else
					secondlist.pop_front();
			}
			if (number == 5)
			{
				cout << "Select a list number (1 or 2)\n";
				cin >> numberlist;
				while ((numberlist < 1) or (numberlist > 2))
				{
					cout << "Incorrect number entered repeat\n";
					cin >> numberlist;
				}
				cout << "Enter the data to write to the new array element\n";
				cin >> data;
				cout << "Enter the index\n";
				cin >> index;
				if (numberlist == 1)
					firstlist.insert(data, index);
				else
					secondlist.insert(data, index);
			}
			if (number == 6)
			{
				cout << "Select a list number (1 or 2)\n";
				cin >> numberlist;
				while ((numberlist < 1) or (numberlist > 2))
				{
					cout << "Incorrect number entered repeat\n";
					cin >> numberlist;
				}
				cout << "Enter the index\n";
				cin >> index;
				if (numberlist == 1)
					cout << firstlist.at(index) << endl;
				else
					cout << secondlist.at(index) << endl;
			}
			if (number == 7)
			{
				cout << "Select a list number (1 or 2)\n";
				cin >> numberlist;
				while ((numberlist < 1) or (numberlist > 2))
				{
					cout << "Incorrect number entered repeat\n";
					cin >> numberlist;
				}
				cout << "Enter the index\n";
				cin >> index;
				if (numberlist == 1)
					firstlist.remove(index);
				else
					secondlist.remove(index);
			}
			if (number == 8)
			{
				cout << "Select a list number (1 or 2)\n";
				cin >> numberlist;
				while ((numberlist < 1) or (numberlist > 2))
				{
					cout << "Incorrect number entered repeat\n";
					cin >> numberlist;
				}
				if (numberlist == 1)
					cout << firstlist.get_size() << endl;
				else
					cout << secondlist.get_size() << endl;
			}
			if (number == 9)
			{
				cout << "Select a list number (1 or 2)\n";
				cin >> numberlist;
				while ((numberlist < 1) or (numberlist > 2))
				{
					cout << "Incorrect number entered repeat\n";
					cin >> numberlist;
				}
				if (numberlist == 1)
					firstlist.clear();
				else
					secondlist.clear();
			}
			if (number == 10)
			{
				cout << "Select a list number (1 or 2)\n";
				cin >> numberlist;
				while ((numberlist < 1) or (numberlist > 2))
				{
					cout << "Incorrect number entered repeat\n";
					cin >> numberlist;
				}
				cout << "Enter the data to write to the new array element\n";
				cin >> data;
				cout << "Enter the index\n";
				cin >> index;
				if (numberlist == 1)
					firstlist.set(index, data);
				else
					secondlist.set(index, data);
			}
			if (number == 11)
			{
				cout << "Select a list number (1 or 2)\n";
				cin >> numberlist;
				while ((numberlist < 1) or (numberlist > 2))
				{
					cout << "Incorrect number entered repeat\n";
					cin >> numberlist;
				}
				if (numberlist == 1)
					cout << firstlist.isEmpty() << endl;
				else
					cout << secondlist.isEmpty() << endl;
			}
			if (number == 12)
			{
				cout << "Select the end of which list to insert (1 or 2)\n";
				cin >> numberlist;
				while ((numberlist < 1) or (numberlist > 2))
				{
					cout << "Incorrect number entered repeat\n";
					cin >> numberlist;
				}
				if (numberlist == 1)
					firstlist.push_back(&secondlist);
				else
					secondlist.push_back(&firstlist);
			}
		}
		catch (const out_of_range expection)
		{
			cout << expection.what() << endl;
		}
		if (number == 13)
			break;
	}
	return 0;
}