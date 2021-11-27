/*************************************************************************
 ** Optimal Page Replacement Algorithm.**
**************************************************************************/


#include <stdlib.h>
#include <set>
#include <functional>
#include <iostream>
#include<time.h>
#include <vector>

// Input Frame Size
// Input data - one number at a time.
// 

using namespace std;

class OptimalPageReplacementFrame {
    public:
        OptimalPageReplacementFrame(int frame_size, vector<int> page_nos) {
            // _frame_buffer = (int*)malloc(frame_size*sizeof(int));
            _frame_size = frame_size;
            _curr_size = 0;
            _page_nos = page_nos;
        }

        // Returns true if hit and false if miss.
        bool accessPage(int page_no, int pos) {
            // If frame is full.
            if(_curr_size >= _frame_size) {
                // Check if page is present in the frame.
                if(_frame_buffer.find(page_no) != _frame_buffer.end()) {
                // Hit
                    return true;
                } else {
                    // Miss
                    // Randomly select a page to replace.
                    // srand(time(0));
                    // int random_index = (rand())%_frame_size;
                    // set<int>::iterator random_itr = _frame_buffer.begin(); 
                    // advance(random_itr, random_index);

                    auto _farthest_used_page_no_itr = (_frame_buffer.begin());
                    int max_dist = 0;
                    auto start = _page_nos.begin();
                    advance(start, pos);
                    for(auto i = _farthest_used_page_no_itr; i!=_frame_buffer.end(); i++) {
                        auto j = i;
                        j++;
                        int dist = 1;
                        auto start = _page_nos.begin();
                        advance(start, pos);
                        for(auto j = start; j != _page_nos.end(); j++) {
                            if(*j == *i) {
                                break;
                            }
                            dist++;
                        }
                        if(dist > max_dist) {
                            max_dist = dist;
                            _farthest_used_page_no_itr = i;
                        }
                    }

                    // Remove randomly selected page
                    _frame_buffer.erase(_farthest_used_page_no_itr);
                    
                    // Insert new page
                    _frame_buffer.insert(page_no);
                    return false;
                } 
            } else {
                // If frame is not yet full.
                if(_frame_buffer.find(page_no) != _frame_buffer.end()) {
                    // Hit
                    return true;
                } else {
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

int optimal(int frame_size, vector<int> pageNoSeq) {
    int no_of_pages = pageNoSeq.size();
    int hits = 0, misses = 0;
    OptimalPageReplacementFrame*  frame;
    frame = new OptimalPageReplacementFrame(frame_size, pageNoSeq);
    int pos = 0;
    while(pos < no_of_pages) {
        int pageNo = pageNoSeq[pos];
        if(frame->accessPage(pageNo, pos)){
            hits++;
        } else {
            misses++;
        }
        pos++;
    }

    float hitRatio = ((float)(hits))/(hits + misses);
    return misses;
}
