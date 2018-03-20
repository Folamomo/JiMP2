//
// Created by igor on 19.03.18.
//

#ifndef JIMP_EXERCISES_SIMPLEFORWARDLIST_H
#define JIMP_EXERCISES_SIMPLEFORWARDLIST_H

typedef struct fwl ForwardList;

struct fwl{
    int value;
    struct fwl * next;
};

ForwardList *CreateNode(int value);
void DestroyList(ForwardList *list);

ForwardList *PushFront(ForwardList *list, int value);
void Append(ForwardList *list, ForwardList *tail);

#endif //JIMP_EXERCISES_SIMPLEFORWARDLIST_H
