#include <iostream>
#include <stdio.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

ListNode *kcycle(ListNode *head, int k)
{
    if (!head)
    {
        return nullptr;
    }
    for (int i = 1; i < k; i++)
    {
        if (!head->next)
        {
            return nullptr;
        }
        // if (i==k-1){
        //     taillist.push_back(head);
        // }
        head = head->next;
    }
    return head;
}

void relist(ListNode *head, int k)
{
    ListNode *listhead=head;
    ListNode *last = nullptr;
    ListNode *now = head;
    for (int i = 0; i < k; i++)
    {
        ListNode *next = now->next;
        now->next = last;
        last = now;
        now = next;
    }
    listhead->next=kcycle(now,k);
    if (listhead->next){
        relist(now,k);
    }
    else{
        listhead->next=now;
    }
    return;
}

int main()
{
    ListNode *plast = new ListNode;
    plast->val = 1;
    ListNode *head = plast;
    ListNode *chead = head;
    ListNode *tail;
    ListNode *pnow = nullptr;
    ListNode now;
    for (int i = 2; i <= 8; i++)
    {
        ListNode *pnow = new ListNode;
        pnow->val = i;
        pnow->next = nullptr;
        plast->next = pnow;
        plast = pnow;
    }
    while (head)
    {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;

    int k = 3;

    tail=kcycle(chead,k);
    //head=tail;
    head=chead;
    relist(head,k);
    head=tail;
    while (head)
    {
        cout << head->val << ' ';
        head = head->next;
    }

    return 0;
}