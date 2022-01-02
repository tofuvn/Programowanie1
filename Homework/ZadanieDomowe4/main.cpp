#include <iostream>

using namespace std;

struct Point {
    int x, y;

    Point(int x_ = 0, int y_ = 0) {
        x = x_;
        y = y_;
    }
};

struct Node {
    Point point;

    Node *next;

    Node(Point point_, Node *next_) {
        point = point_;
        next = next_;
    }
};

struct List {
    Node *head = nullptr;
};

bool smaller(Point point1, Point point2);

void insert(Node *node, Point point) {

    if (!node) {
        return;
    }

    Node *newNode = new Node(point, nullptr);

    Node *temp = node->next;

    node->next = newNode;

    newNode->next = temp;
}

void push_front(List &list, Point point) {
    if (list.head == nullptr) {
        list.head = new Node(point, nullptr);
        return;
    }

    Node *newNode = new Node(point, nullptr);
    newNode->next = list.head;
    list.head = newNode;

}

void push_back(List &list, Point point) {
    if (list.head == nullptr) {
        list.head = new Node(point, nullptr);
        return;
    }

    Node *current = list.head;

    while (current->next != nullptr) {
        current = current->next;
    }

    Node *newNode = new Node(point, nullptr);
    current->next = newNode;
}

bool smaller(Point point1, Point point2) {
    return point1.x < point2.x or (point1.x == point2.x and point1.y <= point2.y);
}

Node *mergeUtil(Node *head1, Node *head2) {
    if (!head1->next) {
        head1->next = head2;
        return head1;
    }
    Node *curr1 = head1, *next1 = head1->next;
    Node *curr2 = head2, *next2;

    while (next1 && curr2) {
        // if curr2 lies in between curr1 and next1
        // then do curr1->curr2->next1
        if (smaller(curr1->point, curr2->point) and smaller(curr2->point, next1->point)) {
            next2 = curr2->next;
            curr1->next = curr2;
            curr2->next = next1;

            // now let curr1 and curr2 to point
            // to their immediate next pointers
            curr1 = curr2;
            curr2 = next2;
        } else {
            // if more nodes in first list
            if (next1->next) {
                next1 = next1->next;
                curr1 = curr1->next;
            }
                // else point the last node of first list
                // to the remaining nodes of second list
            else {
                next1->next = curr2;
                return head1;
            }
        }
    }
    return head1;

}


Node *merge(Node *head1, Node *head2) {
    if (!head1) {
        return head2;
    }

    if (!head2) {
        return head1;
    }

    if (smaller(head1->point, head2->point)) {
        return mergeUtil(head1, head2);
    } else {
        return mergeUtil(head2, head1);
    }
}


bool isEmpty(List &list) {
    return list.head == nullptr;
}

void display(Node *head) {
    while (head != nullptr) {
        cout << head->point.x << " :" << head->point.y << endl;
        head = head->next;
    }
}

int main() {
    List list;
    cout << boolalpha;
    cout << isEmpty(list) << endl;
    push_front(list, Point(1, 2));
    push_front(list, Point(3, 4));
    push_front(list, Point(5, 6));
    push_front(list, Point(7, 8));
    push_front(list, Point(9, 10));
    push_back(list, Point(100, 1000));
    insert(list.head, Point(100, 1000));

    display(list.head);
    cout << isEmpty(list) << endl;

    cout << "-------------------" << endl;
    cout << "Merge two sorted list " << endl;

    List list1;
    push_back(list1, Point(1, 2));
    push_back(list1, Point(3, 4));
    push_back(list1, Point(5, 6));
    push_back(list1, Point(7, 8));

    List list2;
    push_back(list2, Point(1, 2));
    push_back(list2, Point(8, 10));
    push_back(list2, Point(10, 12));

    Node *head = merge(list1.head, list2.head);

    display(head);

}
