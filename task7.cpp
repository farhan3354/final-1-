#include <iostream>
using namespace std;

int main() {

    char arr[200] = { "sugar#salt#flour#rice#pasta#beans#oil#cheese#eggs#milk#bread#butter#honey#tea#coffee#spices#nuts#fruits#vegetables#meat" };
    char arr1[200] = { "Farhan@Ali@Asif@Fahad@Faizan@Faheem@Nadeeml@Hamza@fahad@milk@bread@butter@honey@tea@coffee@spices@nuts@fruits@vegetables@meat" };
    int productid[30] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
    int productprice[30] = { 110,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000 };
    int customerid[30] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
    int customerage[30] = { 21,20,30,40,50,55,45,33,32,21,22,31,34,16,15,35,17,18,19,29 };
    int customercontact[30] = { 923112,923123,923112,923123,923112,923123,923112,923123,923112,923123,923113,923123,923112,923123,923112,923123,923112,923122,923113,923127 };
    int stock[20] = { 50, 100, 75, 60, 80, 120, 30, 40, 90, 70, 110, 55, 65, 85, 95, 45, 35, 25, 15, 10 };
    int count = 20;
    int count1 = 20;

    int productIndex = 0;

    int currentLength = 0;

    for (int i = 0; arr[i] != '\0'; i++)
    {
        currentLength++;
    }


    char Category[26];
    for (int i = 0; i < 26; i++)
    {
        Category[i] = 'A' + i;
    }

    int choice;
    while (true)
    {
        cout << "\nSelect an option: \n";
        cout << "1. Product Management\n";
        cout << "2. Customer Management\n";
        cout << "3. Restock Products\n";
        cout << "4. Search Products\n";
        cout << "5. Purchase Products\n";
        cout << "6. Generate Reports\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0)
        {
            cout << "Exiting program.\n";
            break;
        }

        switch (choice)
        {
        case 1:
        {
            int point;
            cout << "Product management system\n";
            cout << "Enter your point (1 for entering product, 2 for checking list): ";
            cin >> point;

            if (point == 2)
            {
                cout << "The Product list is given below:" << endl;

                for (int i = 0; arr[i] != '\0'; i++)
                {
                    if (arr[i] == '#')
                    {
                        productIndex++;
                        cout << endl;
                    }
                    else
                    {
                        if (i == 0 || arr[i - 1] == '#')
                        {
                            cout << "Product Id: " << productid[productIndex] << "  Product Price: " << productprice[productIndex] << "  Product Stock: " << stock[productIndex] << "  Product Name: ";
                        }
                        cout << arr[i];
                    }
                }

                cout << endl;
                /* for (int i = 0; i < count; i++) {

                    cout << "Product Id: " << productid[i] << "  Product Price: " << productprice[i] << "  Product stock are: " << stock[i] <<" Product Name : ";
                    cout << endl;
                }*/
            }

            else if (point == 1)
            {
                int productIndex = 0;

                if (count < 30)
                { 
                    int new_id;
                    bool idexists = false;
                    do {
                        cout << "Enter the product id: ";
                        cin >> new_id;

                        idexists = false;
                        for (int i = 0; i < count; i++)
                        {
                            if (productid[i] == new_id)
                            {
                                idexists = true;
                                cout << "Product ID already exists. Please enter a different ID.\n";
                                break;
                            }
                        }
                    } while (idexists);

                    productid[count] = new_id;

                    cout << "Enter the product price: ";
                    cin >> productprice[count];
                    cout << "Enter the product stock: ";
                    cin >> stock[count];
                    cout << "Enter the number of items you want to add: ";
                    int numItems;
                    cin >> numItems;
                    cin.ignore(); 

                    for (int i = 0; i < numItems; i++)
                    {
                        char newItem[50];  
                        cout << "Enter item #" << i + 1 << ": ";
                        cin.getline(newItem, 50);  

                        bool canAdd = true;
                        int j = 0;

                        while (newItem[j] != '\0')
                        {
                            if (currentLength + j + 1 >= sizeof(arr))
                            { 
                                canAdd = false;
                                break;
                            }
                            j++;
                        }
                        if (canAdd)
                        {
                            if (currentLength > 0)
                            {
                                arr[currentLength] = '#'; 
                                currentLength++;
                            }

                            for (int k = 0; newItem[k] != '\0'; k++)
                            {
                                arr[currentLength] = newItem[k];
                                currentLength++;
                            }
                        }
                        else
                        {
                            cout << "Not enough space to add more items." << endl;
                            break;
                        }
                    }

                    count++;

                    cout << "\nUpdated Product List:\n";
                    for (int i = 0; arr[i] != '\0'; i++)
                    {
                        if (arr[i] == '#')
                        {
                            productIndex++;
                            cout << endl;
                        }
                        else
                        {
                            if (i == 0 || arr[i - 1] == '#')
                            {
                                cout << "Product Id: " << productid[productIndex] << "  Product Price: " << productprice[productIndex] << "  Product Stock: " << stock[productIndex] << "  Product Name: ";
                            }
                            cout << arr[i];
                        }
                    }
                    /*for (int i = 0; i < count; i++) {
                        cout << "Product Id: " << productid[i] << "  Product Price: " << productprice[i] << "  Product stock are: " << stock[i] <<" Product Name" << endl;
                    }*/
                }
                else
                {
                    cout << "Cannot add more products, the list is full.\n";
                }
            }
            else if (point == 0)
            {
                break;
            }
            else
            {
                cout << "Invalid option, please try again.\n";
            }
            break;
        }

        case 2:
        {
            int productIndex = 0;
            int point;
            cout << "Customer management system\n";
            cout << "Enter your point(1 for entering customer, 2 for checking list, 3 for searching customers) : ";
            cin >> point;

            if (point == 2)
            {
                cout << "The Customer list is given below:" << endl;
                for (int i = 0; arr1[i] != '\0'; i++) {
                    if (arr1[i] == '@') {
                        productIndex++;
                        cout << endl;
                    }
                    else {
                        if (i == 0 || arr1[i - 1] == '@')
                        {
                            cout << "customer Id: " << customerid[productIndex] << "  customer Age: " << customerage[productIndex] << "  customer Contact: " << customercontact[productIndex] << "  customer Name: ";
                        }
                        cout << arr1[i];
                    }
                }

                cout << endl;
                /*  for (int i = 0; i < count; i++) {
                    cout << "Customer Id: " << customerid[i] << "  Customer Age: " << customerage[i] << "  Customer Category: " << Category[i] << "  Customer Contact: " << customercontact[i] << endl;
                }*/

            }

            else if (point == 1)
            {
                if (count1 < 30)
                { 
                    int newidc;
                    bool idexistsc = false;
                    do {
                        cout << "Enter the Customer id: ";
                        cin >> newidc;

                        idexistsc = false;
                        for (int i = 0; i < count1; i++)
                        {
                            if (customerid[i] == newidc)
                            {
                                idexistsc = true;
                                cout << "Customer ID already exists. Please enter a different ID.\n";
                                break;
                            }
                        }
                    } while (idexistsc);

                    customerid[count1] = newidc;

                    int age;
                    do {
                        cout << "Enter the Customer age (must be greater than 14): ";
                        cin >> age;
                        if (age <= 14)
                        {
                            cout << "Invalid age. Age must be greater than 14.\n";
                        }
                    } while (age <= 14);

                    customerage[count1] = age;

                    cout << "Enter the Customer contact: ";
                    cin >> customercontact[count1];
                    count1++;
                }
                cout << "Enter the number of customer you want to add: ";
                int numcus;
                cin >> numcus;
                cin.ignore();

                for (int i = 0; i < numcus; i++)
                {
                    char newcus[50];
                    cout << "Enter customer #" << i + 1 << ": ";
                    cin.getline(newcus, 50);

                    bool canAdd = true;
                    int j = 0;

                    while (newcus[j] != '\0')
                    {
                        if (currentLength + j + 1 >= sizeof(arr1))
                        { 
                            canAdd = false;
                            break;
                        }
                        j++;
                    }
                    if (canAdd)
                    {
                        if (currentLength > 0)
                        {
                            arr1[currentLength] = '@';
                            currentLength++;
                        }

                        for (int k = 0; newcus[k] != '\0'; k++)
                        {
                            arr1[currentLength] = newcus[k];
                            currentLength++;
                        }
                    }
                    cout << "The  recods are updated Successfully : " << endl;

                    cout << "\nUpdated Customer List:\n";
                    for (int i = 0; arr1[i] != '\0'; i++)
                    {
                        if (arr1[i] == '@')
                        {
                            productIndex++;
                            cout << endl;
                        }
                        else
                        {
                            if (i == 0 || arr1[i - 1] == '@')
                            {
                                cout << "Customer Id: " << customerid[productIndex] << "  Customer Contact: " << customercontact[productIndex]<<"Customer Category: "<<Category[productIndex] << "  Customer Age: " << customerage[productIndex] << "  Customer Name: ";
                            }
                            cout << arr1[i];
                        }
                    }

                }

            }
            else if (point == 0)
            {
                break;
            }
            else if (point == 3)
            {
                int searchChoice;
                cout << "Search by:\n";
                cout << "1. Customer ID\n";
                cout << "2. Customer Name\n";
                cout << "Enter your choice: ";
                cin >> searchChoice;

                if (searchChoice == 1)
                {
                    int searchID;
                    cout << "Enter the Customer ID: ";
                    cin >> searchID;

                    bool found = false;
                    for (int i = 0; i < count1; i++)
                    {
                        if (customerid[i] == searchID)
                        {
                            cout << "Customer Found:\n";
                            cout << "Customer Id: " << customerid[i] << "  Customer Age: " << customerage[i] << "  Customer Contact: " << customercontact[i] << "  Customer Name: ";

                            int nameStart = 0;
                            for (int j = 0; j < i; j++)
                            {
                                while (arr1[nameStart] != '@' && arr1[nameStart] != '\0')
                                {
                                    nameStart++;
                                }
                                nameStart++; 
                            }

                            while (arr1[nameStart] != '@' && arr1[nameStart] != '\0')
                            {
                                cout << arr1[nameStart];
                                nameStart++;
                            }
                            cout << endl;
                            found = true;
                            break;
                        }
                    }

                    if (!found)
                    {
                        cout << "Customer not found.\n";
                    }
                }
                else if (searchChoice == 2)
                {
                    char searchName[50];
                    cout << "Enter the Customer Name: ";
                    cin.ignore(); 
                    cin.getline(searchName, 50);

                    bool found = false;
                    int nameStart = 0;
                    for (int i = 0; i < count1; i++)
                    {
                        char currentName[50];
                        int k = 0;
                        while (arr1[nameStart] != '@' && arr1[nameStart] != '\0')
                        {
                            currentName[k++] = arr1[nameStart++];
                        }
                        currentName[k] = '\0'; 
                        nameStart++;

                        bool match = true;
                        for (int j = 0; searchName[j] != '\0' || currentName[j] != '\0'; j++)
                        {
                            if (searchName[j] != currentName[j])
                            {
                                match = false;
                                break;
                            }
                        }

                        if (match)
                        {
                            cout << "Customer Found:\n";
                            cout << "Customer Id: " << customerid[i] << "  Customer Age: " << customerage[i] << "  Customer Contact: " << customercontact[i] << "  Customer Name: " << currentName << endl;
                            found = true;
                            break;
                        }
                    }

                    if (!found)
                    {
                        cout << "Customer not found.\n";
                    }
                }
                else
                {
                    cout << "Invalid choice.\n";
                }
                }
            else if (point == 0)
            {
                break;
                }
            else
            {
                cout << "Invalid option, please try again.\n";
                }
                break;

        }


        case 3:
        {
            cout << "3. Restock Products\n";
            int editid, newprice, newstock;
            bool idfound = false;

            cout << "Enter the product id you want to edit: ";
            cin >> editid;

            for (int i = 0; i < count; i++)
            {
                if (productid[i] == editid)
                {
                    cout << "Enter the new price for product ID " << editid << ": ";
                    cin >> newprice;
                    cout << "Enter the new stock for product ID " << editid << ": ";
                    cin >> newstock;

                    productprice[i] = newprice;
                    stock[i] = newstock;

                    cout << "Product price updated successfully.\n";
                    cout << "Product stock updated successfully.\n";

                    idfound = true;
                    break;
                }
            }

            if (!idfound)
            {
                cout << "Product ID not found.\n";
            }

            if (idfound)
            {
                cout << "\nUpdated Product List:\n";
                for (int i = 0; i < count; i++)
                {
                    cout << "Product Id: " << productid[i]
                        << "  Product Price: " << productprice[i]
                        << "  Product Stock: " << stock[i]
                        << "  Product Name: ";

                    int productIndex = 0;
                    for (int j = 0; arr[j] != '\0'; j++)
                    {
                        if (arr[j] == '#')
                        {
                            productIndex++;
                        }
                        else
                        {
                            if (j == 0 || arr[j - 1] == '#') 
                            {
                                while (arr[j] != '#' && arr[j] != '\0')
                                {
                                    cout << arr[j];
                                    j++;
                                }
                                break;
                            }
                        }
                    }
                    cout << endl;
                }
            }

            break;
        }
        case 4:
        {
            cout << "4. Search Products\n";
            int searchChoice;
            cout << "Search by:\n";
            cout << "1. Product ID\n";
            cout << "2. Product Name\n";
            cout << "3. Product Category\n";
            cout << "Enter your choice: ";
            cin >> searchChoice;

            if (searchChoice == 1)
            {
                int searchID;
                cout << "Enter the Product ID: ";
                cin >> searchID;

                bool found = false;
                for (int i = 0; i < count; i++)
                {
                    if (productid[i] == searchID)
                    {
                        cout << "Product Found:\n";
                        cout << "Product Id: " << productid[i] << "  Product Price: " << productprice[i] << "  Product stock are: " << stock[i] << endl;
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    cout << "Product not found.\n";
                }
            }
            else if (searchChoice == 2)
            {
                char searchName[10];
                cout << "Enter the Product Name (up to 9 characters): ";
                cin >> searchName;

                bool found = false;
                for (int i = 0; i < count; i++) {
                    bool match = true;

                    if (match)
                    {
                        cout << "Product Found:\n";
                        cout << "Product Id: " << productid[i] << "  Product Price: " << productprice[i] << "  Product stock are: " << stock[i] << endl;
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    cout << "Product not found.\n";
                }
            }
            else if (searchChoice == 3)
            {
                char searchCategory;
                cout << "Enter the Product Category (A-Z): ";
                cin >> searchCategory;

                bool found = false;
                for (int i = 0; i < count; i++)
                {
                    if (Category[i] == searchCategory)
                    {
                        cout << "Product Found:\n";
                        cout << "Product Id: " << productid[i] << "  Product Price: " << productprice[i] << "  Product stock are: " << stock[i] <<Category[i]<< endl;
                        found = true;
                    }
                }

                if (!found)
                {
                    cout << "No products found in this category.\n";
                }
            }
            else
            {
                cout << "Invalid choice.\n";
            }
            break;
        }

        case 5:
        {
            int productsid, quantity;
            cout << "Enter the product ID you want to purchase: ";
            cin >> productsid;


            int index = -1;
            for (int i = 0; i < count; i++)
            {
                if (productid[i] == productsid)
                {
                    index = i;
                    break;
                }
            }

            if (index == -1)
            {
                cout << "Product not found.\n";
                break;
            }

            cout << "Enter the quantity you want to purchase: ";
            cin >> quantity;

            if (stock[index] >= quantity)
            {
                stock[index] -= quantity;
                cout << "Purchase successful! Remaining stock for product " << productid[index] << " is " << stock[index] << ".\n";
            }
            else
            {
                cout << "Not enough stock available. Only " << stock[index] << " items left.\n";
            }
            break;
        }
        case 6:
        {
            int reportChoice;
            cout << "Generate Reports:\n";
            cout << "1. Display all products and their details\n";
            cout << "2. Display all customers and their details\n";
            cout << "3. Generate low stock report\n";
            cout << "Enter your choice: ";
            cin >> reportChoice;

            if (reportChoice == 1)
            {
                cout << "\nList of All Products:\n";
                productIndex = 0;
                for (int i = 0; arr[i] != '\0'; i++)
                {
                    if (arr[i] == '#')
                    {
                        productIndex++;
                        cout << endl;
                    }
                    else
                    {
                        if (i == 0 || arr[i - 1] == '#')
                        {
                            cout << "Product Id: " << productid[productIndex] << "  Product Price: " << productprice[productIndex] << "  Product Stock: " << stock[productIndex] << "  Product Name: ";
                        }
                        cout << arr[i];
                    }
                }
                cout << endl;
            }
            else if (reportChoice == 2)
            {
                cout << "\nList of All Customers:\n";
                int customerIndex = 0; 
                for (int i = 0; arr1[i] != '\0'; i++)
                {
                    if (arr1[i] == '@')
                    {
                        customerIndex++;
                        cout << endl;
                    }
                    else
                    {
                        if (i == 0 || arr1[i - 1] == '@')
                        {
                            cout << "Customer Id: " << customerid[customerIndex] << "  Customer Age: " << customerage[customerIndex] << "  Customer Contact: " << customercontact[customerIndex] << "  Customer Name: ";
                        }
                        cout << arr1[i];
                    }
                }
                cout << endl;
            }
            else if (reportChoice == 3)
            {
                int threshold;
                cout << "Enter the stock threshold (e.g., 5): ";
                cin >> threshold;

                cout << "\nLow Stock Report (Products with stock less than " << threshold << "):\n";
                productIndex = 0;
                bool foundLowStock = false; 

                for (int i = 0; arr[i] != '\0'; i++)
                {
                    if (arr[i] == '#')
                    {
                        productIndex++;
                    }
                    else
                    {
                        if (i == 0 || arr[i - 1] == '#') 
                        {
                            if (stock[productIndex] < threshold)
                            {
                                cout << "Product Id: " << productid[productIndex]
                                    << "  Product Price: " << productprice[productIndex]
                                    << "  Product Stock: " << stock[productIndex]
                                    << "  Product Name: ";

                                while (arr[i] != '#' && arr[i] != '\0')
                                {
                                    cout << arr[i];
                                    i++;
                                }
                                cout << endl;
                                foundLowStock = true;
                            }
                        }
                    }
                }

                if (!foundLowStock)
                {
                    cout << "No products have stock less than the threshold (" << threshold << ").\n";
                }
            }
            else
            {
                cout << "Invalid choice.\n";
            }
            break;
        }

        default:
        {
            cout << "Invalid choice. Please try again.\n";
            break;
        }
        }
    }

    return 0;
}



//#include<iostream>
//using namespace std;
//int main()
//{
//
//	int productid[30] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
//	int productprice[30] = { 110,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000 };
//	int customerid[30] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
//	int customerage[30] = { 21,20,30,40,50,55,45,33,32,21,22,31,34,16,15,35,17,18,19,29 };
//	int customercontact[30] = {923112,923123,923112,923123,923112,923123,923112,923123,923112,923123,923113,923123,923112,923123,923112,923123,923112,923122,923113,923127 };
//	int stock[30] = { 21,12,23,34,54,65,67,78,34,23,45,67,98,452,312,32,54,21,12 };
//	int count = 20;
//
//	char Category[26];
//
//	// Fill the array with 'A' to 'Z'
//	for (int i = 0; i < 26; i++) {
//		Category[i] = 'A' + i;
//	}
//
//	int choice;	
//	while (true) {
//		cout << "\nSelect an option: \n";
//		cout << "1. Product Management\n";
//		cout << "2. Customer Management\n";
//		cout << "3. Restock Products\n";
//		cout << "4. Search Products\n";
//		cout << "0. Exit\n";
//		cout << "Enter your choice: ";
//		cin >> choice;
//
//		// Exit the program if the user selects 0
//		if (choice == 0) {
//			cout << "Exiting program.\n";
//			break;
//		}
//
//		// Handle product management and other choices
//		switch (choice) {
//		case 1: {
//			int point;
//			cout << "Product management system\n";
//			cout << "Enter your point (1 for entering product name, 2 for checking list): ";
//			cin >> point;
//
//			if (point == 2) {
//				cout << "The Product list is given below:" << endl;
//				for (int i = 0; i < count; i++) {
//					cout << "Product Id: " << productid[i] << "  Product Price: " << productprice[i] <<"  Product stock are: "<<stock[i] << endl;
//				}
//			}
//
//			else if (point == 1) {
//				if (count < 30) { // Check to ensure we don't exceed array size
//					int new_id;
//					bool id_exists = false;
//					do {
//						cout << "Enter the product id: ";
//						cin >> new_id;
//
//						// Check if the ID already exists
//						id_exists = false;
//						for (int i = 0; i < count; i++) {
//							if (productid[i] == new_id) {
//								id_exists = true;
//								cout << "Product ID already exists. Please enter a different ID.\n";
//								break;
//							}
//						}
//					} while (id_exists);
//
//					productid[count] = new_id;
//
//					cout << "Enter the product price: ";
//					cin >> productprice[count];
//					count++;
//				}
//				else {
//					cout << "Cannot add more products, the list is full.\n";
//				}
//			}
//			else if (point == 0) {
//				break; // Exit the loop
//			}
//			else {
//				cout << "Invalid option, please try again.\n";
//			}
//			break;
//		}
//
//		case 2: {
//			int point;
//			cout << "Customer management system\n";
//			cout << "Enter your point (1 for entering product name, 2 for checking list): ";
//			cin >> point;
//
//			if (point == 2) {
//				cout << "The Customer list is given below:" << endl;
//				for (int i = 0; i < count; i++) {
//					cout << "Customer Id: " << customerid[i] << "  Customer Price: " << customerage[i] << "  Customer Category: " << Category[i] << "  Customer Contact: " << customercontact[i] << endl;
//				}
//			}
//
//			else if (point == 1) {
//				if (count < 30) { // Check to ensure we don't exceed array size
//					int new_id;
//					bool id_exists = false;
//					do {
//						cout << "Enter the Customer id: ";
//						cin >> new_id;
//
//						// Check if the ID already exists
//						id_exists = false;
//						for (int i = 0; i < count; i++) {
//							if (customerid[i] == new_id) {
//								id_exists = true;
//								cout << "Customer ID already exists. Please enter a different ID.\n";
//								break;
//							}
//						}
//					} while (id_exists);
//
//					customerid[count] = new_id;
//
//
//					int age;
//					do {
//						cout << "Enter the Customer age (must be greater than 14): ";
//						cin >> age;
//						if (age <= 14) {
//							cout << "Invalid age. Age must be greater than 14.\n";
//						}
//					} while (age <= 14);
//
//					customerage[count] = age;
//					
//					cout << "Enter the Customer contact: ";
//					cin >> customercontact[count];
//					count++;
//				}
//				else {
//					cout << "Cannot add more products, the list is full.\n";
//				}
//			}
//			else if (point == 0) {
//				break; // Exit the loop
//			}
//			else {
//				cout << "Invalid option, please try again.\n";
//				break; // Exit the loop
//
//			}
//			break;
//		}
//		
//		case 3: {
//			cout << "3. Restock Products\n";
//			int edit_id, new_price;
//			bool id_found = false;
//
//			cout << "Enter the product id you want to edit: ";
//			cin >> edit_id;
//
//			// Search for the product ID
//			for (int i = 0; i < count; i++) {
//				if (productid[i] == edit_id) {
//					cout << "Enter the new price for product ID " << edit_id << ": ";
//					cin >> new_price;
//
//					// Update the price
//					productprice[i] = new_price;
//					cout << "Product price updated successfully.\n";
//					id_found = true;
//					break;
//				}
//			}
//
//			if (!id_found) {
//				cout << "Product ID not found.\n";
//			}
//
//
//			break;
//
//		}
//		
//		case 4: {
//			cout << "4. Search Products\n";
//			break;
//		}
//		
//		}
//	
//		}
//	
//	}




//old code 

//#include <iostream>
//using namespace std;
//
//int main() {
//   
//    int n;
//
//    cout << "Enter the size of the array (between 5 and 20): ";
//    cin >> n;
//
//    while (n < 5 || n > 20) {
//        cout << "Invalid size! Please enter a size between 5 and 20: ";
//        cin >> n;
//    }
//
//    int arr[n];
//    int sum = 0;
//
//    cout << "Enter " << n << " positive integers:\n";
//    for (int i = 0; i < n; i++) {
//        cin >> arr[i];
//        while (arr[i] <= 0) {
//            cout << "Please enter a positive integer: ";
//            cin >> arr[i];
//        }
//        sum += arr[i];
//    }
//
//    int largest = INT_MIN;
//    int smallest = INT_MAX;
//    for (int i = 0; i < n; i++) {
//        if (arr[i] > largest) {
//            largest = arr[i];
//        }
//        if (arr[i] < smallest) {
//            smallest = arr[i];
//        }
//    }
//
//    int average = sum / n; 
//    int countGreaterThanAvg = 0;
//
//    for (int i = 0; i < n; i++) {
//        if (arr[i] > average) {
//            countGreaterThanAvg++;
//        }
//    }
//
//    cout << "\nAnalysis Results:\n";
//    cout << "Largest element: " << largest << endl;
//    cout << "Smallest element: " << smallest << endl;
//    cout << "Average of the elements: " << average << endl;
//    cout << "Number of elements greater than the average: " << countGreaterThanAvg << endl;
//
//    for (int i = 0; i < n; i++) {
//        if (arr[i] % 2 == 0) { 
//            arr[i] /= 2; 
//        }
//        else {
//            arr[i] = arr[i] * arr[i]; 
//        }
//    }
//
//    cout << "\nTransformed Array:\n";
//    for (int i = 0; i < n; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//
//      int x;
//    cout << "Enter the number to search in the array: ";
//    cin >> x;
//
//    bool found = false;
//    for (int i = 0; i < n; i++) {
//        if (arr[i] == x) {
//            found = true;
//            cout << "Number " << x << " found at index " << i << ".\n";
//            break;
//        }
//    }

// if (!found) {
// cout << "Number " << x << " not found in the array.\n";
    //}
    //return 0;
//}
 
//#include<iostream>
//using namespace std;
//int main()
//{
	//int arr[5] = { 34,76,24,6,45 };
	//int temp;

	//temp = arr[0];

	//for (int i = 0; i < 5 - 1; i++)
	//{
		//arr[i] = arr[i + 1];
	//}
	//arr[4] = temp;
	//for (int i = 0; i < 5; i++)
	//{
		//cout << arr[i] << " ";
	//}

	//cout << endl;

	//int re[6] = { 23,34,54,6,7,5 };

	//for (int e = 5; e > 0; e--) {
		//re[e] = re[e - 1];

	//}
	//re[0] = 0;
	//for (int w = 0; w < 6; w++) {
		//cout << re[w]<<" ";
	//}
	
// int arr[10] = { 12,45,76,13,6,5,7,4,79,56 };
	//int temp;
	//int n;

	//for (int i = 0; i < 10; i++)
	//{
		//for (int j = 0; j < 10 - 1; j++)
		//{
			//if (arr[j] < arr[j + 1])
			//{
				//temp = arr[j];
				//arr[j] = arr[j + 1];
				//arr[j + 1] = temp;
			//}
		//}
	//}
	//cout << "Enter n: ";
	//cin >> n;

	//cout << "The " << n << "th largest number is: " << arr[n - 1];*/

	//int arr[10] = { 342,32,69,3,-876,5,12,876,43,69 };
	//int max1 = -999, indexOfLargest;
	//int max2 = -999;

	//for (int i = 0; i < 10; i++)
//	{
//		if (arr[i] > max1)
//		{
//			max1 = arr[i];
//			indexOfLargest = i;
//
//		}
//	}
//	cout << "largest number is at index " << indexOfLargest;
//
//	arr[indexOfLargest] = 0;
//
//	for (int i = 0; i < 10; i++)
//	{
//		if (arr[i] > max2)
//		{
//			max2 = arr[i];
//			indexOfLargest = i;
//			cout << "Second largest number is at index " << i;
//			break;
//		}
//	}
//	//int array1[10] = { 342,32,69,3,-876,5,12,76,43,69 };
//	//int array2[10] = { 876,45,54,12,7,34,34,32,87,342 };
//	//int min = 999, max = -999;
//
//	//for (int i = 0; i < 10; i++)
// {
	//	if (array1[i] > max)
	//	{
   	//		max = array1[i];
	//	}
	//}
	//for (int i = 0; i < 10; i++)
	//{
	//	if (array2[i] == max)
	//	{
	//		cout << "Max number of array 1 (" << max << ") is at " << i << " index in array 2";
	//	}
	//}
//
//	int arr[10] = { 342,32,69,3,-876,5,12,876,43,69 };
//	int count = 0;

//	for (int i = 0; i < 10; i += 2)
//	{
//		if (arr[i] % 2 == 0)
//		{
//			count++;
//		}
//	}
//	cout << "Number of even number present on even index are: " << count;*/

//	int arr[10] = { 342,32,69,3,-876,5,12,76,43,69 };
//	int max = -999, min = 999;

//int arr[10] = { 342, 32, 69, 3, -876, 5, 12, 876, 43, 69 };
//int max = INT_MIN;
//int min = INT_MAX;
//
//for (int i = 0; i < 10; i++) {
//    if (arr[i] > max) {
//        max = arr[i];
//    }
//    if (arr[i] < min) {
//        min = arr[i];
//    }
//}
//cout << "Maximum number: " << max << "\nMinimum number: " << min << endl;

//int target, count = 0;
//cout << "Enter target number: ";
//cin >> target;
//
//for (int i = 0; i < 10; i++) {
//    if (arr[i] == target) {
//        count++;
//    }
//}
//if (count > 0) {
//    cout << "Number is present: " << count << " times" << endl;
//}
//else {
//    cout << "Number is not present" << endl;
//}

//bool found = false;
//cout << "Enter target number to search: ";
//cin >> target;
//
//for (int i = 0; i < 10; i++) {
//    if (arr[i] == target) {
//        cout << "Number is at index " << i << endl;
//        found = true;
//        break;
//    }
//}
//if (!found) {
//    cout << "The number is not found" << endl;
//}
//
//// Part 4: Reverse an Array
//int Array1[10] = { 342, 32, 6, 3, 876, 5, 12, 876, 43, 6 };
//int Array2[10];
//int j = 9;
//
//cout << "Array1: ";
//for (int i = 0; i < 10; i++) {
//    cout << Array1[i] << " ";
//}
//cout << endl;
//
//for (int i = 0; i < 10; i++) {
//    Array2[i] = Array1[j];
//    j--;
//}
//
//cout << "Reversed Array2: ";
//for (int i = 0; i < 10; i++) {
//    cout << Array2[i] << " ";
//}
//cout << endl;

//int arr[10] = {};
//int reverseArr[10] = {};
//int j = 9;
//
//cout << "Enter elements:\n";
//for (int i = 0; i < 10; i++) {
//    cin >> arr[i];
//}
//for (int i = 0; i < 10; i++) {
//    reverseArr[i] = arr[j];
//    j--;
//}
//for (int i = 0; i < 10; i++) {
//    cout << reverseArr[i] << " ";
//}
//
//int e[10] = { 12, 15, 8, 23, 42, 11, 18, 29, 4, 6 };
//
//cout << "Odd numbers in the array: ";
//for (int k = 10; k > 0; --k) {
//    if (e[k] % 2 != 0) {
//        cout << e[k] << " ";
//    }
//}
//cout << endl;
//
//int we[10] = { 12, 15, 8, 23, 42, 11, 18, 29, 4, 6 };
//cout << "Even numbers in the array: ";
//for (int k = 0; k < 10; ++k) {
//    if (we[k] % 2 == 0) {
//        cout << we[k] << " ";
//    }
//}
//cout << endl;
//
//int rollNumbers[7] = { 10, 20, 30, 40, 50, 60, 70 };
//cout << "Last roll number: " << rollNumbers[6] << endl;
//rollNumbers[4] = 40;
//cout << "Updated 5th roll number: " << rollNumbers[4] << endl;
//rollNumbers[2] = rollNumbers[0] + rollNumbers[1] - 2;
//cout << "Updated 3rd roll number: " << rollNumbers[2] << endl;
//cout << "Updated roll numbers: ";
//for (int i = 0; i < 7; ++i) {
//    cout << rollNumbers[i] << " ";
//}
//cout << endl;
//
//int sad, ds;
//cout << "Enter the height of the parallelogram: ";
//cin >> sad;
//cout << "Enter the width of the parallelogram: ";
//cin >> ds;
//
//for (int i = 0; i < sad; ++i) {
//    for (int j = 0; j < sad - i - 1; ++j) {
//        cout << " ";
//    }
//    for (int j = 0; j < ds; ++j) {
//        cout << "*";
//    }
//    cout << endl;
//}
//
//int in;
//cout << "Enter the height of the filled triangle: ";
//cin >> in;
//for (int i = 1; i <= in; i++) {
//    for (int j = 1; j <= 2 * in - 1; j++) {
//        if (j >= in - (i - 1) && j <= in + (i - 1)) {
//            cout << "*";
//        }
//        else {
//            cout << " ";
//        }
//    }
//    cout << endl;
//}
//
//int height;
//cout << "Enter the height of the hollow triangle: ";
//cin >> height;
//for (int i = 1; i <= height; i++) {
//    for (int j = 1; j <= 2 * height - 1; j++) {
//        if (j == height - (i - 1) || j == height + (i - 1) || i == height) {
//            cout << "*";
//        }
//        else {
//            cout << " ";
//        }
//    }
//    cout << endl;
//}
//
//int num1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//int num2[10];
//j = 9;
//for (int i = 0; i < 10; i++) {
//    num2[i] = num1[j];
//    j--;
//}
//for (int i = 0; i < 10; i++) {
//    cout << num2[i];
//}
//
//int num, digit, sum = 0;
//cout << "Enter the number";
//cin >> num;
//while (num > 0) {
//    digit = num % 10;
//    sum += digit;
//    num /= 10;
//}
//cout << "Final" << sum;
//
//float balance = 10000.0;
//int option;
//float deposit, withdraw;
//
//do {
//    cout << "\nATM Menu: \n";
//    cout << "1. Check Balance\n";
//    cout << "2. Deposit Amount\n";
//    cout << "3. Withdraw Amount\n";
//    cout << "4. Exit\n";
//    cout << "Select an option: ";
//    cin >> option;
//
//    switch (option) {
//    case 1:
//        cout << "\nYour current balance is: Rs. " << balance << endl;
//        break;
//    case 2:
//        cout << "\nEnter the amount to deposit: Rs. ";
//        cin >> deposit;
//        if (deposit > 0) {
//            balance += deposit;
//            cout << "You have successfully deposited Rs. " << deposit << endl;
//        }
//        else {
//            cout << "Invalid deposit amount!" << endl;
//        }
//        break;
//    case 3:
//        cout << "\nEnter the amount to withdraw: Rs. ";
//        cin >> withdraw;
//        if (withdraw > 0 && withdraw <= balance) {
//            balance -= withdraw;
//            cout << "You have successfully withdrawn Rs. " << withdraw << endl;
//        }
//        else if (withdraw > balance) {
//            cout << "Insufficient funds. You cannot withdraw more than your current balance." << endl;
//        }
//        else {
//            cout << "Invalid withdrawal amount!" << endl;
//        }
//        break;
//    case 4:
//        cout << "\nExiting the system. Thank you for using the ATM!" << endl;
//        break;
//    default:
//        cout << "\nInvalid option! Please select a valid menu option." << endl;
//        break;
//    }
//} while (option != 4);



    //char name;
    //int totalTasks, tasksCompleted;
    //float customerSatisfaction;
    //int bonus = 5; 

    //cout << "Enter the first character of employee's  name: ";
    //cin>>name;

    //cout << "Enter the total tasks assigned to " << name << ": ";
    //cin >> totalTasks;

    //cout << "Enter the number of tasks completed by " << name << ": ";
    //cin >> tasksCompleted;

    //cout << "Enter the customer satisfaction rating (out of 5) for " << name << ": ";
    //cin >> customerSatisfaction;

    //float  CompletionRate = (tasksCompleted / totalTasks) * 100;

        //if (CompletionRate == 100) {

            //if (customerSatisfaction == 4.5 || customerSatisfaction < 4.5) {
                //bonus++; 
                //cout << "award a performance bonus of ++bonus of "<<bonus;
            //}
            //else {
                //cout << "Customer satisfaction is average. Bonus remains the same." << endl;
            //}

        //}
        //else if (CompletionRate >= 80 && CompletionRate < 100) {
         
            //if (customerSatisfaction >= 4.0) {
                //bonus++;  
                //cout << "Customer satisfaction is good. Bonus slightly increased." << endl;
            //}
            //else {
                //bonus--;
                //cout << "Customer satisfaction is low. Bonus decreased by 1." << endl;
            //}
        //}
        //else {
            //bonus -= 2; 
            //cout << "Completion rate is low. Bonus decreased by 2." << endl;
        //}

        //cout << "\nFinal Performance Bonus for " << name << ": " << bonus << endl;

    //float subject1, subject2, subject3;
    //float total, percentage;
    //char grade;

    //cout << "Enter the score for Subject 1 (out of 100): ";
    //cin >> subject1;
    //cout << "Enter the score for Subject 2 (out of 100): ";
    //cin >> subject2;
    //cout << "Enter the score for Subject 3 (out of 100): ";
    //cin >> subject3;

    //total = subject1 + subject2 + subject3;
    //percentage = (total / 300) * 100;

    //if (percentage >= 90) {
    //    grade = 'A'; 
    //    cout << "Grade: A+" << endl;
    //}
    //    grade = 'A';
    //    cout << "Grade: A" << endl;
    //}
    //else if (percentage >= 70 && percentage < 80) {
    //    grade = 'B';
    //    cout << "Grade: B" << endl;
    //}
    //else if (percentage >= 60 && percentage < 70) {
    //    grade = 'C';
    //    cout << "Grade: C" << endl;
    //}
    //else if (percentage <= 60 ) {
    //    grade = 'F';
    //    cout << "Grade: Fail" << endl;
    //}

    //int n;

    //cout << "Enter a number: ";
    //cin >> n;

    //cout << "Prime numbers up to " << n << " are: ";

    //for (int i = 2; i <= n; ++i) {
    //    bool isPrime = true;

    //    for (int j = 2; j * j <= i; ++j) {
    //        if (i % j == 0) {
    //            isPrime = false; // i is divisible by j, so it's not prime
    //            break;
    //        }
    //    }

    //    if (isPrime) {
    //        cout << i << " ";
    //    }
    //}
    //cout << endl;


    //int number, originalNum, reversedNum = 0, digit;

    //cout << "Enter an integer: ";
    //cin >> number;

    //originalNum = number;

    //while (number > 0) {
    //    digit = number % 10;       
    //    reversedNum = reversedNum * 10 + digit; 
    //    number = number / 10;          
    //}

    //if (originalNum == reversedNum) {
    //    cout << originalNum << " is a palindrome." << endl;
    //}
    //else {
       //cout << originalNum << " is not a palindrome." << endl;
    //}

    //int number, originalNumber, remainder, result = 0;

    //cout << "Enter a 3-digit number: ";
    //cin >> number;

    //originalNumber = number;

    //while (number != 0) {
        //remainder = number % 10;          
        //result += remainder * remainder * remainder; 
        //number /= 10;             
    //}

    //if (result == originalNumber) {
        //cout << originalNumber << " is an Armstrong number." << endl;
    //}
    //else {
        //cout << originalNumber << " is not an Armstrong number." << endl;
    //}

   //int num1, num2, lcm;

    //cout << "Enter the first positive integer: ";
    //cin >> num1;
    //cout << "Enter the second positive integer: ";
    //cin >> num2;

    //int maxVal = (num1 > num2) ? num1 : num2;

    //for (int i = maxVal; ; i++) {
        //if (i % num1 == 0 && i % num2 == 0) {
            //lcm = i;
            //break;
        //}
    //}
    //cout << "The Least Common Multiple (LCM) of " << num1 << " and " << num2 << " is: " << lcm << endl;*/
 //}
//}



//}
//#include <iostream>
//using namespace std;
//
//const int TOTAL_BOOKS = 20;
//const int TOTAL_MEMBERS = 10;
//const int MAX_BORROW = 3;
//const int MAX_OVERDUE_DAYS = 7;  // Max days after which fine is applied
//
//// Arrays for storing book details
//char bookTitles[TOTAL_BOOKS][50];
//char bookAuthors[TOTAL_BOOKS][50];
//char bookGenres[TOTAL_BOOKS][20];
//char bookISBNs[TOTAL_BOOKS][20];
//bool bookAvailability[TOTAL_BOOKS];
//int bookPublicationYear[TOTAL_BOOKS];  // Store publication year of the book
//
//// Arrays for storing member details
//char memberNames[TOTAL_MEMBERS][50];
//int memberIDs[TOTAL_MEMBERS];
//int memberAges[TOTAL_MEMBERS];
//char memberAddresses[TOTAL_MEMBERS][100];
//int borrowedBooks[TOTAL_MEMBERS][MAX_BORROW];  // Store indices of borrowed books
//int borrowedCount[TOTAL_MEMBERS];  // Count of borrowed books for each member
//int overdueFines[TOTAL_MEMBERS];  // Overdue fines for members
//int borrowedDates[TOTAL_MEMBERS][MAX_BORROW]; // Store borrowing dates (in days)
//
//// Main program logic
//int main() {
//    // Initialize book details
//    for (int i = 0; i < TOTAL_BOOKS; ++i) {
//        for (int j = 0; j < 50; ++j) {
//            bookTitles[i][j] = '\0';
//            bookAuthors[i][j] = '\0';
//        }
//        for (int j = 0; j < 20; ++j) {
//            bookGenres[i][j] = '\0';
//            bookISBNs[i][j] = '\0';
//        }
//        bookAvailability[i] = true;
//        bookPublicationYear[i] = 0;
//    }
//
//    // Example data for books
//    char exampleTitle1[] = "Book1";
//    char exampleAuthor1[] = "Author1";
//    char exampleGenre1[] = "Fiction";
//    char exampleISBN1[] = "12345";
//    int examplePublicationYear1 = 2010;
//
//    // Copy example data into arrays
//    for (int j = 0; exampleTitle1[j] != '\0'; ++j) bookTitles[0][j] = exampleTitle1[j];
//    for (int j = 0; exampleAuthor1[j] != '\0'; ++j) bookAuthors[0][j] = exampleAuthor1[j];
//    for (int j = 0; exampleGenre1[j] != '\0'; ++j) bookGenres[0][j] = exampleGenre1[j];
//    for (int j = 0; exampleISBN1[j] != '\0'; ++j) bookISBNs[0][j] = exampleISBN1[j];
//    bookPublicationYear[0] = examplePublicationYear1;
//
//    // Initialize member details
//    for (int i = 0; i < TOTAL_MEMBERS; ++i) {
//        for (int j = 0; j < 50; ++j) memberNames[i][j] = '\0';
//        for (int j = 0; j < 100; ++j) memberAddresses[i][j] = '\0';
//        memberIDs[i] = i + 1;
//        memberAges[i] = 20 + i; // Example age
//        borrowedCount[i] = 0;  // No books borrowed initially
//        overdueFines[i] = 0;  // No fines initially
//    }
//
//    // Example data for members
//    char exampleName1[] = "Member1";
//    char exampleAddress1[] = "Addr1";
//
//    // Copy example data into arrays
//    for (int j = 0; exampleName1[j] != '\0'; ++j) memberNames[0][j] = exampleName1[j];
//    for (int j = 0; exampleAddress1[j] != '\0'; ++j) memberAddresses[0][j] = exampleAddress1[j];
//
//    while (true) {
//        // Menu display
//        cout << "\nLibrary Management System\n";
//        cout << "1. Display Books\n";
//        cout << "2. Display Members\n";
//        cout << "3. Borrow Book\n";
//        cout << "4. Return Book\n";
//        cout << "5. Search Book\n";
//        cout << "6. Display Overdue Fines\n";
//        cout << "7. Exit\n";
//        cout << "Enter your choice: ";
//
//        int choice;
//        cin >> choice;
//
//        if (choice == 1) {
//            // Display books
//            cout << "\nBooks in Library:\n";
//            for (int i = 0; i < TOTAL_BOOKS; ++i) {
//                if (bookTitles[i][0] != '\0') {
//                    cout << "Title: " << bookTitles[i] << ", Author: " << bookAuthors[i]
//                        << ", Genre: " << bookGenres[i] << ", ISBN: " << bookISBNs[i]
//                        << ", Available: " << (bookAvailability[i] ? "Yes" : "No")
//                        << ", Year: " << bookPublicationYear[i] << endl;
//                }
//            }
//        }
//        else if (choice == 2) {
//            // Display members
//            cout << "\nLibrary Members:\n";
//            for (int i = 0; i < TOTAL_MEMBERS; ++i) {
//                if (memberNames[i][0] != '\0') {
//                    cout << "Name: " << memberNames[i] << ", Member ID: " << memberIDs[i]
//                        << ", Age: " << memberAges[i] << ", Address: " << memberAddresses[i]
//                        << ", Borrowed Books: ";
//                    for (int j = 0; j < borrowedCount[i]; ++j) {
//                        cout << bookTitles[borrowedBooks[i][j]] << " ";
//                    }
//                    cout << endl;
//                }
//            }
//        }
//        else if (choice == 3) {
//            // Borrow book
//            cout << "Enter Member ID: ";
//            int memberID;
//            cin >> memberID;
//
//            cout << "Enter Book Title (single word): ";
//            char bookTitle[50];
//            cin >> bookTitle;
//
//            cout << "Enter Book Author: ";
//            char bookAuthor[50];
//            cin >> bookAuthor;
//
//            cout << "Enter Book Publication Year: ";
//            int bookYear;
//            cin >> bookYear;
//
//            int memberIndex = -1, bookIndex = -1;
//            for (int i = 0; i < TOTAL_MEMBERS; ++i) {
//                if (memberIDs[i] == memberID) {
//                    memberIndex = i;
//                    break;
//                }
//            }
//
//            for (int i = 0; i < TOTAL_BOOKS; ++i) {
//                bool match = true;
//                for (int j = 0; bookTitles[i][j] != '\0'; ++j) {
//                    if (bookTitles[i][j] != bookTitle[j]) {
//                        match = false;
//                        break;
//                    }
//                }
//                if (match) {
//                    bool authorMatch = true;
//                    for (int j = 0; bookAuthors[i][j] != '\0'; ++j) {
//                        if (bookAuthors[i][j] != bookAuthor[j]) {
//                            authorMatch = false;
//                            break;
//                        }
//                    }
//                    if (authorMatch && bookAvailability[i] && bookPublicationYear[i] == bookYear) {
//                        bookIndex = i;
//                        break;
//                    }
//                }
//            }
//
//            if (memberIndex != -1 && bookIndex != -1) {
//                if (borrowedCount[memberIndex] < MAX_BORROW) {
//                    bookAvailability[bookIndex] = false;
//                    borrowedBooks[memberIndex][borrowedCount[memberIndex]++] = bookIndex;
//                    borrowedDates[memberIndex][borrowedCount[memberIndex] - 1] = 1; // Assume day 1 for borrowing
//                    cout << "Book borrowed successfully.\n";
//                }
//                else {
//                    cout << "Member has already borrowed the maximum number of books.\n";
//                }
//            }
//            else {
//                cout << "Member or Book not found or book not available.\n";
//            }
//        }
//        else if (choice == 4) {
//            // Return book
//            cout << "Enter Member ID: ";
//            int memberID;
//            cin >> memberID;
//
//            cout << "Enter Book Title (single word): ";
//            char bookTitle[50];
//            cin >> bookTitle;
//
//            int memberIndex = -1, bookIndex = -1;
//            for (int i = 0; i < TOTAL_MEMBERS; ++i) {
//                if (memberIDs[i] == memberID) {
//                    memberIndex = i;
//                    break;
//                }
//            }
//
//            for (int i = 0; i < TOTAL_BOOKS; ++i) {
//                bool match = true;
//                for (int j = 0; bookTitles[i][j] != '\0'; ++j) {
//                    if (bookTitles[i][j] != bookTitle[j]) {
//                        match = false;
//                        break;
//                    }
//                }
//                if (match) {
//                    bookIndex = i;
//                    break;
//                }
//            }
//
//            if (memberIndex != -1 && bookIndex != -1) {
//                bool found = false;
//                for (int j = 0; j < borrowedCount[memberIndex]; ++j) {
//                    if (borrowedBooks[memberIndex][j] == bookIndex) {
//                        for (int k = j; k < borrowedCount[memberIndex] - 1; ++k) {
//                            borrowedBooks[memberIndex][k] = borrowedBooks[memberIndex][k + 1];
//                        }
//                        borrowedCount[memberIndex]--;
//                        bookAvailability[bookIndex] = true;
//                        cout << "Book returned successfully.\n";
//                        found = true;
//                        break;
//                    }
//                }
//                if (!found) {
//                    cout << "Book not found in the member's borrowed list.\n";
//                }
//            }
//            else {
//                cout << "Member or Book not found.\n";
//            }
//        }
//        else if (choice == 5) {
//            // Search book
//            cout << "Enter search query (single word title): ";
//            char query[50];
//            cin >> query;
//
//            cout << "Search Results:\n";
//            for (int i = 0; i < TOTAL_BOOKS; ++i) {
//                bool match = true;
//                for (int j = 0; bookTitles[i][j] != '\0'; ++j) {
//                    if (bookTitles[i][j] != query[j]) {
//                        match = false;
//                        break;
//                    }
//                }
//                if (match) {
//                    cout << "Title: " << bookTitles[i] << ", Author: " << bookAuthors[i]
//                        << ", Genre: " << bookGenres[i] << ", ISBN: " << bookISBNs[i]
//                        << ", Available: " << (bookAvailability[i] ? "Yes" : "No")
//                        << ", Year: " << bookPublicationYear[i] << endl;
//                }
//            }
//        }
//        else if (choice == 6) {
//            // Display overdue fines
//            cout << "\nOverdue Fines:\n";
//            for (int i = 0; i < TOTAL_MEMBERS; ++i) {
//                if (memberIDs[i] != 0) {
//                    int fine = 0;
//                    for (int j = 0; j < borrowedCount[i]; ++j) {
//                        int daysOverdue = borrowedDates[i][j] - 1;  // Assume the current date is day 30
//                        if (daysOverdue > MAX_OVERDUE_DAYS) {
//                            fine += (daysOverdue - MAX_OVERDUE_DAYS) * 5;
//                        }
//                    }
//                    overdueFines[i] = fine;
//                    cout << "Member " << memberNames[i] << " has a fine of: " << overdueFines[i] << endl;
//                }
//            }
//        }
//        else if (choice == 7) {
//            cout << "Exiting the system.\n";
//            break;
//        }
//        else {
//            cout << "Invalid choice. Please try again.\n";
//        }
//    }
//    int arr[6] = { 1,2,3,6,5,4 };
//    int temp;
//
//    temp = arr[0];
//    arr[0] = arr[5];
//    arr[5] = 0;
//
//    for (int i = 5; i > 1; i--)
//    {
//        arr[i] = arr[i - 1];
//    }
//    arr[1] = temp;
//    for (int i = 0; i < 6; i++)
//    {
//        cout << arr[i] << " ";
//    }
//
//    return 0;
//}
//////


//#include <iostream>
//using namespace std;
//
//int main()
//{
//    int arr[4] = { 1,22,111,23 };
//
//    for (int i = 0; i < 4; i++)
//    {
//        if (arr[i] / 10 >= 1 && arr[i] / 10 <= 10)
//        {
//            cout << arr[i] << " ";
//        }
//    }
//}
