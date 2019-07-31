#include "../src/version.cpp"
#include <assert.h>
int main(int args, char ** arg)
{
    version v("1.2.3.4");
    assert(v.m_major==1);
    assert(v.m_minor==2);
    assert(v.m_revision==3);
    assert(v.m_build==4);

    version vOne("9.8.7.6");
    version vTwo("2.3.4.5");
    assert((vOne>vTwo)==true);
    assert((vOne<vTwo)==false);
    assert((vOne<=vTwo)==false);
    assert((vOne==vTwo)==false);

    version vThree("1.2.2.1");
    vThree.increment(false,true,true,false);
    assert(vThree()=="1.3.3.1");

    std::cout << 
    " [ Test RUN ] all ok! "
    << std::endl;

    return 0;
}