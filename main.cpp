#include <stdlib.h>
#include <set>
#include <functional>
#include <iostream>
#include<time.h>
#include <vector>
#include "LRU_aos.h"
#include "Optimal_Page_Replacement.h"
#include "Random_Page_Replacement.h"
#include "Working_Set_Page_Replacement.h"
#include "fifo.h"
#include "fifo_2ndchance.h"
#include "nfu.h"
#include "nru.h"


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
    vector<int> pageNoSeq;
    int frame_size;

    // Read all page no. in advance.
    while(readNextPageNo(fp, &data)) {
        if(i==0) {
            frame_size = data;
        } else {
            pageNo = data;
            pageNoSeq.push_back(pageNo);
        }
        i++;
    }

    int no_of_pages = i - 1;

    // Create Frame
    while(1){
        cout<<"Select Algorithm"<<endl;
        cout<<"1. Random Page Replacement algorithm"<<endl;
        cout<<"2. Optimal Page Replacement algorithm"<<endl;
        cout<<"3. NRU (Not Recently Used)"<<endl;
        cout<<"4. FIFO (First-In-First-Out)"<<endl;
        cout<<"5. FIFO with second chance"<<endl;
        cout<<"6. Clock"<<endl;
        cout<<"7. LRU (Least Recently Used)"<<endl;
        cout<<"8. NFU (Not Frequently Used)"<<endl;
        cout<<"9. Working Set"<<endl;
        cout<<"10. Aging (approximate LRU)"<<endl;
        cout<<"11.WSClock"<<endl;
        cout<<"0. Exit"<<endl;
        int choice;
        cin>>choice;

        if (choice == 1) {
            random(frame_size, pageNoSeq); // returning miss ratio
        }
        if(choice == 2){
            optimal(frame_size, pageNoSeq); // returning miss ratio
        }
        else if(choice == 3)
        {
            NRU(pageNoSeq,frame_size);
        }
        else if(choice == 4)
        {
            fifo(pageNoSeq,frame_size);
        }
        else if(choice == 5)
        {
            fifo_secondchance(pageNoSeq,frame_size);
        }
        else if(choice == 7){
            LRU(frame_size,pageNoSeq);
        }
        else if(choice == 8)
        {
            NFU(pageNoSeq,frame_size);
        }
        else if(choice == 9)
        {
            working_set(frame_size, pageNoSeq); // returning miss ratio
        }
        else if(choice == 0){
            break;
        }
    }
    return 0;
}