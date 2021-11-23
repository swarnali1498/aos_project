/*************************************************************************
 ** Working Set Page Replacement Algorithm.**
**************************************************************************/

#include <stdlib.h>
#include <set>
#include <functional>
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
#include <queue>

// Input Frame Size
// Input data - one number at a time.
//

using namespace std;

class WorkingSetPageReplacementFrame
{
public:
    WorkingSetPageReplacementFrame(int frame_size, vector<int> page_nos)
    {
        // _frame_buffer = (int*)malloc(frame_size*sizeof(int));
        _frame_size = frame_size;
        _curr_size = 0;
        _page_nos = page_nos;
    }

    deque<int> working_set;

    // Returns true if hit and false if miss.
    bool accessPage(int page_no, int pos)
    {
        if (working_set.size() == _frame_size)
        {
            working_set.pop_front();
        }
        working_set.push_back(page_no);
        // cout << "Working set : ";
        // for(int i=0; i<working_set.size(); i++) {
        //     cout << working_set[i]<< " ";
        // }
        // cout << endl;
        // If frame is full.
        if (_curr_size >= _frame_size)
        {
            // Check if page is present in the frame.
            if (_frame_buffer.find(page_no) != _frame_buffer.end())
            {
                // Hit
                return true;
            }
            else
            {
                // Miss
                set<int>::iterator itr = _frame_buffer.begin();
                bool slot_emptied = false;
                for (int i = 0; i < _curr_size; i++)
                {
                    // If the page is not found in the working set we remove it from the frame_buffer.
                    if (find(working_set.begin(), working_set.end(), *itr) == working_set.end())
                    {
                        _frame_buffer.erase(*itr);
                        slot_emptied = true;
                        break;
                    }
                    advance(itr, 1);
                }

                if (slot_emptied)
                {
                    _frame_buffer.insert(page_no);
                }
                return false;
            }
        }
        else
        {
            // If frame is not yet full.
            if (_frame_buffer.find(page_no) != _frame_buffer.end())
            {
                // Hit
                return true;
            }
            else
            {
                // Insert new page
                _frame_buffer.insert(page_no);
                _curr_size++;
                return false;
            }
        }
    }

private:
    int _frame_size;
    int _curr_size;
    vector<int> _page_nos;
    set<int, greater<int>> _frame_buffer;
};

float working_set(int frame_size, vector<int> pageNoSeq)
{
    int no_of_pages = pageNoSeq.size();
    int hits = 0, misses = 0;
    WorkingSetPageReplacementFrame *frame;
    frame = new WorkingSetPageReplacementFrame(frame_size, pageNoSeq);
    int pos = 0;
    while (pos < no_of_pages)
    {
        int pageNo = pageNoSeq[pos];
        if (frame->accessPage(pageNo, pos))
        {
            hits++;
        }
        else
        {
            misses++;
        }
        pos++;
    }
    float hitRatio = ((float)(hits)) / (hits + misses);
    cout << " Total no. of page accesses : " << hits + misses << endl;
    cout << " No. of hits : " << hits << endl;
    cout << " No. of misses : " << misses << endl;
    cout << " Hit ratio : " << hitRatio << endl;
    return (1 - hitRatio);
}

// bool readNextPageNo(FILE* fp ,int* pageNo) {
//     int retval;

//     if(fp == NULL) {
//         printf("error in opening file\n");
//         // handle it
//     }
//     // note the null statement in the body of the loop
//     retval = fscanf(fp, "%d", pageNo);
//     // cout << *pageNo << " " << retval << endl;
//     if(retval == 0) {
//         // read value not an integer. matching failure
//         cout << "Error while reading input from file.";
//         return false;
//     }

//     if(retval == EOF) {
//     // end of file reached or a read error occurred
//     if(ferror(fp)) {
//         // read error occurred in the stream fp
//         // clear it
//         clearerr(fp);
//     }
//     fclose(fp);
//     return false;
//   }
//     return true;
// }

// int main() {
//     int data, pageNo, i = 0, hits = 0, misses = 0;
//     FILE *fp = fopen("input.txt", "r");
//     WorkingSetPageReplacementFrame*  frame;
//     vector<int> pageNoSeq;
//     int frame_size;

//     // Read all page no. in advance.
//     while(readNextPageNo(fp, &data)) {
//         if(i==0) {
//             frame_size = data;
//         } else {
//             pageNo = data;
//             pageNoSeq.push_back(pageNo);
//         }
//         i++;
//     }

//     int no_of_pages = i - 1;

//     // Create Frame
//     frame = new WorkingSetPageReplacementFrame(frame_size, pageNoSeq);
//     int pos = 0;
//     while(pos < no_of_pages) {
//         int pageNo = pageNoSeq[pos];
//         if(frame->accessPage(pageNo, pos)){
//                 hits++;
//         } else {
//                 misses++;
//         }
//         pos++;
//     }

//     float hitRatio = ((float)(hits))/(hits + misses);
//     cout << " Total no. of page accesses : " << hits + misses << endl;
//     cout << " No. of hits : " << hits << endl;
//     cout << " No. of misses : " << misses << endl;
//     cout << " Hit ratio : " << hitRatio << endl;
//     return 0;
// }