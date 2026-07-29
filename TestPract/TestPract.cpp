// Online C++ compiler to run C++ program online
/*
#include <iostream>
#include<vector>

using namespace std;

class weatherstation  //observer
{
public:

    virtual void update(float temp, float pressure, float humdi) = 0;
};

class stngroup // subject
{
public:
    float temperatur;
    float pressr;
    float humdit;
    std::vector<weatherstation*>stn;
    void regweatherstns(weatherstation* stn1)
    {
        stn.push_back(stn1);
    }
    void setparams(float temp, float hum, float pres)
    {

        temperatur = temp;
        humdit = hum;
        pressr = pres;
        notify();
    }
    void notify()
    {
        for (int i = 0; i < stn.size(); i++)
            stn[i]->update(temperatur, humdit, pressr);
    }

};


class display :public  weatherstation
{
public:
    void update(float temp, float hum, float pres)
    {
        std::cout << " tempera" << temp << "humidity" << hum << pres << std::endl;
    }


};

using namespace std;
int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro" << std::endl;

    display ds1;
    display ds2;
    stngroup* stngrp = new stngroup();
    stngrp->regweatherstns(&ds1);
    stngrp->setparams(35, 455, 34);
    return 0;
}*/




/*
#include<iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

int i = 0;
condition_variable cv;
mutex mtx;


void print_odd()
{
    
    for (;i < 100;)
    {
        std::unique_lock<std::mutex>locker(mtx);
        cv.wait(locker, []() {return i % 2 == 1; });
            std::cout << "odd:" << i <<" ";
        locker.unlock();
        i++;
            cv.notify_one();


    }

}

void print_even()
{
    
    for (; i < 100;)
    {
        std::unique_lock<std::mutex>locker(mtx);
        cv.wait(locker, []() {return i % 2 == 0; });
            std::cout << "even:" << i<< " ";
        locker.unlock();
        i++;
        cv.notify_one();


    }
}

int main()
{
    thread th1(print_odd);
    thread th2(print_even);
    th1.join();
    th2.join();
}
*/
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
/*
#include <iostream>
#include <cstring>
#include <memory>

using namespace std;


unique_ptr<char[]> strrev(const char* str1)

{
    int len = strlen(str1);
    std::cout << len << str1 << std::endl;
   // char* temp = new char[len];
    unique_ptr<char[]>uptr1(new char[len+1]);
    int i = 0;
    for (int j = len-1; j >= 0; j--)
    {
        
        uptr1[i] = str1[j];
        //std::cout<<temp[i]<<" ";
        i = i++;
    }
    while (i <= strlen(str1))
    {
        temp[i] = str1[--len];
        std::cout<<temp[i]<<" ";
       i = i + 1;
        //len = len - 1;
    }
    uptr1[len] = '\0';
    std::cout <<"i value"<< i << std::endl;
    std::cout << uptr1;
    return uptr1;
}





int main()
{
    const char* str = "MaheshLagisetty";
    unique_ptr<char[]>uptr2 = move(strrev(str));
    //std::cout << "Hello World";

    return 0;
}



*/


/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

void strfreq(const char* str, const char* sstr, int slen, int sublen)
{
    int cnt = 0;
    int fcnt = 0;
    for (int i = 0; i <= slen-sublen; i++)
    {

        for (int j = 0; j < sublen; j++)
        {

            if (sstr[j] != str[i + j])
            {
                break;
            }
            if (j ==sublen-1)
            {

             
                    fcnt++;
       
            }

        }
        cnt = 0;
    }
    std::cout << sstr << " repeated:  " << fcnt << std::endl;

}

int main()
{
    const char* str = "MahMaheshMaheMahRamMah"; //22
    const char* sstr = "Mah";

    
    int slen = strlen(str);
    int sublen = strlen(sstr);
    std::cout << slen << " " << sizeof(slen) << std::endl;

    strfreq(str, sstr, slen, sublen);
    std::cout << "Hello World";

    string str1 = str;
    std::cout << "string is " << str << std::endl;
    for (string::size_type i = str1.find("Mah"); i!= string::npos; i = str1.find("Mah"))
    {
        str1.erase(i, 3);
    }
    /*for (string::size_type i = str1.find("+"); i != string::npos; i = str1.find("+"))
    {
        str1.erase(i, 1);
    }*/
    std::cout <<"After sub str erase:"<< str1 << std::endl;
    return 0;
}