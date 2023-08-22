
// This is a simple string class that I made for fun
// It is not meant to be used in production code
// It is meant to be used as a learning tool
// I am not responsible for any damage caused by this code
// Use at your own risk
/**
	@author Anirudh Madhusudhan
	@version 0.1
	@brief A simple string class
*/

#ifndef STRING_HPP
#define STRING_HPP

#if __cplusplus < 201103L // Mainly because of move semantics
    #error "This library needs at least a C++11 compliant compiler"
#endif

// This is for cin
#define BUFFER_SIZE 1024

#define DEBUG_LOG 0

#include <iostream>
#include <cstring>

class String
{
private:
    char* m_data;
    size_t m_size;
public:
    String(); // Default Constructor
    String(const char* str); // C-String Constructor
    String(const String& other); // Copy Constructor
    String(String&& other); // Move Constructor
    
    
    ~String(); // Destructor

    size_t size() const; // get length of string

    void clear(); // clear string

    bool empty() const; // check if string is empty

    const char* c_str() const; // get C-String
    
    // String Concatenation
    String operator+(const String& other) const;
    String operator+(const char* other) const;
    String operator+(char other) const;

    String& operator+=(const String& other);
    String& operator+=(const char* other);
    String& operator+=(char other);

    // String Comparison
    bool operator==(const String& other) const;
    bool operator==(const char* other) const;

    bool operator!=(const String& other) const;
    bool operator!=(const char* other) const;
    
    bool operator<(const String& other) const;
    bool operator<(const char* other) const;
    
    bool operator>(const String& other) const;
    bool operator>(const char* other) const;
    
    bool operator<=(const String& other) const;
    bool operator<=(const char* other) const;
    
    bool operator>=(const String& other) const;
    bool operator>=(const char* other) const;

    // String Stream
    friend std::ostream& operator<<(std::ostream& os, const String& str);
    friend std::istream& operator>>(std::istream& is, String& str);
    
    // String Assignment
    String& operator=(const String& other); // Copy Assignment
    String& operator=(String&& other); // Move Assignment

    // String Indexing
    char& operator[](size_t index); // get/set
    const char& operator[](size_t index) const; // get only 

    // String Substring
    String substr(size_t pos, size_t len) const;


};

#endif // STRING_HPP

