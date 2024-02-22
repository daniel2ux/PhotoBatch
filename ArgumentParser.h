#pragma once

#include <string>
#include <map>

/*
 * Classe utilizada para obter os argumentos da linha de comando
 *
 * Exemplo:
 * ArgumentParser argParser;
 * argParser.RegisterFlag("rename");
 * argParser.Parser(argc, argv);
 * argParser.GetFlag("rename")
 *
 */

template <typename T>
struct tag
{
    using type = T;
};

// Classe usada para ler os argumentos da linha de comando
class ArgumentParser
{
public:
    // Registra uma flag usada durante o parse
    void RegisterFlag(const std::string &flag);

    // Registrar uma opção usada durante o parser
    void RegisterOption(const std::string &option);

    // Obtem o valor de uma flag obtida durante o parse
    bool GetFlag(const std::string &flag) const;

    template <typename T>
    T GetOptionAs(const std::string &option) const { return GetOptionAs(option, tag<T>{}); }

    std::string GetOptionAs(const std::string &option, tag<std::string>) const { return GetOption(option); }

    float GetOptionAs(const std::string &option, tag<float>) const { return GetOptionAsFloat(option); }

    int GetOptionAs(const std::string &option, tag<int>) const { return GetOptionAsInt(option); }

    // Faz o parse da lista de argumento em argv
    void Parse(int argc, char *argv[]);

private:
    std::map<std::string, bool> m_Flags;
    std::map<std::string, std::string> m_Options;

    // Obter o valor de uma opção lida durante o parse
    std::string GetOption(const std::string &option) const;

    // Obter o valor de uma opção convertida para float
    float GetOptionAsFloat(const std::string &option) const;

    // Obter o valor de uma opção convertida para int
    int GetOptionAsInt(const std::string &option) const;
};
