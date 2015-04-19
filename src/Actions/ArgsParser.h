//
//  ArgsParser.h
//  ArgsParser
//
//  Created by SR3u on 01.12.14.
//  Copyright (c) 2014 SR3u. All rights reserved.
//

//Parser for cmdline arguments
//
//Simple usage example:
//
//int main(int argc,char *argv[])
//{
//   ArgsParser ap;
//   ap.parse(argc,argv);
//   std::cout<<"--arg="<<ap.getString("--arg")<<"\n";
//   return 0;
//}
//
//
#ifndef __ArgsParser__ArgsParser__
#define __ArgsParser__ArgsParser__

#include <map>
#include <string>
typedef std::map<std::string, std::string> Arguments_t;

class ArgsParser
{//Parser for cmdline arguments
    Arguments_t args;
public:
    static std::string trim(std::string const& source, char const* delims = " \t\r\n");//trims string
    static bool String2Bool(std::string str);
    ArgsParser();
    ArgsParser(const int argc, const char*argv[]);//Creates and calls ArgsParser::parse immediately!
    std::string getString(const std::string & key);//returns std::string value for key 'key'
    int getInt(const std::string & key);//returns int value for key 'key'
    long getLong(const std::string & key);//returns long value for key 'key'
    long long getLongLong(const std::string & key);//returns long long value for key 'key'
    unsigned int getUInt(const std::string & key);//returns unsigned int value for key 'key'
    unsigned long getULong(const std::string & key);//returns unsigned long value for key 'key'
    unsigned long long getULongLong(const std::string & key);//returns unsigned long long value for key 'key'
    bool getBool(const std::string & key);//returns boolean value for key 'key'
    float getFloat(const std::string & key);//returns float value for key 'key'
    double getDouble(const std::string & key);//returns double value for key 'key'
    long double getLongDouble(const std::string & key);//returns long double value for key 'key'
    Arguments_t getAll();//returns all arguments as Arguments_t
    void parse(const int argc, const char*argv[]);//Parses argc and argv (parameters of main function) cmdline arguments
    void clear();//clears all parsed data
    void add(const std::string &key,const std::string value);//adds value 'value' for key 'key'
    void del(const std::string &key);//removes value for key 'key'
    
    bool exists(const std::string &key);//returns true, if value for key 'key' exists
};

#endif /* defined(__ArgsParser__ArgsParser__) */
