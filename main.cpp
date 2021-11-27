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
#include "clock.h"
#include "nfu.h"
#include "nru.h"
#include "aging.h"
#include "wsclock.h"
#include <Python.h>

void run_algo(int choice);

int data, pageNo, i = 0, hits = 0, misses = 0;
FILE *fp = fopen("input2.txt", "r");
vector<int> pageNoSeq;

bool readNextPageNo(FILE *fp, int *pageNo)
{
    int retval;

    if (fp == NULL)
    {
        printf("error in opening file\n");
        // handle it
    }
    // note the null statement in the body of the loop
    retval = fscanf(fp, "%d", pageNo);
    // cout << *pageNo << " " << retval << endl;
    if (retval == 0)
    {
        // read value not an integer. matching failure
        cout << "Error while reading input from file.";
        return false;
    }

    if (retval == EOF)
    {
        // end of file reached or a read error occurred
        if (ferror(fp))
        {
            // read error occurred in the stream fp
            // clear it
            clearerr(fp);
        }
        fclose(fp);
        return false;
    }
    return true;
}

void run_algo(int no_of_pages)
{
    int i, j;
    int nm;
    float mr;
    //----------------------------------------------------
    FILE *random_pt;
    random_pt = fopen("random_output.txt", "w");
    FILE *optimal_pt;
    optimal_pt = fopen("optimal_output.txt", "w");
    FILE *nru_pt;
    nru_pt = fopen("nru_output.txt", "w");
    FILE *fifo_pt;
    fifo_pt = fopen("fifo_output.txt", "w");
    FILE *fifo2nd_pt;
    fifo2nd_pt = fopen("fifo2nd_output.txt", "w");
    FILE *clock_pt;
    clock_pt = fopen("clock_output.txt", "w");
    FILE *lru_pt;
    lru_pt = fopen("lru_output.txt", "w");
    FILE *nfu_pt;
    nfu_pt = fopen("nfu_output.txt", "w");
    FILE *workingset_pt;
    workingset_pt = fopen("workingset_output.txt", "w");
    FILE *aging_pt;
    aging_pt = fopen("aging_output.txt", "w");
    FILE *wsclock_pt;
    wsclock_pt = fopen("wsclock_output.txt", "w");
    //-----------------------------------------------------

    for (i = 14; i < 20; i++)
    {
            int frame_size = i;
            int swaps=0;
            //----------------------Random----------------------------------
            nm = random(frame_size, pageNoSeq);
            if(nm>i)
            {
                swaps=nm-i;
            }
            string coordinates = to_string(i) + "," + to_string((float(nm))/no_of_pages) + "," + to_string(swaps) + "\n";
            //cout << coordinates;
            fprintf(random_pt, "%s", coordinates.c_str());
            //--------------------------------------------------------------

            coordinates = "";
            //----------------------Optimal---------------------------------
            nm = optimal(frame_size, pageNoSeq);
            if(nm>i)
            {
                swaps=nm-i;
            }
            coordinates = to_string(i) + "," + to_string((float(nm))/no_of_pages) + "," + to_string(swaps) + "\n";
            // cout << coordinates;
            fprintf(optimal_pt, "%s", coordinates.c_str());
            //--------------------------------------------------------------

            coordinates = "";
            //----------------------NRU-------------------------------------
            nm = NRU(pageNoSeq, frame_size);
            if(nm>i)
            {
                swaps=nm-i;
            }
            coordinates = to_string(i) + "," + to_string((float(nm))/no_of_pages) + "," + to_string(swaps) + "\n";
            // cout << coordinates;
            fprintf(nru_pt, "%s", coordinates.c_str());
            //--------------------------------------------------------------

            coordinates = "";
            //----------------------FIFO------------------------------------
            nm = fifo(pageNoSeq, frame_size);
            if(nm>i)
            {
                swaps=nm-i;
            }
            coordinates = to_string(i) + "," + to_string((float(nm))/no_of_pages) + "," + to_string(swaps) + "\n";
            // cout << coordinates;
            fprintf(fifo_pt, "%s", coordinates.c_str());
            //--------------------------------------------------------------

            coordinates = "";
            //----------------------FIFO second chance----------------------
            nm = fifo_secondchance(pageNoSeq, frame_size);
            if(nm>i)
            {
                swaps=nm-i;
            }
            coordinates = to_string(i) + "," + to_string((float(nm))/no_of_pages) + "," + to_string(swaps) + "\n";
            // cout << coordinates;
            fprintf(fifo2nd_pt, "%s", coordinates.c_str());
            //--------------------------------------------------------------

            coordinates = "";
            //----------------------Clock----------------------
            nm = clock(pageNoSeq, frame_size);
            if(nm>i)
            {
                swaps=nm-i;
            }
            coordinates = to_string(i) + "," + to_string((float(nm))/no_of_pages) + "," + to_string(swaps) + "\n";
            // cout << coordinates;
            fprintf(clock_pt, "%s", coordinates.c_str());
            //--------------------------------------------------------------


            coordinates = "";
            //----------------------LRU-------------------------------------
            nm = LRU(frame_size, pageNoSeq);
            if(nm>i)
            {
                swaps=nm-i;
            }
            coordinates = to_string(i) + "," + to_string((float(nm))/no_of_pages) + "," + to_string(swaps) + "\n";
            // cout << coordinates;
            fprintf(lru_pt, "%s", coordinates.c_str());
            //--------------------------------------------------------------

            coordinates = "";
            //----------------------NFU-------------------------------------
            nm = NFU(pageNoSeq, frame_size);
            if(nm>i)
            {
                swaps=nm-i;
            }
            coordinates = to_string(i) + "," + to_string((float(nm))/no_of_pages) + "," + to_string(swaps) + "\n";
            // cout << coordinates;
            fprintf(nfu_pt, "%s", coordinates.c_str());
            //--------------------------------------------------------------

            coordinates = "";
            //----------------------Working Set-----------------------------
            nm = working_set(frame_size, pageNoSeq);
            if(nm>i)
            {
                swaps=nm-i;
            }
            coordinates = to_string(i) + "," + to_string((float(nm))/no_of_pages) + "," + to_string(swaps) + "\n";
            // cout << coordinates;
            fprintf(workingset_pt, "%s", coordinates.c_str());
            //--------------------------------------------------------------
            coordinates = "";
            //----------------------Aging(Approx. LRU)-----------------------------
            nm = approx_LRU(frame_size, pageNoSeq);
            if(nm>i)
            {
                swaps=nm-i;
            }
            coordinates = to_string(i) + "," + to_string((float(nm))/no_of_pages) + "," + to_string(swaps) + "\n";
            // cout << coordinates;
            fprintf(aging_pt, "%s", coordinates.c_str());
            //--------------------------------------------------------------
            coordinates = "";
            //----------------------WSClock-----------------------------
            nm = wsclock(frame_size, pageNoSeq);
            if(nm>i)
            {
                swaps=nm-i;
            }
            coordinates = to_string(i) + "," + to_string((float(nm))/no_of_pages) + "," + to_string(swaps) + "\n";
            // cout << coordinates;
            fprintf(wsclock_pt, "%s", coordinates.c_str());
            //--------------------------------------------------------------
    }
    //--------------------------------------------------------------------------
    fclose(random_pt);
    fclose(optimal_pt);
    fclose(nru_pt);
    fclose(fifo_pt);
    fclose(fifo2nd_pt);
    fclose(clock_pt);
    fclose(lru_pt);
    fclose(nfu_pt);
    fclose(workingset_pt);
    fclose(aging_pt);
    fclose(wsclock_pt);
    //--------------------------------------------------------------------------

    char filename[] = "graph.py";
    FILE *fp;

    Py_Initialize();

    fp = _Py_fopen(filename, "r");
    PyRun_SimpleFile(fp, filename);

    char filename1[] = "graph1.py";

    fp = _Py_fopen(filename1, "r");
    PyRun_SimpleFile(fp, filename1);

    Py_Finalize();


    remove("optimal_output.txt");
    remove("random_output.txt");
    remove("nru_output.txt");
    remove("nfu_output.txt");
    remove("fifo_output.txt");
    remove("fifo2nd_output.txt");
    remove("lru_output.txt");
    remove("workingset_output.txt");
    remove("clock_output.txt");
    remove("aging_output.txt");
    remove("wsclock_output.txt");
}

int main()
{
    // int data, pageNo, i = 0, hits = 0, misses = 0;
    // FILE *fp = fopen("input.txt", "r");
    // vector<int> pageNoSeq;

    srand(time(0));
    FILE *fp = fopen("input.txt", "w");
    for (int i = 0; i < 100; i++)
    {
        int num = rand() % 20;
        fprintf(fp, "%d ", num);
    }
    fclose(fp);

    fp = fopen("input.txt", "r");

    // Read all page no. in advance.
    while (readNextPageNo(fp, &data))
    {
        pageNo = data;
        pageNoSeq.push_back(pageNo);
        i++;
    }

    int no_of_pages = i;

    // Create Frame
    run_algo(no_of_pages);
    return 0;
}