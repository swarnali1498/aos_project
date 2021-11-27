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

int working_set(int frame_size, vector<int> pageNoSeq)
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
    return misses;
}
