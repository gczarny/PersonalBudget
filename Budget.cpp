#include <iostream>
#include "Budget.h"

using namespace std;

void Budget::setUserId(int newUserId)
{
    userId = newUserId;
}

void Budget::setDate(int newDate)
{
    date = newDate;
}

void Budget::setItem(string newItem)
{
    item = newItem;
}

void Budget::setAmount(string newAmount)
{
    amount = newAmount;
}

int Budget::getUserId()
{
    return userId;
}

int Budget::getDate()
{
    return date;
}

string Budget::getItem()
{
    return item;
}

string Budget::getAmount()
{
    return amount;
}
