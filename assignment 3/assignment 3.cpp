#include<iostream>
using namespace std;
class QNode {
public:
    int data;
    QNode *qnext;
};
class Linkqueue {
public:
    void InitQueue(Linkqueue &Q);
    void IsEmpty(Linkqueue &Q);
    void EnQueue(Linkqueue &Q);
    void DeQueue(Linkqueue &Q);
    void showqueue(Linkqueue &Q);
    void findQueue(Linkqueue &Q, int value);
    void destroyQueue(Linkqueue &Q);

private:
    QNode *front;
    QNode *rear;
};
//initial queue 
void Linkqueue::InitQueue(Linkqueue &Q) {
    QNode *p = new QNode;
    p->qnext = NULL;
    Q.front = p;
    Q.rear = p;
}
// if this link empty or not
void Linkqueue::IsEmpty(Linkqueue &Q) {
    if (Q.rear == Q.front) {
        cout << "this list is empty";
    }
    else
        cout << "this is not empty";
    cout << endl;
}
//input node
void Linkqueue::EnQueue(Linkqueue &Q) {
    QNode *pnew = new QNode;
    pnew->qnext = NULL;
    cout << "enter the node = ";
    cin >> pnew->data;
    Q.rear->qnext = pnew;
    Q.rear = pnew;
}
// delete queue
void Linkqueue::DeQueue(Linkqueue &Q)
{
    QNode *p;
    p = Q.front->qnext;
    Q.front->qnext = Q.front->qnext->qnext;     
    if (Q.rear == p)   
        Q.rear = Q.front;
    delete p;
}
//showqueue
void Linkqueue::showqueue(Linkqueue &Q) {
    QNode *p;
    p = Q.front->qnext;
    if (p == NULL)  
    {
        cout << "list is empty" << endl;
    }
    cout << endl;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->qnext;
    }
    cout << endl;
}
//find queue
void Linkqueue::findQueue(Linkqueue &Q, int value) {
    QNode *ptarget;
    ptarget = Q.front;
    int n = 0;
    cout << "value is " << value << "this location=";
    while (ptarget != Q.rear) {
        if (ptarget->data == value) {
            cout << n + 1 << " ";
        }
        n = n + 1;
        ptarget = ptarget->qnext;
    }
    cout << endl;
}

//destroyqueue
void Linkqueue::destroyQueue(Linkqueue &Q) {
    while (Q.front)
    {
        Q.rear = Q.front->qnext;
        delete Q.front;
        Q.front = Q.rear;
    }
}
int main() {
    Linkqueue queue;
    Linkqueue *Q;
    int n;
    Q = new Linkqueue;
    queue.InitQueue(*Q);
    cout << "how many node do you need = ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        queue.EnQueue(*Q);
    }
    cout << "node is ：";
    queue.showqueue(*Q);
    cout << "after delete first：";
    queue.DeQueue(*Q);
    queue.showqueue(*Q);
    queue.findQueue(*Q, 1);
    queue.IsEmpty(*Q);
    queue.destroyQueue(*Q);
   
    return 0;
}