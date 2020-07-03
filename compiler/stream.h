#pragma once

#include <iostream>
#include <vector>
#include <variant>
#include <tuple>
#include <utility>

template <typename> struct is_tuple : std::false_type {};

template <typename ...T> struct is_tuple<std::tuple<T...>> : std::true_type {};

template <typename> struct is_variant : std::false_type {};

template <typename ...T> struct is_variant<std::variant<T...>> : std::true_type {};

template<class T>
class Stream
{
public:
    Stream() : m_current(0), m_buffer() {}
    Stream(const std::vector<T>& buffer) : m_current(0), m_buffer(buffer) {}
    void next() { 
        while (m_current < m_buffer.size() - 1 && (m_buffer[++m_current] == ' ' || m_buffer[m_current]  == '\n'))
        { }
    }
    T top() const { return m_buffer[m_current]; }
    void add(T element) { m_buffer.push_back(element); }


    friend std::ostream& operator<<(std::ostream& outputStream, const Stream<T>& stream)
    {
        outputStream << "(";
        for (unsigned int i = stream.m_current; i < stream.m_buffer.size(); i++)
        {
            if constexpr (is_tuple<T>::value)
            {
                outputStream << "<";
                std::apply([&outputStream](auto&&... args) {((outputStream << args << ','), ...); }, stream.m_buffer[i]);
                outputStream << ">";
            }
            else if constexpr (is_variant<T>::value)
            {
                std::visit([&outputStream](const auto& elem) { outputStream << elem; }, stream.m_buffer[i]);
            }
            else
            {
                outputStream << stream.m_buffer[i];
            }
            outputStream << ",";
        }
        outputStream << ")" << std::endl;
        return outputStream;
    }

    unsigned int size() { return m_current; }
private:
    unsigned int m_current;
    std::vector<T> m_buffer;
};