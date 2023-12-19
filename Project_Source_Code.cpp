#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <conio.h>
#include <iterator>
using namespace std;
// ------------------------------------------------------------------------------------------------------------------
class Review_Node
{
public:
    string reviewer_name;
    string review_content;
    Review_Node* next;

    // parameterized constructor
    Review_Node(string reviewer_name, string review_content)
    {
        this->reviewer_name = reviewer_name;
        this->review_content = review_content;
        this->next = NULL;
    }
};
//
//
// ------------------------------------------------------------------------------------------------------------------

class Chapter_Node
{
public:
    string chapter_title;
    string chapter_content;
    Chapter_Node* next;

    // parameterized constructor
    Chapter_Node(string chapter_title, string chapter_content)
    {
        this->chapter_title = chapter_title;
        this->chapter_content = chapter_content;
        this->next = NULL;
    }
};
//
//
// ------------------------------------------------------------------------------------------------------------------
class Book
{
public:
    int book_ID;
    string book_title;
    string book_author;
    string book_genre;

    int book_sales;
    int book_inventory;
    int book_price;

    Book* left;
    Book* right;
    int height;

    Review_Node* review_head;
    Chapter_Node* chapter_head;

    static int key_ID;

    // default constructor
    Book()
    {
        left = NULL;
        right = NULL;
        this->book_ID = ++key_ID;
        height = 0;
        review_head = NULL;
        chapter_head = NULL;
    }
    bool operator==(const Book& other) const
    {
        return (book_title == other.book_title) &&
            (book_author == other.book_author) &&
            (book_genre == other.book_genre) &&
            (book_sales == other.book_sales) &&
            (book_inventory == other.book_inventory) &&
            (book_price == other.book_price);
    }
    Book(const Book& other)
        : book_title(other.book_title), book_author(other.book_author), book_genre(other.book_genre),
        book_sales(other.book_sales), book_inventory(other.book_inventory), book_price(other.book_price),
        left(NULL), right(NULL), height(other.height)
    {
    }
    // parameterized constructor
    Book(string book_title, string book_author, string book_genre, int book_sales, int book_inventory, int book_price)
    {
        left = NULL;
        right = NULL;
        this->book_ID = ++key_ID;
        height = 0;
        review_head = NULL;
        chapter_head = NULL;

        this->book_title = book_title;
        this->book_author = book_author;
        this->book_genre = book_genre;
        this->book_sales = book_sales;
        this->book_inventory = book_inventory;
        this->book_price = book_price;
    }
    string getTitle() const
    {
        return book_title;
    }

    string getAuthor() const
    {
        return book_author;
    }

    // // parameterized constructor
    // Book (Book& book)
    // {
    //     *this = book;
    // }

    // add review to Review_Node Linked List
    void add_Review(string reviewer_name, string review_content)
    {
        Review_Node* new_review = new Review_Node(reviewer_name, review_content);

        if (review_head == NULL)
        {
            review_head = new_review;
        }

        else
        {
            Review_Node* temp = review_head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_review;
        }
    }
    string getGenre() const
    {
        return book_genre;
    }

    // add chapter preview to Chapter_Node Linked List
    void add_Chapter(string chapter_title, string chapter_content)
    {
        Chapter_Node* new_chapter = new Chapter_Node(chapter_title, chapter_content);

        if (chapter_head == NULL)
        {
            chapter_head = new_chapter;
        }

        else
        {
            Chapter_Node* temp = chapter_head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_chapter;
        }
    }

    // display reviews for book from Review_Node Linked List
    void display_Reviews()
    {
        Review_Node* temp = review_head;

        if (temp == NULL)
        {
            cout << "This book currently has no reviews!" << endl;
        }

        else
        {
            while (temp != NULL)
            {
                cout << "Reviwer Name  : " << temp->reviewer_name << endl;
                cout << "Review Content: " << temp->review_content << endl
                    << endl;
                temp = temp->next;
            }
        }
    }

    // display chapter previews for book from Chapter_Node Linked List
    void display_Chapters()
    {
        Chapter_Node* temp = chapter_head;

        if (temp == NULL)
        {
            cout << "Chapter previews are unavailable for this book!" << endl;
        }

        else
        {
            while (temp != NULL)
            {
                cout << "Chapter Title  : " << temp->chapter_title << endl;
                cout << "Chapter Content: " << temp->chapter_content << endl
                    << endl;
                temp = temp->next;
            }
        }
    }

    // display book details
    void display_Book_Details()
    {
        cout << "Book Title : " << book_title << endl;
        cout << "Book Author: " << book_author << endl;
        cout << "Book Genre : " << book_genre << endl;
        cout << "Book Price : Rs. " << book_price << endl << endl;

        // ask to preview book chapters
        char input;
        Chapter_Node* currentChapter = chapter_head;
        cout << "To preview book chapters enter y : ";
        cin  >> input;
        if (input == 'y' || input == 'Y')
        {
            while (currentChapter)
            {
                cout << "Chapter: " << currentChapter->chapter_title  << endl;
                cout << "Content: " << currentChapter->chapter_content << endl;
                currentChapter = currentChapter->next;
            }
        }

        else
        {
            return;
        }
    }
};
int Book::key_ID = 0;
//
//
// ------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------
class User
{
private:
    int user_ID;
    string user_name;
    string user_password;
    list<Book> bookPreference;
    int user_age;
    static int key_ID;

public:
    // parameterized constructor
    User(string user_name, string user_password, int user_age)
    {
        this->user_ID = ++key_ID;
        this->user_name = user_name;
        this->user_password = user_password;
        this->user_age = user_age;
    }
    User(string user_name, string user_password, int user_age, list<Book> bookPreference)
    {
        this->user_age = user_age;
        this->user_name = user_name;
        this->bookPreference = bookPreference;
    }
    // getters
    int getUserID() const
    {
        return user_ID;
    }

    string getUserName() const
    {
        return user_name;
    }

    string getUserPassword() const
    {
        return user_password;
    }

    void addBookPreference(const Book book)
    {
        bookPreference.push_back(book);
    }

    string getName() const
    {
        return user_name;
    }

    int getAge() const
    {
        return user_age;
    }

    const list<Book>& getBookPreferences() const
    {
        return bookPreference;
    }
};
int User::key_ID = -1;
//
//
// ------------------------------------------------------------------------------------------------------------------
class Admin
{
private:
    int admin_ID;
    string admin_name;
    string admin_password;
    static int key_ID;

public:
    // parameterized constructor
    Admin(string admin_name, string admin_password)
    {
        this->admin_ID = ++key_ID;
        this->admin_name = admin_name;
        this->admin_password = admin_password;
    }

    // getters
    int getAdminID() const
    {
        return admin_ID;
    }

    string getAdminName() const
    {
        return admin_name;
    }

    string getAdminPassword() const
    {
        return admin_password;
    }
};
int Admin::key_ID = -1;
//
//
// ------------------------------------------------------------------------------------------------------------------
class BookStore
{
public:
    Book* root;
    int num_books;

    // for purchasing books
    stack<Book*> cart;

    // for user login authentification
    string admin_name;
    string admin_password;
    vector<string> username_hash;
    vector<string> password_hash;
    int hash_mod_value;

    // for maintaining heap acc. to best sales
    vector<Book> best_selling_books;

    // default constructor
    BookStore(vector<User>& u, Admin& a, int hash_mod_value)
    {
        cout << "Bookstore Constructor" << endl;
        // initialize data members
        this->root = NULL;
        this->num_books = 0;
        this->hash_mod_value = hash_mod_value;

        // initialize admin_name and admin_password
        this->admin_name = a.getAdminName();
        this->admin_password = a.getAdminPassword();

        // resize password vector to value of hash mod value
        password_hash.resize(hash_mod_value);

        for (int i = 0; i < u.size(); i++)
        {
            User temp = u[i];

            // insert username at i-th index of vector
            username_hash.push_back(temp.getUserName());

            // insert password at hashed index of vector
            int hash_index = find_hash_index(username_hash.size() - 1);

            if (password_hash[hash_index] == "")
            {
                password_hash[hash_index] = temp.getUserPassword();
            }

            else
            {
                username_hash.pop_back();
                cout << "User could not be inserted in hash table" << endl;
            }
        }

        // cout << "-----Admins----" << endl;
        // cout << "Admin Name: " << admin_name << endl;
        // cout << "Password  : " << admin_password << endl;
        // cout << endl
        //     << endl;

        // cout << "-----Usernames----" << endl;
        // for (int i = 0; i < username_hash.size(); i++)
        // {
        //     cout << "Index: " << i << "  ";
        //     cout << "Username : " << username_hash[i] << endl;
        // }
        // cout << endl
        //     << endl;

        // cout << "-----Passwords----" << endl;
        // for (int i = 0; i < password_hash.size(); i++)
        // {
        //     cout << "Index: " << i << "  ";
        //     cout << "Password : " << password_hash[i] << endl;
        // }
        // cout << endl
        //     << endl;
    }

    // hash function
    // K * 19 mod N
    // K: user-ID
    // N: size of hash table
    int find_hash_index(int user_ID)
    {
        return (user_ID * 19 % hash_mod_value);
    }

    bool user_Login(string username, string password)
    {
        // search username
        int user_ID = -1;

        for (int i = 0; i < username_hash.size(); i++)
        {
            if (username == username_hash[i])
            {
                user_ID = i;
                break;
            }
        }

        if (user_ID == -1)
        {
            cout << "Entered username not found in database!" << endl;
            return false;
        }

        else
        {
            int hash_index = find_hash_index(user_ID);

            if (password == password_hash[hash_index])
            {
                cout << "Login successful!" << endl;
                return true;
            }

            else
            {
                cout << "Incorrect password entered!" << endl
                    << endl;
                return false;
            }
        }
    }

    bool admin_Login(string admin_name, string password)
    {
        if (this->admin_name == admin_name && this->admin_password == password)
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    // for maintaining priority queue (max heap)  --- index equals book-ID minus 1
    // book-ID start from 1
    // index is 0th index of vector for first call
    // index is 1st index of vector for second call, and so on...
    void insert_Max_Heap(vector<Book>& best_selling_books, Book& book_insert, int index)
    {
        index = index - 1;
        best_selling_books[index] = book_insert;

        int i = index;

        while (i > 0)
        {
            int parent_index = (i - 1) / 2;

            Book temp_1 = best_selling_books[parent_index];
            Book temp_2 = best_selling_books[i];

            if (temp_1.book_sales < temp_2.book_sales)
            {
                Book temp_3 = best_selling_books[parent_index];
                best_selling_books[parent_index] = best_selling_books[i];
                best_selling_books[i] = temp_3;
                i = parent_index;
            }

            else
            {
                return;
            }
        }
    }

    // for heapifying vector that stores all books ---heap sort bases on sales data
    void max_Heapify(int index, int size)
    {
        int largest_index = index;

        int left_child  = 2 * index + 1;
        int right_child = 2 * index + 2;

        if (left_child < size && best_selling_books[largest_index].book_sales < best_selling_books[left_child].book_sales)
        {
            largest_index = left_child;
        }

        if (right_child < size && best_selling_books[largest_index].book_sales < best_selling_books[right_child].book_sales)
        {
            largest_index = right_child;
        }

        if (largest_index != index)
        {
            Book temp_3 = best_selling_books[index];
            best_selling_books[index] = best_selling_books[largest_index];
            best_selling_books[largest_index] = temp_3;
            max_Heapify(largest_index, size);
        }
    }

    // sort vector using heap sort (ascending order) based on sales data
    void heapify_Best_Sellers()
    {
        vector <vector<Book>> temp = levelOrderTraversalByGenre();

        for (int i = 0; i < temp.size(); i++)
        {
           for (int j = 0; j < temp[i].size(); j++)
            {
                best_selling_books.push_back(temp[i][j]);
            }
        }

        // heapify array / tree starting from last non-leaf node
        // and work backwards till root node i.e. arr[0]
        for (int i = (best_selling_books.size() - 1 / 2) - 1; i >= 0; i--)
        {
            max_Heapify (i, best_selling_books.size());
        }

        // heap sort vector using max_heapify
        for (int i = best_selling_books.size() - 1; i >= 0; i--)
        {
            // 0 because heapify will now be applied to array from index 0 to new last index minus 1
            // index 0 holds next maximum value of shortened array after swapping
            // the new last index will hold next maximum value of shortened array
            swap(best_selling_books[0], best_selling_books[i]);
            max_Heapify(0, i);
        }

        cout << "-----Best Sellers-----" << endl << endl;
        for (int i = best_selling_books.size() - 1; i >= 0; i--)
        {
            Book temp = best_selling_books[i];
            cout << "Book Title: " << temp.book_title << endl;
            cout << "Book Sales: " << temp.book_sales << endl;
            cout << "Book Price: Rs. " << temp.book_price << endl;
        }
        cout << endl << endl;

        //display_Best_Sellers();
    }

    void display_Best_Sellers ()
    {
        // read vector from right to left
        for (int i = 0; i < best_selling_books.size(); i++)
        {
            for (int j = 0; j < best_selling_books.size() - 1 - i; j++)
            {
                if (best_selling_books[j].book_sales > best_selling_books[j+1].book_sales)
                {
                    swap(best_selling_books[j], best_selling_books[j+1]);
                }
            }
        }
        cout << "-----Best Sellers-----" << endl
            << endl;
        for (int i = best_selling_books.size() - 1; i >= 0; i--)
        {
            Book temp = best_selling_books[i];
            cout << "Book Title: " << temp.book_title << endl;
            cout << "Book Sales: " << temp.book_sales << endl;
            cout << "Book Price: Rs. " << temp.book_price << endl;
        }
        cout << endl << endl;
    }

    int getHeight(Book* parent)
    {
        if (parent == NULL)
            return 0;
        return parent->height;
    }

    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    int getBalanceFactor(Book* parent)
    {
        if (parent == NULL)
            return 0;
        return (getHeight(parent->left) - getHeight(parent->right));
    }

    Book* rightRotation(Book* parent)
    {
        Book* tempL = parent->left;
        Book* tempR = tempL->right;
        tempL->right = parent;
        parent->left = tempR;
        tempL->height = max(getHeight(tempL->left), getHeight(tempL->right)) + 1;
        parent->height = max(getHeight(parent->left), getHeight(parent->right)) + 1;
        return tempL;
    }

    Book* leftRotation(Book* parent)
    {
        Book* tempR = parent->right;
        Book* tempL = tempR->left;
        tempR->left = parent;
        parent->right = tempL;
        tempR->height = max(getHeight(tempR->left), getHeight(tempR->right)) + 1;
        parent->height = max(getHeight(parent->left), getHeight(parent->right)) + 1;
        return tempR;
    }

    void insertChapter(Book* book, const string& chapter_title, const string& chapter_content)
    {
        Chapter_Node* new_Chapter = new Chapter_Node(chapter_title, chapter_content);
        new_Chapter->next = book->chapter_head;
        book->chapter_head = new_Chapter;
    }

    void insertion(string book_title, string book_author, string book_genre, int book_sales, int book_inventory, int book_price, string chapter_title, string chapter_content)
    {
        root = insertion(root, book_title, book_author, book_genre, book_sales, book_inventory, book_price, chapter_title, chapter_content);
    }

    Book* insertion(Book* parent, string book_title, string book_author, string book_genre, int book_sales, int book_inventory, int book_price, string chapter_title, string chapter_content)
    {
        if (parent == NULL)
        {
            Book* new_Book = new Book(book_title, book_author, book_genre, book_sales, book_inventory, book_price);
            insertChapter(new_Book, chapter_title, chapter_content);

            return new_Book;
        }

        if (book_title < parent->book_title)
        {
            parent->left = insertion(parent->left, book_title, book_author, book_genre, book_sales, book_inventory, book_price, chapter_title, chapter_content);
        }

        else if (book_title > parent->book_title)
        {
            parent->right = insertion(parent->right, book_title, book_author, book_genre, book_sales, book_inventory, book_price, chapter_title, chapter_content);
        }

        parent->height = 1 + max(getHeight(parent->left), getHeight(parent->right));
        int BF = getBalanceFactor(parent);

        // Left Left Case
        if (BF > 1 && book_title < parent->left->book_title)
        {
            return rightRotation(parent);
        }
        // Right Right Case
        if (BF < -1 && book_title > parent->right->book_title)
        {
            return leftRotation(parent);
        }
        // Left Right Case
        if (BF > 1 && book_title > parent->left->book_title)
        {
            parent->left = leftRotation(parent->left);
            return rightRotation(parent);
        }
        // Right Left Case
        if (BF < -1 && book_title < parent->right->book_title)
        {
            parent->right = rightRotation(parent->right);
            return leftRotation(parent);
        }

        num_books++;
        return parent;
    }

    Book* searchBook(const string& bookTitle)
    {
        return searchBook(root, bookTitle);
    }

    Book* searchBook(Book* parent, const string& bookTitle)
    {
        if (parent == NULL || parent->book_title == bookTitle)
        {
            return parent;
        }

        if (bookTitle < parent->book_title)
        {
            return searchBook(parent->left, bookTitle);
        }
        else
        {
            return searchBook(parent->right, bookTitle);
        }
    }

    void updateBook(const string& oldTitle, const string& newTitle, const string& newAuthor, const string& newGenre)
    {
        root = updateBook(root, oldTitle, newTitle, newAuthor, newGenre);
    }

    Book* updateBook(Book* parent, const string& oldTitle, const string& newTitle, const string& newAuthor, const string& newGenre)
    {
        // Perform regular BST search to find the book to update
        if (parent == NULL)
        {
            return parent; // Book not found
        }

        if (oldTitle < parent->book_title)
        {
            parent->left = updateBook(parent->left, oldTitle, newTitle, newAuthor, newGenre);
        }
        else if (oldTitle > parent->book_title)
        {
            parent->right = updateBook(parent->right, oldTitle, newTitle, newAuthor, newGenre);
        }
        else
        {
            // Book with the given title found, update its data
            parent->book_title = newTitle;
            parent->book_author = newAuthor;
            parent->book_genre = newGenre;
        }

        // Update height
        parent->height = 1 + max(getHeight(parent->left), getHeight(parent->right));

        // Update balance factor
        int balanceFactor = getBalanceFactor(parent);

        // Perform rotations to maintain balance
        // Left Left Case
        if (balanceFactor > 1 && getBalanceFactor(parent->left) >= 0)
        {
            return rightRotation(parent);
        }
        // Left Right Case
        if (balanceFactor > 1 && getBalanceFactor(parent->left) < 0)
        {
            parent->left = leftRotation(parent->left);
            return rightRotation(parent);
        }
        // Right Right Case
        if (balanceFactor < -1 && getBalanceFactor(parent->right) <= 0)
        {
            return leftRotation(parent);
        }
        // Right Left Case
        if (balanceFactor < -1 && getBalanceFactor(parent->right) > 0)
        {
            parent->right = rightRotation(parent->right);
            return leftRotation(parent);
        }

        return parent;
    }

    void deleteBook(const string& bookTitle)
    {
        root = deleteBook(root, bookTitle);
    }

    Book* deleteBook(Book* parent, const string& bookTitle)
    {
        if (parent == NULL)
        {
            return parent; // Book not found
        }

        if (bookTitle < parent->book_title)
        {
            parent->left = deleteBook(parent->left, bookTitle);
        }
        else if (bookTitle > parent->book_title)
        {
            parent->right = deleteBook(parent->right, bookTitle);
        }
        else
        {
            // Book with the given title found
            if (parent->left == NULL || parent->right == NULL)
            {
                // Node with only one child or no child
                Book* temp = (parent->left != NULL) ? parent->left : parent->right;

                if (temp == NULL)
                {
                    // No child case
                    temp = parent;
                    parent = NULL;
                }
                else
                {
                    // One child case
                    *parent = *temp; // Copy the contents of the non-empty child
                }

                delete temp;
            }
            else
            {
                // Node with two children
                Book* successor = findMin(parent->right); // Find the in-order successor
                parent->book_title = successor->book_title;
                parent->right = deleteBook(parent->right, successor->book_title);
            }
        }

        if (parent == NULL)
        {
            return parent; // Book not found
        }

        // Update height and balance factor
        parent->height = 1 + max(getHeight(parent->left), getHeight(parent->right));
        int balanceFactor = getBalanceFactor(parent);

        // Perform rotations to maintain balance
        // Left Left Case
        if (balanceFactor > 1 && getBalanceFactor(parent->left) >= 0)
        {
            return rightRotation(parent);
        }
        // Left Right Case
        if (balanceFactor > 1 && getBalanceFactor(parent->left) < 0)
        {
            parent->left = leftRotation(parent->left);
            return rightRotation(parent);
        }
        // Right Right Case
        if (balanceFactor < -1 && getBalanceFactor(parent->right) <= 0)
        {
            return leftRotation(parent);
        }
        // Right Left Case
        if (balanceFactor < -1 && getBalanceFactor(parent->right) > 0)
        {
            parent->right = rightRotation(parent->right);
            return leftRotation(parent);
        }

        return parent;
    }

    Book* findMin(Book* node)
    {
        while (node->left != NULL)
        {
            node = node->left;
        }
        return node;
    }

    void purchase_Book(string book_title)
    {
        Book* book = searchBook(book_title);

        if (book != NULL)
        {
            book->display_Book_Details();

            cart.push(book);
            cout << "Book '" << book_title << "' added to the cart." << endl;
        }

        else
        {
            cout << "Book '" << book_title << "' not found in the inventory." << endl;
        }
    }

    void generateBill()
    {
        cout << "\n*** Bill ***\n";
        int totalAmount = 0;

        while (cart.empty() == false)
        {
            Book* book = cart.top();
            checkInventoryAlerts(book);
            cart.pop();
            cout << "Title: " << book->book_title << ", Price: " << book->book_price << endl;
            totalAmount += book->book_price;
        }

        cout << "\nTotal Amount: " << totalAmount << endl;

        while (cart.empty() == false)
        {
            cart.pop();
        }
    }

    void checkInventoryAlerts(Book* parent)
    {
        if (parent->book_inventory < 10)
        {
            cout << "Low stock alert for book '" << parent->book_title << "'. Inventory: " << parent->book_inventory << endl;
            cout << "Request has been sent to increase " << parent->book_title << " Inventory." << endl;
            parent->book_inventory += 10;
        }
        return;
    }

    vector<vector<Book>> levelOrderTraversalByGenre()
    {
        vector<vector<Book>> result;

        queue<Book*> levelOrderQueue;
        levelOrderQueue.push(root);

        while (levelOrderQueue.empty() == false)
        {
            int levelSize = levelOrderQueue.size();
            vector<Book> levelBooks;

            for (int i = 0; i < levelSize; ++i)
            {
                Book* current = levelOrderQueue.front();
                levelOrderQueue.pop();

                if (current != NULL)
                {
                    // If the current book has the same genre as the previous one, add it to the same level
                    if (levelBooks.empty() == false && current->book_genre == levelBooks.back().book_genre)
                    {
                        levelBooks.push_back(*current);
                    }

                    // If the genre changes, start a new level
                    else
                    {
                        if (levelBooks.empty() == false)
                        {
                            result.push_back(levelBooks);
                        }

                        levelBooks.clear();
                        levelBooks.push_back(*current);
                    }

                    // Enqueue the left and right children
                    if (current->left != NULL)
                    {
                        levelOrderQueue.push(current->left);
                    }

                    if (current->right != NULL)
                    {
                        levelOrderQueue.push(current->right);
                    }
                }
            }

            // Add the last level's books
            if (levelBooks.empty() == false)
            {
                result.push_back(levelBooks);
            }
        }
        return result;
    }

    void preOrderTraversal()
    {
        preOrderTraversal(root);
    }

    void preOrderTraversal(Book* parent)
    {
        if (parent == NULL)
            return;
        cout << parent->book_title << endl;
        preOrderTraversal(parent->left);
        preOrderTraversal(parent->right);
    }

    void inOrderTraversal()
    {
        inOrderTraversal(root);
    }

    void inOrderTraversal(Book* parent)
    {
        if (parent == NULL)
            return;
        inOrderTraversal(parent->left);
        cout << parent->book_title << endl;
        inOrderTraversal(parent->right);
    }

    int getNumBooks()
    {
        return num_books;
    }

    void salesInOrder(Book* parent, vector<Book*>* arr)
    {
        if (parent == NULL)
            return;
        inOrderTraversal(parent->left);
        arr->push_back(parent);
        inOrderTraversal(parent->right);
    }
};
class SocialNetwork
{
private:
    int numPeople;
    list<User>* users;
    list<string>* adjacencyList;
    vector<pair<string, int>> nameToIndex;

public:
    SocialNetwork(int numPeople) : numPeople(numPeople)
    {
        users = new list<User>[numPeople];
        adjacencyList = new list<string>[numPeople];
    }

    ~SocialNetwork()
    {
        delete[] users;
        delete[] adjacencyList;
    }

    void addUser(const User& user)
    {
        int index = userIndex(user);
        users[index].push_back(user);
    }

    void addFriendship(const User& user1, const User& user2)
    {
        int index1 = userIndex(user1);
        int index2 = userIndex(user2);

        adjacencyList[index1].push_back(user2.getName());
        adjacencyList[index2].push_back(user1.getName());
    }

    void printSocialNetwork()
    {
        for (int i = 0; i < numPeople; ++i)
        {
            cout << "Friends of " << this->userName(i) << " (" << i << "): ";
            copy(adjacencyList[i].begin(), adjacencyList[i].end(),
                ostream_iterator<string>(cout, " "));
            cout << endl;

            cout << "Book Preferences of " << userName(i) << ": ";
            const auto& preferences = users[i].front().getBookPreferences();
            for (const auto& book : preferences)
            {
                cout << book.getTitle() << " by " << book.getAuthor() << ", ";
            }
            cout << endl;
        }
    }

    vector<Book> getSocialBookRecommendations(const User& user)
    {
        int userIndex = findUserIndex(user);
        if (userIndex == -1)
        {
            cerr << "User not found in the social network." << endl;
            return {};
        }

        vector<Book> recommendations;
        const auto& userFriends = adjacencyList[userIndex];
        const auto& userPreferences = users[userIndex].front().getBookPreferences();

        // Iterate through each friend of the user
        for (const auto& friendName : userFriends)
        {
            int friendIndex = findUserIndexByName(friendName);
            if (friendIndex != -1)
            {
                // Get the book preferences of the friend
                const auto& friendPreferences = users[friendIndex].front().getBookPreferences();

                // Find books that the friend likes but the user hasn't read
                for (const auto& book : friendPreferences)
                {
                    if (find(userPreferences.begin(), userPreferences.end(), book) == userPreferences.end())
                    {
                        recommendations.push_back(book);
                    }
                }
            }
        }

        return recommendations;
    }

private:
    int userIndex(const User& user)
    {
        for (size_t i = 0; i < nameToIndex.size(); ++i)
        {
            if (nameToIndex[i].first == user.getName())
            {
                return nameToIndex[i].second;
            }
        }

        // If the user is not found, assign a new index
        int newIndex = nameToIndex.size();
        nameToIndex.push_back({ user.getName(), newIndex });
        return newIndex;
    }

    int findUserIndex(const User& user) const
    {
        for (size_t i = 0; i < nameToIndex.size(); ++i)
        {
            if (nameToIndex[i].first == user.getName())
            {
                return nameToIndex[i].second;
            }
        }
        return -1;
    }

    int findUserIndexByName(const string& userName) const
    {
        for (size_t i = 0; i < nameToIndex.size(); ++i)
        {
            if (nameToIndex[i].first == userName)
            {
                return nameToIndex[i].second;
            }
        }
        return -1;
    }

    string userName(int index)
    {
        for (const auto& entry : nameToIndex)
        {
            if (entry.second == index)
            {
                return entry.first;
            }
        }

        // No match found
        cerr << "No user found for index " << index << endl;
        return ""; // This should not happen if the index is valid
    }

    /**/
};
//
//
// ------------------------------------------------------------------------------------------------------------------
//
//
// ------------------------------------------------------------------------------------------------------------------
int main()
{
    system("cls");

    // sample usernames for interacting as user
    vector<User> u;
    User u1("Test_User", "T-0000", 20);
    u.push_back(u1);
    User u2("Ibrahim", "I-4173", 20);
    u.push_back(u2);
    User u3("Rohit", "R-4545", 20);
    u.push_back(u3);
    User u4("Sayal", "S-4625", 20);
    u.push_back(u4);

    // sample admin name for interacting as admin
    Admin a1("Test_Admin", "A-0000");

    // initializing BookStore object with users vector and value for hash function for passwords
    BookStore store_1(u, a1, 12);

    store_1.root = store_1.insertion(store_1.root, "The Great Gatsby", "F. Scott Fitzgerald", "Classic", 43, 9, 800, "Chapter 1", "In my younger and more vulnerable years...");
    store_1.root = store_1.insertion(store_1.root, "To Kill A Mockingbird", "Harper Lee", "Fiction", 21, 6, 800, "Chapter-1", "About half way between West Egg and New York...");
    store_1.root = store_1.insertion(store_1.root, "1984", "George Orwell", "Fiction", 39, 8, 900, "Chapter-2", "About half way between West Egg and New York...");
    store_1.root = store_1.insertion(store_1.root, "The Catcher in the Rye", "J.D. Salinger", "Coming-of-age", 9, 7, 600, "Chapter 2", "About half way between West Egg and New York...");
    store_1.root = store_1.insertion(store_1.root, "Pride and Prejudice", "Jane Austen", "Romance", 53, 5, 1000, "Chapter 2", "About half way between West Egg and New York...");

    // initialize Book Object
    //store_1.inOrderTraversal(store_1.root);
    cout << "Continue..." << endl;
    getch();

    char choice;

Main_Menu:
    system("cls");
    fflush(stdin);

    cout << "----------Login Menu----------" << endl
        << endl;
    cout << "1 - Login as Admin" << endl;
    cout << "2 - Login as User " << endl;
    cout << "0 - End Program   " << endl;

    do
    {
        cout << endl
            << "Choice: ";
        cin >> choice;
    } while (choice < '0' || choice > '2');

    if (choice == '0')
        goto End_Program;

    if (choice == '1')
        goto Admin_Login;

    if (choice == '2')
        goto User_Login;

Admin_Login:
    do
    {
        system("cls");
        fflush(stdin);

        string username;
        string password;

        cout << "----------Admin Login Menu----------" << endl
            << endl;
        cout << "Enter username: ";
        getline(cin, username);

        cout << "Enter password: ";
        getline(cin, password);

        bool login_success = store_1.admin_Login(username, password);

        if (login_success == false)
        {
            getch();
            cout << "Press any key to try logging in again" << endl;
            goto Admin_Login;
        }

        else
            goto Admin_Menu;
    } while (choice != '0');

Admin_Menu:
    do
    {
        system("cls");
        fflush(stdin);

        cout << "----------Admin Interactive Menu----------" << endl
            << endl;
        cout << "1. Display Books" << endl;
        cout << "2. Search Book" << endl;
        cout << "3. Update Book" << endl;
        cout << "4. Delete Book" << endl;
        cout << "0. Log out" << endl;

        do
        {
            cout << endl
                << "Choice: ";
            cin >> choice;
        } while (choice < '0' || choice > '6');

        // log out
        if (choice == '0')
        {
            goto Main_Menu;
        }

        // display books
        if (choice == '1')
        {
            store_1.inOrderTraversal(store_1.root);
            getch();
        }

        // search books
        if (choice == '2')
        {
            fflush(stdin);
            string book_title;

            cout << "Enter book to be searched: ";
            getline(cin, book_title);
            Book* find_book = store_1.searchBook(book_title);

            if (find_book != NULL)
            {
                cout << "Book found in database!" << endl;
            }

            else
            {
                cout << "Book not found in database!" << endl;
            }
            getch();
        }

        // update books
        if (choice == '3')
        {
            fflush(stdin);
            string old_title, new_title, new_author, new_genre;

            cout << "Enter the title of the book you want to update: ";
            getline(cin, old_title);

            Book* bookToUpdate = store_1.searchBook(old_title);

            if (bookToUpdate != NULL)
            {
                cout << "Enter the new details for the book" << endl;

                fflush(stdin);
                cout << "New Title: ";
                getline(cin, new_title);

                fflush(stdin);
                cout << "New Author: ";
                getline(cin, new_author);

                fflush(stdin);
                cout << "New Genre: ";
                getline(cin, new_genre);

                store_1.updateBook(old_title, new_title, new_author, new_genre);
                cout << "Book updated successfully!" << endl;
            }

            else
            {
                cout << "Book not found in the inventory" << endl;
            }
        }

        // delete book
        if (choice == '4')
        {
            fflush(stdin);
            string book_title;

            cout << "Enter book to be deleted: ";
            getline(cin, book_title);
            cout << book_title << endl;
            getch();
            Book* Book_To_Delete = store_1.searchBook(book_title);

            if (Book_To_Delete != NULL)
            {
                store_1.deleteBook(book_title);
                cout << "Book deleted" << endl;
                store_1.inOrderTraversal(store_1.root);
                getch();
            }
        }
    } while (choice != '0');

User_Login:
    do
    {
        system("cls");
        fflush(stdin);

        string username;
        string password;

        cout << "----------User Login Menu----------" << endl
            << endl;
        cout << "Enter username: ";
        getline(cin, username);

        cout << "Enter password: ";
        getline(cin, password);

        bool login_success = store_1.user_Login(username, password);

        if (login_success == false)
        {
            getch();
            cout << "Press any key to try logging in again" << endl;
            goto User_Login;
        }

        else
            goto User_Menu;
    } while (choice != '0');

User_Menu:
    do
    {
        system("cls");
        fflush(stdin);

        cout << "----------User Interactive Menu----------" << endl
            << endl;
        cout << "1. Display Books" << endl;
        cout << "2. Search Book" << endl;
        cout << "3. Purchase Books" << endl;
        cout << "4. Display Books by Genre" << endl;
        cout << "5. Display Friend Preferences" << endl;
        cout << "6. Display Best Selling Books" << endl;
        cout << "0. Log out" << endl;

        do
        {
            cout << endl
                << "Choice: ";
            cin >> choice;
        } while (choice < '0' || choice > '6');

        // log out
        if (choice == '0')
        {
            goto Main_Menu;
        }

        // display books
        if (choice == '1')
        {
            store_1.inOrderTraversal(store_1.root);
            getch();
        }

        // search books
        if (choice == '2')
        {
            fflush(stdin);
            string book_title;

            cout << "Enter book to be searched: ";
            getline(cin, book_title);
            Book* find_book = store_1.searchBook(book_title);

            if (find_book != NULL)
            {
                cout << "Book found in database!" << endl;
            }

            else
            {
                cout << "Book not found in database!" << endl;
            }
            getch();
        }

        // purchase books
        if (choice == '3')
        {
            store_1.inOrderTraversal(store_1.root);

            string book_title;
            int x;
            fflush(stdin);

            while (1)
            {
                cout << "Enter the book title you want to purchase: ";
                getline (cin, book_title);
                store_1.purchase_Book(book_title);

                cout << "Do you want to continue? Press 1 to continue";
                cin  >> x;

                if (x != 1)
                {
                    break;
                }
                cin.ignore();
            }

            store_1.generateBill();
            getch();
        }

        // display books sorted by genre
        if (choice == '4')
        {
            vector<vector<Book>> temp = store_1.levelOrderTraversalByGenre();
            cout << "Displaying books by Genre" << endl << endl;

            fflush (stdin);
            string book_genre;
            cout << "Enter book genre for which books to display: ";
            getline (cin, book_genre);

            for (int i = 0; i < temp.size(); i++)
            {
                for (int j = 0; j < temp[i].size(); j++)
                {
                    if (temp[i][j].book_genre == book_genre)
                    {
                        cout << "Book Title: " << temp[i][j].book_title << endl;
                    }
                }
            }
            getch();
        }

        // social network
        if (choice == '5')
        {
            SocialNetwork socialNetwork(3);
            Book book1("The Catcher in the Rye", "J.D. Salinger", "Fiction", 1951, 224, 12);
            Book book2("To Kill a Mockingbird", "Harper Lee", "Fiction", 1960, 281, 10);
            Book book3("1984", "George Orwell", "Dystopian", 1949, 328, 5);
            Book book4("Pride and Prejudice", "Jane Austen", "Romance", 1813, 279, 15);
            Book book5("The Great Gatsby", "F. Scott Fitzgerald", "Classic", 1925, 180, 8);
            User user1("Ibrahim", "I-4173", 25, {});
            User user2("Sayal", "S-4625", 30, {});
            User user3("Rohit", "R-4544", 22, {});
            user1.addBookPreference(book1);
            user1.addBookPreference(book2);
            user2.addBookPreference(book3);
            user3.addBookPreference(book4);
            socialNetwork.addUser(user1);
            socialNetwork.addUser(user2);
            socialNetwork.addUser(user3);
            socialNetwork.addFriendship(user1, user2);
            socialNetwork.addFriendship(user2, user3);
            socialNetwork.addFriendship(user1, user3);
            User currentUser = user1;
            vector<Book> recommendations = socialNetwork.getSocialBookRecommendations(currentUser);
            cout << "\nBook Recommendations for " << currentUser.getName() << ":\n";
            for (const auto& book : recommendations)
            {
                cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", Genre: " << book.getGenre() << endl;
            }
            getch();
        }

        // display books
        if (choice == '6')
        {
            store_1.heapify_Best_Sellers();
            getch();
        }

    } 
    while (choice != '0');

End_Program:
    system("cls");
    cout << "Program end" << endl;

    // end of program
}