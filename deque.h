// deque.h
#ifndef Deque_H
#define Deque_H

#include <algorithm>
#include <stdexcept>
#include <cstddef>
#include <cstring>
#include <iostream>
using std::copy;
template<typename T>
class Deque {
	enum { CHUNK = 10 };

private:
	T* data;
	std::size_t first;
	std::size_t last;
	std::size_t cur_size;

public:

	Deque(); // Allocates a default-size (CHUNK) array
	~Deque(); // Deletes array heap memory
	Deque(const Deque&) = delete; // Disables copy
	Deque& operator=(const Deque&) = delete; // Disables assignment
	void push_front(T); // Adds new element to the front (left end)
	void push_back(T); // Adds new element to the back (right end)
	T& front(); // Returns a reference to the first used element
	T& back(); // Returns a reference to the last used element
	T& at(size_t pos); // Return a reference to the element in position pos
	void pop_front(); // "Removes" first deque element (just change front_)
	void pop_back(); // "Removes" last deque element (just change back_)
	size_t size() const; // Returns the # of used items. NOTE:size_t is defined in <cstddef>
	T* begin(); // Returns a pointer to the first element
	T* end(); // Returns a pointer to one position past the last element
	void resize();
};

template <typename T>
Deque<T>::Deque() {
	cur_size = CHUNK;
	data = new T[CHUNK];
	first = CHUNK / 2;
	last = first;
}
template <typename T>
Deque<T>::~Deque() {
	delete[] data;
}
template <typename T>
void Deque<T>::push_front(T input) {
	if (first == 0) //resize
		resize();
	data[--first] = input;
}
template <typename T>
void Deque<T>::push_back(T input) {
	if (last == cur_size) //resize
		resize();
	data[last++] = input;
}
template <typename T>
T& Deque<T>::front() {
	if (size() == 0)
		throw std::logic_error("error");
	return data[first];
}
template <typename T>
T& Deque<T>::back() {
	if (size() == 0)
		throw std::logic_error("error");
	return data[last - 1];
}
template <typename T>
T& Deque<T>::at(size_t pos) {
	if (size() == 0)
		throw std::logic_error("error");
	return data[first + (pos)];
}
template <typename T>
size_t Deque<T>::size() const {
	return last - first;
}
template <typename T>
void Deque<T>::pop_front() {
	if (size() != 0) first = first + 1;
}
template <typename T>
void Deque<T>::pop_back() {
	if (size() != 0) last = last - 1;
}
template <typename T>
T* Deque<T>::begin() {
	return &data[first];
}
template <typename T>
T* Deque<T>::end() {
	return &data[last];
}
template <typename T>
void Deque<T>::resize() {
	
	int new_size = cur_size + CHUNK;
	T* temp = new T[new_size];
	int tempfirst = ((new_size - size()) / 2);
	copy(data+first,data+last,temp + tempfirst);	
	delete [] data;
	data = temp;
	last = tempfirst + size();
	first = tempfirst;
	cur_size = new_size;

}
#endif
/*This was a good 1st program. It has been a while for me with C++ and needs some refreshing.
This program was hard because I have not used pointers in a while. As well as some new libraries that I never have used.
I talked with others for explination of pointers and how to use them. As well as some errors that were coming from the debugger.
The debugger was hard to get working because I started out on Cloud9 which doesn’t have all the need debugger to run the asserts.
I ended up moving over to Visual Studio 2015 to do the program. The memcpy was new to me and still trying to make sure I understand it all the way.
As well as size_t was new but I think I get that now. The const being used is still a little fusy and would like more clarity on it.
I learned some new things about pointers and how to use them better. I learned that even though sometimes a project seems easy it is not.
I learned what assert was. I leared templates which was good as I never had to write one before.
Overall the project was channeling due to all the new and review items. Although it was a good project to get things moving again with C++.
This helped to get my envirorment setup for upcoming programs.
Excited for others to come.
*/
