//
//  StringHelper.hpp
//  GameTemplate
//
//  Created by 李崧榕 on 15/11/6.
//
//

#ifndef StringHelper_hpp
#define StringHelper_hpp

#include "cocos2d.h"
USING_NS_CC;
using namespace std;

class StringHelper
{
public:
    
    static string intToString(int val);
    static string floatToString(float val);
    static string pointToString(CCPoint val, string separator = ",");
    
    static int stringToInt(const string& val);
    static float stringToFloat(const string& val);
    static CCPoint stringToPoint(const string& val);
    
    static string replaceSubString(string str_source, const string& str_be_replace, const string& str_replace);
    static bool hasSubString(const string& str_source, const string& str_sub);
    static vector<string> getSeparateVec(const string& str_source, const string& separator);
};

#endif /* StringHelper_hpp */
