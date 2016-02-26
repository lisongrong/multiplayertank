//
//  StringHelper.cpp
//  GameTemplate
//
//  Created by 李崧榕 on 15/11/6.
//
//

#include "StringHelper.hpp"

string StringHelper::intToString(int val)
{
    stringstream ss;
    ss << val;
    return ss.str();
}

string StringHelper::floatToString(float val)
{
    stringstream ss;
    ss << val;
    return ss.str();
}

string StringHelper::pointToString(cocos2d::CCPoint val, string separator/*,*/)
{
    return floatToString(val.x) + separator + floatToString(val.y);
}

int StringHelper::stringToInt(const string &val)
{
    int i = 0;
    stringstream ss(val);
    ss >> i;
    return i;
}

float StringHelper::stringToFloat(const string &val)
{
    float f = 0;
    stringstream ss(val);
    ss >> f;
    return f;
}

CCPoint StringHelper::stringToPoint(const string &val)
{
    vector<string> vec_str = getSeparateVec(val, ",");
    if(vec_str.size() == 2)
    {
        return CCPointMake(stringToFloat(vec_str[0]), stringToFloat(vec_str[1]));
    }
    else
    {
        CCLOG("stringToPoint parse error, str = %s", val.c_str());
        return CCPointZero;
    }
}

string StringHelper::replaceSubString(string str_source, const string &str_be_replace, const string &str_replace)
{
    string::size_type i = str_source.find_first_of(str_be_replace);
    if(i != string::npos)
    {
        str_source.replace(i, str_be_replace.length(), str_replace);
        i = str_source.find_first_of(str_be_replace);
    }
    return str_source;
}

bool StringHelper::hasSubString(const string &str_source, const string &str_sub)
{
    return str_source.find(str_sub) != string::npos;
}

vector<string> StringHelper::getSeparateVec(const string &str_source, const string &separator)
{
    vector<string> vec_str;
    string::size_type i_start = 0;
    string::size_type i = str_source.find(separator, i_start);
    string::size_type size_separator = separator.size();
    while(i != string::npos)
    {
        vec_str.push_back(str_source.substr(i_start, i - i_start));
        i_start = i + size_separator;
        i = str_source.find(separator, i_start);
    }
    vec_str.push_back(str_source.substr(i_start, str_source.size() - i_start));
    return vec_str;
}