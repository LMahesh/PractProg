// Online C++ compiler to run C++ program online
#include <iostream>
#include <cstring>

char* strrev(const char* str1)
{
    std::cout << strlen(str1) << std::endl;
    int len = strlen(str1);
    char* tmp = new char[len];
    int j = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        //std::cout<<str1[i]<<std::endl;
        tmp[j] = str1[i];
        j++;
    }
    //tmp[j]='\0';
    //std::cout<<tmp<<std::endl;
    return tmp;

}
int substrcnt(const char* srcstr, const char* substr, int strl, int sstrl)
{
    //int strl = sizeof(srcstr);
    //int sstrl = sizeof(substr);
    std::cout << "strl:" << strl << "sstrl:" << sstrl << std::endl;
    std::cout << "srcstr:" << srcstr << "substr:" << substr << std::endl;
    int cnt = 0; int sustr = 0;

    for (int i = 0; i <= strl - sstrl; i++)
    {

        for (int m = 0; m < sstrl; m++)
        {
            if (srcstr[i + m] != substr[m])
            {
                //std::cout<<i<<" "<<m;
               // std::cout<<std::endl;
                break;
            }
            if (m == sstrl - 1)
            {
                std::cout << "substring is:" << substr << std::endl;
                cnt++;
            }
            // cnt++;    

        }

    }
    std::cout << "count:" << cnt << std::endl;
    return sustr;


}

int main() {

    const char* str = "MahMaheshMaheMahRamMahRaj";

    //char* ch = strrev(str);
   // ch = strrev(ch);
    int len = strlen(str);
    const char* str1 = "Mah";
    int len1 = strlen(str1);
    int strcnt = substrcnt(str, str1, len, len1);

    // Write C++ code here
    std::cout << "Try programiz.pro" << std::endl;
    // std::cout<<ch<<std::endl;
    return 0;
}