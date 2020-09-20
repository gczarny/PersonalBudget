#include <iostream>
#include "Expenses.h"

using namespace std;

void Expenses::setExpenseId(int newExpenseId)
{
    expenseId = newExpenseId;
}

void Expenses::setUserId(int newUserId)
{
    userId = newUserId;
}

void Expenses::setDate(int newDate)
{
    date = newDate;
}

void Expenses::setItem(string newItem)
{
    item = newItem;
}

void Expenses::setAmount(string newAmount)
{
    amount = newAmount;
}

int Expenses::getExpenseId()
{
    return expenseId;
}

int Expenses::getUserId()
{
    return userId;
}

int Expenses::getDate()
{
    return date;
}

string Expenses::getItem()
{
    return item;
}

string Expenses::getAmount()
{
    return amount;
}
