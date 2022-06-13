// Smart Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Code by Kelley Kramer
//CSC275

#include <iostream>
#include <string>
#include <execution>
#include <cstdlib>

using namespace std;

struct Test
{
    int tId;
    Test(int id) :tId(id)
    {
        cout << "Test Creator\n" << endl;
    }
    ~Test() 
    {
        cout << "Test Destroyer" << endl;
    }
};

int main()
{
    cout << "\n\t\t *** SMART POINTERS ** \n\n" << endl;
    cout << "This program will define the three types of smart pointer." << endl;
    cout << "It will also expalin when to use them, and the pros and the cons of each.\n\n" << endl;

    cout << "The three tpes of smart pointer we will discuss are:" << endl;
    cout << "-shared_ptr \n-unique_ptr \n-weak_ptr\n" << endl;

    cout << "shared_ptr:" << endl;
    cout << "\tA shared pointer is a pointer that shares ownership with other smart pointer types.\n"
        "\tIt maintains a reference count which is incremented when another shared pointer points\n"
        "\tto the same object.  So when a reference count equals zero, the object is destroyed.\n"
        "\t\thttps://www.educative.io/edpresso/shared-pointers-in-cpp" << endl;

    cout << "\t\Pros:" << endl;
    cout << "\tThis type of pointer has the benifit of auto-deletion once the pointer is out of scope.\n"
        "\tThis type also has the benefit of auto initiation to null.\n" << endl;

    cout << "\t\Cons:" << endl;
    cout << "\tThe draw back to this type of pointer is in order to delet it all pointers must be out of scope.\n" << endl;

    cout << "\tUseage case:" << endl;
    cout << "\tWe would want to use this typ of pointer to assign one raw pointer to multiple owners.\n\n"<< endl;

    cout << "unique_ptr:" << endl;
    cout << "\tA unique pointer is a pointer that has exclusive ownership over their pointer.\n"
        "\tNo other managed pointer should point to it's managed object.  As soon as they have to,\n"
        "\tunique_ptr objects delete their mannaged object, ignoring wheter other pointers are still\n"
        "\tpointing to it.  If there are other pointers, then they will report an invalid location\n"
        "\t\thttps://cplusplus.com/reference/memory/unique_ptr/" << endl;

    cout << "\t\Pros:" << endl;
    cout << "\tThis type of pointer also has the benifit of auto deletion once out of scope.\n"
            "\tThis type can also transfer ownership to other unique pointers, and will auto initialize to null\n" << endl;

    cout << "\t\Cons:" << endl;
    cout << "\tThe owner ship of this type of pointer can not be shared.\n" << endl;

    cout << "\tUseage case:" << endl;
    cout << "\tThis pointer is used, when you need exclusive owner ship of an object, and do\n" 
            "\tnot intend to share the resource.\n\n"<< endl;

    cout << "weak_ptr:" << endl;
    cout << "\tThe weak pointer is a smart pointer that does not take ownership of an object, but.\n"
            "\tinstead, acts like an observer.  This also means it is not considered in an auto deletion.\n"
            "\t\thttps://iamsorush.com/posts/weak-pointer-cpp/" << endl;

    cout << "\t\Pros:" << endl;
    cout << "\tOne advantage of this type of pointer is, that it is not included in auto-deletion\n"
            "\tAnother benifit, is that it never has ownership of the object it is pointing to.\n" << endl;

    cout << "\t\Cons:" << endl;
    cout << "\tOne of its advanatages, not having ownership, can also be its biggest disadvantage.\n"  
            "\tIt can offten be replaced with a shared pointer\n" << endl;

    cout << "\tUseage case:" << endl;
    cout << "\tA weak pointer is most oftenly used to break the curcular dependency of shared pointer.\n"
            "\tOtherwise thay are unable to delete their objects.\n\n" << endl;

    cout << "The following will demonstrate a unique pointer:\n" << endl;

    // Create a unique_ptr object through raw pointer
    std::unique_ptr<Test> TestPtr(new Test(23));

    //Access the element through unique_ptr
    int id = TestPtr->tId;

    std::cout << id << "\n"<<std::endl;

    return 0;
}