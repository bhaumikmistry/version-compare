/* 
@auther bmistry
@bfrief struct to deal with version management
 */

#include <cstdio>
#include <vector>
#include <string>
#include <iostream>


struct version
{
    int m_major = 0;
    int m_minor = 0;
    int m_revision = 0;
    int m_build = 0;

    std::string m_delimiter = "";

    version(int major,int minor ,int revision,int build,std::string delimiter=".")
    :m_major(major),
    m_minor(minor),
    m_revision(revision),
    m_build(build),
    m_delimiter(delimiter)
    {}

    version(std::string string_version,std::string delimiter="."):
    m_delimiter(delimiter)
    {
        std::string format = "%d" + m_delimiter + 
            "%d" + m_delimiter + 
            "%d" + m_delimiter + 
            "%d" + m_delimiter ; 
        std::sscanf(string_version.c_str(),format.c_str(),&m_major,&m_minor,&m_revision,&m_build);
    }

    std::string operator()()
    {
        std::string version = "";
        version += std::to_string(m_major);
        version += m_delimiter;
        version += std::to_string(m_minor);
        version += m_delimiter;
        version += std::to_string(m_revision);
        version += m_delimiter;
        version += std::to_string(m_build);
        return version;
    }

    bool operator>(const version& to_check)
    {
        if(this->m_major>to_check.m_major)
            return true;
        if(this->m_minor>to_check.m_minor)
            return true;
        if(this->m_revision>to_check.m_revision)
            return true;
        if(this->m_build>to_check.m_build)
            return true;

        return false;
    }

    bool operator<(const version& to_check)
    {
        if(this->m_major<to_check.m_major)
            return true;
        if(this->m_minor<to_check.m_minor)
            return true;
        if(this->m_revision<to_check.m_revision)
            return true;
        if(this->m_build<to_check.m_build)
            return true;

        return false;    }

    bool operator<=(const version& to_check)
    {
        return !operator>(to_check);
    }

    bool operator==(const version& to_check)
    {
        if(this->m_major==to_check.m_major)
            return true;
        if(this->m_minor==to_check.m_minor)
            return true;
        if(this->m_revision==to_check.m_revision)
            return true;
        if(this->m_build==to_check.m_build)
            return true;
        return false;
    }

    void increment(bool major,bool minor,bool revision,bool build)
    {
        (major)? m_major++ : 0 ;
        (minor)? m_minor++ : 0 ;
        (revision)? m_revision++ : 0 ;
        (build)? m_build++ : 0 ;
    }

};

// int main(int args, char ** arg)
// {
   
//     return 0;
// }