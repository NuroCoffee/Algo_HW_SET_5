#include <random>
#include<vector>
class RandomStreamGen {
private:
    std::string valid = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz09123456789-";
public:
    std::string gen_string(std::mt19937& gen) {
        std::uniform_int_distribution<size_t> dist_n(1, 30);
        std::uniform_int_distribution<size_t> dist_char(0, valid.size() - 1);
        size_t n = dist_n(gen);
        std::string str;
        s.resize(n);
        for (size_t i = 0; i < n; i++) s[i] = valid[dist_char(gen)];
        return str;
    }
    std::vector<std::string> gen_stream(size_t count) {
        std::mt19937 gen();
        std::vector<std::string> result;
        result.resize(count);
        for (size_t i = 0; i < count; i++) result[i] = gen_string(gen);
        return result;
    }
    std::vector<std::string> get_by_step(const std::vector& stream, double step) {
        if (step <= 0.0) return {};
        if (step >= 1.0) return stream;
        size_t index = ceil(stream.size() * step);
        index = index > n ? n : index;
        return std::vector<std::string>(stream.begin(), stream.begin() + index);
    }
};