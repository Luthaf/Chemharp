// Chemfiles, a modern library for chemistry file reading and writing
// Copyright (C) Guillaume Fraux and contributors -- BSD license

#include <limits>
#include <cstdint>

#include "chemfiles/parse.hpp"
#include "chemfiles/utils.hpp"
#include "chemfiles/error_fmt.hpp"
#include "chemfiles/string_view.hpp"

using namespace chemfiles;

static bool is_digit(char c) {
    return '0' <= c && c <= '9';
}

static bool is_ascii_upper(char c) {
    return 'A' <= c && c <= 'Z';
}

static bool is_ascii_lower(char c) {
    return 'a' <= c && c <= 'z';
}

template <> int64_t chemfiles::parse(string_view input) {
    if (input.empty()) {
        throw error("can not parse an integer from an empty string");
    }

    auto it = input.begin();
    auto end = input.end();

    // skip whitespaces before number
    while (it != end && is_whitespace(*it)) {
        it++;
    }

    int sign = 1;
    // Parse sign, if any
    if (it != end && *it == '-') {
        sign = -1;
        it++;
    } else if (it != end && *it == '+') {
        it++;
    }

    int64_t result = 0;
    for (/*no initialization*/; it!=end; it++) {
        if (is_digit(*it)) {
            int64_t digit = static_cast<int64_t>(*it - '0');
            if (sign == -1) {
                // Check for underflow
                if (result >= ((std::numeric_limits<int64_t>::min() + digit) / 10))
                    result = result * 10 - digit;
                else {
                    throw error("{} is out of range for 64-bit integer", input);
                }
            } else {
                // Check for overflow
                if (result <= ((std::numeric_limits<int64_t>::max() - digit) / 10))
                    result = result * 10 + digit;
                else {
                    throw error("{} is out of range for 64-bit integer", input);
                }
            }
        } else {
            // we found the end of the number
            break;
        }
    }

    // skip whitespaces after number if any
    while (it != end && is_whitespace(*it)) {
        it++;
    }

    if (it != end) {
        throw error("can not parse '{}' as an integer", input);
    }

    return result;
}

template <> uint64_t chemfiles::parse(string_view input) {
    if (input.empty()) {
        throw error("can not parse an integer from an empty string");
    }

    auto it = input.begin();
    auto end = input.end();

    // skip whitespaces before number
    while (it != end && is_whitespace(*it)) {
        it++;
    }

    // Parse sign, if any
    if (it != end && *it == '+') {
        it++;
    }

    uint64_t result = 0;
    for (/*no initialization*/; it!=end; it++) {
        if (is_digit(*it)) {
            uint64_t digit = static_cast<uint64_t>(*it - '0');
            // Check for overflow
            if (result <= ((std::numeric_limits<uint64_t>::max() - digit) / 10))
                result = result * 10 + digit;
            else {
                throw error("{} is out of range for 64-bit unsigned integer", input);
            }
        } else {
            // we found the end of the number
            break;
        }
    }

    // skip whitespaces after number if any
    while (it != end && is_whitespace(*it)) {
        it++;
    }

    if (it != end) {
        throw error("can not parse '{}' as a positive integer", input);
    }

    return result;
}


template <> double chemfiles::parse(string_view input) {
    if (input.empty()) {
        throw error("can not parse a double from an empty string");
    }

    auto it = input.begin();
    auto end = input.end();

    // skip whitespaces before number
    while (it != end && is_whitespace(*it)) {
        it++;
    }

    // Get sign, if any.
    int sign = 1.0;
    if (it != end && *it == '-') {
        sign = -1.0;
        it++;
    } else if (it != end && *it == '+') {
        it++;
    }

    auto digit_start = it;
    // Get digits before decimal point or exponent, if any.
    double value = 0.0;
    while (it != end && is_digit(*it)) {
        value = value * 10.0 + static_cast<double>(*it - '0');
        it++;
    }
    bool got_digits = (digit_start != it);

    // Get digits after decimal point, if any.
    if (it != end && *it == '.') {
        it++;
        auto frac_start = it;
        double pow10 = 10.0;
        while (it != end && is_digit(*it)) {
            value += static_cast<double>(*it - '0') / pow10;
            pow10 *= 10.0;
            it++;
        }

        got_digits = got_digits || (frac_start != it);
    }

    // Handle exponent, if any.
    bool frac = false;
    double scale = 1.0;
    if (it != end && (*it == 'e' || *it == 'E')) {
        it++;
        auto exponent_start = it;

        // Get sign of exponent, if any.
        if (it != end && *it == '-') {
            frac = true;
            it++;
        } else if (it != end && *it == '+') {
            it++;
        }

        // Get digits of exponent, if any.
        unsigned expon = 0;
        while (it != end && is_digit(*it)) {
            unsigned digit = static_cast<unsigned>(*it - '0');
            if (expon <= ((std::numeric_limits<unsigned>::max() - digit) / 10))
                expon = expon * 10 + digit;
            else {
                throw error("float exponent in {} is out of range for unsigned integer", input);
            }

            it++;
        }

        if (it == exponent_start) {
            throw error("missing exponent in '{}'", input);
        } else if (expon > 308) {
            throw error("{} is out of range for double", input);
        }

        // Calculate scaling factor.
        while (expon >= 50) { scale *= 1e50; expon -= 50; }
        while (expon >=  8) { scale *= 1e8;  expon -=  8; }
        while (expon >   0) { scale *= 1e1;  expon -=  1; }
    }

    // skip whitespaces after number if any
    while (it != end && is_whitespace(*it)) {
        it++;
    }

    if (it != end || !got_digits) {
        throw error("can not parse '{}' as a double", input);
    }

    // Return signed and scaled floating point result.
    return sign * (frac ? (value / scale) : (value * scale));
}

static const auto digits_upper = std::string("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ");
static const auto digits_lower = std::string("0123456789abcdefghijklmnopqrstuvwxyz");

static int32_t digit_to_value(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }

    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 10;
    }

    // We know all the places this function is used, so this should be fine
    return c - 'a' + 10;
}

static std::string encode_pure(const std::string& digits, int64_t value) {
    if (value == 0) {
        return std::string(digits, 1);
    }

    auto n = static_cast<int32_t>(digits.length());
    std::string result;
    while (value != 0) {
        auto rest = value / n;
        result += digits[static_cast<size_t>(value - rest * n)];
        value = rest;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

static int64_t decode_pure(string_view s) {
    int64_t result = 0;
    auto n = static_cast<int64_t>(digits_upper.length());
    for (auto c : s) {
        result *= n;
        result += digit_to_value(c);
    }
    return result;
}

/// Evaluates base^(power) and casts the result to int64_t while addressing
/// issues where the result maybe rounded down due to floating point errors
static int64_t pow_int(uint64_t base, uint64_t power) {
    return static_cast<int64_t>(std::pow(base, power) + 0.5);
}

std::string chemfiles::encode_hydrid36(uint64_t width, int64_t value) {

    // the number is too negative to be encoded
    if (value < (1 - pow_int(10, width - 1))) {
        return std::string(width, '*');
    }

    // no need to encode
    if (value < pow_int(10, width)) {
        return std::to_string(value);
    }

    // use upper case set
    value -= pow_int(10, width);
    if (value < 26 * pow_int(36, (width - 1))) {
        value += 10 * pow_int(36, (width - 1));
        return encode_pure(digits_upper, value);
    }

    // use lower case set
    value -= 26 * pow_int(36, width - 1);
    if (value < 26 * pow_int(36, width - 1)) {
        value += 10 * pow_int(36, width - 1);
        return encode_pure(digits_lower, value);
    }

    // too large to be encoded
    return std::string(width, '*');
}

int64_t chemfiles::decode_hybrid36(uint64_t width, string_view s) {

    // This function is only called within chemfiles for fixed format files.
    // Therefore, the width should also be the length of the string as this is
    // known at compile time.
    if (s.length() > width) {
        throw error("the length of '{}' is greater than the width '{}', this is a bug in chemfiles", s, width);
    }

    auto f = s[0];
    if (f == '-' || f == ' ' || is_digit(f)) {
        // Negative number, these are not encoded
        return parse<int64_t>(s);
    }

    // See above comment. Standard says blank strings needs to be treated as 0
    if (trim(s).size() == 0) {
        return 0;
    }

    if (digits_upper.find(f) != std::string::npos) {
        auto is_valid = std::all_of(s.begin(), s.end(), [](char c) {
            return is_digit(c) || is_ascii_upper(c);
        });

        if (!is_valid) {
            throw error("the value '{}' is not a valid hybrid 36 number", s);
        }

        return decode_pure(s) - 10 * pow_int(36, width - 1) + pow_int(10, width);
    }

    if (digits_lower.find(f) != std::string::npos) {
        auto is_valid = std::all_of(s.begin(), s.end(), [](char c) {
            return is_digit(c) || is_ascii_lower(c);
         });

        if (!is_valid) {
            throw error("the value '{}' is not a valid hybrid 36 number", s);
        }

        return decode_pure(s) + 16 * pow_int(36, width - 1) + pow_int(10, width);
    }

    throw error("the value '{}' is not a valid hybrid 36 number", s);
}
