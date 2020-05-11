#include "customstack.h"


CustomStack::CustomStack(size_t size):
    mTopId(0), mSize(size), mData(new char*[size]){}

CustomStack::~CustomStack()
{
    for (size_t i = mTopId; i > 0; i--)
        delete mData[i-1];
    delete [] mData;
}

void CustomStack::push(const char *val)
{
//    std::cout << "adding \"" << val << "\" to stack" << std::endl;
    if (mTopId  == mSize)
        this->extend(10);

    mData[mTopId] = new char[strlen(val)+1];
    strcpy(mData[mTopId], val);
    mTopId++;
}

void CustomStack::pop()
{
//    std::cout << "removing \"" << mData[mTopId] << "\" from stack" << std::endl;
    if (mTopId > 0)
    {
        delete mData[mTopId - 1];
        mTopId--;
    }
}

char *CustomStack::top()
{
    if (!(this->empty()))
        return mData[mTopId-1];
    else
        return NULL;
}

size_t CustomStack::size()
{
    return mTopId;
}

bool CustomStack::empty()
{
    return (mTopId == 0);
}

void CustomStack::extend(int n)
{
    mSize += n;
    char** tmp = new char*[mSize];
    for (size_t i = 0; i <= mTopId-1; i++)
        tmp[i] = mData[i];
    delete [] mData;
    this->mData = tmp;
}
