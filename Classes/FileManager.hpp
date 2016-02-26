//
//  FileManager.hpp
//  GameTemplate
//
//  Created by 李崧榕 on 15/11/18.
//
//

#ifndef FileManager_hpp
#define FileManager_hpp

#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;
using namespace std;
using namespace rapidjson;

#define guBool(__k__) FileManager::getInstance()->getUserBool(__k__)
#define guBoolV(__k__, __v__) FileManager::getInstance()->getUserBool(__k__, __v__)
#define suBoolV(__k__, __v__) FileManager::getInstance()->setUserBool(__k__, __v__)

#define guInt(__k__) FileManager::getInstance()->getUserInt(__k__)
#define guIntV(__k__, __v__) FileManager::getInstance()->getUserInt(__k__, __v__)
#define suIntV(__k__, __v__) FileManager::getInstance()->setUserInt(__k__, __v__)

#define guDouble(__k__) FileManager::getInstance()->getUserDouble(__k__)
#define guDoubleV(__k__, __v__) FileManager::getInstance()->getUserDouble(__k__, __v__)
#define suDoubleV(__k__, __v__) FileManager::getInstance()->setUserDouble(__k__, __v__)

#define guString(__k__) FileManager::getInstance()->getUserString(__k__)
#define guStringV(__k__, __v__) FileManager::getInstance()->getUserString(__k__, __v__)
#define suStringV(__k__, __v__) FileManager::getInstance()->setUserString(__k__, __v__)

class FileManager : public CCObject
{
public:
    
    static FileManager* getInstance();
    static void destroyInstance();
    
    // Json
    Document getJsonFile(const string& path);
    
    // User
    bool getUserBool(string key, bool v_default = false);
    void setUserBool(string key, bool value);
    
    int getUserInt(string key, int v_default = 0);
    void setUserInt(string key, int value);
    
    double getUserDouble(string key, double v_default = 0.0);
    void setUserDouble(string key, double value);
    
    string getUserString(string key, string v_default = "");
    void setUserString(string key, string value);
    
    // TODO: Custom
    
    // Save
    void updateSaveFile(float dt);
    void saveUserFile();
    
protected:
    
    FileManager();
    bool init();
    
private:
    
    static FileManager* _instance;
    
    CCUserDefault* _user;
    
    bool _need_save_user;
};

#endif /* FileManager_hpp */
