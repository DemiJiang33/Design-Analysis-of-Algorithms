//file: insertionSort.cpp
/**
Name: Shanshan Jiang
Course: CSC551 Algorithm
Date: 02/04/2016
Description:
This is the insertionSort.cpp.
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

void insertionSort(int arr[], int n)
{
  int j, temp;

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

B:  for (int i = 0; i < n; i++)
  {
    j = i;//set j to the current index of array

    while (j > 0 && arr[j] < arr[j - 1]) {
      temp = arr[j];
      arr[j] = arr[j - 1];
      arr[j - 1] = temp;
      j--;
      //++count2;
    }//end of while loop
    //++count;// # of iteration         
  }//end of for loop


    //mark end time
  double end = cpuTime();
  clock_t et = clock();

  //calc deltas
  double cpuTime = end - start;
  if (cpuTime <= 3) {
    repeat += 1;
    goto B;
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