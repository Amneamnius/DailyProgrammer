//Challenge #127[Intermediate]

#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

struct Worker {
    int myNum;
    int fwdNum;
    int vacStrt;
    int vacEnd;

    bool operator<(const Worker& a) const
    {
        return myNum < a.myNum;
    }
};

void AddZeros(std::stringstream &Chain, int value)
{
    if(value < 10)
        Chain << "000";
    else if(value < 100)
        Chain << "00";
    else if(value < 1000)
        Chain << "0";
}

template <class T>
inline std::string to_string(const T& t)
{
    std::stringstream ss;
    AddZeros(ss, t);
    ss << t;
    return ss.str();
}

void getWorkers(std::vector<Worker> &vac_Workers, int num_schd)
{
    Worker Temp;
    int vLst;

    for(int i = 0; i < num_schd; i++)
    {
        std::cin >> Temp.myNum >> Temp.fwdNum >> Temp.vacStrt >> vLst;
        Temp.vacEnd = Temp.vacStrt + vLst;

        vac_Workers.push_back(Temp);
    }
}

void keepOnlyVacWork(std::vector<Worker> &vac_Workers, int num_schd, int vacDay)
{
    for(int i = 0; i < num_schd; i++)
    {
        //If this worker is on vacation skip it
        if((vacDay < vac_Workers[i].vacStrt) || (vacDay > vac_Workers[i].vacEnd))
            vac_Workers.erase(vac_Workers.begin()+i);
    }
}

int main()
{
    int num_vac_sch;
    int tstDay;
    int vLst;
    int FNum;
    int chainLen;
    bool skipi;
    bool infLoop = 0;
    int maxChainLen = 0;
    int numfwdCalls = 0;
    Worker Temp;
    std::stringstream thisChain;
    std::vector<Worker> vacWorkers;
    std::vector<std::string> chains;
    std::size_t found;

    std::cin >> num_vac_sch;

    //Get the vacation schedule and phone numbers
    getWorkers(vacWorkers, num_vac_sch);

    std::cin >> tstDay;

    //Keep only the workers who are on vacation on the test day
    keepOnlyVacWork(vacWorkers, num_vac_sch, tstDay);

    //Sort the workers based on myNum
    std::sort(vacWorkers.begin(), vacWorkers.end());

    //Follow the chains
    for(int i = 0; i < num_vac_sch; i++)
    {
        //Initialize some Values
        thisChain.str("");
        skipi = false;
        chainLen = 0;
        //Initial forwarding
        FNum = vacWorkers[i].fwdNum;

        //is it already in a chain?
        for(unsigned int k = 0; k < chains.size(); k ++)
        {
            found = chains[k].find(to_string(vacWorkers[i].myNum));

            //If so then skip this i
            if(found != std::string::npos)
                skipi = true;
            if(skipi)
                break;
        }

        if(skipi)
            continue;

        //Otherwise create a new chain
        AddZeros(thisChain, vacWorkers[i].myNum);


        thisChain << vacWorkers[i].myNum << "->";
        AddZeros(thisChain, vacWorkers[i].fwdNum);
        thisChain << vacWorkers[i].fwdNum;

        chainLen++;
        numfwdCalls++;

        //Follow this chain
        for(int j = 0; j < num_vac_sch; j++)
        {
            if(vacWorkers[j].myNum == FNum)
            {
                FNum = vacWorkers[j].fwdNum;

                //If FNum is already in this chain then we have an inf loop
                found = thisChain.str().find(to_string(FNum));
                if(found != std::string::npos)
                    infLoop = true;

                thisChain << "->";
                AddZeros(thisChain, FNum);

                thisChain << FNum;
                chainLen++;
                numfwdCalls++;
            }
        }

        if(infLoop)
        {
            std::cout << "Infinite Loop: " << thisChain.str();
            return 0;
        }

        std::cout << thisChain.str() << std::endl;

        chains.push_back(thisChain.str());

        if(chainLen > maxChainLen)
            maxChainLen = chainLen;
    }

    std::cout << numfwdCalls << " call forwardings set up on day " << tstDay << std::endl;
    std::cout << maxChainLen << " call forwardings are the longest chain on day " << tstDay << std::endl;

    return 0;
}
