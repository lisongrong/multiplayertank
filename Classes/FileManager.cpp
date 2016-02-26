//
//  FileManager.cpp
//  GameTemplate
//
//  Created by 李崧榕 on 15/11/18.
//
//

#include "FileManager.hpp"

FileManager* FileManager::_instance = NULL;

const float KInterval_AutoSave = 1.0f;

FileManager* FileManager::getInstance()
{
    if(!_instance)
    {
        _instance = new FileManager();
        _instance->init();
        
        CCDirector::sharedDirector()->getScheduler()->scheduleSelector(schedule_selector(FileManager::updateSaveFile), _instance, KInterval_AutoSave, false);
    }
    return _instance;
}

void FileManager::destroyInstance()
{
    if(_instance)
    {
        CCDirector::sharedDirector()->getScheduler()->unscheduleAllForTarget(_instance);
        
        delete _instance;
        _instance = NULL;
    }
}

FileManager::FileManager()
: _need_save_user(false)
{
    
}

bool FileManager::init()
{
    _user = CCUserDefault::sharedUserDefault();
    
    return true;
}

// Json
Document FileManager::getJsonFile(const string &path)
{
    unsigned long size;
    unsigned char* uch_data = CCFileUtils::sharedFileUtils()->getFileData(path.c_str(), "r", &size);
    string str_data = string((const char*)uch_data, size);
    Document doc;
    doc.Parse<0>(str_data.c_str());
    
    if(doc.HasParseError())
        CCLOG("Json Parse Error : %s", doc.GetParseError());
    
    return doc;
}

// User
bool FileManager::getUserBool(string key, bool v_default/*false*/)
{
    return _user->getBoolForKey(key.c_str(), v_default);
}

void FileManager::setUserBool(string key, bool value)
{
    _need_save_user = true;
    _user->setBoolForKey(key.c_str(), value);
}

int FileManager::getUserInt(string key, int v_default/*0*/)
{
    return _user->getIntegerForKey(key.c_str(), v_default);
}

void FileManager::setUserInt(string key, int value)
{
    _need_save_user = true;
    _user->setIntegerForKey(key.c_str(), value);
}

double FileManager::getUserDouble(string key, double v_default/*0.0*/)
{
    return _user->getDoubleForKey(key.c_str(), v_default);
}

void FileManager::setUserDouble(string key, double value)
{
    _need_save_user = true;
    _user->setDoubleForKey(key.c_str(), value);
}

string FileManager::getUserString(string key, string v_default/*""*/)
{
    return _user->getStringForKey(key.c_str(), v_default);
}

void FileManager::setUserString(string key, string value)
{
    _need_save_user = true;
    _user->setStringForKey(key.c_str(), value);
}

// Save
void FileManager::updateSaveFile(float dt)
{
    if(_need_save_user)
    {
        _need_save_user = false;
        this->saveUserFile();
    }
}

void FileManager::saveUserFile()
{
    _user->flush();
}