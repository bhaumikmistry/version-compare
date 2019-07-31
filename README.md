# version-compare

[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg)](https://github.com/bhaumikmistry/name-generator/blob/master/CONTRIBUTING.md)
[![MIT license](https://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/bhaumikmistry/name-generator/blob/master/LICENSE)
[![version](https://img.shields.io/github/tag-date/bhaumikmistry/version-compare)]()

Simple tool to deal with Versions of software, .pkg, files.

To compare version strings in c++, start with storing the string in struct or a class and the second thing you need to know is 'How to split a string in C++?'. 

This can be used in the version management of any project or software in c++. You will be able to manipulate, update, compare and generate string formatted version string using following struct.

+ src
    + version.cpp
+ test
    + test.cpp
    + ./test


## How to split string to get version out of it.
---
+ STRTOK
+ SSCANF

### STRTOK
> Slower than sscanf but one of the way to do it.
```
    char * pch;
    pch = strtok(const_cast<char*>(string_version.c_str()),m_delimiter.c_str());
    std::vector<std::string> data;
    while(pch != NULL)
    {
        data.push_back(std::string(pch));
        pch = strtok(NULL,m_delimiter.c_str());
    }

    m_major=std::stoi(data[0]);
    m_minor=std::stoi(data[1]);
    m_revision=std::stoi(data[2]);
    m_build=std::stoi(data[3]);
```
### SSCANF
> Split the string and store values in respective values.
```
    std::string format = "%d" + m_delimiter + 
        "%d" + m_delimiter + 
        "%d" + m_delimiter + 
        "%d" + m_delimiter ; 
    std::sscanf(string_version.c_str(),format.c_str(),&m_major,&m_minor,&m_revision,&m_build);
```

### Example and Test
Check out test and example in /test.