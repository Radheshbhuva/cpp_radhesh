#include <iostream>
#include <string>

using namespace std;

const int MAX_ITEMS = 100;

class LibraryItem
{
protected:
    string title;
    string author;
    string dueDate;

public:
    LibraryItem(string t, string a) : title(t), author(a), dueDate("") {}

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getDueDate() const { return dueDate; }

    void setTitle(string newTitle) { title = newTitle; }
    void setAuthor(string newAuthor) { author = newAuthor; }
    void setDueDate(string newDueDate) { dueDate = newDueDate; }

    virtual ~LibraryItem() {}
};

class Book : public LibraryItem
{
private:
    string isbn;

public:
    Book(string t, string a, string i) : LibraryItem(t, a), isbn(i) {}

    void checkOut() override
    {
        dueDate = "2024-10-01";
        cout << "Checked out Book: " << title << endl;
    }

    void returnItem() override
    {
        dueDate = "";
        cout << "Returned Book: " << title << endl;
    }

    void displayDetails() const override
    {
        cout << "Book - Title: " << title << ", Author: " << author
             << ", ISBN: " << isbn << ", Due Date: " << dueDate << endl;
    }
};

class DVD : public LibraryItem
{
private:
    int duration;

public:
    DVD(string t, string a, int d) : LibraryItem(t, a), duration(d) {}

    void checkOut() override
    {
        dueDate = "2024-10-01";
        cout << "Checked out DVD: " << title << endl;
    }

    void returnItem() override
    {
        dueDate = "";
        cout << "Returned DVD: " << title << endl;
    }

    void displayDetails() const override
    {
        cout << "DVD - Title: " << title << ", Author: " << author
             << ", Duration: " << duration << " mins, Due Date: " << dueDate << endl;
    }
};

class Magazine : public LibraryItem
{
private:
    int issueNumber;

public:
    Magazine(string t, string a, int i) : LibraryItem(t, a), issueNumber(i) {}

    void checkOut() override
    {
        dueDate = "2024-10-01";
        cout << "Checked out Magazine: " << title << endl;
    }

    void returnItem() override
    {
        dueDate = "";
        cout << "Returned Magazine: " << title << endl;
    }

    void displayDetails() const override
    {
        cout << "Magazine - Title: " << title << ", Author: " << author
             << ", Issue Number: " << issueNumber << ", Due Date: " << dueDate << endl;
    }
};

class Library
{
private:
    LibraryItem *libraryItems[MAX_ITEMS];
    int itemCount;

public:
    Library() : itemCount(0) {}

    void addItem(LibraryItem *item)
    {
        if (itemCount < MAX_ITEMS)
        {
            libraryItems[itemCount++] = item;
        }
        else
        {
            cout << "Library is full, cannot add more items!" << endl;
        }
    }

    void checkOutItem(const string &title)
    {
        for (int i = 0; i < itemCount; ++i)
        {
            if (libraryItems[i]->getTitle() == title)
            {
                libraryItems[i]->checkOut();
                return;
            }
        }
        cout << "Item not found!" << endl;
    }

    void returnItem(const string &title)
    {
        for (int i = 0; i < itemCount; ++i)
        {
            if (libraryItems[i]->getTitle() == title)
            {
                libraryItems[i]->returnItem();
                return;
            }
        }
        cout << "Item not found!" << endl;
    }

    void displayItems() const
    {
        for (int i = 0; i < itemCount; ++i)
        {
            libraryItems[i]->displayDetails();
        }
    }

    ~Library()
    {
        for (int i = 0; i < itemCount; ++i)
        {
            delete libraryItems[i];
        }
    }
};

void menu()
{
    cout << "Library Management System Menu:" << endl;
    cout << "1. Add Book" << endl;
    cout << "2. Add DVD" << endl;
    cout << "3. Add Magazine" << endl;
    cout << "4. Check Out Item" << endl;
    cout << "5. Return Item" << endl;
    cout << "6. Display All Items" << endl;
    cout << "7. Exit" << endl;
}

int main()
{
    Library library;
    int choice;

    while (true)
    {
        menu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            string title, author, isbn;
            cout << "Enter Book Title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter Author: ";
            getline(cin, author);
            cout << "Enter ISBN: ";
            getline(cin, isbn);
            cout << " << Book Added >> " << endl
                 << endl;
            library.addItem(new Book(title, author, isbn));
        }
        else if (choice == 2)
        {
            string title, author;
            int duration;
            cout << "Enter DVD Title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter Author: ";
            getline(cin, author);
            cout << "Enter Duration (in minutes): ";
            cin >> duration;
            cout << " << DVD Added >> " << endl
                 << endl;
            if (duration < 0)
            {
                cout << "Duration cannot be negative." << endl
                     << endl;
            }
            else
            {
                library.addItem(new DVD(title, author, duration));
            }
        }
        else if (choice == 3)
        {
            string title, author;
            int issueNumber;
            cout << "Enter Magazine Title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter Author: ";
            getline(cin, author);
            cout << "Enter Issue Number: ";
            cin >> issueNumber;
            cout << " << Magazine Added >> " << endl
                 << endl;
            if (issueNumber < 0)
            {
                cout << "Issue number cannot be negative." << endl
                     << endl;
            }
            else
            {
                library.addItem(new Magazine(title, author, issueNumber));
            }
        }
        else if (choice == 4)
        {
            string title;
            cout << "Enter the title of the item to check out: ";
            cin.ignore();
            getline(cin, title);
            library.checkOutItem(title);
        }
        else if (choice == 5)
        {
            string title;
            cout << "Enter the title of the item to return: ";
            cin.ignore();
            getline(cin, title);
            library.returnItem(title);
        }
        else if (choice == 6)
        {
            library.displayItems();
        }
        else if (choice == 7)
        {
            break;
        }
        else
        {
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
