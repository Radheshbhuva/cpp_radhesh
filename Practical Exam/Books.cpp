#include <iostream>
#include <string>
using namespace std;

class Book
{
public:
    string title;
    string author;
    int publishedYear;

    Book(const string &t = "", const string &a = "", int year = 0)
        : title(t), author(a), publishedYear(year) {}
};

int main()
{
    const int maxBooks = 100;
    Book books[maxBooks];
    int numberOfBooks;

    cout << "Enter the number of books ";
    cin >> numberOfBooks;
    cin.ignore();

    if (numberOfBooks > maxBooks)
    {
        cout << "Number of books exceeds the maximum limit. Setting to " << maxBooks << ".\n";
        numberOfBooks = maxBooks;
    }

    for (int i = 0; i < numberOfBooks; i++)
    {
        string title;
        string author;
        int publishedYear;

        cout << "Enter details for book " << (i + 1) << ":\n";
        cout << "Title: ";
        getline(cin, title);
        cout << "Author: ";
        getline(cin, author);
        cout << "Published Year: ";
        cin >> publishedYear;
        cin.ignore();

        books[i] = Book(title, author, publishedYear);
    }

    cout << "\nYou entered the following books:\n";
    for (int i = 0; i < numberOfBooks; i++)
    {
        cout << "Title: " << books[i].title
             << ", Author: " << books[i].author
             << ", Published Year: " << books[i].publishedYear << endl;
    }

    return 0;
}
