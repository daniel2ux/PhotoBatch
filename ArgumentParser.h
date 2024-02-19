//
// Created by daniel on 17/02/24.
//

#ifndef PHOTOBATCH_ARGUMENTPARSER_H
#define PHOTOBATCH_ARGUMENTPARSER_H
#include <string>
#include <map>

class ArgumentParser
{
public:
    void RegisterFlag(const std::string& flag);
    bool GetFlag(const std::string& flag) const;
    void Parser(int argc, char* argv[]);

private:
    std::map<std::string, bool> m_Flags;
};


#endif //PHOTOBATCH_ARGUMENTPARSER_H
