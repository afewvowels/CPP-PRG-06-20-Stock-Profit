//
//  main.cpp
//  PRG-6-20-Stock-Profit
//
//  Created by Keith Smith on 9/21/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  The profit from the sale of a stock can be calculated as follows:
//
//  Profit = ((NS * SP) - SC) - ((NS * PP) + PC)
//
//  Where NS is the number of shares, SP is the sale price per share, SC is the sale commission
//  paid, PP is the purchase price per share, and PC is the purchase commission paid.
//  If the calculation yields a positive value, then the sale of the stock resulted in a profit.
//  If the calculation yields a negative number, then the sale resulted in a loss.
//
//  Write a function that accepts as arguments the number of shares, the purchase price per
//  share, the purchase commission paid, the sale price per share, and the sale commission
//  paid. The function should return the profit (or loss) from the sale of stock.
//  Demonstrate the function is a progrm that asks the user to enter the necessary data
//  and displays the amount of profit or loss.

#include <iostream>

using namespace std;

void inputData(int &, float &, float &, float &, float &);
float calculateGain(int, float, float, float, float, float);

int main()
{
    int intNumberOfShares;
    
    float fltSalePricePerShare;
    float fltSaleCommissionPaid;
    float fltPurchasePricePerShare;
    float fltPurchaseCommissionPaid;
    float fltTotalGain;
    
    fltTotalGain = 0.0f; // Initialize at 0 to pass to calculateGain()
    
    inputData(intNumberOfShares, fltSalePricePerShare, fltSaleCommissionPaid, fltPurchasePricePerShare, fltPurchaseCommissionPaid);
    
    fltTotalGain = calculateGain(intNumberOfShares, fltSalePricePerShare, fltSaleCommissionPaid, fltPurchasePricePerShare, fltPurchaseCommissionPaid, fltTotalGain);
    
    cout << "The total gain/loss was $" << fltTotalGain << endl;
    
    return 0;
}

void inputData(int &refShares, float &refSalePrice, float &refSaleCommission, float &refPurchasePrice, float &refPurchaseCommission)
{
    cout << "Please enter the total number of shares:\n";
    cin >> refShares;
    
    while(!cin || refShares < 0 || refShares > 1000000)
    {
        cout << "Please enter a number between 1 and 1,000,000:\n";
        cin.clear();
        cin.ignore();
        cin >> refShares;
    }
    
    cout << "Please enter the sale price per share:\n";
    cin >> refSalePrice;
    
    while(!cin || refSalePrice < 0.0f || refSalePrice > 10000.0f)
    {
        cout << "Please enter a number between $1.00 and $10,000.00:\n";
        cin.clear();
        cin.ignore();
        cin >> refSalePrice;
    }
    
    cout << "Please enter the sales commission:\n";
    cin >> refSaleCommission;
    
    while(!cin || refSaleCommission < 0.0f || refSaleCommission > 100000.0f)
    {
        cout << "Please enter a number between $1.00 and $100,000.00:\n";
        cin.clear();
        cin.ignore();
        cin >> refSaleCommission;
    }
    
    cout << "Please enter the purchase price per share:\n";
    cin >> refPurchasePrice;
    
    while(!cin || refPurchasePrice < 0.0f || refPurchasePrice > 10000.0f)
    {
        cout << "Please enter a number between $1.00 and $10,000.00:\n";
        cin.clear();
        cin.ignore();
        cin >> refPurchasePrice;
    }
    
    cout << "Please enter purchase commission:\n";
    cin >> refPurchaseCommission;
    
    while(!cin || refPurchaseCommission < 0.0f || refPurchaseCommission > 100000.0f)
    {
        cout << "Please enter a number between $1.00 and $100,000.00:\n";
        cin.clear();
        cin.ignore();
        cin >> refPurchaseCommission;
    }
}

float calculateGain(int intNumberOfShares, float fltSalesPricePerShare, float fltSaleCommissionPaid, float fltPurchasePricePerShare, float fltPurchaseCommissionPaid, float fltTotalGain)
{
    fltTotalGain = ((intNumberOfShares * fltSalesPricePerShare) - fltSaleCommissionPaid) - ((intNumberOfShares * fltPurchasePricePerShare) - fltPurchaseCommissionPaid);
    
    return fltTotalGain;
}

