/* multiton.cpp */

#include <iostream>

class Multiton {
private:
	Multiton () { std::cout<< ms_id << "\t"; } 
	static const std::size_t ms_arr_size {3};
	static inline std::size_t ms_id {};
public:
	~Multiton () = default;
	static inline Multiton* arr[ms_arr_size];
	static Multiton* create_obj ();
};

void test_creation (Multiton**, std::size_t);

int main () {
	const size_t count {10};
	Multiton* arr[count];
	test_creation (arr, count);

return 0;
}

Multiton* Multiton::create_obj () {
	if (ms_id < ms_arr_size) {
		arr[ms_id] = new Multiton;
		++ms_id;
		return arr[ms_id-1];
	} else { 
		++ms_id;
		return arr[(ms_id-1) % ms_arr_size];
	}	
	return arr[(ms_id-1) % ms_arr_size];
}

void test_creation (Multiton** arr, std::size_t count) {
	for (size_t i{}; i<count; ++i) {
		arr[i] = Multiton::create_obj();
		std::cout<< arr[i] << "\n";
	}
}	

