// #linkedlist

#include <iostream>
using namespace std;

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution Class containing the result ListNode
class Solution
{
public:
    ListNode *result = nullptr, *last = nullptr;
    // Function to add an element at the end of the result list
    void insert(int x)
    {
        if (result == nullptr)
        {
            result = new ListNode(x);
            last = result;
        }
        else
        {
            last->next = new ListNode(x);
            last = last->next;
        }
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // sum will contain single digit sum of corresponding values of l1 and l2
        // carryOver will contain the carry over value of their sum
        int sum{}, carryOver{};

        // creating temp nodes for traversing l1 and l2
        ListNode *temp1 = l1, *temp2 = l2;
        while (temp1 != nullptr || temp2 != nullptr)
        {
            sum = 0; // setting sum to 0 for after the previous loop

            // l1 and l2 may not be of same size therefore we divide into two cases:
            if (temp1 != nullptr)
            {
                sum += temp1->val;
                temp1 = temp1->next;
            }

            if (temp2 != nullptr)
            {
                sum += temp2->val;
                temp2 = temp2->next;
            }

            // the calculated sum value can be a two digit number
            // so to get face value we take mod 10
            // and add the carryOver value from previous loop and insert it
            insert((sum % 10 + carryOver) % 10);

            // if the sum was greater than 10, carry over will be 1 else 0
            carryOver = (sum >= 10);
        }

        // after traversing both l1 and l2, there might be carry over left
        // to add in the result list if yes then insert it:
        if (carryOver)
            insert(carryOver);

        return result;
    }
};

void printList(ListNode *list)
{
    ListNode *temp = list;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

int main()
{
    Solution s1;

    cout << "Adding two numbers using Linked list: " << endl;
    int l1_arr[] = {2, 4, 7}, l2_arr[] = {5, 6, 4};
    // inserting elements in list l1 (ignore)
    ListNode *l1 = new ListNode(l1_arr[0]);
    ListNode *n1 = new ListNode(l1_arr[1]);
    l1->next = n1;
    ListNode *n2 = new ListNode(l1_arr[2]);
    n1->next = n2;

    // inserting elements in list l2 (ignore)
    ListNode *l2 = new ListNode(l2_arr[0]);
    ListNode *n3 = new ListNode(l2_arr[1]);
    l2->next = n3;
    ListNode *n4 = new ListNode(l2_arr[2]);
    n3->next = n4;
    printList(l1);
    cout << " + ";
    printList(l2);
    cout << " = ";
    // calculating the resultant sum and storing in a linked list
    ListNode *result = s1.addTwoNumbers(l1, l2);

    // displaying the result
    printList(result);
}
