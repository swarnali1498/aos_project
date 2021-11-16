/*************************************************************************
 ** Random Page Replacement Algorithm.**
**************************************************************************/

#include <stdlib.h>
#include <set>
#include <functional>
#include <iostream>
#include<time.h>

// Input Frame Size
// Input data - one number at a time.
// 

using namespace std;

class RandomPageReplacementFrame {
    public:
        RandomPageReplacementFrame(int frame_size) {
            // _frame_buffer = (int*)malloc(frame_size*sizeof(int));
            _frame_size = frame_size;
            _curr_size = 0;
        }

        // Returns true if hit and false if miss.
        bool accessPage(int page_no) {
            // If frame is full.
            if(_curr_size >= _frame_size) {
                // Check if page is present in the frame.
                if(_frame_buffer.find(page_no) != _frame_buffer.end()) {
                // Hit
                    return true;
                } else {
                    // Miss
                    // Randomly select a page to replace.
                    srand(time(0));
                    int random_index = (rand())%_frame_size;
                    set<int>::iterator random_itr = _frame_buffer.begin(); 
                    advance(random_itr, random_index);

                    // Remove randomly selected page
                    _frame_buffer.erase(random_itr);
                    
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
        set<int, greater<int>> _frame_buffer;
};

bool readNextPageNo(FILE* fp ,int* pageNo) {
    int retval;

    if(fp == NULL) {
        printf("error in opening file\n");
        // handle it
    }
    // note the null statement in the body of the loop
    retval = fscanf(fp, "%d", pageNo);
    // cout << *pageNo << " " << retval << endl;
    if(retval == 0) {
        // read value not an integer. matching failure
        cout << "Error while reading input from file.";
        return false;
    }

    if(retval == EOF) {
    // end of file reached or a read error occurred
    if(ferror(fp)) {
        // read error occurred in the stream fp
        // clear it
        clearerr(fp);
    }
    fclose(fp);
    return false;
  }
    return true;
}

int main() {
    int data, pageNo, i = 0, hits = 0, misses = 0;
    FILE *fp = fopen("input.txt", "r");
    RandomPageReplacementFrame*  frame;
    while(readNextPageNo(fp, &data)) {
        if(i==0) {
            frame = new RandomPageReplacementFrame(data);
        } else {
            pageNo = data;
            if(frame->accessPage(pageNo)){
                hits++;
            } else {
                misses++;
            }
        }
        i++;
    }
    float hitRatio = ((float)(hits))/(hits + misses);
    cout << " Total no. of page accesses : " << hits + misses << endl;
    cout << " No. of hits : " << hits << endl;
    cout << " No. of misses : " << misses << endl;
    cout << " Hit ratio : " << hitRatio << endl;
    return 0;
}