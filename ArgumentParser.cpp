//
// Created by daniel on 17/02/24.
//
#include "ArgumentParser.h"
#include "Utils.h"

using std::string;

void ArgumentParser::RegisterFlag(const string &flag)
{
    if (!flag.empty())
    {
        m_Flags[flag] = false;
    }
}

void ArgumentParser::RegisterOption(const string &option)
{
    if (!option.empty())
    {
        m_Options[option] = "";
    }
}

bool ArgumentParser::GetFlag(const string &flag) const
{
    if (!flag.empty())
    {
        auto flagIt = m_Flags.find(flag);

        if (flagIt != std::end(m_Flags))
            return flagIt->second;
    }

    return false;
}

std::string ArgumentParser::GetOption(const string &option) const
{
    if (!option.empty())
    {
        auto optionIt = m_Options.find(option);

        if (optionIt != std::end(m_Options))
            return optionIt->second;
    }

    static string EmptyOption;
    return EmptyOption;
}

float ArgumentParser::GetOptionAsFloat(const string &option) const
{
    const string &optionValue = GetOption(option);

    if (!optionValue.empty())
    {
        return std::stof(optionValue);
    }

    return -1;
}

int ArgumentParser::GetOptionAsInt(const string &option) const
{
    const string &optionValue = GetOption(option);

    if (!optionValue.empty())
    {
        return std::stoi(optionValue);
    }

    return -1;
}

void ArgumentParser::Parse(int argc, char **argv)
{
    if (argc > 1)
    {
        for (int i = 1; i < argc; ++i)
        {
            string arg = Utils::ToLower(argv[i]);
            if (arg.length() >= 3)
            {
                if (arg[0] == '-' && arg[1] == '-')
                {
                    arg = arg.substr(2);
                    if (arg.find_first_of('=') != string::npos)
                    {
                        // isso é uma opção
                        const size_t equalsSizePos = arg.find('=');
                        if (equalsSizePos != string::npos)
                        {
                            // dividir a opção em chave e valor
                            string optionName = arg.substr(0, equalsSizePos);
                            string optionValue = arg.substr(equalsSizePos + 1);

                            auto optionIt = m_Options.find(optionName);
                            if (optionIt != end(m_Options))
                            {
                                // achamos uma opção válida
                                optionIt->second = optionValue;
                            }
                        }
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