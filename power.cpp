
#include <iostream>
#include <array>
#include <chrono>
using namespace std;


template <size_t N>
array<int, N> initialize_array_runtime() {
    array<int, N> arr;
    for (size_t i = 0; i < N; ++i) {
        arr[i] = i;
    }
    return arr;
}


template <size_t... Indices>
constexpr std::array<int, sizeof...(Indices)> initialize_array_metaprogramming_impl(std::index_sequence<Indices...>) {
    return {Indices...};
}

template <size_t N>
constexpr std::array<int, N> initialize_array_metaprogramming() {
    return initialize_array_metaprogramming_impl(std::make_index_sequence<N>());
}

int main() {
    constexpr size_t array_size = 10000;

    auto start1 = chrono::high_resolution_clock::now(); 
    auto arr_runtime = initialize_array_runtime<array_size>();
    auto end1 = chrono::high_resolution_clock::now();

    auto dur1 = chrono::duration_cast<chrono::nanoseconds>(end1 - start1);

    
    auto start2 = chrono::high_resolution_clock::now();
    constexpr auto arr_metaprogramming = initialize_array_metaprogramming<array_size>();
    auto end2 = chrono::high_resolution_clock::now();

    auto dur2 = chrono::duration_cast<chrono::nanoseconds>(end2 - start2);

    
    std::cout << "Runtime Initialization: ";
    for (const auto& elem : arr_runtime) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    cout << "Time taken for Normal Execution: " << dur1.count() << endl;
    cout << "Time taken for metaprogramming: " << dur2.count() << endl;

    cout << "Hence, Template Programming execution is always constant time " << endl;

    return 0;
}
