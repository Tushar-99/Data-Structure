#include <iostream>
#include <vector>
#include <string>
#include <limits>

template <typename T>
std::string mx(T e) {
    std::vector<T> v;
    return std::to_string(v.max_size());
}

std::size_t maxColWidth(std::vector<std::string> v) {
    std::size_t maxWidth = 0;

    for (const auto &s: v)
        if (s.length() > maxWidth)
            maxWidth = s.length();

    // Add 2 for space on each side
    return maxWidth + 2;
}

constexpr long double maxStdSize_t = std::numeric_limits<std::size_t>::max();

// cs stands for compared to std::size_t
template <typename T>
std::string cs(T e) {
    std::vector<T> v;
    long double maxSize = v.max_size();
    long double quotient = maxStdSize_t / maxSize;
    return std::to_string(quotient);
}

int main() {
    bool v0 = 0;
    char v1 = 0;

    int8_t v2 = 0;
    int16_t v3 = 0;
    int32_t v4 = 0;
    int64_t v5 = 0;

    uint8_t v6 = 0;
    uint16_t v7 = 0;
    uint32_t v8 = 0;
    uint64_t v9 = 0;

    std::size_t v10 = 0;
    double v11 = 0;
    long double v12 = 0;

    std::vector<std::string> types = {"data types", "bool", "char", "int8_t", "int16_t",
                                      "int32_t", "int64_t", "uint8_t", "uint16_t",
                                      "uint32_t", "uint64_t", "size_t", "double",
                                      "long double"};

    std::vector<std::string> sizes = {"approx max array length", mx(v0), mx(v1), mx(v2),
                                      mx(v3), mx(v4), mx(v5), mx(v6), mx(v7), mx(v8),
                                      mx(v9), mx(v10), mx(v11), mx(v12)};

    std::vector<std::string> quotients = {"max std::size_t / max array size", cs(v0),
                                          cs(v1), cs(v2), cs(v3), cs(v4), cs(v5), cs(v6),
                                          cs(v7), cs(v8), cs(v9), cs(v10), cs(v11), cs(v12)};

    std::size_t max1 = maxColWidth(types);
    std::size_t max2 = maxColWidth(sizes);
    std::size_t max3 = maxColWidth(quotients);

    for (std::size_t i = 0; i < types.size(); ++i) {
        while (types[i].length() < (max1 - 1)) {
            types[i] = " " + types[i];
        }

        types[i] += " ";

        for  (int j = 0; sizes[i].length() < max2; ++j)
            sizes[i] = (j % 2 == 0) ? " " + sizes[i] : sizes[i] + " ";

        for  (int j = 0; quotients[i].length() < max3; ++j)
            quotients[i] = (j % 2 == 0) ? " " + quotients[i] : quotients[i] + " ";

        std::cout << "|" << types[i] << "|" << sizes[i] << "|" << quotients[i] << "|\n";
    }

    std::cout << std::endl;

    std::cout << "N.B. max std::size_t is: " <<
        std::numeric_limits<std::size_t>::max() << std::endl;

    return 0;
}

// |  data types | approx max array length | max std::size_t / max array size |
// |        bool |        2147483616       |             2.000000             |
// |        char |        2147483647       |             2.000000             |
// |      int8_t |        2147483647       |             2.000000             |
// |     int16_t |        1073741823       |             4.000000             |
// |     int32_t |        536870911        |             8.000000             |
// |     int64_t |        268435455        |             16.000000            |
// |     uint8_t |        2147483647       |             2.000000             |
// |    uint16_t |        1073741823       |             4.000000             |
// |    uint32_t |        536870911        |             8.000000             |
// |    uint64_t |        268435455        |             16.000000            |
// |      size_t |        536870911        |             8.000000             |
// |      double |        268435455        |             16.000000            |
// | long double |        178956970        |             24.000000            |

// N.B. max std::size_t is: 4294967295