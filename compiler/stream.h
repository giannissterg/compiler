#pragma once

#include <iostream>
#include <vector>
#include <variant>
#include <tuple>
#include <utility>
#include <sstream>

template <typename> struct is_tuple : std::false_type {};

template <typename ...T> struct is_tuple<std::tuple<T...>> : std::true_type {};

template <typename> struct is_variant : std::false_type {};

template <typename ...T> struct is_variant<std::variant<T...>> : std::true_type {};

template<class T>
class Stream
{
public:
    virtual ~Stream() = 0;
    virtual void next() = 0;
    virtual T top() const = 0;
protected:
    std::basic_stringstream<T> m_buffer;
};

template<class T>
inline Stream<T>::~Stream() { }


template<class T>
class BaseStream : public Stream<T>
{
public:
    BaseStream() : m_current(0) {}
    BaseStream(const std::vector<T>& buffer) : m_current(0) { this->m_buffer = buffer; }
    ~BaseStream() = default;
    void next() override { 
        while (m_current < this->m_buffer.size() - 1 && (this->m_buffer[++m_current] == ' ' || this->m_buffer[m_current]  == '\n'))
        { }
    }
    T top() const override { return this->m_buffer[m_current]; }
    void add(T element) { this->m_buffer.push_back(element); }


    friend std::ostream& operator<<(std::ostream& outputStream, const BaseStream<T>& stream)
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
protected:
    unsigned int m_current;
};