//
// Created by Gandifil on 25.04.2021.
//

#ifndef BYSONVM_STATE_HPP
#define BYSONVM_STATE_HPP

#include <memory>
#include <vector>

namespace Byson::VirtualMachine {
    struct IndexedHeap {
    public:
        void add(size_t index) {
            if (index < data.size()) {
                if (data[index] == 0)
                    data[index] = 1;
                else throw std::overflow_error{ "IndexedHeap::add index" };
            }
            else {
                data.resize(index + 1);
                data.back() = 1;
            }
        }

        void remove(size_t index) {
            if (index < data.size())
                data[index] = 0;
            else throw std::out_of_range{ "IndexedHeap::remove index" };
        }

        int operator[](size_t index) const {
            return data[index];
        }

        int& operator[](size_t index) {
            return data[index];
        }

    private:
        std::vector<int> data;
    };

    struct State {
    public:
        IndexedHeap heap;
    };
}


#endif //BYSONVM_STATE_HPP
