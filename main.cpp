#include <stdlib.h>
#include <set>
#include <functional>
#include <iostream>
#include <time.h>
#include <vector>
#include "LRU_aos.h"
#include "Optimal_Page_Replacement.h"
#include "Random_Page_Replacement.h"
#include "Working_Set_Page_Replacement.h"
#include "fifo.h"
#include "fifo_2ndchance.h"
#include "nfu.h"
#include "nru.h"
#include <Python.h>

void run_algo(int choice);

 int data, pageNo, i = 0, hits = 0, misses = 0;
    FILE *fp = fopen("input.txt", "r");
    vector<int> pageNoSeq;

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

void run_algo(int choice, int no_of_pages)
    {
        int i,j;
        float mr;
        FILE* out_fp;
        out_fp = fopen("output.txt","w");       
        for(i=3;i<53;i++)
        {
            int frame_size = i;
            if (choice == 1) {
                mr = random(frame_size, pageNoSeq);
                // string coordinates = to_string(i)+","+to_string(mr)+"\n";
                // cout << coordinates;
                // fprintf(out_fp, "%s", coordinates.c_str());
            }
            if(choice == 2){
                mr = optimal(frame_size, pageNoSeq);
                // string coordinates = to_string(i)+","+to_string(mr)+"\n";
                // // cout << coordinates;
                // fprintf(out_fp, "%s", coordinates.c_str());
            }
            else if(choice == 3)
            {
                mr = NRU(pageNoSeq,frame_size);
                // string coordinates = to_string(i)+","+to_string(mr)+"\n";
                // // cout << coordinates;
                // fprintf(out_fp, "%s", coordinates.c_str());
            }
            else if(choice == 4)
            {
                mr = fifo(pageNoSeq,frame_size);
                string coordinates = to_string(i)+","+to_string(mr)+"\n";
                // cout << coordinates;
                fprintf(out_fp, "%s", coordinates.c_str());
            }
            else if(choice == 5)
            {
                mr = fifo_secondchance(pageNoSeq,frame_size);
                string coordinates = to_string(i)+","+to_string(mr)+"\n";
                // cout << coordinates;
                fprintf(out_fp, "%s", coordinates.c_str());
            }
            else if(choice == 7){
                mr = LRU(frame_size,pageNoSeq);
                string coordinates = to_string(i)+","+to_string(mr)+"\n";
                // cout << coordinates;
                fprintf(out_fp, "%s", coordinates.c_str());
            }
            else if(choice == 8)
            {
                mr = NFU(pageNoSeq,frame_size);
                string coordinates = to_string(i)+","+to_string(mr)+"\n";
                // cout << coordinates;
                fprintf(out_fp, "%s", coordinates.c_str());
            }
            else if(choice == 9)
            {
                mr = working_set(frame_size, pageNoSeq);
                string coordinates = to_string(i)+","+to_string(mr)+"\n";
                // cout << coordinates;
                fprintf(out_fp, "%s", coordinates.c_str());                        
            }
            else if(choice == 0){
                break;
            }
        }
        fclose(out_fp);
        char filename[] = "graph.py";
        FILE* fp;

        Py_Initialize();

        fp = _Py_fopen(filename, "r");
        PyRun_SimpleFile(fp, filename);

        Py_Finalize();
    }


int main() {
    // int data, pageNo, i = 0, hits = 0, misses = 0;
    // FILE *fp = fopen("input.txt", "r");
    // vector<int> pageNoSeq;

    // Read all page no. in advance.
    while(readNextPageNo(fp, &data)) {
        pageNo = data;
        pageNoSeq.push_back(pageNo);
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
        run_algo(choice, no_of_pages);
    }

    // void run_algo(int choice)
    // {
    //     int i,j;

    //     for(i=3;i<13;i++)
    //     {
    //         int frame_size = i;
    //             if (choice == 1) {
    //             RandomPageReplacementFrame*  frame;
    //             frame = new RandomPageReplacementFrame(frame_size);
    //             int pos = 0;
    //             while(pos < no_of_pages) {
    //                 int pageNo = pageNoSeq[pos];
    //                 if(frame->accessPage(pageNo)){
    //                         hits++;
    //                 } else {
    //                         misses++;
    //                 }
    //                 pos++;
    //             }

    //             float hitRatio = ((float)(hits))/(hits + misses);
    //             cout << " Total no. of page accesses : " << hits + misses << endl;
    //             cout << " No. of hits : " << hits << endl;
    //             cout << " No. of misses : " << misses << endl;
    //             cout << " Hit ratio : " << hitRatio << endl;            
    //         }
    //         if(choice == 2){
    //             OptimalPageReplacementFrame*  frame;
    //             frame = new OptimalPageReplacementFrame(frame_size, pageNoSeq);
    //             int pos = 0;
    //             while(pos < no_of_pages) {
    //                 int pageNo = pageNoSeq[pos];
    //                 if(frame->accessPage(pageNo, pos)){
    //                         hits++;
    //                 } else {
    //                         misses++;
    //                 }
    //                 pos++;
    //             }

    //             float hitRatio = ((float)(hits))/(hits + misses);
    //             cout << " Total no. of page accesses : " << hits + misses << endl;
    //             cout << " No. of hits : " << hits << endl;
    //             cout << " No. of misses : " << misses << endl;
    //             cout << " Hit ratio : " << hitRatio << endl;
    //         }
    //         else if(choice == 3)
    //         {
    //             mr = NRU(pageNoSeq,frame_size);
    //         }
    //         else if(choice == 4)
    //         {
    //             mr = fifo(pageNoSeq,frame_size);
    //         }
    //         else if(choice == 5)
    //         {
    //             mr = fifo_secondchance(pageNoSeq,frame_size);
    //         }
    //         else if(choice == 7){
    //             mr = LRU(frame_size,pageNoSeq);
    //         }
    //         else if(choice == 8)
    //         {
    //             mr = NFU(pageNoSeq,frame_size);
    //         }
    //         else if(choice == 9)
    //         {
    //             WorkingSetPageReplacementFrame*  frame;
    //             frame = new WorkingSetPageReplacementFrame(frame_size, pageNoSeq);
    //             int pos = 0;
    //             while(pos < no_of_pages) {
    //                 int pageNo = pageNoSeq[pos];
    //                 if(frame->accessPage(pageNo, pos)){
    //                         hits++;
    //                 } else {
    //                         misses++;
    //                 }
    //                 pos++;
    //             }
    //             float hitRatio = ((float)(hits))/(hits + misses);
    //             cout << " Total no. of page accesses : " << hits + misses << endl;
    //             cout << " No. of hits : " << hits << endl;
    //             cout << " No. of misses : " << misses << endl;
    //             cout << " Hit ratio : " << hitRatio << endl;            
    //         }
    //         else if(choice == 0){
    //             break;
    //         }
    //     }
    //     char filename[] = "graph.py";
	   //  FILE* fp;

    // 	Py_Initialize();

	   //  fp = _Py_fopen(filename, "r");
	   //  PyRun_SimpleFile(fp, filename);

	   //  Py_Finalize();
    // }
    return 0;
}