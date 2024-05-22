// It’s possible to move the link - time error up to compile time(always a
// good thing — earlier error detection is better than later) by declaring
// the copy constructor and copy assignment operator private not in
// HomeForSale itself, but in a base class specifically designed to prevent
// copying.The base class is simplicity itself :
class Uncopyable {
protected: // allow construction
	Uncopyable() {} // and destruction of
	~Uncopyable() {} // derived objects...
private:
	Uncopyable(const Uncopyable&); // ...but prevent copying
	Uncopyable& operator=(const Uncopyable&);
};
// To keep HomeForSale objects from being copied, all we have to do now
// is inherit from Uncopyable :
class HomeForSale : private Uncopyable { // class no longer
	// ... // declares copy ctor or
}; // copy assign. operator