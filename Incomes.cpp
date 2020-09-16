#include <iostream>
#include "Incomes.h"

using namespace std;

void Incomes::setDate(string newDate)
{
    date = newDate;
}

void Incomes::setItem(string newItem)
{
    item = newItem;
}

void Incomes::setAmount(string newAmount)
{
    amount = newAmount;
}

string Incomes::getDate()
{
    return date;
}

string Incomes::getItem()
{
    return item;
}

string Incomes::getAmount()
{
    return amount;
}
