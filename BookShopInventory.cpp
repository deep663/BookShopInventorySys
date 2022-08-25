#include <iostream>
#include <cstring>
using namespace std;

int no_s_t = 0;
int no_us_t = 0;
int total_books = 0;

class Books
{
    char *title;
    char *author;
    char *publisher;
    int price, stock;

public:
    Books()
    {
        title = new char[30];
        author = new char[30];
        publisher = new char[30];
        price = 0;
        stock = 0;
    }

    ~Books()
    {
        delete title;
        delete author;
        delete publisher;
    }

    void getdata()
    {
        cin.ignore();
        cout << "\nEnter Author Name: ";
        cin.getline(author, 30);
        cout << "Enter Title: ";
        cin.getline(title, 30);
        cout << "Enter publisher: ";
        cin.getline(publisher, 30);
        cout << "Enter price: ";
        cin >> price;
        cout << "Enter stock: ";
        cin >> stock;
    }

    void updatePrice()
    {
        cout << "Current price: RS. " << price;
        cout << "\nEnter new price: ";
        cin >> price;
    }

    void display()
    {
        cout << "\n\tAuthor Name: " << author;
        cout << "\n\tTitle Name: " << title;
        cout << "\n\tPublisher Name: " << publisher;
        cout << "\n\tPrice: " << price;
        cout << "\n\tStock available: " << stock << endl;
    }

    int find(char *title1, char *author1)
    {
        if (strcmp(title, title1) == 0 && strcmp(author, author1) == 0)
            return 1;
        else
            return 0;
    }
    friend void buy(Books &a);
};

void buy(Books &a)
{
    int no_of_copies;
    cout << "\nEnter no. of copies required:";
    cin >> no_of_copies;
    if (no_of_copies <= a.stock)
    {
        cout << "\nNumber of entered copies is available to buy" << endl;
        cout << "Total Bill is : RS." << no_of_copies * a.price << endl;
        a.stock -= no_of_copies;
        no_s_t++;
    }
    else
    {
        cout << "\nRequired copies of the book is not available...";
        no_us_t++;
    }
    system("pause");
    system("CLS");
}

int main()
{
    int val = 0, ch;
    char author1[30], title1[30];
    Books B[100];

    do
    {
        cout << "\n******MENU*****\n";
        cout << " 1.Add new Book\n 2.Display Data\n 3.Buy a Book\n 4.Update Books price\n 5.Display statistic\n 6.Exit" << endl;
        cout << "Enter your choice:";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "\nEnter details of book" << endl;
            B[total_books++].getdata();
            break;
        case 2:
            cout << "Available books are:\n";
            for (int i = 0; i < total_books; i++)
            {
                cout << "-----------------------------------\n";
                cout << "Details of book  " << i + 1 << "  is ";
                B[i].display();
            }
            break;
        case 3:
            cin.ignore();
            cout << "\nEnter Title: ";
            cin.getline(title1, 50);
            cout << "Enter Author Name: ";
            cin.getline(author1, 50);

            for (int i = 0; i < total_books; i++)
            {
                val = B[i].find(title1, author1);
                if (val == 1)
                {
                    buy(B[i]);
                    break;
                }
            }
            if (val == 0)
            {
                cout << "\nBook is not available\n";
            }
            break;
        case 4:
            cin.ignore();
            cout << "\nEnter Title: ";
            cin.getline(title1, 50);
            cout << "Enter Author Name: ";
            cin.getline(author1, 50);

            for (int i = 0; i < total_books; i++)
            {
                val = B[i].find(title1, author1);
                if (val == 1)
                {
                    B[i].updatePrice();
                    break;
                }
            }
            if (val == 0)
            {
                cout << "\nBook is not available\n";
            }
            break;
        case 5:
            cout << "The number of successful transactions are: " << no_s_t << endl;
            cout << "The number of unsuccessful transactions are: " << no_us_t << endl;
            break;
        default:
            cout << "\nInvalid Entry !!!!!\n";
            break;
        }
    } while (ch);

    return 0;
}