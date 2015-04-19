//
//  ArgsParser.cpp
//  KVM
//
//  Created by SR3u on 01.12.14.
//  Copyright (c) 2014 SR3u. All rights reserved.
//

#include "ArgsParser.h"
#include <iostream>

ArgsParser::ArgsParser(){}
ArgsParser::ArgsParser(const int argc, const char*argv[])
{
    this->parse(argc, argv);
}


std::string ArgsParser::trim(std::string const& source, char const* delims)
{
    std::string result(source);
    std::string::size_type index = result.find_last_not_of(delims);
    if(index != std::string::npos)
        result.erase(++index);
    index = result.find_first_not_of(delims);
    if(index != std::string::npos)
        result.erase(0, index);
    else
        result.erase();
    return result;
}

bool ArgsParser::String2Bool(std::string str)
{
    std::transform(str.begin(), str.end(), str.begin(),::tolower);
    switch (str[0])
    {
        case 0:
        case 'f':
            return false;
            break;
        case 1:
        case 't':
            return true;
            break;
        default:
            break;
    }
    if(str.find("true"))
        return true;
    if(str.find("false"))
        return false;
    if(str.find("1"))
        return true;
    if(str.find("0"))
        return false;
    return false;
}
std::string ArgsParser::getString(const std::string & key)
{
    Arguments_t::iterator it=args.find(key);
    if (it==args.end())
    {
        std::cout<<__PRETTY_FUNCTION__<<"[WARNING:] No value for key '"<<key<<"'.\n"
                 <<__PRETTY_FUNCTION__<<"[SOLVED:] returning empty string.\n";
        return "";
    }
    return args[key];
}
int ArgsParser::getInt(const std::string & key)
{
    std::string tmp=getString(key);
    if (tmp=="")
    {
        std::cout<<__PRETTY_FUNCTION__<<"[WARNING:] ArgsParser::getString returned empty string.\n"
                <<__PRETTY_FUNCTION__<<"[SOLVED:] Maybe no value for key '"<<key<<"', returning '0'.\n";
        return 0;
    }
    return std::stoi(tmp,NULL);
}
long ArgsParser::getLong(const std::string & key)
{
    std::string tmp=getString(key);
    if (tmp=="")
    {
        std::cout<<__PRETTY_FUNCTION__<<"[WARNING:] ArgsParser::getString returned empty string.\n"
        <<__PRETTY_FUNCTION__<<"[SOLVED:] Maybe no value for key '"<<key<<"', returning '0'.\n";
        return 0;
    }
    return std::stol(tmp,NULL);
}
long long ArgsParser::getLongLong(const std::string & key)
{
    std::string tmp=getString(key);
    if (tmp=="")
    {
        std::cout<<__PRETTY_FUNCTION__<<"[WARNING:] ArgsParser::getString returned empty string.\n"
        <<__PRETTY_FUNCTION__<<"[SOLVED:] Maybe no value for key '"<<key<<"', returning '0'.\n";
        return 0;
    }
    return std::stoll(tmp,NULL);
}
unsigned int ArgsParser::getUInt(const std::string & key)
{
    std::string tmp=getString(key);
    if (tmp=="")
    {
        std::cout<<__PRETTY_FUNCTION__<<"[WARNING:] ArgsParser::getString returned empty string.\n"
        <<__PRETTY_FUNCTION__<<"[SOLVED:] Maybe no value for key '"<<key<<"', returning '0'.\n";
        return 0;
    }
    return (unsigned int)std::stoul(tmp,NULL);
}
unsigned long ArgsParser::getULong(const std::string & key)
{
    std::string tmp=getString(key);
    if (tmp=="")
    {
        std::cout<<__PRETTY_FUNCTION__<<"[WARNING:] ArgsParser::getString returned empty string.\n"
        <<__PRETTY_FUNCTION__<<"[SOLVED:] Maybe no value for key '"<<key<<"', returning '0'.\n";
        return 0;
    }
    return std::stoul(tmp,NULL);
}
unsigned long long ArgsParser::getULongLong(const std::string & key)
{
    std::string tmp=getString(key);
    if (tmp=="")
    {
        std::cout<<__PRETTY_FUNCTION__<<"[WARNING:] ArgsParser::getString returned empty string.\n"
        <<__PRETTY_FUNCTION__<<"[SOLVED:] Maybe no value for key '"<<key<<"', returning '0'.\n";
        return 0;
    }
    return std::stoull(tmp,NULL);
}
bool ArgsParser::getBool(const std::string & key)
{
    std::string tmp=getString(key);
    if (tmp=="")
    {
        std::cout<<__PRETTY_FUNCTION__<<"[WARNING:] ArgsParser::getString returned empty string.\n"
        <<__PRETTY_FUNCTION__<<"[SOLVED:] Maybe no value for key '"<<key<<"', returning false.\n";
        return false;
    }
    return String2Bool(tmp);
}
float ArgsParser::getFloat(const std::string & key)
{
    std::string tmp=getString(key);
    if (tmp=="")
    {
        std::cout<<__PRETTY_FUNCTION__<<"[WARNING:] ArgsParser::getString returned empty string.\n"
        <<__PRETTY_FUNCTION__<<"[SOLVED:] Maybe no value for key '"<<key<<"', returning '0.0'.\n";
        return 0;
    }
    return std::stof(tmp,NULL);
}
double ArgsParser::getDouble(const std::string & key)
{
    std::string tmp=getString(key);
    if (tmp=="")
    {
        std::cout<<__PRETTY_FUNCTION__<<"[WARNING:] ArgsParser::getString returned empty string.\n"
        <<__PRETTY_FUNCTION__<<"[SOLVED:] Maybe no value for key '"<<key<<"', returning '0.0'.\n";
        return 0;
    }
    return std::stod(tmp,NULL);
}
long double ArgsParser::getLongDouble(const std::string & key)
{
    std::string tmp=getString(key);
    if (tmp=="")
    {
        std::cout<<__PRETTY_FUNCTION__<<"[WARNING:] ArgsParser::getString returned empty string.\n"
        <<__PRETTY_FUNCTION__<<"[SOLVED:] Maybe no value for key '"<<key<<"', returning '0.0'.\n";
        return 0;
    }
    return std::stold(tmp,NULL);
}
Arguments_t ArgsParser::getAll()
{
    return args;
}

void ArgsParser::clear()
{
    args.clear();
}
void ArgsParser::add(const std::string &key,const std::string value)
{
    Arguments_t::iterator it=args.find(key);
    if (it!=args.end())
    {
        std::cout<<__PRETTY_FUNCTION__<<"[WARNING:] Dublicated key '"<<key<<"'.\n"
                 <<__PRETTY_FUNCTION__<<"[SOLVED:] Replacing value '"<<it->second<<"' with '"<<value<<"\n";
        args.erase(it);
    }
    args[key]=value;
}
void ArgsParser::del(const std::string &key)
{
    Arguments_t::iterator it=args.find(key);
    if (it==args.end())
    {
        std::cout<<__PRETTY_FUNCTION__<<"[WARNING:] No key '"<<key<<"'! Cannot delete nothing!\n";
        return;
    }
    args.erase(it);
}

void ArgsParser::parse(const int argc, const char*argv[])
{
    std::string line,name,value;
    std::string::size_type posEqual;
    for (int i=1; i<argc; i++)//argv[0] is program name!
    {
        line=argv[i];
        if (!line.length()) continue;
        posEqual=line.find('=');
        if(posEqual!=std::string::npos)
        {
            name = trim(line.substr(0,posEqual));
            value = trim(line.substr(posEqual+1));
            args[name]=value;
        }
        else
            args[""]=line;
    }
}
bool ArgsParser::exists(const std::string &key)
{
    Arguments_t::iterator it=args.find(key);
    if (it!=args.end())
        return true;
    return false;
}