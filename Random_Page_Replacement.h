/*************************************************************************
 ** Random Page Replacement Algorithm.**
**************************************************************************/

#include <stdlib.h>
#include <set>
#include <functional>
#include <iostream>
#include <time.h>

// Input Frame Size
// Input data - one number at a time.
//

using namespace std;

class RandomPageReplacementFrame
{
public:
    RandomPageReplacementFrame(int frame_size)
    {
        // _frame_buffer = (int*)malloc(frame_size*sizeof(int));
        _frame_size = frame_size;
        _curr_size = 0;
    }

    // Returns true if hit and false if miss.
    bool accessPage(int page_no)
    {
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
                // Randomly select a page to replace.
                srand(time(0));
                int random_index = (rand()) % _frame_size;
                set<int>::iterator random_itr = _frame_buffer.begin();
                advance(random_itr, random_index);

                // Remove randomly selected page
                _frame_buffer.erase(random_itr);

                // Insert new page
                _frame_buffer.insert(page_no);
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
    set<int, greater<int>> _frame_buffer;
};

int random(int frame_size, vector<int> pageNoSeq)
{
    int no_of_pages = pageNoSeq.size();
    int hits = 0, misses = 0;
    RandomPageReplacementFrame *frame;
    frame = new RandomPageReplacementFrame(frame_size);
    int pos = 0;
    while (pos < no_of_pages)
    {
        int pageNo = pageNoSeq[pos];
        if (frame->accessPage(pageNo))
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
