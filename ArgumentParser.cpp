//
// Created by daniel on 17/02/24.
//
#include "ArgumentParser.h"

void ArgumentParser::RegisterFlag(const std::string &flag)
{
    if (!flag.empty())
    {
        m_Flags[flag] = false;
    }
}

bool ArgumentParser::GetFlag(const std::string &flag) const
{
    if (!flag.empty())
    {
        auto flagIt = m_Flags.find(flag);

        if (flagIt != std::end(m_Flags))
        {
            return flagIt->second;
        }
    }

    return false;
}

void ArgumentParser::Parser(int argc, char **argv)
{
    if (argc > 1)
    {
        for (int i = 1; i < argc; ++i)
        {
            std::string arg = argv[i];
            if (arg.length() >= 3)
            {
                if (arg[0] == '-' && arg[1] == '-')
                {
                    arg = arg.substr(2);
                    if (arg.find_first_of('=') != std::string::npos)
                    {
                        // isso é uma opção
                    }
                    else
                    {
                        // isso é uma flag
                        auto flagIt = m_Flags.find(arg);
                        if (flagIt != std::end(m_Flags))
                        {
                            flagIt->second = true;
                        }
                    }
                }
            }
        }
    }
}
