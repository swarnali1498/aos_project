#include <bits/stdc++.h>
using namespace std;

int replacePage(unordered_map<int, int> table, unordered_map<int, int> counter)
{
    int oldPage;
    int minCount = INT_MAX;
    for (auto a : table)
    {
        // if more than one page have a min count then we use LRU to select page
        if ((counter[a.first] < minCount) || ((counter[a.first] == minCount) && table[oldPage] > a.second))
        {
            minCount = counter[a.first];
            oldPage = a.first;
        }
    }
    return oldPage;
}

void performance(int n, int pageFault)
{
    cout << "Number of Page Faults: " << pageFault << endl;
    double missRatio = double(pageFault) / n;
    double hitRatio = 1 - missRatio;

    cout << "Hit Ratio: " << setprecision(2) << hitRatio << endl;
    cout << "Miss Ratio: " << setprecision(2) << missRatio << endl;
}

void NFU(string str, int frames)
{
    string s2;
    stringstream s(str);
    int pages[100], i = 0;
    while (getline(s, s2, ' '))
    {
        pages[i] = stoi(s2);
        i++;
    }
    int n = i;
    unordered_map<int, int> table; // page_num->counter
    unordered_map<int, int> counter;
    int pageFault = 0;
    int capacity = frames;
    for (int i = 0; i < n; i++)
    {
        // if the page is not in the memory
        if (table.find(pages[i]) == table.end())
        {
            pageFault++;
            // no space in the memory
            if (table.size() >= capacity)
            {
                // select a page to replace from the memory
                int oldPage = replacePage(table, counter);
                table.erase(oldPage);
                counter.erase(oldPage);
            }
            table[pages[i]] = i;
            counter[pages[i]]++;
        }
        // page is already in memory, update the referenced bit
        else
        {
            table[pages[i]] = i;
            counter[pages[i]]++;
        }
        cout << "\nPages in memory:: " << endl;
        for (auto a : table)
            cout << a.first << " ";
        cout << endl;
    }
    performance(n, pageFault);
}

int main()
{
    int frames;
    string a, b;
    ifstream inputFile("input.txt");
    inputFile.is_open();
    while (true)
    {
        if (!inputFile.eof())
        {
            getline(inputFile, a);
            getline(inputFile, b);
            frames = stoi(a);
            NFU(b, frames);
            cout << endl;
        }
        else
            break;
    }
    return 0;
}