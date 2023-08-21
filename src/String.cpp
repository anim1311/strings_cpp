#include <String.hpp> // My Custom Strings Implementation

#define DEBUG_LOG 1

#if DEBUG_LOG
    #define LOG(x) std::cout << x << std::endl
#else
    #define LOG(x)
#endif

String::String() // Default Constructor
    : m_data(nullptr), m_size(0)
{
    LOG("Default Constructor Called");
}

String::String(const char* str) // C-String Constructor
{
    LOG("C-String Constructor Called");

    m_size = strlen(str);
    m_data = new char[m_size + 1];
    memcpy(m_data, str, m_size);
    m_data[m_size] = '\0';
}

String::String(const String& other) // Copy Constructor
{
    LOG("Copy Constructor Called");

    m_size = other.m_size;
    m_data = new char[m_size + 1];
    memcpy(m_data, other.m_data, m_size);
    m_data[m_size] = '\0';
}

String::String(String&& other) // Move Constructor
{
    LOG("Move Constructor Called");

    m_size = other.m_size;
    m_data = other.m_data;
    other.m_size = 0;
    other.m_data = nullptr;
}

String::~String() // Destructor
{
    LOG("Destructor Called");

    delete[] m_data;
}


size_t String::size() const // get length of string
{
    return m_size;
}

void String::clear() // clear string
{
    delete[] m_data;
    m_size = 0;
    m_data = nullptr;
}

bool String::empty() const // check if string is empty
{
    return m_size == 0;
}

const char* String::c_str() const // get C-String
{
    return m_data;
}


std::ostream& operator<<(std::ostream& os, const String& str)
{
    os << str.m_data;
    return os;
}

std::istream& operator>>(std::istream& is, String& str)
{
    char buffer[BUFFER_SIZE];
    is.get(buffer, BUFFER_SIZE);
    str = String(buffer);
    return is;
}

String& String::operator=(const String& other) // Copy Assignment
{
    if (this != &other)
    {
        delete[] m_data;
        m_size = other.m_size;
        m_data = new char[m_size + 1];
        memcpy(m_data, other.m_data, m_size);
        m_data[m_size] = '\0';
    }
    return *this;
}

String& String::operator=(String&& other) // Move Assignment
{
    if (this != &other)
    {
        delete[] m_data;
        m_size = other.m_size;
        m_data = other.m_data;
        other.m_size = 0;
        other.m_data = nullptr;
    }
    return *this;
}

char& String::operator[](size_t index) // get/set
{
    return m_data[index];
}

const char& String::operator[](size_t index) const // get only 
{
    return m_data[index];
}

// String Concatenation

String String::operator+(const String& other) const
{
    String result;
    result.m_size = m_size + other.m_size;
    result.m_data = new char[result.m_size + 1];
    memcpy(result.m_data, m_data, m_size);
    memcpy(result.m_data + m_size, other.m_data, other.m_size);
    result.m_data[result.m_size] = '\0';
    return result;
}

String String::operator+(const char* other) const
{
    String result;
    result.m_size = m_size + strlen(other);
    result.m_data = new char[result.m_size + 1];
    memcpy(result.m_data, m_data, m_size);
    memcpy(result.m_data + m_size, other, strlen(other));
    result.m_data[result.m_size] = '\0';
    return result;
}

String String::operator+(char other) const
{
    String result;
    result.m_size = m_size + 1;
    result.m_data = new char[result.m_size + 1];
    memcpy(result.m_data, m_data, m_size);
    result.m_data[m_size] = other;
    result.m_data[result.m_size] = '\0';
    return result;
}

String& String::operator+=(const String& other)
{
    *this = *this + other;
    return *this;
}

String& String::operator+=(const char* other)
{
    *this = *this + other;
    return *this;
}

String& String::operator+=(char other)
{
    *this = *this + other;
    return *this;
}

// String Comparison

bool String::operator==(const String& other) const
{
    return strcmp(m_data, other.m_data) == 0;
}

bool String::operator==(const char* other) const
{
    return strcmp(m_data, other) == 0;
}

bool String::operator!=(const String& other) const
{
    return strcmp(m_data, other.m_data) != 0;
}

bool String::operator!=(const char* other) const
{
    return strcmp(m_data, other) != 0;
}

bool String::operator<(const String& other) const
{
    return strcmp(m_data, other.m_data) < 0;
}

bool String::operator<(const char* other) const
{
    return strcmp(m_data, other) < 0;
}

bool String::operator>(const String& other) const
{
    return strcmp(m_data, other.m_data) > 0;
}

bool String::operator>(const char* other) const
{
    return strcmp(m_data, other) > 0;
}

bool String::operator<=(const String& other) const
{
    return strcmp(m_data, other.m_data) <= 0;
}

bool String::operator<=(const char* other) const
{
    return strcmp(m_data, other) <= 0;
}

bool String::operator>=(const String& other) const
{
    return strcmp(m_data, other.m_data) >= 0;
}

bool String::operator>=(const char* other) const
{
    return strcmp(m_data, other) >= 0;
}

// String Substring

String String::substr(size_t pos, size_t len) const
{
    String result;
    result.m_size = len;
    result.m_data = new char[result.m_size + 1];
    memcpy(result.m_data, m_data + pos, len);
    result.m_data[result.m_size] = '\0';
    return result;
}






