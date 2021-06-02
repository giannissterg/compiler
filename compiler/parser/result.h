#pragma once

#include <string> 

class Error
{
public:
    Error(const std::string& message) : m_message(message) {}
private:
    std::string m_message;
};

class UnexpectedTokenError : public Error
{
public:
    UnexpectedTokenError() : Error("Unexpected token found") {}
};

template <class T>
class Success
{
public:
    Success() = default;
    Success(T data) : m_data(data) {}
    T getData() const { return m_data; }
private:
    T m_data;
};

class Failure
{
public:
    Failure(Error error) : m_error(error) {}
private:
    Error m_error;
};

template<class T>
class ParseResult
{
    ParseResult(Success<T> result, Stream<char>* restInputStream) : m_result(result), m_restInputStream(restInputStream) {}
    ParseResult(Failure result, Stream<char>* restInputStream) : m_result(result), m_restInputStream(restInputStream) {}
private:
    std::variant<Success<T>, Failure> m_result;
    Stream<char>* m_restInputStream;
};