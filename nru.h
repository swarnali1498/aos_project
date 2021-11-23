#include <bits/stdc++.h>
using namespace std;
// if same prefrence in NRU then use LRU
// 1-not modified       not referenced
// 2-not referenced     modified
// 3-referenced         not modified
// 4-referenced         modified

int replacePage(unordered_map<int, int> table, unordered_map<int, int> priority)
{
    int minPrior = 5;
    int oldPage;
    for (auto a : priority)
    {
        if (a.second < minPrior)
        {
            minPrior = a.second;
        }
    }
    // if many pages have same priority then we use LRU to choose a page for replacement
    int minRef = INT_MAX;
    for (auto a : table)
    {
        if ((priority[a.first] == minPrior) && (a.first < minRef))
        {
            minRef = a.second;
            oldPage = a.first;
        }
    }
    return oldPage;
}

// randomly modify half pages of the process
map<int, int> modify(set<int> unique)
{
    int n = unique.size();
    set<int>::iterator it;
    map<int, int> modified;
    set<int> mod;
    for (auto i = unique.begin(); i != unique.end(); i++)
        modified[*i] = 0;
    srand(time(0));
    //cout << "Modified Pages: ";
    while (mod.size() != n / 2)
    {
        int x = rand() % n;
        it = next(unique.begin(), x);
        mod.insert(*it);
    }
    for (auto a : mod)
    {
        modified[a] = 1;
      //  cout << a << " ";
    }
    //cout << endl;
    return modified;
}

float performance(int n, int pageFault)
{
    //cout << "Number of Page Faults: " << pageFault << endl;
    double missRatio = double(pageFault) / n;
    double hitRatio = 1 - missRatio;

    //cout << "Hit Ratio: " << setprecision(2) << hitRatio << endl;
    //cout << "Miss Ratio: " << setprecision(2) << missRatio << endl;
    return missRatio;
}

int NRU(vector<int> pages, int frames)
{
    // string s2;
    // stringstream s(str);
    set<int> unique;
    int n = pages.size();

    for (int i = 0; i < n; i++)
    {
        // pages[i] = stoi(s2);
        unique.insert(pages[i]);
    }
    // int n = i;
    map<int, int> modified = modify(unique); // page_num->modified bit
    unordered_map<int, int> table;           // page_num->last reference of that page
    unordered_map<int, int> reference;       // page_num->reference bit
    unordered_map<int, int> priority;        // page_num->priority list number
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
                int oldPage = replacePage(table, priority);
                table.erase(oldPage);
                reference.erase(oldPage);
                modified.erase(oldPage);
                priority.erase(oldPage);
            }
            table[pages[i]] = i;
            reference[pages[i]] = 0;
            priority[pages[i]] = 1;
        }
        // page is already in memory, update the referenced bit
        else
        {
            reference[pages[i]] = 1;
            if (modified[pages[i]] == 1)
                priority[pages[i]] = 4;
            else
                priority[pages[i]] = 3;
            table[pages[i]] = i;
        }
        // cout << "\nPages in memory:: " << endl;
        // for (auto a : table)
        //     cout << a.first << " ";
        // cout << endl;
    }
    float missRatio = performance(n, pageFault);
    return pageFault;
}

// int main()
// {
//     int frames;
//     string a, b;
//     ifstream inputFile("input.txt");
//     inputFile.is_open();
//     while (true)
//     {
//         if (!inputFile.eof())
//         {

//             getline(inputFile, a);
//             getline(inputFile, b);
//             frames = stoi(a);
//             //-----------
//             vector<int> pages;
//             string s2;
//             stringstream s(b);
//             while (getline(s, s2, ' '))
//             {
//                 pages.push_back(stoi(s2));
//             }
//             //----------
//             LRU(pages, frames);
//             cout << endl
//                  << endl;
//         }
//         else
//             break;
//     }
//     return 0;
// }