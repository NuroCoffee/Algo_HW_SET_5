#ifndef RANDOM_STREAM_GEN_H
#define RANDOM_STREAM_GEN_H

#include <vector>
#include "random"
#include "limits"

struct HashFunc {
    size_t operator()(std::string const& str) const {
        std::mt19937 gen();
        std::uniform_int_distribution<size_t> dist(0, UINT64_MAX - 1);
        return std::hash<std::string>{}(s + std::to_string(dist(gen)));
    }
};

class HashFuncGen {
public:
    HashFunc create() {
        return HashFunc{};
    }
};

#endif