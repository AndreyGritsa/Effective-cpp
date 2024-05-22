#include <string>
#include <list>


class PhoneNumber {}; // ... 
class ABEntry { // ABEntry = “Address Book Entry”
public:
	ABEntry(const std::string& name, const std::string& address,
		const std::list<PhoneNumber>& phones);
	ABEntry();
private:
	std::string theName;
	std::string theAddress;
	std::list<PhoneNumber> thePhones;
	int numTimesConsulted;
};

ABEntry::ABEntry(const std::string& name, const std::string& address,
	const std::list<PhoneNumber>& phones)
{
	theName = name; // these are all assignments,
	theAddress = address; // not initializations
	thePhones = phones;
	numTimesConsulted = 0;
}


// This will yield ABEntry objects with the values you expect, but it’s still
// not the best approach.The rules of C++ stipulate that data members
// of an object are initialized before the body of a constructor is entered.
// Inside the ABEntry constructor, theName, theAddress, and thePhones
// aren’t being initialized, they’re being assigned.Initialization took place
// earlier — when their default constructors were automatically called
// prior to entering the body of the ABEntry constructor.This isn’t true for
// numTimesConsulted, because it’s a built - in type.For it, there’s no guarantee it was initialized at all prior to its assignment.

ABEntry::ABEntry(const std::string& name, const std::string& address,
	const std::list<PhoneNumber>& phones)
	: theName(name),
	theAddress(address), // these are now all initializations
	thePhones(phones),
	numTimesConsulted(0)
{} // the ctor body is now empty

ABEntry::ABEntry()
	: theName(), // call theName’s default ctor;
	theAddress(), // do the same for theAddress;
	thePhones(), // and for thePhones;
	numTimesConsulted(0) // but explicitly initialize
{} // numTimesConsulted to zero


class FileSystem {
	// Implementation details of FileSystem
};

FileSystem& tfs() {
	// Define and initialize a local static FileSystem object
	static FileSystem fs;
	// Return a reference to the static object
	return fs;
}

// This function replaces the need for a static FileSystem object within the class.
// static FileSystem fs; creates a static instance of FileSystem within the function.
// This object is created the first time the function is called and persists for the lifetime of the program.
// return fs; returns a reference to this static object, allowing access to the same FileSystem instance every time tfs() is called.

class Directory {
	// Implementation details of Directory
};

Directory::Directory(params) {
	// Constructor implementation where references to tfs are now to tfs()
	std::size_t disks = tfs().numDisks();
	// Other initialization code
}

Directory& tempDir() {
	// Define and initialize a local static Directory object
	static Directory td(params);
	// Return a reference to the static object
	return td;
}

// Encapsulation of Static Objects : By defining the static instances within functions, 
// the code encapsulates the static objects' creation and access logic within specific functions, 
// reducing the risk of unintended interactions.
// 
// Lazy Initialization : The static objects(FileSystem and Directory) are only created when 
// the respective functions are first called, ensuring that the objects are not created if they are not needed.
// 
// Global Access : The functions tfs() and tempDir() provide a way to access the same instances 
// of FileSystem and Directory globally without using global variables.

