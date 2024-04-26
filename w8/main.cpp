#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>

using namespace std;

//comparing elements from the pair

struct Compare
{
    bool operator()(const pair<string, int>&a, const pair<string, int>& b)
    {
        if(a.second==b.second)
        {
            return a.first>b.first; //lexicogrammatically
        }
        return a.second<b.second; //by the frequency
    }
};

int main()
{
    ifstream file("map.txt"); //opens the file

    //checks wether the file exists or not
    if(!file.is_open())
    {
        cerr<<"file cannot be opened!!!";
        return 1;
    }

    //reading from the file
    string line;
    map<string, int> wordCount; //the map of the words and frequency

    while(getline(file, line))
    {
        string word;

        for(char& c:line)
        {
            if(c==' '|| c=='.' || c=='?' || c==',' || c=='!') //separators
            {
                if(!word.empty())
                {
                    for(char &ch:word)
                    {
                        ch=tolower(ch); //turning the words lowercase
                    }
                    wordCount[word]++; //add the word and frequency
                    word.clear();
                }
            }
            else
            {
                word+=c;
            }
        }
        if(!word.empty())
        {
            for(char& ch:word)
            {
                ch=tolower(ch);
            }
            wordCount[word]++;
        }
    }

    file.close();


    //priority queue <pair, vector<pair>, comparisson method>
    priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq;

    for(const auto& pair:wordCount)
    {
        pq.push(pair);
    }

    while(!pq.empty())
    {
        pair<string, int> top=pq.top();
        cout<<top.first<<"=>"<<top.second<<"\n";
        pq.pop();
    }

    return 0;
}