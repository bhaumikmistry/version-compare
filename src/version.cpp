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

        // std::string format = "%d" + m_delimiter + 
        //     "%d" + m_delimiter + 
        //     "%d" + m_delimiter + 
        //     "%d" + m_delimiter ; 
        // std::sscanf(string_version.c_str(),format.c_str(),&m_major,&m_minor,&m_revision,&m_build);

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
        return operator>(to_check);
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

int main(int args, char ** arg)
{
    std::cout << "main()" << std::endl;
    
    version v(2,3,4,5);
    std::string ver = v();
    std::cout << ver << std::endl;

    version v1("4.1.6.2",".");
    std::string ver1 = v1();
    std::cout << ver1 << std::endl;

    std::cout<< ((v1>v)? "true":"false") << std::endl;

    version v2(2,3,4,5);
    version v3("2.3.4.6",".");
    std::cout<< ((v2<v3)? "true":"false") << std::endl;

    version v4(2,3,4,4);
    version v5("2.3.4.5",".");
    std::cout<< ((v4==v5)? "true":"false") << std::endl;

    version v6(2,3,4,5);
    v6.increment(false,false,true,true);
    ver = v6();
    std::cout << ver << std::endl;


    return 0;
}