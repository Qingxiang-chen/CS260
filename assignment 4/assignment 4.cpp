#include "stdafx.h"
#include <iostream> 
#include <assert.h>
using namespace std;

struct MyNode
{
    int data;
    MyNode* pNext;
};

class MyList
{
private:
    MyNode* pHead;
    int count;
public:
    MyList()
    {
        pHead = NULL;
        count = 0;
    }
    ~MyList()
    {
        MyNode* pDel;
        while (pHead)
        {
            pDel = pHead;
            pHead = pHead->pNext;
            delete pDel;
        }
        pHead = NULL;
    }

    /**
    * add value in front 
    */
    bool push_front(int data)
    {
        MyNode* pAdd = new MyNode;
        pAdd->data = data;
        pAdd->pNext = pHead;
        pHead = pAdd;
        count++;
        return true;
    }
    /**
    * delete value in front 
    */
    bool pop_front()
    {
        if (0 == count) return false;
        MyNode* pDel = pHead;
        pHead = pHead->pNext;
        delete pDel;
        count--;
        return true;
    }
    /**
    * add  in the last 
    *  consider if it is empty
    */
    bool push_back(int data)
    {
        MyNode* pCur = pHead;
        int i = 0;
        //loop to last ，so pCur will be last 
        while (i < count - 1)
        {
            pCur = pCur->pNext;
            i++;
        }
        MyNode* pAdd = new MyNode;
        pAdd->data = data;
        pAdd->pNext = NULL;
        if (0 == count)
            pHead = pAdd;
        else
            pCur->pNext = pAdd; 
        count++;
        return true;
    }
    /**
    * Pop an element at the end of the linked list
    */
    bool pop_back()
    {
        MyNode* pCur = pHead;
        int i = 0;
        while (i < count - 2)
        {
            pCur = pCur->pNext;
            i++;
        }
        MyNode* pDel = pCur->pNext;
        pCur->pNext = NULL;
        delete pDel;
        count--;
        return true;
    }
    /** 
    *  add in the list 
    * @param[in] data the value 
    * @param[in] index the location what I chose 
    */
    bool Insert(int index, int data)
    {
        if (index < 1 || index > count) return false;
        MyNode* pCur = pHead;
        int i = 0;
        while (i < index - 1)
        {
            pCur = pCur->pNext;
            i++;
        }
        MyNode* pAdd = new MyNode;
        pAdd->data = data;
        pAdd->pNext = pCur->pNext;
        pCur->pNext = pAdd;
        count++;
        return true;
    }
    /**
    * delete one 
    * @param[in] index the location of value delete 
    */
    bool Delete(int index)
    {
        if (index < 1 || index > count) return false;
        MyNode* pCur = pHead;
        int i = 0;
        while (i < index - 1)
        {
            pCur = pCur->pNext;
            i++;
        }
        MyNode* pDel = pCur->pNext;
        pCur->pNext = pDel->pNext;
        delete pDel;
        count--;
        return true;
    }
    /**
    *  get value from list 
    * @param[in] index the location of value which need get 
    */
    int operator[](int index)
    {
        assert(index >=0 && index < count);
        MyNode* pCur = pHead;
        int i = 0;
        while (i < index)
        {
            pCur = pCur->pNext;
            i++;
        }
        return pCur->data;
    }

    void Traverse()
    {
        MyNode* pCur = pHead;
        while (pCur)
        {
            cout << pCur->data << " ";
            pCur = pCur->pNext;
        }
        cout << endl;
    }
};


int main()
{
    MyList mylist;
    mylist.push_back(2);
    mylist.push_back(4);
    mylist.push_back(6);
    mylist.push_back(8);
    mylist.push_front(0);
    mylist.push_back(10);
    mylist.push_front(-2);
    mylist.Traverse();
    mylist.pop_back();
    mylist.pop_front();
    mylist.Traverse();
    mylist.Insert(4, 100);
    mylist.Traverse();
    mylist.Delete(4);
    mylist.Traverse();
    cout << mylist[4] << endl;
    getchar();
    return 0;
}