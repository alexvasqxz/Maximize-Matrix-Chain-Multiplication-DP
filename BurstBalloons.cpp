// BurstBalloons.cpp
// Burst Balloons
// Maximize the possible outcome for
// multiplications, this algorithm can be understand by
// understanding the logic of the Goldbole's algorithm
// to multiply matrix chain products, in this case
// we are trying to obtain the greates possible outcome
// using Dynamic Programming
//Leetcode Problems:
//https://leetcode.com/problems/burst-balloons/
//
//  Created by Gustavo Alejandro Vasquez on 4/25/20.
//  Copyright © 2020 Alex Vasquez. All rights reserved.
//
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

#define MAX 200
class Solution {
public:
    /*////////////////////////////////////////////////
    // calc
    //
    // This function creates a 2D array that stores the
    // values of the greatest outcome for each
    // multiplication depending on the number of
    // numbers and the indexes
    //
    // Parameters:
    // D[][] = 2Darray that will store the values
    // nums = Vector that contains the numbers to be
     multiply
    // n = size of the array nums
    //
    // Return:
    // Greates possible outcome for the multiplication    /////////////////////////////////////////////////
    */
int calc(int D[MAX][MAX], vector<int>& nums, long n){
    int index, great, temp;
    for (int i = 1; i<n; i++){
        // [i][i] = 0, hence, the main diagonal
        D[i][i] = 0;
        for (int j = 1; j<=(n-1)-i; j++){
            // The matrix will be traverse diagonally
            index = (j-1)+i+1;
            great = 0;
            for (int k = j; k<index; k++){
                // This formula allows us to calculate the
                // greates number for each multiplication
                temp = D[j][k] + D[k+1][index] + (nums[j-1]*nums[k]*nums[index]);
                if (temp > great){
                    great = temp;
                }
            }
            D[j][index] = great;
        }
    }
    // Value with the greatest number for all the numbers
    // being multiplied
    return D[1][n-1];
}

    /*
    ////////////////////////////////////////////////
    // maxCoins
    //
    // This function will create our 2d array and add
    // a 1 both to the end and beggining to the vector
    // containing our numbers to be multiplied
    //
    // Parameters:
    // nums = Vector that contains the numbers to be multiply
    //
    // Return:
    // Result (Gratest number of coins)
    ///////////////////////////////////////////////
    */
int maxCoins(vector<int>& nums) {
    int DP [MAX][MAX];
    // 1 is added both to the end and beggining of the vector
    // so we can complete the 2d array in the calc function
    nums.insert(nums.begin(), 1);
    nums.insert(nums.end(), 1);
    return calc(DP, nums, nums.size());
}
};
