
#include <iostream>

using namespace std;

const int maxBooks=500;

struct BOOK {


    int isbn;
    string title;
    string author;
    string genre;
    double price;
    int stock;

};


  BOOK books[maxBooks];
  int numBooks =0;

void addNewBook()
{


    if(numBooks>=maxBooks)

   {

    cout<<"Error: Maximum number of books reached."<<endl;

    return ;
   }


   cout<<"==========Add new book=======  "<<endl;
   cout<<"------------------------------"<<endl;


    cout<<"Enter ISBN = ";
    cin>>books[numBooks].isbn;

    cout<<"Enter Title = ";
    cin.ignore();
    getline(cin,books[numBooks].title);


    cout<<"Enter Author = ";
    getline(cin,books[numBooks].author);


    cout<<"Enter Genre = ";
    getline(cin,books[numBooks].genre);


    cout<<"Enter Price = ";
    cin>>books[numBooks].price;


    cout<<"Enter Stock = ";
    cin>>books[numBooks].stock;


    numBooks++;
    cout<<"Book added successfully"<<endl;
}





void displayAllBooks()
{


    if(numBooks==0)
        {
        cout<<"No books available in inventory."<<endl;
        return;
        }

    cout<<"===== All Books ====="<<endl;
    cout<<"---------------------"<<endl;
    for(int i=0;i<numBooks;++i)
        {
        cout<<"ISBN= "<<books[i].isbn<<endl;
        cout<<"Title= "<<books[i].title<<endl;
        cout<<"Author= "<<books[i].author<<endl;
        cout<<"Genre= "<<books[i].genre<<endl;
        cout<<"Price= "<<books[i].price<<" $"<<endl;
        cout<<"Stock= "<<books[i].stock<<endl<<endl;
        }
}

void updateStock()
{

   cout<<"====== Update Stock ======"<<endl;
   cout<<"--------------------------"<<endl;

   if(numBooks==0) {
        cout<<"No books available in inventory."<<endl;
        return;
    }

    int updateISBN;
    cout<<"Enter the ISBN of the book to update stock = ";
    cin>>updateISBN;

    for(int i=0;i<numBooks;++i) {
        if (books[i].isbn==updateISBN)
            {
            int newStock;
            cout<<"Enter the new stock level for book '"<<books[i].title<<"' = ";
            cin>>newStock;
            if(newStock<0)
            {
                cout<<"Error: Stock level cannot be negative."<<endl;
                return;
            }
            books[i].stock = newStock;
            cout<<"Stock level for book '"<<books[i].title<<"' updated successfully."<<endl;
            return;
        }
    }

    cout<<"Book with ISBN "<<updateISBN<<" not found."<<endl;
}






void processSale()
{

    cout<<"====== Process Book sales ====="<<endl;
    cout<<"-------------------------------"<<endl;

if(numBooks==0)
    {
        cout<<"No books available in inventory."<<endl;
        return;
    }

    int saleISBN,saleQuantity;
    cout<<"Enter the ISBN of the book sold= ";
    cin>>saleISBN;

    for(int i=0;i<numBooks;++i) {
        if(books[i].isbn==saleISBN)
         {
            cout<<"Enter the quantity sold for book '"<<books[i].title<<"' = ";
            cin>>saleQuantity;
            if(saleQuantity< 0 ||saleQuantity>books[i].stock) {
                cout<< "Error: Invalid quantity." << endl;
                return;
            }
            double totalCost=saleQuantity * books[i].price;
            books[i].stock -= saleQuantity;
            cout<<"Total cost of sale= "<<totalCost<<"$ "<<endl;
            cout<<"Remaining stock for book  Favourite book = "<<books[i].stock<<endl;
            return;


        }
    }

    cout<<"Book with ISBN "<<saleISBN<<" not found."<<endl;
}


void generateSalesReport()
{
   if(numBooks==0) {
        cout<<"No books available in inventory."<<endl;
        return;
    }

    double totalSales=0.0;
    int salesCount=0;

    cout<<"===== Sales Report ====="<<endl;
    cout<<"-------------------------"<<endl;

    for(int i=0;i<numBooks;++i)
    {
        if (books[i].stock<maxBooks)
            {
            double salesAmount=(maxBooks-books[i].stock)*books[i].price;
            cout<<"Book= "<<books[i].title<<endl;
            cout<<"Quantity Sold= "<<maxBooks-books[i].stock<<endl;
            cout<<"Sales Amount= "<<salesAmount<<"$"<<endl<<endl;
            totalSales+=salesAmount;
            salesCount++;
        }
    }

    if(salesCount==0)
        {
        cout<<"No sales were made."<<endl;
        }
    else

      {
        cout<<"Total Sales= "<<totalSales<<" $"<<endl;
        cout<<endl;
      }
}

int main()
{
    int choice ;
while (true) {
    cout<<"===== Bookstore Inventory Management System ====="<<endl;
    cout<<"--------------------------------------------------"<<endl;
    cout<<"1.Add New Book"<<endl;;
    cout<<"2.Display All Books"<<endl;
    cout<<"3.Update Stock"<<endl;
    cout<<"4.Process Sale"<<endl;
    cout<<"5.Generate Sales Report"<<endl;
    cout<<"6.Exit Program"<<endl;
    cout<<"Enter your choice = ";
    cin>> choice;


    switch (choice)
    {
            case 1:
                addNewBook();

            break;

            case 2:
                displayAllBooks();

            break;

            case 3:
                updateStock();
            break;

            case 4:
                processSale();
            break;

            case 5:
                generateSalesReport();
            break;

            case 6:
                cout <<"Exiting program...."<<endl;
            break;

            default:
                cout <<"Invalid choice!!!"<<endl;
        }


}

    return 0;
}
