//file: selectionSort.cpp
/**
Name: Shanshan Jiang
Course: CSC551 Algorithm
Date: 02/04/2016
Description:
This is the selectionSort.cpp.
The const N can be changed from 10 to 1000000.
**/
#include <iostream>
#include <math.h>
#include <time.h>
#include <Windows.h>

using namespace std;
//based on:
// http://stackoverflow.com/questions/19378805/measure-cpu-time-on-windows-using-getprocesstimes
static double cpuTime(void) {
  FILETIME createTime, exitTime, kernelTime, userTime;

  if (GetProcessTimes(GetCurrentProcess(), &createTime, &exitTime,
    &kernelTime, &userTime) != -1) {
    SYSTEMTIME userSystemTime;
    if (FileTimeToSystemTime(&userTime, &userSystemTime) != -1)
      return (double)userSystemTime.wHour * 3600.0 +
      (double)userSystemTime.wMinute * 60.0 +
      (double)userSystemTime.wSecond +
      (double)userSystemTime.wMilliseconds / 1000.0;
  }
  return -1;
}

void selectionSort(int arr[], int n)
{
  //pos_min is short for position of min
  int pos_min, temp;

  //mark start time
  clock_t st = clock();
  double start = cpuTime();
    //long count = 0, count2 = 0; 
  //do stuff
  double  sum = 0;
  for (double d = 0; d<10000; d += 0.01) {
    sum += sin(d) * cos(d);
  }
  Sleep(2000);  //sleep for 2 sec
  double repeat = 1;// # of repeat

A:  for (int i = 0; i < n - 1; i++)
{
  pos_min = i;//set pos_min to the current index of array

  for (int j = i + 1; j < n; j++)
  {

    if (arr[j] < arr[pos_min]) {
      pos_min = j;
            //++count2; // # of iteration     
    }
    //pos_min will keep track of the index that min is in, this is needed when a swap happens

  }//inner for loop

   //if pos_min no longer equals i than a smaller value must have been found, so a swap must occur
  if (pos_min != i)
  {
    temp = arr[i];
    arr[i] = arr[pos_min];
    arr[pos_min] = temp;
  } //if
    //++count; // # of iteration
}// outer loop


 //mark end time
  double end = cpuTime();
  clock_t et = clock();

  //calc deltas
  double cpuTime = end - start;
  if (cpuTime <= 3) {
    repeat += 1;
    goto A;
  }
  double avgCPU = cpuTime / repeat;
  double elapsedTime = ((double)et - st) / CLOCKS_PER_SEC;

  //report results
    //cout << "operation count(outer loop) = " << count << endl;
    //cout << "operation count2(inner loop) = " << count2 << endl;
    //cout << "# of iteration = " << count2 + count << endl;
  ///////////////////////////?????????????????????????????????////////////////////////////////////////////////////////////
  cout << "# repeat  = " << repeat << endl;
  cout << "elapsed time = " << elapsedTime << " sec" << endl;
  cout << "tcpu time = " << cpuTime << " sec" << endl;
  cout << "avgcpu time = " << avgCPU << " sec" << endl;
}